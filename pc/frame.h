#ifndef GUARD_PC_FRAME_H
#define GUARD_PC_FRAME_H

// What the display needs to draw one GBA frame, copied out of the GBA memory
// when the frame is finished. The renderer works from this copy on its own
// thread, so it can draw a frame more than once (between two game frames,
// with the positions interpolated) without touching the game's memory.

#include <stddef.h>
#include <stdint.h>

#define PPU_WIDTH  240
#define PPU_HEIGHT 160
#define PPU_VRAM_SIZE 0x18000
#define PPU_PLTT_SIZE 0x400
#define PPU_OAM_SIZE  0x400

// Registers from DISPCNT to BLDY, as they were when the line was drawn, and
// the internal reference points of the affine backgrounds on that line.
#define PPU_IO_SIZE 0x56

struct PpuLine
{
    uint16_t io[PPU_IO_SIZE / 2];
    int32_t affineX[2];
    int32_t affineY[2];
};

struct PpuFrame
{
    uint8_t vram[PPU_VRAM_SIZE];
    uint16_t pltt[PPU_PLTT_SIZE / 2];
    uint16_t oam[PPU_OAM_SIZE / 2];
    struct PpuLine lines[PPU_HEIGHT];
};

// The full table: one frame per camera position.
#define MAX_STRIPS 4
#define TABLE_WIDTH 256
#define TABLE_MAX_HEIGHT 512

// Lines of each strip used for the table: the last ones are the status bar.
#define STRIP_LINES 144

// Status of the game for the overlays, taken with the frame.
struct FrameInfo
{
    uint32_t frameNumber;
    uint8_t inGame;
    uint8_t field;
    uint8_t paused;
    uint8_t mode;          // board state
    int16_t ballX, ballY;  // table coordinates
    int16_t ballVelX, ballVelY;
    int16_t ballSpin;
    uint8_t ballHidden;
    uint8_t physicsState;
    int16_t cameraX, cameraY;
    int16_t flipperAngle[2];
    uint32_t rng;
    uint32_t fieldFrames;
    uint32_t scoreHi, scoreLo;
    int8_t lives;
    uint8_t coins;
    uint16_t stageTimer;
    uint16_t saverTime;
    uint16_t modeTimer;
    uint16_t bonusTimer;
    int16_t species;       // species being caught, -1 if none
    uint16_t evolutionTarget;
    uint8_t catchProgress;
    uint8_t catchNeeded;
    uint8_t area;
    uint8_t pokedexCaught;
    uint8_t pokedexSeen;
    uint8_t boardSubState;
    uint8_t ballUpgrade;
    uint8_t language;
    // Hitboxes, in table coordinates; 0 radius = not used.
    struct { int32_t x, y, r, kind; } hit[16];
    uint8_t numHit;
};

// One published frame.
struct FrameSet
{
    struct PpuFrame main;      // what a GBA would show
    struct FrameInfo info;
    int numStrips;             // 0 = no table view for this frame
    int tableWidth, tableHeight;
    int tableLeft;             // table column of the strips' GBA column 0
    int stripY[MAX_STRIPS];    // table line at the top of each strip
    int mainY;                 // table line at the top of the main frame
    int mainX;                 // table column at the left of the main frame
    struct PpuFrame strip[MAX_STRIPS];
    // 128 bits: sprites of the main frame that belong to the screen, not the table.
    uint32_t screenSprites[4];
};

// What Ppu_Render draws.
struct PpuRenderArgs
{
    const struct PpuFrame *frame;
    const struct PpuFrame *prev;   // NULL = no interpolation
    int alpha;                     // 0..256: 256 = all the way to frame
    int scale;                     // output pixels per GBA pixel
    uint32_t *out;                 // top left pixel of line firstLine
    int stride;                    // in pixels
    int firstLine, lastLine;       // GBA lines to draw, end excluded
    int outLeft;                   // GBA columns before column 0 of out
    int width;                     // GBA columns to draw
    int layerMask;                 // BG0-3 = bits 0-3, sprites = bit 4
    const uint32_t *spriteMask;    // 128 bits, NULL = all sprites
    int spriteMaskInvert;
    int transparent;               // leave the pixels with nothing on them alone
};

struct PpuState;

void Ppu_Init(void);
size_t Ppu_StateSize(void);
void Ppu_Prepare(struct PpuState *state, const struct PpuRenderArgs *args);
void Ppu_RenderBand(const struct PpuState *state, int firstOutLine, int lastOutLine);
void Ppu_Render(const struct PpuRenderArgs *args);

#endif // GUARD_PC_FRAME_H
