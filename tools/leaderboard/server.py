#!/usr/bin/env python3
"""Leaderboard server for the native build (stdlib only, Windows).

    python server.py path\\to\\pokepinballrs_pc.exe [--port 8377] [--db leaderboard.sqlite]

The game sends a replay; a replay is the starting conditions and the keys of a
game, so the server plays it again (PINBALL_VERIFY) and takes the score from
that run. A score can't be made up: it has to come from a game that really
plays out that way. Only finished games with the original rules count.

    POST /submit?name=NAME   body: the .ppr file
    GET  /top                name|field|score|yes per line, best first

Replays are files from strangers and the check runs the game on them, so run
this on a machine (or in a sandbox) that has nothing else on it.
"""

import argparse
import json
import os
import re
import sqlite3
import subprocess
import tempfile
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from urllib.parse import parse_qs, urlparse

FIELDS = ["Ruby", "Sapphire", "Dusclops", "Kecleon", "Kyogre", "Groudon", "Rayquaza", "Spheal"]
MAX_REPLAY_SIZE = 8 * 1024 * 1024
VERIFY_TIMEOUT = 600
TOP_COUNT = 12


def verify_replay(exe, data):
    """Plays the replay in an empty folder; returns the result as a dict, or None."""
    with tempfile.TemporaryDirectory() as folder:
        path = os.path.join(folder, "game.ppr")
        with open(path, "wb") as f:
            f.write(data)
        env = dict(os.environ, PINBALL_VERIFY=path, PINBALL_HIDDEN="1", PINBALL_WINDOW="240x160", PINBALL_DIR=folder)
        try:
            result = subprocess.run([exe], env=env, capture_output=True, timeout=VERIFY_TIMEOUT)
        except subprocess.TimeoutExpired:
            return None
        for line in result.stdout.decode("utf8", "replace").splitlines():
            if line.startswith("{"):
                return json.loads(line)
    return None


def format_score(hi, lo):
    return f"{hi}{lo:08d}" if hi else str(lo)


class Board:
    def __init__(self, path):
        self.db = sqlite3.connect(path, check_same_thread=False)
        self.db.execute(
            "CREATE TABLE IF NOT EXISTS scores (hash TEXT PRIMARY KEY, name TEXT, field INTEGER, hi INTEGER, lo INTEGER, frames INTEGER)"
        )

    # The same game counts once, however its file was changed: the key is the
    # hash of how the game ended, not of the file.
    def add(self, digest, name, result):
        try:
            with self.db:
                self.db.execute(
                    "INSERT INTO scores VALUES (?, ?, ?, ?, ?, ?)",
                    (digest, name, result["field"], result["scoreHi"], result["scoreLo"], result["frames"]),
                )
        except sqlite3.IntegrityError:
            return False
        return True

    def top(self):
        rows = self.db.execute(f"SELECT name, field, hi, lo FROM scores ORDER BY hi DESC, lo DESC LIMIT {TOP_COUNT}")
        return "".join(f"{name}|{FIELDS[field]}|{format_score(hi, lo)}|yes\n" for name, field, hi, lo in rows)


class Handler(BaseHTTPRequestHandler):
    def reply(self, status, text):
        body = text.encode("utf8")
        self.send_response(status)
        self.send_header("Content-Type", "text/plain; charset=utf-8")
        self.send_header("Content-Length", str(len(body)))
        self.end_headers()
        self.wfile.write(body)

    def do_GET(self):
        if urlparse(self.path).path == "/top":
            self.reply(200, self.server.board.top())
        else:
            self.reply(404, "not found")

    def do_POST(self):
        url = urlparse(self.path)
        if url.path != "/submit":
            self.reply(404, "not found")
            return

        size = int(self.headers.get("Content-Length", 0))
        if size <= 0 or size > MAX_REPLAY_SIZE:
            self.reply(400, "bad size")
            return
        data = self.rfile.read(size)

        name = parse_qs(url.query).get("name", ["Player"])[0]
        name = re.sub(r"[^0-9A-Za-z _-]", "", name)[:16] or "Player"

        result = verify_replay(self.server.exe, data)
        if result is None or "error" in result:
            self.reply(400, "the replay can't be played")
        elif not result["ok"]:
            self.reply(400, "the replay doesn't match its score")
        elif not result["finished"]:
            self.reply(400, "the game wasn't finished")
        elif not result["vanilla"] or result["training"]:
            self.reply(400, "only games with the original rules count")
        elif not self.server.board.add(result["hash"], name, result):
            self.reply(400, "already sent")
        else:
            self.reply(200, "ok")

    def log_message(self, format, *args):
        print(self.address_string(), format % args)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("exe")
    parser.add_argument("--port", type=int, default=8377)
    parser.add_argument("--host", default="127.0.0.1")
    parser.add_argument("--db", default="leaderboard.sqlite")
    args = parser.parse_args()

    server = ThreadingHTTPServer((args.host, args.port), Handler)
    server.exe = os.path.abspath(args.exe)
    server.board = Board(args.db)
    print(f"Listening on http://{args.host}:{args.port}")
    server.serve_forever()


if __name__ == "__main__":
    main()
