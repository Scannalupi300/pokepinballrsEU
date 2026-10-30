#ifndef GUARD_PC_HOST_H
#define GUARD_PC_HOST_H

// Interface between the game side of the native build (game code and the pc/
// files listed as game side in pc/pc.mk, compiled with -fno-leading-underscore
// like the data assembly) and the Win32 side (compiled normally). The asm
// labels give both sides the same symbol names.
//
// The structs used by both sides hold only 32-bit values or are checked with
// HOST_CHECK_SIZE: the game side gives every struct agbcc's layout, the Win32
// side doesn't.

#include <stddef.h>
#include <stdint.h>

#include "frame.h"

#define HOST_SYM(name) __asm__(#name)
#define HOST_CHECK_SIZE(type, size) _Static_assert(sizeof(type) == (size), #type " has a different layout")

#define GBA_SCREEN_WIDTH  240
#define GBA_SCREEN_HEIGHT 160

// 16777216 Hz / 280896 cycles per frame
#define GBA_FRAME_RATE 59.7275

#define HOST_AUDIO_RATE 48000

// GBA memory, mapped at the GBA addresses by win32.c before the game starts.
#define GBA_EWRAM 0x02000000
#define GBA_IWRAM 0x03000000
#define GBA_IO    0x04000000
#define GBA_PLTT  0x05000000
#define GBA_VRAM  0x06000000
#define GBA_OAM   0x07000000
#define GBA_SRAM  0x0E000000

#define GBA_EWRAM_SIZE 0x40000
#define GBA_IWRAM_SIZE 0x8000
#define GBA_IO_SIZE    0x400
#define GBA_PLTT_SIZE  0x400
#define GBA_VRAM_SIZE  0x18000
#define GBA_OAM_SIZE   0x400
#define GBA_SRAM_SIZE  0x8000

#define GBA_IO16(offset) (*(volatile uint16_t *)(GBA_IO + (offset)))
#define GBA_IO32(offset) (*(volatile uint32_t *)(GBA_IO + (offset)))

// Options that change what happens in the game. They are fixed when a game
// starts and stored in its replay, so a replay plays the same with any
// settings. "vanilla" switches all of them off.
enum
{
    FIX_TRAVEL_CARD_PALETTE = 1 << 0,  // travel ramp card: palette index not multiplied by 16
    FIX_SAVED_LANGUAGE      = 1 << 1,  // resuming a saved game puts back the language it was saved in
    FIX_ALL                 = (1 << 2) - 1,
};

struct PcGameplay
{
    int32_t vanilla;        // 1 = none of the below
    int32_t ballSaver;      // 1 = as in the game, 2-4 = lasts that many times longer
    int32_t infiniteBalls;
    int32_t fixes;          // FIX_ flags
};

enum { VIEW_NORMAL, VIEW_TABLE, VIEW_COUNT };
enum { SCALE_INTEGER, SCALE_FIT, SCALE_COUNT };
enum { FILTER_NONE, FILTER_LCD, FILTER_CRT, FILTER_COUNT };

struct PcOptions
{
    // Video
    int32_t view;
    int32_t panels;
    int32_t interpolate;    // draw between game frames at the monitor's refresh rate
    int32_t internalScale;  // 0 = from the window size
    int32_t scaleMode;
    int32_t filter;
    int32_t vsync;
    int32_t showFps;
    int32_t debugOverlay;
    int32_t debugCollision;
    // Controls
    int32_t lowLatency;
    int32_t rumble;         // 0-100
    int32_t rumbleFlippers;
    // Comfort
    int32_t pokedexSpeed;   // 1 = as in the game, up to 4
    int32_t autoSuspend;    // suspend on exit, offer to resume on start
    // The next game
    struct PcGameplay game;
    // Online
    int32_t onlineEnabled;
};

extern struct PcOptions gPcOptions HOST_SYM(gPcOptions);

// What the Win32 side asks of the game. They run at the top of the main loop,
// where the game has nothing on the stack.
enum HostCommandType
{
    CMD_NONE,
    CMD_SAVE_STATE,     // a = slot
    CMD_LOAD_STATE,     // a = slot
    CMD_REBOOT,
    CMD_TRAINING,       // a = field, b = training mode
    CMD_PLAY_REPLAY,    // path
    CMD_STOP_REPLAY,
    CMD_SET_LANGUAGE,   // a = language
    CMD_PLACE_BALL,     // for tests: a, b = position, c, d = velocity, e = board layer
};

struct HostCommand
{
    int32_t type;
    int32_t a, b, c, d, e;
    char path[260];
};

// A game's starting conditions: with these and the keys of every frame, the
// game plays the same again. Stored at the start of a replay.
#define RUN_SAVE_SIZE 0x300

struct RunHeader
{
    uint32_t magic;
    uint32_t version;
    uint32_t field;
    uint32_t isBonusField;
    uint32_t rngValue;
    uint32_t frameCount;
    uint32_t trainingMode;
    uint32_t language;
    int32_t eReaderBonuses[8];
    uint32_t buttonConfigs[16];
    struct PcGameplay game;
    uint8_t saveData[RUN_SAVE_SIZE];
};
HOST_CHECK_SIZE(struct RunHeader, 8 * 4 + 8 * 4 + 16 * 4 + 16 + RUN_SAVE_SIZE);

// Sent to the statistics and the achievements.
enum RunEvent
{
    EVENT_GAME_START,
    EVENT_GAME_OVER,      // a = score hi, b = score lo
    EVENT_BALL_LOST,
    EVENT_BALL_SAVED,
    EVENT_CATCH,          // a = species
    EVENT_EVOLUTION,      // a = species
    EVENT_BONUS_CLEARED,  // a = field
    EVENT_FLIPPER,
    EVENT_BUMPER,
    EVENT_TRAVEL,
    EVENT_SCORE,          // a = score hi, b = score lo
    EVENT_COINS,          // a = coins
    EVENT_PLAY_TIME,      // a = frames
};

