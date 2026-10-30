// Replays: a game's starting conditions (struct RunHeader) and the keys of
// every frame, run-length coded. The game is deterministic, so this replays it
// exactly: the file ends with the final score and a hash of the game state,
// and playing it back checks them.
//
// File: struct ReplayFile, the header, then pairs of 16-bit values
// (keys, frames - 1).

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "pc.h"

#define REPLAY_MAGIC 0x31525050  // "PPR1"
#define REPLAY_VERSION 1

// In struct SaveData
#define SAVE_BALL_SPEED_OFFSET 0xCF
#define SAVE_BUTTON_CONFIG_OFFSET 0xD0

struct ReplayFile
{
    uint32_t magic;
    uint32_t version;
    uint32_t frames;
    uint32_t numEntries;
    uint32_t scoreHi, scoreLo;
    uint32_t hash;
    uint32_t finished;   // the game reached its end
};

struct Entry
{
    uint16_t keys;
    uint16_t run;
};

static struct Entry *sEntries;
static uint32_t sCapacity, sCount;
static uint32_t sFrames;
static struct RunHeader sHeader;
static int sRecording, sTainted;

static int sPlaying;
static uint32_t sPlayEntry, sPlayRun;
static struct ReplayFile sFile;
static int sVerifying;
static char sVerifyPath[MAX_PATH];

static void AddEntry(uint32_t keys)
{
    if (sCount && sEntries[sCount - 1].keys == keys && sEntries[sCount - 1].run != 0xFFFF)
    {
        sEntries[sCount - 1].run++;
        return;
    }
    if (sCount == sCapacity)
    {
        sCapacity = sCapacity ? sCapacity * 2 : 4096;
        sEntries = realloc(sEntries, sCapacity * sizeof(*sEntries));
    }
    sEntries[sCount].keys = keys;
    sEntries[sCount].run = 0;
    sCount++;
}

void Replay_Init(void)
{
    char path[MAX_PATH];

    Host_UserFile(path, "replays");
    CreateDirectoryA(path, NULL);
}

void Replay_StartRecording(const struct RunHeader *header)
{
    sHeader = *header;
    sCount = 0;
    sFrames = 0;
    sRecording = 1;
    sTainted = 0;
}

void Replay_RecordKeys(uint32_t keys)
{
    if (sRecording)
    {
        AddEntry(keys);
        sFrames++;
    }
}

void Replay_Taint(void)
{
    sTainted = 1;
}

static int WriteReplay(const char *path, const struct ReplayFile *info)
{
    FILE *file = fopen(path, "wb");

    if (!file)
        return 0;
    fwrite(info, sizeof(*info), 1, file);
    fwrite(&sHeader, sizeof(sHeader), 1, file);
    fwrite(sEntries, sizeof(*sEntries), sCount, file);
    fclose(file);
    return 1;
}

void Replay_StopRecording(uint32_t scoreHi, uint32_t scoreLo, uint32_t hash, int finished)
{
    struct ReplayFile info;
    char name[128], path[MAX_PATH];
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    if (!sRecording)
        return;
    sRecording = 0;
    if (sTainted || sCount == 0)
        return;

    memset(&info, 0, sizeof(info));
    info.magic = REPLAY_MAGIC;
    info.version = REPLAY_VERSION;
    info.frames = sFrames;
    info.numEntries = sCount;
    info.scoreHi = scoreHi;
    info.scoreLo = scoreLo;
    info.hash = hash;
    info.finished = finished;

    snprintf(name, sizeof(name), "replays\\%04d%02d%02d-%02d%02d%02d-f%u-%u%08u.ppr",
             t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec,
             (unsigned)sHeader.field, (unsigned)scoreHi, (unsigned)scoreLo);
    Host_UserFile(path, name);
    WriteReplay(path, &info);
    Host_UserFile(path, "replays\\last.ppr");
    WriteReplay(path, &info);
}

