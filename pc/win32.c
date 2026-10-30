// Windows side of the native build: GBA memory map, window, sound output, frame
// timing and the save file. The game runs on its own thread (AgbMain never
// returns), the display on another (pc/video.c); this thread keeps the window
// responsive.

#include "pc.h"
#include <mmsystem.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define WINDOW_SCALE 3

HWND gWindow;
LARGE_INTEGER gInputTime;
static int sFullscreen;
static WINDOWPLACEMENT sWindowPlacement = {sizeof(WINDOWPLACEMENT)};

static char sSavePath[MAX_PATH];
static uint8_t sSavedSram[GBA_SRAM_SIZE];
static CRITICAL_SECTION sSaveLock;
static volatile LONG sSramGuard;

static LARGE_INTEGER sTimerFrequency;
static LARGE_INTEGER sNextFrame;
static unsigned sFrameCount;
static volatile LONG sPauseReasons;
static HANDLE sResumeEvent;

// Commands from this thread to the game
#define MAX_COMMANDS 8
static CRITICAL_SECTION sCommandLock;
static struct HostCommand sCommands[MAX_COMMANDS];
static int sNumCommands;
static HANDLE sCommandDone;
static volatile LONG sQuitting;
static volatile LONG sStartMenu;

// Test mode, from environment variables:
//   PINBALL_INPUT=frame:keys,...  holds keys (A B SELECT START RIGHT LEFT UP DOWN R L,
//                                 joined with +) from that frame to the next entry
//   PINBALL_DUMP=dir              saves what is on screen as dir/frame_NNNNN.bmp ...
//   PINBALL_DUMP_FRAMES=n,...     ... these ones (all of them if not set)
//   PINBALL_EXIT_FRAME=n          quits after frame n
//   PINBALL_TURBO=1               doesn't wait between frames
//   PINBALL_NOAUDIO=1             no sound output
//   PINBALL_WAV=file              records the sound to a .wav file
//   PINBALL_HIDDEN=1              no window on screen
//   PINBALL_WINDOW=WxH            size of the picture
//   PINBALL_DIR=dir               where the save, settings, states and replays go
//   PINBALL_SYNC=1                the game waits for each frame to be drawn
//   PINBALL_ALPHA=n               interpolate always at n/256
//   PINBALL_GDI=1, PINBALL_WARP=1 force the slower ways of drawing
//   PINBALL_CMD=frame:cmd,...     does what the menu does: save, load, reboot,
//                                 train-FIELD-MODE, replay-FILE, lang-N, vk-CODE,
//                                 ball/X/Y/VX/VY/LAYER
//   PINBALL_SET=name=value,...    overrides settings
//   PINBALL_VERIFY=file           plays a replay as fast as possible, prints the
//                                 result as JSON and quits
//   PINBALL_REFRESH=n             draws as if the monitor ran at n Hz
//   PINBALL_STATS=1               prints pictures, frame rate and latency on exit
//   PINBALL_UI_CHECK=1            logs the lines of the menu that don't fit
//   PINBALL_TRACE=file            writes the ball and the board state of every
//                                 frame to a CSV file
static const char *sTestInput;
static const char *sDumpDir;
static const char *sDumpFrames;
static const char *sTestCommands;
static unsigned sExitFrame;
static int sTurbo;
static FILE *sWavFile;
static FILE *sTraceFile;
static uint32_t sWavFrames;
static char sDataDir[MAX_PATH];

// Sound output
#define AUDIO_BUFFERS 32
static HWAVEOUT sWaveOut;
static WAVEHDR sWaveHeaders[AUDIO_BUFFERS];
static int16_t sWaveData[AUDIO_BUFFERS][4096 * 2];
static int sNextWaveHeader;

void Host_Log(const char *fmt, ...)
{
    char buffer[1024];
    va_list args;

    va_start(args, fmt);
    vsnprintf(buffer, sizeof(buffer), fmt, args);
    va_end(args);
    OutputDebugStringA(buffer);
    fputs(buffer, stderr);
}

void Host_Fatal(const char *fmt, ...)
{
    char buffer[1024];
    va_list args;

    va_start(args, fmt);
    vsnprintf(buffer, sizeof(buffer), fmt, args);
    va_end(args);
    fputs(buffer, stderr);
    if (!getenv("PINBALL_EXIT_FRAME") && !getenv("PINBALL_VERIFY"))
        MessageBoxA(NULL, buffer, "Pokemon Pinball R/S", MB_ICONERROR);
    ExitProcess(1);
}