// Host_Rumble takes the game's patterns (PlayRumble) and this one, for the flippers.
#define RUMBLE_FLIPPER 1

// win32.c
struct FrameSet *Host_AcquireFrame(void) HOST_SYM(Host_AcquireFrame);
void Host_PublishFrame(struct FrameSet *frame) HOST_SYM(Host_PublishFrame);
void Host_ReleaseFrame(struct FrameSet *frame) HOST_SYM(Host_ReleaseFrame);
void Host_InheritStrips(struct FrameSet *frame) HOST_SYM(Host_InheritStrips);
void *Host_Alloc(size_t size) HOST_SYM(Host_Alloc);
void Host_WaitFrame(void) HOST_SYM(Host_WaitFrame);
void Host_PollInput(void) HOST_SYM(Host_PollInput);
void Host_AudioWrite(const int16_t *samples, uint32_t frames) HOST_SYM(Host_AudioWrite);
uint32_t Host_AudioQueued(void) HOST_SYM(Host_AudioQueued);
int Host_FastForward(void) HOST_SYM(Host_FastForward);
void Host_Log(const char *fmt, ...) HOST_SYM(Host_Log);
void Host_Fatal(const char *fmt, ...) HOST_SYM(Host_Fatal);
void Host_Memcpy(void *dest, const void *src, size_t size) HOST_SYM(Host_Memcpy);
int Host_NextCommand(struct HostCommand *command) HOST_SYM(Host_NextCommand);
int Host_IsPaused(void) HOST_SYM(Host_IsPaused);
void Host_PauseWait(void) HOST_SYM(Host_PauseWait);
void Host_Rumble(int pattern) HOST_SYM(Host_Rumble);
void Host_Toast(const char *text) HOST_SYM(Host_Toast);
void Host_SetSramGuard(int on) HOST_SYM(Host_SetSramGuard);
void Host_GameReady(void) HOST_SYM(Host_GameReady);
void Host_Trace(uint32_t frame, int x, int y, int vx, int vy, int lives, int saver, int state, int layer, int subState, int species, int target) HOST_SYM(Host_Trace);

// state.c
int State_Save(int slot) HOST_SYM(State_Save);
int State_Load(int slot) HOST_SYM(State_Load);
int State_Copy(void *dest) HOST_SYM(State_Copy);
void State_Paste(const void *src) HOST_SYM(State_Paste);
int State_Size(void) HOST_SYM(State_Size);
uint32_t State_Hash(const void *data, size_t size) HOST_SYM(State_Hash);

// replay.c
void Replay_StartRecording(const struct RunHeader *header) HOST_SYM(Replay_StartRecording);
void Replay_RecordKeys(uint32_t keys) HOST_SYM(Replay_RecordKeys);
void Replay_StopRecording(uint32_t scoreHi, uint32_t scoreLo, uint32_t hash, int finished) HOST_SYM(Replay_StopRecording);
void Replay_Taint(void) HOST_SYM(Replay_Taint);
int Replay_Load(const char *path, struct RunHeader *header) HOST_SYM(Replay_Load);
int Replay_NextKeys(uint32_t *keys) HOST_SYM(Replay_NextKeys);
int Replay_KeysLeft(void) HOST_SYM(Replay_KeysLeft);
void Replay_FinishPlayback(uint32_t scoreHi, uint32_t scoreLo, uint32_t hash) HOST_SYM(Replay_FinishPlayback);
int Replay_IsPlaying(void) HOST_SYM(Replay_IsPlaying);
int Replay_IsVerifying(void) HOST_SYM(Replay_IsVerifying);

// stats.c
void Stats_Event(int event, uint32_t a, uint32_t b) HOST_SYM(Stats_Event);

// game side, pc/hooks.c
void AgbMain(void) HOST_SYM(AgbMain);
int Hook_Portrait(int species, uint32_t *pixels, int *width, int *height) HOST_SYM(Hook_Portrait);
const char *Hook_SpeciesName(int species, int language) HOST_SYM(Hook_SpeciesName);
const uint8_t *Hook_FontTiles(void) HOST_SYM(Hook_FontTiles);
void Hook_OptionsBackground(uint32_t *out, int language) HOST_SYM(Hook_OptionsBackground);
void Hook_OptionsSprite(uint32_t *out, int tileX, int tileY, int widthTiles, int heightTiles, int palette, int language) HOST_SYM(Hook_OptionsSprite);
int Hook_Language(void) HOST_SYM(Hook_Language);
int Hook_NumSpecies(void) HOST_SYM(Hook_NumSpecies);
int Hook_CollisionAt(int x, int y) HOST_SYM(Hook_CollisionAt);

// game side, pc/gba_bios.c, pc/m4a_host.c, pc/audio.c
void Audio_EndFrame(void) HOST_SYM(Audio_EndFrame);
void Audio_PushPcm(const int8_t *right, const int8_t *left, uint32_t count, uint32_t rate) HOST_SYM(Audio_PushPcm);
void Psg_Update(void) HOST_SYM(Psg_Update);
void Psg_Render(int32_t *out, uint32_t frames, uint32_t rate) HOST_SYM(Psg_Render);
// The host state that belongs to a saved game
void *Audio_StateData(int *size) HOST_SYM(Audio_StateData);
void *Bios_StateData(int *size) HOST_SYM(Bios_StateData);

#endif // GUARD_PC_HOST_H
