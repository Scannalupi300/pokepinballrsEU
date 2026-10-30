// Keyboard, game pads and vibration. The keys held are kept here; the game
// gets them when it reads REG_KEYINPUT, as late as possible (see Host_PollInput).

#include "pc.h"
#include <mmsystem.h>
#include <stdio.h>
#include <string.h>


typedef struct
{
    WORD wButtons;
    BYTE bLeftTrigger;
    BYTE bRightTrigger;
    SHORT sThumbLX;
    SHORT sThumbLY;
    SHORT sThumbRX;
    SHORT sThumbRY;
} PadGamepad;

typedef struct
{
    DWORD dwPacketNumber;
    PadGamepad Gamepad;
} PadState;

typedef struct
{
    WORD wLeftMotorSpeed;
    WORD wRightMotorSpeed;
} PadVibration;

typedef DWORD(WINAPI *XInputGetStateFunc)(DWORD, PadState *);
typedef DWORD(WINAPI *XInputSetStateFunc)(DWORD, PadVibration *);

#define STICK_THRESHOLD 16000
#define TRIGGER_THRESHOLD 64
// A pad that isn't there is slow to ask for: look for it now and then.
#define PAD_SEARCH_INTERVAL 120

struct Bindings gBindings;

static XInputGetStateFunc sXInputGetState;
static XInputSetStateFunc sXInputSetState;
static uint8_t sKeysDown[256];
static volatile LONG sActions;        // bit per action, from the keyboard
static volatile LONG sPadActions;
static volatile LONG sScriptKeys;
static int sPadIndex = -1;
static int sJoystickId = -1;
static unsigned sPollCount;
static int sPadInputs[PAD_COUNT];
static int sCaptureBaseline[PAD_COUNT];
static char sPadName[64];

// Vibration
static int sRumbleFrames;
static WORD sRumbleLow, sRumbleHigh;
static int sRumbleOn;

void Input_DefaultBindings(struct Bindings *b)
{
    memset(b, 0, sizeof(*b));
    b->keys[ACTION_A][0] = 'X';
    b->keys[ACTION_A][1] = VK_SPACE;
    b->keys[ACTION_B][0] = 'Z';
    b->keys[ACTION_SELECT][0] = VK_BACK;
    b->keys[ACTION_START][0] = VK_RETURN;
    b->keys[ACTION_RIGHT][0] = VK_RIGHT;
    b->keys[ACTION_LEFT][0] = VK_LEFT;
    b->keys[ACTION_UP][0] = VK_UP;
    b->keys[ACTION_DOWN][0] = VK_DOWN;
    b->keys[ACTION_R][0] = 'S';
    b->keys[ACTION_R][1] = VK_RSHIFT;
    b->keys[ACTION_L][0] = 'A';
    b->keys[ACTION_L][1] = VK_LSHIFT;
    b->keys[ACTION_MENU][0] = VK_ESCAPE;
    b->keys[ACTION_MENU][1] = VK_F1;
    b->keys[ACTION_FAST_FORWARD][0] = VK_TAB;
    b->keys[ACTION_QUICK_SAVE][0] = VK_F5;
    b->keys[ACTION_QUICK_LOAD][0] = VK_F7;
    b->keys[ACTION_DEBUG][0] = VK_F3;

    b->pad[ACTION_A][0] = PAD_A;
    b->pad[ACTION_A][1] = PAD_Y;
    b->pad[ACTION_B][0] = PAD_B;
    b->pad[ACTION_B][1] = PAD_X;
    b->pad[ACTION_SELECT][0] = PAD_BACK;
    b->pad[ACTION_START][0] = PAD_START;
    b->pad[ACTION_RIGHT][0] = PAD_DPAD_RIGHT;
    b->pad[ACTION_RIGHT][1] = PAD_STICK_RIGHT;
    b->pad[ACTION_LEFT][0] = PAD_DPAD_LEFT;
    b->pad[ACTION_LEFT][1] = PAD_STICK_LEFT;
    b->pad[ACTION_UP][0] = PAD_DPAD_UP;
    b->pad[ACTION_UP][1] = PAD_STICK_UP;
    b->pad[ACTION_DOWN][0] = PAD_DPAD_DOWN;
    b->pad[ACTION_DOWN][1] = PAD_STICK_DOWN;
    b->pad[ACTION_R][0] = PAD_RB;
    b->pad[ACTION_R][1] = PAD_RT;
    b->pad[ACTION_L][0] = PAD_LB;
    b->pad[ACTION_L][1] = PAD_LT;
    b->pad[ACTION_MENU][0] = PAD_RS;
}