void Host_Memcpy(void *dest, const void *src, size_t size)
{
    memcpy(dest, src, size);
}

void *Host_Alloc(size_t size)
{
    void *memory = malloc(size);

    if (!memory)
        Host_Fatal("Out of memory");
    return memory;
}

// Files the program keeps next to itself (or in PINBALL_DIR).
void Host_UserFile(char *path, const char *name)
{
    if (sDataDir[0])
    {
        snprintf(path, MAX_PATH, "%s\\%s", sDataDir, name);
    }
    else
    {
        char *slash;

        GetModuleFileNameA(NULL, path, MAX_PATH - 32);
        slash = strrchr(path, '\\');
        if (slash)
            slash[1] = 0;
        strncat(path, name, MAX_PATH - strlen(path) - 1);
    }
}

static void UpdateKeyInput(void)
{
    GBA_IO16(0x130) = ~Input_GbaKeys() & 0x3FF;
}

// Called by the game right before it reads the keys.
void Host_PollInput(void)
{
    Input_Poll();
    UpdateKeyInput();
}

int Host_IsPaused(void)
{
    return sPauseReasons != 0;
}

static void TestStep(void);

void Host_PauseWait(void)
{
    WaitForSingleObject(sResumeEvent, 20);
    Input_Poll();
    UpdateKeyInput();
    // A test goes on while the menu has the game paused.
    if (sTestCommands)
        TestStep();
    QueryPerformanceCounter(&sNextFrame);
}

void Host_SetPaused(int reason, int on)
{
    if (on)
    {
        InterlockedOr(&sPauseReasons, reason);
        Input_StopRumble();
    }
    else
    {
        InterlockedAnd(&sPauseReasons, ~reason);
        SetEvent(sResumeEvent);
    }
}

void Host_PostCommand(const struct HostCommand *command)
{
    EnterCriticalSection(&sCommandLock);
    if (sNumCommands < MAX_COMMANDS)
        sCommands[sNumCommands++] = *command;
    LeaveCriticalSection(&sCommandLock);
    SetEvent(sResumeEvent);
}

int Host_NextCommand(struct HostCommand *command)
{
    int found = 0;

    EnterCriticalSection(&sCommandLock);
    if (sNumCommands)
    {
        *command = sCommands[0];
        memmove(&sCommands[0], &sCommands[1], (--sNumCommands) * sizeof(sCommands[0]));
        found = 1;
    }
    else
    {
        SetEvent(sCommandDone);
    }
    LeaveCriticalSection(&sCommandLock);
    return found;
}

void Host_Trace(uint32_t frame, int x, int y, int vx, int vy, int lives, int saver, int state, int layer, int subState, int species, int target)
{
    if (sTraceFile)
        fprintf(sTraceFile, "%u,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n", (unsigned)frame, x, y, vx, vy, lives, saver, state, layer, subState, species, target);
}

// The first time the game reaches its main loop.
void Host_GameReady(void)
{
    if (InterlockedExchange(&sStartMenu, 0))
        Ui_OpenMenu();
}

void Host_Rumble(int pattern)
{
    Input_RumblePattern(pattern);
}

void Host_Toast(const char *text)
{
    static const struct { const char *code; const wchar_t *it, *en; } messages[] = {
        {"state_bad", L"Salvataggio non valido", L"Invalid save state"},
        {"state_old", L"Salvataggio di un'altra versione", L"Save state from another build"},
        {"replay_ok", L"Replay finito: identico alla partita", L"Replay finished: same as the game"},
        {"replay_diverged", L"Replay finito: diverso dalla partita", L"Replay finished: it went differently"},
    };
    unsigned i;

    for (i = 0; i < sizeof(messages) / sizeof(messages[0]); i++)
    {
        if (strcmp(messages[i].code, text) == 0)
            Ui_ToastW(Video_LatestInfo()->language == 3 ? messages[i].it : messages[i].en);
    }
}

static LONG ParseKeys(const char *s, const char *end)
{
    static const struct { const char *name; LONG key; } names[] = {
        {"A", 1 << ACTION_A}, {"B", 1 << ACTION_B}, {"SELECT", 1 << ACTION_SELECT}, {"START", 1 << ACTION_START},
        {"RIGHT", 1 << ACTION_RIGHT}, {"LEFT", 1 << ACTION_LEFT}, {"UP", 1 << ACTION_UP}, {"DOWN", 1 << ACTION_DOWN},
        {"R", 1 << ACTION_R}, {"L", 1 << ACTION_L},
    };
    LONG keys = 0;

    while (s < end)
    {
        const char *next = s;
        unsigned i;

        while (next < end && *next != '+')
            next++;
        for (i = 0; i < sizeof(names) / sizeof(names[0]); i++)
        {
            if ((size_t)(next - s) == strlen(names[i].name) && strncmp(s, names[i].name, next - s) == 0)
                keys |= names[i].key;
        }
        s = next + 1;
    }
    return keys;
}