int Replay_Load(const char *path, struct RunHeader *header)
{
    FILE *file = fopen(path, "rb");

    sPlaying = 0;
    if (!file)
        return 0;
    if (fread(&sFile, sizeof(sFile), 1, file) != 1 || sFile.magic != REPLAY_MAGIC || sFile.version != REPLAY_VERSION
        || fread(&sHeader, sizeof(sHeader), 1, file) != 1 || sFile.numEntries > 100000000
        || sHeader.magic != REPLAY_MAGIC || sHeader.version != 1 || sHeader.field >= 8 || sHeader.isBonusField > 1
        || (sHeader.field >= 2) != (sHeader.isBonusField != 0) || sHeader.language >= 5
        || sHeader.saveData[SAVE_BALL_SPEED_OFFSET] > 1 || sHeader.saveData[SAVE_BUTTON_CONFIG_OFFSET] > 4
        || (sHeader.trainingMode > 7 && sHeader.trainingMode != 0xFF))
    {
        fclose(file);
        return 0;
    }
    if (sFile.numEntries > sCapacity)
    {
        sCapacity = sFile.numEntries;
        sEntries = realloc(sEntries, sCapacity * sizeof(*sEntries));
    }
    sCount = sFile.numEntries;
    if (fread(sEntries, sizeof(*sEntries), sCount, file) != sCount)
    {
        fclose(file);
        return 0;
    }
    fclose(file);

    *header = sHeader;
    sPlayEntry = 0;
    sPlayRun = 0;
    sPlaying = 1;
    Host_SetSramGuard(1);
    return 1;
}

int Replay_NextKeys(uint32_t *keys)
{
    if (sPlayEntry >= sCount)
        return 0;
    *keys = sEntries[sPlayEntry].keys;
    if (sPlayRun++ >= sEntries[sPlayEntry].run)
    {
        sPlayEntry++;
        sPlayRun = 0;
    }
    return 1;
}

int Replay_KeysLeft(void)
{
    return sPlayEntry < sCount;
}

void Replay_FinishPlayback(uint32_t scoreHi, uint32_t scoreLo, uint32_t hash)
{
    int ok = sFile.hash == hash && sFile.scoreHi == scoreHi && sFile.scoreLo == scoreLo;

    sPlaying = 0;
    Host_SetSramGuard(0);

    if (sVerifying)
    {
        // Read by tools/leaderboard/server.py
        printf("{\"ok\": %s, \"field\": %u, \"scoreHi\": %u, \"scoreLo\": %u, \"frames\": %u, \"finished\": %u, \"vanilla\": %d, \"training\": %u, \"hash\": \"%08x\", \"expectedHash\": \"%08x\"}\n",
               ok ? "true" : "false", (unsigned)sHeader.field, (unsigned)scoreHi, (unsigned)scoreLo, (unsigned)sFile.frames,
               (unsigned)sFile.finished, (int)sHeader.game.vanilla, (unsigned)sHeader.trainingMode, (unsigned)hash, (unsigned)sFile.hash);
        fflush(stdout);
        ExitProcess(ok ? 0 : 2);
    }
    Host_Log("Replay %s: hash %08X, expected %08X\n", ok ? "ok" : "diverged", (unsigned)hash, (unsigned)sFile.hash);
    Host_Toast(ok ? "replay_ok" : "replay_diverged");
}

int Replay_IsPlaying(void)
{
    return sPlaying;
}

int Replay_IsVerifying(void)
{
    return sVerifying;
}

void Replay_InstallVerify(const char *path)
{
    struct HostCommand command;
    struct RunHeader header;

    if (!Replay_Load(path, &header))
    {
        printf("{\"ok\": false, \"error\": \"bad replay\"}\n");
        fflush(stdout);
        ExitProcess(2);
    }
    sPlaying = 0;
    Host_SetSramGuard(0);
    sVerifying = 1;
    strncpy(sVerifyPath, path, sizeof(sVerifyPath) - 1);
    memset(&command, 0, sizeof(command));
    command.type = CMD_PLAY_REPLAY;
    strncpy(command.path, path, sizeof(command.path) - 1);
    Host_PostCommand(&command);
}

const struct RunHeader *Replay_CurrentHeader(void)
{
    return &sHeader;
}

// The newest ones first.
static int CompareNames(const void *a, const void *b)
{
    return -strcmp((const char *)a, (const char *)b);
}

int Replay_ListFiles(char names[][260], int max)
{
    WIN32_FIND_DATAA data;
    char pattern[MAX_PATH];
    HANDLE find;
    int count = 0;

    Host_UserFile(pattern, "replays\\*.ppr");
    find = FindFirstFileA(pattern, &data);
    if (find == INVALID_HANDLE_VALUE)
        return 0;
    do
    {
        if (count < max && strcmp(data.cFileName, "last.ppr") != 0)
            strncpy(names[count++], data.cFileName, 259);
    } while (FindNextFileA(find, &data));
    FindClose(find);
    qsort(names, count, 260, CompareNames);
    return count;
}