void Input_Init(void)
{
    static const char *const names[] = {"xinput1_4.dll", "xinput1_3.dll", "xinput9_1_0.dll"};
    unsigned i;

    for (i = 0; i < sizeof(names) / sizeof(names[0]); i++)
    {
        HMODULE module = LoadLibraryA(names[i]);
        if (module)
        {
            sXInputGetState = (XInputGetStateFunc)(void *)GetProcAddress(module, "XInputGetState");
            sXInputSetState = (XInputSetStateFunc)(void *)GetProcAddress(module, "XInputSetState");
            if (sXInputGetState)
                break;
        }
    }
}

static int ActionsForKey(int vk)
{
    int action, slot, mask = 0;

    for (action = 0; action < NUM_ACTIONS; action++)
    {
        for (slot = 0; slot < NUM_BINDINGS; slot++)
        {
            if (gBindings.keys[action][slot] == vk)
                mask |= 1 << action;
        }
    }
    return mask;
}

static void UpdateKeyboardActions(void)
{
    int vk, mask = 0;

    for (vk = 1; vk < 256; vk++)
    {
        if (sKeysDown[vk])
            mask |= ActionsForKey(vk);
    }
    InterlockedExchange(&sActions, mask);
}

void Input_KeyEvent(int vk, int down)
{
    if (vk > 0 && vk < 256)
    {
        sKeysDown[vk] = down;
        UpdateKeyboardActions();
    }
}

void Input_ReleaseKeys(void)
{
    memset(sKeysDown, 0, sizeof(sKeysDown));
    InterlockedExchange(&sActions, 0);
}

static void ReadXInput(void)
{
    PadState state;
    WORD b;
    DWORD i;

    if (!sXInputGetState)
        return;

    if (sPadIndex < 0)
    {
        if (sPollCount % PAD_SEARCH_INTERVAL != 0)
            return;
        for (i = 0; i < 4; i++)
        {
            if (sXInputGetState(i, &state) == ERROR_SUCCESS)
            {
                sPadIndex = i;
                snprintf(sPadName, sizeof(sPadName), "XInput %lu", (unsigned long)i + 1);
                break;
            }
        }
        if (sPadIndex < 0)
            return;
    }

    if (sXInputGetState(sPadIndex, &state) != ERROR_SUCCESS)
    {
        sPadIndex = -1;
        sPadName[0] = 0;
        return;
    }

    b = state.Gamepad.wButtons;
    sPadInputs[PAD_DPAD_UP] = (b & 0x0001) != 0;
    sPadInputs[PAD_DPAD_DOWN] = (b & 0x0002) != 0;
    sPadInputs[PAD_DPAD_LEFT] = (b & 0x0004) != 0;
    sPadInputs[PAD_DPAD_RIGHT] = (b & 0x0008) != 0;
    sPadInputs[PAD_START] = (b & 0x0010) != 0;
    sPadInputs[PAD_BACK] = (b & 0x0020) != 0;
    sPadInputs[PAD_LS] = (b & 0x0040) != 0;
    sPadInputs[PAD_RS] = (b & 0x0080) != 0;
    sPadInputs[PAD_LB] = (b & 0x0100) != 0;
    sPadInputs[PAD_RB] = (b & 0x0200) != 0;
    sPadInputs[PAD_A] = (b & 0x1000) != 0;
    sPadInputs[PAD_B] = (b & 0x2000) != 0;
    sPadInputs[PAD_X] = (b & 0x4000) != 0;
    sPadInputs[PAD_Y] = (b & 0x8000) != 0;
    sPadInputs[PAD_LT] = state.Gamepad.bLeftTrigger > TRIGGER_THRESHOLD;
    sPadInputs[PAD_RT] = state.Gamepad.bRightTrigger > TRIGGER_THRESHOLD;
    sPadInputs[PAD_STICK_LEFT] = state.Gamepad.sThumbLX < -STICK_THRESHOLD;
    sPadInputs[PAD_STICK_RIGHT] = state.Gamepad.sThumbLX > STICK_THRESHOLD;
    sPadInputs[PAD_STICK_UP] = state.Gamepad.sThumbLY > STICK_THRESHOLD;
    sPadInputs[PAD_STICK_DOWN] = state.Gamepad.sThumbLY < -STICK_THRESHOLD;
}