// The entries are in frame order: sTestInput advances past the used ones.
static void RunTestInput(void)
{
    while (sTestInput && *sTestInput)
    {
        char *colon;
        unsigned frame = strtoul(sTestInput, &colon, 10);
        const char *end;

        if (*colon != ':' || frame > sFrameCount)
            break;
        end = strchr(colon, ',');
        if (!end)
            end = colon + strlen(colon);
        Input_SetScriptKeys(ParseKeys(colon + 1, end));
        sTestInput = *end ? end + 1 : end;
    }
}

static void RunTestCommand(const char *text)
{
    struct HostCommand command;

    memset(&command, 0, sizeof(command));
    if (strcmp(text, "save") == 0)
    {
        command.type = CMD_SAVE_STATE;
        command.a = STATE_SLOT_QUICK;
    }
    else if (strcmp(text, "load") == 0)
    {
        command.type = CMD_LOAD_STATE;
        command.a = STATE_SLOT_QUICK;
    }
    else if (strncmp(text, "ball/", 5) == 0)
    {
        command.type = CMD_PLACE_BALL;
        sscanf(text + 5, "%d/%d/%d/%d/%d", &command.a, &command.b, &command.c, &command.d, &command.e);
    }
    else if (strcmp(text, "close") == 0)
    {
        PostMessageA(gWindow, WM_CLOSE, 0, 0);
        return;
    }
    else if (strcmp(text, "reboot") == 0)
    {
        command.type = CMD_REBOOT;
    }
    else if (strncmp(text, "train-", 6) == 0)
    {
        int field = 0, mode = 0;

        sscanf(text + 6, "%d-%d", &field, &mode);
        command.type = CMD_TRAINING;
        command.a = field;
        command.b = mode;
    }
    else if (strncmp(text, "replay-", 7) == 0)
    {
        command.type = CMD_PLAY_REPLAY;
        strncpy(command.path, text + 7, sizeof(command.path) - 1);
    }
    else if (strncmp(text, "lang-", 5) == 0)
    {
        command.type = CMD_SET_LANGUAGE;
        command.a = atoi(text + 5);
    }
    else if (strncmp(text, "vk-", 3) == 0)
    {
        int vk = atoi(text + 3);

        PostMessageA(gWindow, WM_KEYDOWN, vk, 0);
        PostMessageA(gWindow, WM_KEYUP, vk, 0);
        return;
    }
    else
    {
        return;
    }
    Host_PostCommand(&command);
}

static void RunTestCommands(void)
{
    while (sTestCommands && *sTestCommands)
    {
        char *colon;
        char text[300];
        unsigned frame = strtoul(sTestCommands, &colon, 10);
        const char *end;
        size_t length;

        if (*colon != ':' || frame > sFrameCount)
            break;
        end = strchr(colon, ',');
        if (!end)
            end = colon + strlen(colon);
        length = end - colon - 1;
        if (length >= sizeof(text))
            length = sizeof(text) - 1;
        memcpy(text, colon + 1, length);
        text[length] = 0;
        RunTestCommand(text);
        sTestCommands = *end ? end + 1 : end;
    }
}

static int IsListedFrame(const char *list, unsigned frame)
{
    while (list && *list)
    {
        char *end;
        if (strtoul(list, &end, 10) == frame)
            return 1;
        list = *end ? end + 1 : end;
    }
    return 0;
}

static void WriteWavHeader(void)
{
    uint32_t header[11] = {
        0x46464952, 36 + sWavFrames * 4, 0x45564157, 0x20746D66, 16,
        1 | (2 << 16), HOST_AUDIO_RATE, HOST_AUDIO_RATE * 4, 4 | (16 << 16),
        0x61746164, sWavFrames * 4,
    };

    fseek(sWavFile, 0, SEEK_SET);
    fwrite(header, sizeof(header), 1, sWavFile);
    fseek(sWavFile, 0, SEEK_END);
}

static void StartWav(const char *path)
{
    sWavFile = fopen(path, "wb");
    if (sWavFile)
        WriteWavHeader();
}

static void FinishWav(void)
{
    if (sWavFile)
    {
        WriteWavHeader();
        fclose(sWavFile);
        sWavFile = NULL;
    }
}

