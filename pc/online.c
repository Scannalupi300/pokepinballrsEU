// The online leaderboard: sends a replay to a server and reads the top scores.
// There is no public server: it talks to the one set in the settings file
// (online_url), and tools/leaderboard/server.py is one. The server replays
// every file with `PINBALL_VERIFY` before it accepts the score, so a score
// can't be made up: it has to come from a game that really plays out that way.

#include "pc.h"
#include <winhttp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static char sUrl[256];
static char sName[32] = "Player";
static char sStatus[128];

const char *Online_Url(void)
{
    return sUrl;
}

const char *Online_Name(void)
{
    return sName;
}

void Online_SetUrl(const char *url)
{
    strncpy(sUrl, url, sizeof(sUrl) - 1);
}

void Online_SetName(const char *name)
{
    strncpy(sName, name, sizeof(sName) - 1);
}

const char *Online_Status(void)
{
    return sStatus;
}

void Online_Init(void)
{
}

// Does one request; the reply is a NUL-terminated string the caller frees.
static char *Request(const wchar_t *method, const char *pathAndQuery, const void *body, DWORD bodySize)
{
    URL_COMPONENTSW parts;
    wchar_t url[300], host[128], path[512], fullPath[800];
    HINTERNET session = NULL, connect = NULL, request = NULL;
    char *reply = NULL;
    size_t replySize = 0;
    DWORD status = 0, size = sizeof(status);

    if (!sUrl[0])
    {
        snprintf(sStatus, sizeof(sStatus), "no_url");
        return NULL;
    }

    MultiByteToWideChar(CP_UTF8, 0, sUrl, -1, url, 300);
    memset(&parts, 0, sizeof(parts));
    parts.dwStructSize = sizeof(parts);
    parts.lpszHostName = host;
    parts.dwHostNameLength = 128;
    parts.lpszUrlPath = path;
    parts.dwUrlPathLength = 512;
    if (!WinHttpCrackUrl(url, 0, 0, &parts))
    {
        snprintf(sStatus, sizeof(sStatus), "bad_url");
        return NULL;
    }
    MultiByteToWideChar(CP_UTF8, 0, pathAndQuery, -1, fullPath, 800);

    session = WinHttpOpen(L"PokePinballRS", WINHTTP_ACCESS_TYPE_DEFAULT_PROXY, NULL, NULL, 0);
    if (session)
    {
        WinHttpSetTimeouts(session, 5000, 5000, 15000, 120000);
        connect = WinHttpConnect(session, host, parts.nPort, 0);
    }
    if (connect)
        request = WinHttpOpenRequest(connect, method, fullPath, NULL, NULL, NULL,
                                     parts.nScheme == INTERNET_SCHEME_HTTPS ? WINHTTP_FLAG_SECURE : 0);
    if (request && WinHttpSendRequest(request, NULL, 0, (void *)body, bodySize, bodySize, 0) && WinHttpReceiveResponse(request, NULL))
    {
        DWORD available;

        WinHttpQueryHeaders(request, WINHTTP_QUERY_STATUS_CODE | WINHTTP_QUERY_FLAG_NUMBER, NULL, &status, &size, NULL);
        while (WinHttpQueryDataAvailable(request, &available) && available)
        {
            DWORD read = 0;

            reply = realloc(reply, replySize + available + 1);
            if (!WinHttpReadData(request, reply + replySize, available, &read))
                break;
            replySize += read;
        }
        if (!reply)
            reply = calloc(1, 1);
        reply[replySize] = 0;
    }

    if (request)
        WinHttpCloseHandle(request);
    if (connect)
        WinHttpCloseHandle(connect);
    if (session)
        WinHttpCloseHandle(session);

    if (!reply)
    {
        snprintf(sStatus, sizeof(sStatus), "no_server");
        return NULL;
    }
    if (status != 200)
    {
        // The server explains in the body.
        snprintf(sStatus, sizeof(sStatus), "%.120s", reply);
        free(reply);
        return NULL;
    }
    snprintf(sStatus, sizeof(sStatus), "ok");
    return reply;
}

int Online_Submit(const char *replayPath)
{
    FILE *file = fopen(replayPath, "rb");
    char query[128];
    char *reply;
    uint8_t *data;
    long size;
    int i, j = 0;

    if (!file)
    {
        snprintf(sStatus, sizeof(sStatus), "no_replay");
        return 0;
    }
    fseek(file, 0, SEEK_END);
    size = ftell(file);
    fseek(file, 0, SEEK_SET);
    data = malloc(size);
    if (fread(data, 1, size, file) != (size_t)size)
    {
        free(data);
        fclose(file);
        return 0;
    }
    fclose(file);

    j = snprintf(query, sizeof(query), "/submit?name=");
    for (i = 0; sName[i] && j < (int)sizeof(query) - 4; i++)
    {
        unsigned char c = sName[i];

        if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '_' || c == '-')
            query[j++] = c;
        else
            j += snprintf(query + j, 4, "%%%02X", c);
    }
    query[j] = 0;

    reply = Request(L"POST", query, data, size);
    free(data);
    if (!reply)
        return 0;
    free(reply);
    return 1;
}

// One entry per line: name|field|score|verified
int Online_Fetch(struct LeaderboardEntry *entries, int max)
{
    char *reply = Request(L"GET", "/top", NULL, 0);
    char *line, *next;
    int count = 0;

    if (!reply)
        return 0;
    for (line = reply; line && *line && count < max; line = next)
    {
        char *fields[4];
        int i;

        next = strchr(line, '\n');
        if (next)
            *next++ = 0;
        fields[0] = line;
        for (i = 1; i < 4; i++)
        {
            fields[i] = strchr(fields[i - 1], '|');
            if (!fields[i])
                break;
            *fields[i]++ = 0;
        }
        if (i < 4)
            continue;
        snprintf(entries[count].name, sizeof(entries[count].name), "%s", fields[0]);
        snprintf(entries[count].field, sizeof(entries[count].field), "%s", fields[1]);
        snprintf(entries[count].score, sizeof(entries[count].score), "%s", fields[2]);
        snprintf(entries[count].verified, sizeof(entries[count].verified), "%s", fields[3]);
        count++;
    }
    free(reply);
    return count;
}