// Pads without XInput (Switch, PlayStation, older ones) through the joystick API.
static void ReadJoystick(void)
{
    JOYINFOEX info;
    JOYCAPSA caps;
    UINT i, count;
    int b;

    if (sPadIndex >= 0)
        return;

    if (sJoystickId < 0)
    {
        if (sPollCount % PAD_SEARCH_INTERVAL != 0)
            return;
        count = joyGetNumDevs();
        for (i = 0; i < count && i < 16; i++)
        {
            memset(&info, 0, sizeof(info));
            info.dwSize = sizeof(info);
            info.dwFlags = JOY_RETURNBUTTONS;
            if (joyGetPosEx(i, &info) == JOYERR_NOERROR && joyGetDevCapsA(i, &caps, sizeof(caps)) == JOYERR_NOERROR)
            {
                sJoystickId = i;
                snprintf(sPadName, sizeof(sPadName), "%s", caps.szPname);
                break;
            }
        }
        if (sJoystickId < 0)
            return;
    }

    memset(&info, 0, sizeof(info));
    info.dwSize = sizeof(info);
    info.dwFlags = JOY_RETURNBUTTONS | JOY_RETURNX | JOY_RETURNY | JOY_RETURNPOV;
    if (joyGetPosEx(sJoystickId, &info) != JOYERR_NOERROR)
    {
        sJoystickId = -1;
        sPadName[0] = 0;
        return;
    }

    for (b = 0; b < 32; b++)
        sPadInputs[PAD_JOY_BUTTON_1 + b] = (info.dwButtons >> b) & 1;
    sPadInputs[PAD_STICK_LEFT] = info.dwXpos < 16384;
    sPadInputs[PAD_STICK_RIGHT] = info.dwXpos > 49152;
    sPadInputs[PAD_STICK_UP] = info.dwYpos < 16384;
    sPadInputs[PAD_STICK_DOWN] = info.dwYpos > 49152;
    sPadInputs[PAD_DPAD_UP] = info.dwPOV <= 4500 || (info.dwPOV >= 31500 && info.dwPOV != 65535);
    sPadInputs[PAD_DPAD_RIGHT] = info.dwPOV >= 4500 && info.dwPOV <= 13500;
    sPadInputs[PAD_DPAD_DOWN] = info.dwPOV >= 13500 && info.dwPOV <= 22500;
    sPadInputs[PAD_DPAD_LEFT] = info.dwPOV >= 22500 && info.dwPOV <= 31500;
}

static void StepRumble(void)
{
    PadVibration vibration;

    if (sRumbleFrames > 0 && --sRumbleFrames == 0)
        sRumbleLow = sRumbleHigh = 0;

    if (sPadIndex >= 0 && sXInputSetState && (sRumbleOn || sRumbleLow || sRumbleHigh))
    {
        vibration.wLeftMotorSpeed = sRumbleLow;
        vibration.wRightMotorSpeed = sRumbleHigh;
        sXInputSetState(sPadIndex, &vibration);
        sRumbleOn = sRumbleLow || sRumbleHigh;
    }
}

void Input_Poll(void)
{
    int action, slot, mask = 0;

    sPollCount++;
    ReadXInput();
    ReadJoystick();
    if (sPadIndex >= 0 || sJoystickId >= 0)
    {
        for (action = 0; action < NUM_ACTIONS; action++)
        {
            for (slot = 0; slot < NUM_BINDINGS; slot++)
            {
                int code = gBindings.pad[action][slot];

                if (code > 0 && code < PAD_COUNT && sPadInputs[code])
                    mask |= 1 << action;
            }
        }
    }
    InterlockedExchange(&sPadActions, mask);
    StepRumble();
}