int Host_IsFullscreen(void)
{
    return sFullscreen;
}

// Fits the window to the view: tall for the whole table, wider with panels.
void Host_ApplyWindowSize(void)
{
    MONITORINFO monitor = {sizeof(monitor)};
    int columns = gPcOptions.view == VIEW_TABLE ? TABLE_WIDTH : GBA_SCREEN_WIDTH;
    int lines = gPcOptions.view == VIEW_TABLE ? 436 : GBA_SCREEN_HEIGHT;
    int scale, panelWidth;
    RECT rect, window;

    if (sFullscreen)
        return;
    GetMonitorInfoA(MonitorFromWindow(gWindow, MONITOR_DEFAULTTOPRIMARY), &monitor);
    scale = (monitor.rcWork.bottom - monitor.rcWork.top - 64) / lines;
    if (scale < 1)
        scale = 1;
    if (gPcOptions.view != VIEW_TABLE && scale > WINDOW_SCALE)
        scale = WINDOW_SCALE;
    panelWidth = gPcOptions.panels ? (lines * scale) * 2 / 5 : 0;
    SetRect(&rect, 0, 0, columns * scale + panelWidth * 2, lines * scale);
    AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);
    GetWindowRect(gWindow, &window);
    SetWindowPos(gWindow, NULL, window.left, monitor.rcWork.top, rect.right - rect.left, rect.bottom - rect.top,
                 SWP_NOZORDER | SWP_NOOWNERZORDER);
}

void Host_ToggleFullscreen(void)
{
    LONG style = GetWindowLongA(gWindow, GWL_STYLE);

    if (!sFullscreen)
    {
        MONITORINFO monitor = {sizeof(monitor)};

        GetWindowPlacement(gWindow, &sWindowPlacement);
        GetMonitorInfoA(MonitorFromWindow(gWindow, MONITOR_DEFAULTTOPRIMARY), &monitor);
        SetWindowLongA(gWindow, GWL_STYLE, style & ~WS_OVERLAPPEDWINDOW);
        SetWindowPos(gWindow, HWND_TOP, monitor.rcMonitor.left, monitor.rcMonitor.top,
                     monitor.rcMonitor.right - monitor.rcMonitor.left,
                     monitor.rcMonitor.bottom - monitor.rcMonitor.top,
                     SWP_NOOWNERZORDER | SWP_FRAMECHANGED);
        sFullscreen = 1;
    }
    else
    {
        SetWindowLongA(gWindow, GWL_STYLE, style | WS_OVERLAPPEDWINDOW);
        SetWindowPlacement(gWindow, &sWindowPlacement);
        SetWindowPos(gWindow, NULL, 0, 0, 0, 0,
                     SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_NOOWNERZORDER | SWP_FRAMECHANGED);
        sFullscreen = 0;
    }
}

void Host_SetSramGuard(int on)
{
    EnterCriticalSection(&sSaveLock);
    if (!on)
        memcpy((void *)GBA_SRAM, sSavedSram, GBA_SRAM_SIZE);
    InterlockedExchange(&sSramGuard, on);
    LeaveCriticalSection(&sSaveLock);
}

static void SaveSram(void)
{
    FILE *file;

    EnterCriticalSection(&sSaveLock);
    if (!sSramGuard && memcmp(sSavedSram, (const void *)GBA_SRAM, GBA_SRAM_SIZE) != 0)
    {
        memcpy(sSavedSram, (const void *)GBA_SRAM, GBA_SRAM_SIZE);
        file = fopen(sSavePath, "wb");
        if (file)
        {
            fwrite(sSavedSram, 1, GBA_SRAM_SIZE, file);
            fclose(file);
        }
        else
        {
            Host_Log("Can't write %s\n", sSavePath);
        }
    }
    LeaveCriticalSection(&sSaveLock);
}

void Host_SaveSramNow(void)
{
    SaveSram();
}

static void LoadSram(void)
{
    FILE *file;

    Host_UserFile(sSavePath, "pokepinballrs_pc.sav");

    // Erased SRAM reads as 0xFF.
    memset((void *)GBA_SRAM, 0xFF, GBA_SRAM_SIZE);
    file = fopen(sSavePath, "rb");
    if (file)
    {
        fread((void *)GBA_SRAM, 1, GBA_SRAM_SIZE, file);
        fclose(file);
    }
    memcpy(sSavedSram, (const void *)GBA_SRAM, GBA_SRAM_SIZE);
}

