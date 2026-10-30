#ifndef GUARD_PC_PC_H
#define GUARD_PC_PC_H

// What the files on the Win32 side of the native build share.

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "host.h"

// Actions that a key or a pad button can do.
enum Action
{
    ACTION_A, ACTION_B, ACTION_SELECT, ACTION_START,
    ACTION_RIGHT, ACTION_LEFT, ACTION_UP, ACTION_DOWN,
    ACTION_R, ACTION_L,
    NUM_GBA_ACTIONS,
    ACTION_MENU = NUM_GBA_ACTIONS,
    ACTION_FAST_FORWARD,
    ACTION_QUICK_SAVE,
    ACTION_QUICK_LOAD,
    ACTION_DEBUG,
    NUM_ACTIONS
};

#define NUM_BINDINGS 2   // alternatives per action

struct Bindings
{
    int keys[NUM_ACTIONS][NUM_BINDINGS];    // virtual keys
    int pad[NUM_ACTIONS][NUM_BINDINGS];     // PAD_ codes
};

// Pad inputs: the XInput buttons, the triggers and stick directions, and the
// buttons of pads that only have the old joystick interface.
enum
{
    PAD_NONE,
    PAD_DPAD_UP, PAD_DPAD_DOWN, PAD_DPAD_LEFT, PAD_DPAD_RIGHT,
    PAD_START, PAD_BACK, PAD_LS, PAD_RS, PAD_LB, PAD_RB,
    PAD_A, PAD_B, PAD_X, PAD_Y,
    PAD_LT, PAD_RT,
    PAD_STICK_UP, PAD_STICK_DOWN, PAD_STICK_LEFT, PAD_STICK_RIGHT,
    PAD_JOY_BUTTON_1,      // +31: buttons of a non-XInput pad
    PAD_COUNT = PAD_JOY_BUTTON_1 + 32
};

extern struct Bindings gBindings;

// win32.c
extern HWND gWindow;
extern LARGE_INTEGER gInputTime;
void Host_SaveSramNow(void);
void Host_PostCommand(const struct HostCommand *command);
void Host_RequestQuit(void);
void Host_ToggleFullscreen(void);
void Host_ExePath(char *path, const char *extension);
void Host_UserFile(char *path, const char *name);
void Host_SetPaused(int reason, int on);
void Host_ApplyWindowSize(void);
int Host_IsFullscreen(void);
#define PAUSE_MENU 1
#define PAUSE_FOCUS 2

// video.c
void Video_Init(HWND window);
void Video_Resize(int width, int height);
void Video_Stop(void);
void Video_DumpNext(const char *path);
void Video_GetFps(double *display, double *game);
double Video_Latency(void);
void Video_PrintStats(void);
const struct FrameInfo *Video_LatestInfo(void);
double Video_RefreshRate(void);
int Video_UsesD3D(void);
void Video_GameRect(int clientWidth, int clientHeight, int columns, int lines, int panelSpace, int integerScale, RECT *rect, double *scale);

// input.c
void Input_Init(void);
void Input_KeyEvent(int vk, int down);
void Input_ReleaseKeys(void);
void Input_Poll(void);
uint32_t Input_GbaKeys(void);
int Input_HeldActions(void);
int Input_FastForward(void);
void Input_RumblePattern(int pattern);
void Input_StopRumble(void);
void Input_DefaultBindings(struct Bindings *bindings);
const char *Input_KeyName(int vk);
const char *Input_PadName(int code);
int Input_CapturePad(void);
int Input_PadConnected(void);
const char *Input_PadDescription(void);
void Input_SetScriptKeys(uint32_t keys);

// settings.c
void Settings_Load(void);
void Settings_Save(void);

// ui.c
void Ui_Init(void);
void Ui_Resize(int width, int height);
void Ui_Tick(void);
int Ui_MenuOpen(void);
void Ui_OpenMenu(void);
void Ui_CloseMenu(void);
void Ui_MenuKey(int vk);
void Ui_MenuPad(int action);
void Ui_ToastW(const wchar_t *text);
int Ui_PanelSpace(int columns, int lines, int clientWidth, int clientHeight);
void Ui_SetGameRect(const RECT *rect, double scale);
const uint32_t *Ui_TakeOverlay(int *width, int *height);
void Ui_ReleaseOverlay(void);
const uint32_t *Ui_LastOverlay(int *width, int *height);

// ui_art.c: the game's font, frame and sprites
enum ArtSprite
{
    ART_HAND, ART_ARROW_LEFT, ART_ARROW_RIGHT,
    ART_TORCHIC_0, ART_TORCHIC_1, ART_TORCHIC_2, ART_TORCHIC_3, ART_TORCHIC_4,
    ART_SPRITE_COUNT
};

void Art_SetLanguage(int language);
const uint32_t *Art_MenuBackground(void);
int Art_TextWidth(const wchar_t *text);
void Art_Text(uint32_t *target, int targetWidth, int targetHeight, int x, int y, const wchar_t *text, uint32_t color, int scale);
void Art_Sprite(uint32_t *target, int targetWidth, int targetHeight, int x, int y, int sprite, int hFlip, int scale);
void Art_Frame(uint32_t *target, int targetWidth, int targetHeight, int scale);
void Art_Panel(uint32_t *target, int targetWidth, int targetHeight, int x, int y, int w, int h, int scale);
uint32_t Art_TabColor(void);

// state.c
int State_Exists(int slot);
void State_Delete(int slot);
#define STATE_SLOT_AUTO 0
#define STATE_SLOT_QUICK 1

// replay.c
void Replay_Init(void);
int Replay_ListFiles(char names[][260], int max);
const struct RunHeader *Replay_CurrentHeader(void);
void Replay_InstallVerify(const char *path);

// stats.c
struct Stats
{
    uint64_t games, frames, ballsLost, ballsSaved, catches, evolutions, bonusCleared;
    uint64_t flips, bumpers, travels;
    uint64_t bestScore[2];       // hi, lo
    uint32_t achievements;
    uint32_t caughtMax;
    uint32_t coinsMax;
    uint32_t bonusFieldsCleared; // bit per field
};

struct AchievementInfo
{
    const wchar_t *name;
    const wchar_t *description;
};

#define NUM_ACHIEVEMENTS 16

void Stats_Init(void);
const struct Stats *Stats_Get(void);
const struct AchievementInfo *Stats_Achievement(int index, int language);
void Stats_Save(void);

// online.c
struct LeaderboardEntry
{
    char name[32];
    char field[16];
    char score[32];
    char verified[8];
};

void Online_Init(void);
int Online_Submit(const char *replayPath);
int Online_Fetch(struct LeaderboardEntry *entries, int max);
const char *Online_Status(void);
const char *Online_Url(void);
void Online_SetUrl(const char *url);
void Online_SetName(const char *name);
const char *Online_Name(void);

#endif // GUARD_PC_PC_H