// The order of the REG_KEYINPUT bits is the order of the actions.
uint32_t Input_GbaKeys(void)
{
    return ((uint32_t)(sActions | sPadActions) & ((1 << NUM_GBA_ACTIONS) - 1)) | sScriptKeys;
}

int Input_HeldActions(void)
{
    return sActions | sPadActions;
}

int Input_FastForward(void)
{
    return ((sActions | sPadActions) >> ACTION_FAST_FORWARD) & 1;
}

void Input_SetScriptKeys(uint32_t keys)
{
    InterlockedExchange(&sScriptKeys, keys);
}

int Input_PadConnected(void)
{
    return sPadIndex >= 0 || sJoystickId >= 0;
}

const char *Input_PadDescription(void)
{
    return sPadName;
}

// The game's rumble patterns: strength of the two motors and length in frames.
// Pattern numbers as in PlayRumble: 7 is the light hit, 8 a heavier one, 6, 9,
// 11, 12 and 13 the events that shake the table.
void Input_RumblePattern(int pattern)
{
    static const struct { uint8_t low, high, frames; } patterns[16] = {
        [RUMBLE_FLIPPER] = {0, 70, 3},
        [6]  = {120, 200, 18},
        [7]  = {30, 110, 5},
        [8]  = {90, 160, 10},
        [9]  = {200, 200, 26},
        [11] = {60, 170, 14},
        [12] = {220, 220, 30},
        [13] = {150, 110, 12},
    };
    int low, high, strength = gPcOptions.rumble;

    if (pattern < 0 || pattern >= 16 || strength <= 0 || patterns[pattern].frames == 0)
        return;
    low = patterns[pattern].low * 257 * strength / 100;
    high = patterns[pattern].high * 257 * strength / 100;
    sRumbleLow = low > 65535 ? 65535 : low;
    sRumbleHigh = high > 65535 ? 65535 : high;
    sRumbleFrames = patterns[pattern].frames;
}

void Input_StopRumble(void)
{
    PadVibration vibration;

    sRumbleLow = sRumbleHigh = 0;
    sRumbleFrames = 0;
    if (sPadIndex >= 0 && sXInputSetState)
    {
        vibration.wLeftMotorSpeed = 0;
        vibration.wRightMotorSpeed = 0;
        sXInputSetState(sPadIndex, &vibration);
    }
}

const char *Input_KeyName(int vk)
{
    static char name[32];
    UINT scan = MapVirtualKeyA(vk, MAPVK_VK_TO_VSC);
    LONG lParam = scan << 16;

    switch (vk)
    {
    case 0:
        return "-";
    case VK_LEFT: case VK_RIGHT: case VK_UP: case VK_DOWN:
    case VK_PRIOR: case VK_NEXT: case VK_HOME: case VK_END: case VK_INSERT: case VK_DELETE:
        lParam |= 1 << 24;
        break;
    }
    if (!GetKeyNameTextA(lParam, name, sizeof(name)))
        snprintf(name, sizeof(name), "VK %d", vk);
    return name;
}

const char *Input_PadName(int code)
{
    static const char *const names[] = {
        "-", "D-up", "D-down", "D-left", "D-right", "Start", "Back", "LS", "RS", "LB", "RB",
        "A", "B", "X", "Y", "LT", "RT", "Stick up", "Stick down", "Stick left", "Stick right",
    };
    static char name[32];

    if (code >= 0 && code < PAD_JOY_BUTTON_1)
        return names[code];
    snprintf(name, sizeof(name), "Button %d", code - PAD_JOY_BUTTON_1 + 1);
    return name;
}

// For the rebinding menu: the first input that goes down, 0 if none did.
int Input_CapturePad(void)
{
    int code;

    for (code = 1; code < PAD_COUNT; code++)
    {
        if (sPadInputs[code] && !sCaptureBaseline[code])
        {
            memcpy(sCaptureBaseline, sPadInputs, sizeof(sCaptureBaseline));
            return code;
        }
    }
    memcpy(sCaptureBaseline, sPadInputs, sizeof(sCaptureBaseline));
    return 0;
}