// Puts the game away and leaves. With a game on the table, the game saves
// itself first: it does so at the top of its main loop.
void Host_RequestQuit(void)
{
    if (sQuitting)
        return;
    InterlockedExchange(&sQuitting, 1);
    if (gPcOptions.autoSuspend && Video_LatestInfo()->inGame)
    {
        struct HostCommand command;

        memset(&command, 0, sizeof(command));
        command.type = CMD_SAVE_STATE;
        command.a = STATE_SLOT_AUTO;
        ResetEvent(sCommandDone);
        Host_SetPaused(PAUSE_MENU, 0);
        Host_PostCommand(&command);
        WaitForSingleObject(sCommandDone, 1000);
    }
    Input_StopRumble();
    SaveSram();
    Settings_Save();
    Stats_Save();
    Video_Stop();
    Video_PrintStats();
    if (sTraceFile)
        fclose(sTraceFile);
    ExitProcess(0);
}

static int ActionForKey(int vk, int action)
{
    return gBindings.keys[action][0] == vk || gBindings.keys[action][1] == vk;
}

static void QuickState(int type)
{
    struct HostCommand command;

    memset(&command, 0, sizeof(command));
    command.type = type;
    command.a = STATE_SLOT_QUICK;
    Host_PostCommand(&command);
}

static LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_PAINT:
        ValidateRect(hwnd, NULL);
        return 0;
    case WM_ERASEBKGND:
        return 1;
    case WM_SIZE:
        Video_Resize(LOWORD(lParam), HIWORD(lParam));
        return 0;
    case WM_SYSKEYDOWN:
        if (wParam == VK_RETURN)
        {
            Host_ToggleFullscreen();
            return 0;
        }
        break;
    case WM_KEYDOWN:
    {
        int vk = (int)wParam;

        if (vk == VK_SHIFT)
            vk = MapVirtualKeyA((lParam >> 16) & 0xFF, MAPVK_VSC_TO_VK_EX);
        if (vk == VK_F11)
        {
            Host_ToggleFullscreen();
            return 0;
        }
        if (Ui_MenuOpen())
        {
            Ui_MenuKey(vk);
            return 0;
        }
        if (!(lParam & 0x40000000))
        {
            if (ActionForKey(vk, ACTION_MENU))
            {
                Ui_OpenMenu();
                return 0;
            }
            if (ActionForKey(vk, ACTION_QUICK_SAVE))
                QuickState(CMD_SAVE_STATE);
            if (ActionForKey(vk, ACTION_QUICK_LOAD))
                QuickState(CMD_LOAD_STATE);
            if (ActionForKey(vk, ACTION_DEBUG))
                gPcOptions.debugOverlay = !gPcOptions.debugOverlay;
        }
        Input_KeyEvent(vk, 1);
        UpdateKeyInput();
        return 0;
    }
    case WM_KEYUP:
    {
        int vk = (int)wParam;

        if (vk == VK_SHIFT)
        {
            // Releasing one shift key reports only VK_SHIFT: check both.
            if (!(GetKeyState(VK_LSHIFT) & 0x8000))
                Input_KeyEvent(VK_LSHIFT, 0);
            if (!(GetKeyState(VK_RSHIFT) & 0x8000))
                Input_KeyEvent(VK_RSHIFT, 0);
        }
        Input_KeyEvent(vk, 0);
        UpdateKeyInput();
        return 0;
    }
    case WM_KILLFOCUS:
        Input_ReleaseKeys();
        UpdateKeyInput();
        return 0;
    case WM_CLOSE:
        Host_RequestQuit();
        return 0;
    }
    return DefWindowProcW(hwnd, msg, wParam, lParam);
}

int Host_FastForward(void)
{
    return Input_FastForward() || Replay_IsVerifying();
}

static void TestStep(void)
{
    if (sDumpDir && (!sDumpFrames || IsListedFrame(sDumpFrames, sFrameCount)))
    {
        char path[MAX_PATH];

        snprintf(path, sizeof(path), "%s\\frame_%05u.bmp", sDumpDir, sFrameCount);
        Video_DumpNext(path);
    }
    if (sExitFrame && sFrameCount >= sExitFrame)
    {
        FinishWav();
        if (sTraceFile)
            fclose(sTraceFile);
        Video_PrintStats();
        SaveSram();
        Settings_Save();
        ExitProcess(0);
    }

    ++sFrameCount;
    RunTestInput();
    RunTestCommands();
}

void Host_WaitFrame(void)
{
    LARGE_INTEGER now;
    LONGLONG period = (LONGLONG)(sTimerFrequency.QuadPart / GBA_FRAME_RATE);
    int fast = Host_FastForward() || sTurbo;

    TestStep();

    if (sFrameCount % 60 == 0)
        SaveSram();

    QueryPerformanceCounter(&now);
    if (fast)
    {
        sNextFrame = now;
    }
    else
    {
        sNextFrame.QuadPart += period;
        if (now.QuadPart > sNextFrame.QuadPart + period * 4)
        {
            // Too far behind (a stall or a breakpoint): don't try to catch up.
            sNextFrame = now;
        }
        else
        {
            for (;;)
            {
                LONGLONG remaining;

                QueryPerformanceCounter(&now);
                remaining = sNextFrame.QuadPart - now.QuadPart;
                if (remaining <= 0)
                    break;
                if (remaining * 1000 / sTimerFrequency.QuadPart > 2)
                    Sleep(1);
                else
                    YieldProcessor();
            }
        }
    }

    // After the wait, so the game gets the freshest keys.
    Input_Poll();
    UpdateKeyInput();
    QueryPerformanceCounter(&gInputTime);
}

static void OpenAudio(void)
{
    WAVEFORMATEX format;
    int i;

    if (getenv("PINBALL_NOAUDIO") || getenv("PINBALL_VERIFY"))
        return;
    memset(&format, 0, sizeof(format));
    format.wFormatTag = WAVE_FORMAT_PCM;
    format.nChannels = 2;
    format.nSamplesPerSec = HOST_AUDIO_RATE;
    format.wBitsPerSample = 16;
    format.nBlockAlign = 4;
    format.nAvgBytesPerSec = HOST_AUDIO_RATE * 4;
    if (waveOutOpen(&sWaveOut, WAVE_MAPPER, &format, 0, 0, CALLBACK_NULL) != MMSYSERR_NOERROR)
    {
        Host_Log("No sound output\n");
        sWaveOut = NULL;
        return;
    }
    for (i = 0; i < AUDIO_BUFFERS; i++)
    {
        sWaveHeaders[i].lpData = (LPSTR)sWaveData[i];
        sWaveHeaders[i].dwFlags = WHDR_DONE;
    }
}

uint32_t Host_AudioQueued(void)
{
    uint32_t queued = 0;
    int i;

    if (!sWaveOut)
        return 0;
    for (i = 0; i < AUDIO_BUFFERS; i++)
    {
        if (!(sWaveHeaders[i].dwFlags & WHDR_DONE))
            queued += sWaveHeaders[i].dwBufferLength / 4;
    }
    return queued;
}

static void QueueAudio(const int16_t *samples, uint32_t frames)
{
    WAVEHDR *header = &sWaveHeaders[sNextWaveHeader];

    if (frames > 4096)
        frames = 4096;
    if (!(header->dwFlags & WHDR_DONE))
        return;
    if (header->dwFlags & WHDR_PREPARED)
        waveOutUnprepareHeader(sWaveOut, header, sizeof(*header));

    if (samples)
        memcpy(header->lpData, samples, frames * 4);
    else
        memset(header->lpData, 0, frames * 4);
    header->dwBufferLength = frames * 4;
    header->dwFlags = 0;
    waveOutPrepareHeader(sWaveOut, header, sizeof(*header));
    waveOutWrite(sWaveOut, header, sizeof(*header));
    sNextWaveHeader = (sNextWaveHeader + 1) % AUDIO_BUFFERS;
}

void Host_AudioWrite(const int16_t *samples, uint32_t frames)
{
    if (sWavFile)
    {
        fwrite(samples, 4, frames, sWavFile);
        sWavFrames += frames;
    }

    if (!sWaveOut || frames == 0)
        return;

    // At the start, and after a stall, put some silence before the sound so
    // that the next frames arrive before it runs out.
    if (Host_AudioQueued() == 0)
        QueueAudio(NULL, HOST_AUDIO_RATE / 25);
    QueueAudio(samples, frames);
}

// The GBA memory is the first section of the image (pc/pc.mk): check that the
// image was loaded where the link put it.
static void CheckGbaMemory(void)
{
    MEMORY_BASIC_INFORMATION mbi;

    if (!VirtualQuery((void *)GBA_EWRAM, &mbi, sizeof(mbi)) || mbi.AllocationBase != (void *)GetModuleHandleA(NULL))
        Host_Fatal("The GBA memory isn't at %08X", GBA_EWRAM);
}

// Length of a div/idiv instruction (F6 or F7 /6 or /7), 0 if it isn't one.
static int DivideInstructionLength(const uint8_t *p, int *byteSized, int *wordSized)
{
    const uint8_t *start = p;
    uint8_t modrm;
    int mod, rm;

    *wordSized = 0;
    while (*p == 0x66 || *p == 0x26 || *p == 0x2E || *p == 0x36 || *p == 0x3E || *p == 0x64 || *p == 0x65)
    {
        if (*p == 0x66)
            *wordSized = 1;
        p++;
    }
    if (*p != 0xF6 && *p != 0xF7)
        return 0;
    *byteSized = *p == 0xF6;
    modrm = p[1];
    if (((modrm >> 3) & 7) < 6)
        return 0;
    p += 2;
    mod = modrm >> 6;
    rm = modrm & 7;
    if (mod != 3)
    {
        if (rm == 4)
        {
            if (mod == 0 && (*p & 7) == 5)
                p += 4;
            p++;
        }
        else if (mod == 0 && rm == 5)
        {
            p += 4;
        }
        if (mod == 1)
            p += 1;
        else if (mod == 2)
            p += 4;
    }
    return p - start;
}

// The GBA divides with libgcc's __divsi3/__modsi3, which give 0 for a
// division by zero; some of the game's divisions do divide by zero.
static LONG WINAPI DivideHandler(EXCEPTION_POINTERS *info)
{
    DWORD code = info->ExceptionRecord->ExceptionCode;
    CONTEXT *context = info->ContextRecord;
    int byteSized, wordSized, length;

    if (code != EXCEPTION_INT_DIVIDE_BY_ZERO && code != EXCEPTION_INT_OVERFLOW)
        return EXCEPTION_CONTINUE_SEARCH;
    length = DivideInstructionLength((const uint8_t *)context->Eip, &byteSized, &wordSized);
    if (length == 0)
        return EXCEPTION_CONTINUE_SEARCH;

    if (byteSized)
    {
        context->Eax &= ~0xFFFF;
    }
    else if (wordSized)
    {
        if (code == EXCEPTION_INT_DIVIDE_BY_ZERO)
            context->Eax &= ~0xFFFF;
        context->Edx &= ~0xFFFF;
    }
    else
    {
        // INT_MIN / -1 leaves INT_MIN in eax.
        if (code == EXCEPTION_INT_DIVIDE_BY_ZERO)
            context->Eax = 0;
        context->Edx = 0;
    }
    context->Eip += length;
    return EXCEPTION_CONTINUE_EXECUTION;
}

static LONG WINAPI CrashHandler(EXCEPTION_POINTERS *info)
{
    EXCEPTION_RECORD *record = info->ExceptionRecord;

    if (record->ExceptionCode == EXCEPTION_ACCESS_VIOLATION)
        Host_Fatal("Crash at %08lX: %s %08lX", (unsigned long)(uintptr_t)record->ExceptionAddress,
                   record->ExceptionInformation[0] ? "write to" : "read from",
                   (unsigned long)record->ExceptionInformation[1]);
    else
        Host_Fatal("Crash at %08lX: exception %08lX", (unsigned long)(uintptr_t)record->ExceptionAddress,
                   (unsigned long)record->ExceptionCode);
    return EXCEPTION_EXECUTE_HANDLER;
}

static DWORD WINAPI GameThread(LPVOID param)
{
    (void)param;
    QueryPerformanceCounter(&sNextFrame);
    AgbMain();
    return 0;
}

static void ApplyTestSettings(void)
{
    const char *list = getenv("PINBALL_SET");
    static const struct { const char *name; int32_t *value; } names[] = {
        {"view", &gPcOptions.view}, {"panels", &gPcOptions.panels}, {"interpolate", &gPcOptions.interpolate},
        {"scale", &gPcOptions.internalScale}, {"scale_mode", &gPcOptions.scaleMode}, {"filter", &gPcOptions.filter},
        {"vsync", &gPcOptions.vsync}, {"fps", &gPcOptions.showFps}, {"debug", &gPcOptions.debugOverlay},
        {"collision", &gPcOptions.debugCollision}, {"low_latency", &gPcOptions.lowLatency},
        {"rumble", &gPcOptions.rumble}, {"pokedex_speed", &gPcOptions.pokedexSpeed},
        {"vanilla", &gPcOptions.game.vanilla}, {"ball_saver", &gPcOptions.game.ballSaver},
        {"infinite_balls", &gPcOptions.game.infiniteBalls}, {"fixes", &gPcOptions.game.fixes},
        {"auto_suspend", &gPcOptions.autoSuspend},
    };

    while (list && *list)
    {
        const char *comma = strchr(list, ',');
        size_t length = comma ? (size_t)(comma - list) : strlen(list);
        unsigned i;

        for (i = 0; i < sizeof(names) / sizeof(names[0]); i++)
        {
            size_t n = strlen(names[i].name);

            if (n < length && strncmp(list, names[i].name, n) == 0 && list[n] == '=')
                *names[i].value = atoi(list + n + 1);
        }
        list += length + (comma ? 1 : 0);
    }
}

int WINAPI WinMain(HINSTANCE instance, HINSTANCE prevInstance, LPSTR cmdLine, int showCmd)
{
    WNDCLASSW wc;
    RECT rect = {0, 0, GBA_SCREEN_WIDTH * WINDOW_SCALE, GBA_SCREEN_HEIGHT * WINDOW_SCALE};
    MSG msg;
    const char *size = getenv("PINBALL_WINDOW");

    (void)prevInstance;
    (void)cmdLine;

    AddVectoredExceptionHandler(1, DivideHandler);
    SetUnhandledExceptionFilter(CrashHandler);
    sTestInput = getenv("PINBALL_INPUT");
    sTestCommands = getenv("PINBALL_CMD");
    sDumpDir = getenv("PINBALL_DUMP");
    sDumpFrames = getenv("PINBALL_DUMP_FRAMES");
    if (getenv("PINBALL_EXIT_FRAME"))
        sExitFrame = strtoul(getenv("PINBALL_EXIT_FRAME"), NULL, 10);
    sTurbo = getenv("PINBALL_TURBO") != NULL;
    if (getenv("PINBALL_WAV"))
        StartWav(getenv("PINBALL_WAV"));
    if (getenv("PINBALL_TRACE"))
    {
        sTraceFile = fopen(getenv("PINBALL_TRACE"), "w");
        if (sTraceFile)
            fprintf(sTraceFile, "frame,x,y,vx,vy,lives,saver,state,layer,substate,species,target\n");
    }
    if (getenv("PINBALL_DIR"))
    {
        strncpy(sDataDir, getenv("PINBALL_DIR"), sizeof(sDataDir) - 1);
        CreateDirectoryA(sDataDir, NULL);
    }
    CheckGbaMemory();
    InitializeCriticalSection(&sSaveLock);
    InitializeCriticalSection(&sCommandLock);
    sResumeEvent = CreateEventA(NULL, FALSE, FALSE, NULL);
    sCommandDone = CreateEventA(NULL, FALSE, FALSE, NULL);
    LoadSram();
    GBA_IO16(0x130) = 0x3FF;

    QueryPerformanceFrequency(&sTimerFrequency);
    timeBeginPeriod(1);
    Settings_Load();
    ApplyTestSettings();
    Input_Init();
    Stats_Init();
    Replay_Init();
    Online_Init();
    OpenAudio();

    memset(&wc, 0, sizeof(wc));
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = instance;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hIcon = LoadIcon(instance, MAKEINTRESOURCE(1));
    wc.lpszClassName = L"PokePinballRS";
    RegisterClassW(&wc);

    if (size)
        sscanf(size, "%ldx%ld", &rect.right, &rect.bottom);
    AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);
    gWindow = CreateWindowW(L"PokePinballRS", L"Pokémon Pinball R/S", WS_OVERLAPPEDWINDOW,
                            CW_USEDEFAULT, CW_USEDEFAULT, rect.right - rect.left, rect.bottom - rect.top,
                            NULL, NULL, instance, NULL);
    if (!gWindow)
        Host_Fatal("Can't create the window");

    {
        RECT client;

        Ui_Init();
        GetClientRect(gWindow, &client);
        Video_Resize(client.right, client.bottom);
        Video_Init(gWindow);
    }
    if (!getenv("PINBALL_HIDDEN"))
        ShowWindow(gWindow, showCmd);

    if (getenv("PINBALL_VERIFY"))
        Replay_InstallVerify(getenv("PINBALL_VERIFY"));

    CreateThread(NULL, 1 << 20, GameThread, NULL, 0, NULL);

    if ((gPcOptions.autoSuspend || getenv("PINBALL_AUTOMENU")) && State_Exists(STATE_SLOT_AUTO)
        && !getenv("PINBALL_EXIT_FRAME") && !getenv("PINBALL_VERIFY"))
        InterlockedExchange(&sStartMenu, 1);

    while (GetMessageW(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }
    Host_RequestQuit();
    return 0;
}
