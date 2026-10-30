// Software renderer for the GBA display. It draws from a struct PpuFrame (a
// copy of VRAM, palette, OAM and the registers of each line), so it can run on
// another thread and draw the same frame several times.
//
// With scale 1 and no interpolation it gives what the GBA gives. With a larger
// scale it draws more output pixels per GBA pixel, which is what lets moving
// things stop between GBA pixels: the ball and the camera are interpolated
// between two game frames (args->prev and args->frame), in steps of one output
// pixel. Tiles, palettes and which sprite frame is shown always come from the
// newest frame, so a flipper press shows up without waiting for the blend.

#include <stdlib.h>
#include <string.h>

#include "frame.h"

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef int16_t s16;
typedef int32_t s32;

#define IO(line, offset) ((line)->io[(offset) / 2])

#define REG_DISPCNT   0x00
#define REG_BGCNT(n)  (0x08 + (n) * 2)
#define REG_BGHOFS(n) (0x10 + (n) * 4)
#define REG_BGVOFS(n) (0x12 + (n) * 4)
#define REG_BGPA(n)   (0x20 + ((n) - 2) * 0x10)
#define REG_BGPC(n)   (0x24 + ((n) - 2) * 0x10)
#define REG_WIN0H     0x40
#define REG_WIN1H     0x42
#define REG_WIN0V     0x44
#define REG_WIN1V     0x46
#define REG_WININ     0x48
#define REG_WINOUT    0x4A
#define REG_MOSAIC    0x4C
#define REG_BLDCNT    0x50
#define REG_BLDALPHA  0x52
#define REG_BLDY      0x54

#define TRANSPARENT 0x8000
#define MAX_SCALE 4
#define MAX_WIDTH TABLE_WIDTH

// How far something can move in one game frame and still be interpolated.
// More than this is a cut, not movement.
#define MAX_BG_STEP 40
#define MAX_SPRITE_STEP 32

enum { LAYER_BG0, LAYER_BG1, LAYER_BG2, LAYER_BG3, LAYER_OBJ, LAYER_BD };

static u32 sRgb[0x8000];

void Ppu_Init(void)
{
    u32 c;

    for (c = 0; c < 0x8000; c++)
    {
        u32 r = c & 0x1F, g = (c >> 5) & 0x1F, b = (c >> 10) & 0x1F;
        r = (r << 3) | (r >> 2);
        g = (g << 3) | (g >> 2);
        b = (b << 3) | (b >> 2);
        sRgb[c] = 0xFF000000 | (r << 16) | (g << 8) | b;
    }
}

static inline int FloorDiv(int a, int b)
{
    int q = a / b;
    if ((a % b) != 0 && (a < 0))
        q--;
    return q;
}

static s32 SignExtend8(u32 v)
{
    return (s32)(v << 24) >> 24;
}

struct Sprite
{
    int xSub, ySub;       // top left of the bounds, in output pixels
    u16 attr0, attr1, attr2;
    u8 w, h;
    u8 boundW, boundH;
    u8 visible;
    s16 pa, pb, pc, pd;
};

static const u8 sObjSizes[3][4][2] = {
    {{8, 8}, {16, 16}, {32, 32}, {64, 64}},
    {{16, 8}, {32, 8}, {32, 16}, {64, 32}},
    {{8, 16}, {8, 32}, {16, 32}, {32, 64}},
};

static int SpriteBounds(const u16 *oam, int i, int *w, int *h, int *boundW, int *boundH)
{
    u16 attr0 = oam[i * 4 + 0];
    u16 attr1 = oam[i * 4 + 1];
    int affine = attr0 & 0x100;
    int objMode = (attr0 >> 10) & 3;
    int shape = attr0 >> 14;

    if (!affine && (attr0 & 0x200))
        return 0;
    if (objMode == 3 || shape == 3)
        return 0;

    *w = sObjSizes[shape][attr1 >> 14][0];
    *h = sObjSizes[shape][attr1 >> 14][1];
    *boundW = *w;
    *boundH = *h;
    if (affine && (attr0 & 0x200))
    {
        *boundW *= 2;
        *boundH *= 2;
    }
    return 1;
}

struct PpuState
{
    struct PpuRenderArgs args;
    struct Sprite sprites[128];
    int firstSprite, lastSprite;
};

static int Lerp(int value, int delta, int alpha, int scale)
{
    // value at the newest frame, delta since the frame before it
    return value * scale - (delta * scale * (256 - alpha) + (delta >= 0 ? 128 : -128)) / 256;
}

static void PrepareSprites(struct PpuState *state)
{
    const struct PpuRenderArgs *args = &state->args;
    const u16 *oam = args->frame->oam;
    const u16 *prevOam = args->prev ? args->prev->oam : NULL;
    int scale = args->scale;
    int i;

    state->firstSprite = 128;
    state->lastSprite = -1;
    for (i = 0; i < 128; i++)
    {
        struct Sprite *s = &state->sprites[i];
        int w, h, boundW, boundH;
        int x, y;

        s->visible = 0;
        if (args->spriteMask)
        {
            int bit = (args->spriteMask[i >> 5] >> (i & 31)) & 1;
            if (bit == args->spriteMaskInvert)
                continue;
        }
        if (!SpriteBounds(oam, i, &w, &h, &boundW, &boundH))
            continue;

        s->attr0 = oam[i * 4 + 0];
        s->attr1 = oam[i * 4 + 1];
        s->attr2 = oam[i * 4 + 2];
        s->w = w;
        s->h = h;
        s->boundW = boundW;
        s->boundH = boundH;
        s->visible = 1;

        x = s->attr1 & 0x1FF;
        if (x >= 240)
            x -= 512;
        y = s->attr0 & 0xFF;
        s->xSub = x * scale;
        s->ySub = y * scale;

        if (prevOam && args->alpha < 256)
        {
            int pw, ph, pbw, pbh;

            if (SpriteBounds(prevOam, i, &pw, &ph, &pbw, &pbh) && pbw == boundW && pbh == boundH)
            {
                int px = prevOam[i * 4 + 1] & 0x1FF;
                int py = prevOam[i * 4 + 0] & 0xFF;
                int dx = (((s->attr1 & 0x1FF) - px + 256) & 0x1FF) - 256;
                int dy = SignExtend8(y - py);

                if (abs(dx) <= MAX_SPRITE_STEP && abs(dy) <= MAX_SPRITE_STEP)
                {
                    s->xSub = Lerp(x, dx, args->alpha, scale);
                    s->ySub = Lerp(y, dy, args->alpha, scale);
                }
            }
        }

        if (s->attr0 & 0x100)
        {
            int matrix = (s->attr1 >> 9) & 0x1F;
            s->pa = (s16)oam[matrix * 16 + 3];
            s->pb = (s16)oam[matrix * 16 + 7];
            s->pc = (s16)oam[matrix * 16 + 11];
            s->pd = (s16)oam[matrix * 16 + 15];
        }

        if (i < state->firstSprite)
            state->firstSprite = i;
        state->lastSprite = i;
    }
}

// One line of a text background, in GBA pixels, starting at table column col.
static void FetchTextRow(const struct PpuFrame *f, const struct PpuLine *line, int bg, int y0, int col, int count, u16 *out)
{
    u16 cnt = IO(line, REG_BGCNT(bg));
    u32 charBase = ((cnt >> 2) & 3) * 0x4000;
    u32 screenBase = ((cnt >> 8) & 0x1F) * 0x800;
    int is8bpp = cnt & 0x80;
    int size = cnt >> 14;
    int width = (size & 1) ? 512 : 256;
    int height = (size & 2) ? 512 : 256;
    int y = y0 & (height - 1);
    int blockY = (size == 2) ? (y >> 8) : (size == 3) ? (y >> 8) * 2 : 0;
    const u16 *vram16 = (const u16 *)f->vram;
    const u8 *vram8 = f->vram;
    const u16 *pltt = f->pltt;
    int n = 0;

    while (n < count)
    {
        int xx = (col + n) & (width - 1);
        int block = blockY + ((size & 1) ? (xx >> 8) : 0);
        u16 entry = vram16[(screenBase + block * 0x800) / 2 + ((y & 255) >> 3) * 32 + ((xx & 255) >> 3)];
        int px = xx & 7;
        int py = (entry & 0x800) ? 7 - (y & 7) : (y & 7);
        int hflip = entry & 0x400;
        int run = 8 - px;

        if (run > count - n)
            run = count - n;

        if (is8bpp)
        {
            u32 addr = charBase + (entry & 0x3FF) * 64 + py * 8;
            const u8 *row = vram8 + addr;
            int inRange = addr < 0x10000;
            int i;

            for (i = 0; i < run; i++)
            {
                int p = px + i;
                u8 index = inRange ? row[hflip ? 7 - p : p] : 0;
                out[n + i] = index ? (pltt[index] & 0x7FFF) : TRANSPARENT;
            }
        }
        else
        {
            u32 addr = charBase + (entry & 0x3FF) * 32 + py * 4;
            const u16 *pal = pltt + (entry >> 12) * 16;
            u32 data = addr < 0x10000 ? (vram8[addr] | (vram8[addr + 1] << 8) | (vram8[addr + 2] << 16) | ((u32)vram8[addr + 3] << 24)) : 0;
            int i;

            for (i = 0; i < run; i++)
            {
                int p = px + i;
                u32 index = (data >> ((hflip ? 7 - p : p) * 4)) & 0xF;
                out[n + i] = index ? (pal[index] & 0x7FFF) : TRANSPARENT;
            }
        }
        n += run;
    }
}

static void FetchAffineRow(const struct PpuFrame *f, const struct PpuLine *line, int bg, u16 *out)
{
    u16 cnt = IO(line, REG_BGCNT(bg));
    u32 charBase = ((cnt >> 2) & 3) * 0x4000;
    u32 screenBase = ((cnt >> 8) & 0x1F) * 0x800;
    int size = 128 << (cnt >> 14);
    int wrap = cnt & 0x2000;
    s32 pa = (s16)IO(line, REG_BGPA(bg));
    s32 pc = (s16)IO(line, REG_BGPC(bg));
    s32 refX = line->affineX[bg - 2];
    s32 refY = line->affineY[bg - 2];
    int x;

    for (x = 0; x < PPU_WIDTH; x++)
    {
        s32 tx = (refX + pa * x) >> 8;
        s32 ty = (refY + pc * x) >> 8;
        u8 tile, index;
        u32 addr;

        if (wrap)
        {
            tx &= size - 1;
            ty &= size - 1;
        }
        else if (tx < 0 || ty < 0 || tx >= size || ty >= size)
        {
            out[x] = TRANSPARENT;
            continue;
        }

        tile = f->vram[screenBase + (ty >> 3) * (size >> 3) + (tx >> 3)];
        addr = charBase + tile * 64 + (ty & 7) * 8 + (tx & 7);
        index = addr < 0x10000 ? f->vram[addr] : 0;
        out[x] = index ? (f->pltt[index] & 0x7FFF) : TRANSPARENT;
    }
}

static void FetchBitmapRow(const struct PpuFrame *f, const struct PpuLine *line, int mode, u16 *out)
{
    const u16 *vram16 = (const u16 *)f->vram;
    s32 pa = (s16)IO(line, REG_BGPA(2));
    s32 pc = (s16)IO(line, REG_BGPC(2));
    u32 frame = (IO(line, REG_DISPCNT) & 0x10) ? 0xA000 : 0;
    int x;

    for (x = 0; x < PPU_WIDTH; x++)
    {
        s32 tx = (line->affineX[0] + pa * x) >> 8;
        s32 ty = (line->affineY[0] + pc * x) >> 8;

        out[x] = TRANSPARENT;
        if (mode == 3)
        {
            if (tx >= 0 && ty >= 0 && tx < 240 && ty < 160)
                out[x] = vram16[ty * 240 + tx] & 0x7FFF;
        }
        else if (mode == 4)
        {
            if (tx >= 0 && ty >= 0 && tx < 240 && ty < 160)
            {
                u8 index = f->vram[frame + ty * 240 + tx];
                if (index)
                    out[x] = f->pltt[index] & 0x7FFF;
            }
        }
        else
        {
            if (tx >= 0 && ty >= 0 && tx < 160 && ty < 128)
                out[x] = vram16[(frame + (ty * 160 + tx) * 2) / 2] & 0x7FFF;
        }
    }
}

struct Band
{
    u16 row[4][MAX_WIDTH + 2];                    // GBA pixels
    u16 bgLine[4][(MAX_WIDTH + 1) * MAX_SCALE];   // output pixels
    u16 objLine[(MAX_WIDTH + 1) * MAX_SCALE];
    u8 objPrio[(MAX_WIDTH + 1) * MAX_SCALE];
    u8 objSemi[(MAX_WIDTH + 1) * MAX_SCALE];
    u8 objWindow[(MAX_WIDTH + 1) * MAX_SCALE];
    // What row and bgLine hold now
    int rowKey[4][3];
    const struct PpuLine *rowLine[4];
    int lineKey[4][2];
    int anyObj;
};

static inline u16 ObjPixel(const struct PpuFrame *f, const struct Sprite *s, int tx, int ty, int oneDim, int *indexOut)
{
    int is8bpp = s->attr0 & 0x2000;
    int tileNum = s->attr2 & 0x3FF;
    int w = s->w;
    u32 tile, addr;
    u8 index;

    if (is8bpp)
    {
        tile = tileNum + (ty >> 3) * (oneDim ? (w >> 3) * 2 : 32) + (tx >> 3) * 2;
        addr = 0x10000 + (((tile & 0x3FF) * 32 + (ty & 7) * 8 + (tx & 7)) & 0x7FFF);
        index = f->vram[addr];
        *indexOut = index;
        return index ? f->pltt[256 + index] & 0x7FFF : 0;
    }
    tile = tileNum + (ty >> 3) * (oneDim ? (w >> 3) : 32) + (tx >> 3);
    addr = 0x10000 + (((tile & 0x3FF) * 32 + (ty & 7) * 4 + (tx & 7) / 2) & 0x7FFF);
    index = f->vram[addr];
    index = (tx & 1) ? (index >> 4) : (index & 0xF);
    *indexOut = index;
    return index ? f->pltt[256 + (s->attr2 >> 12) * 16 + index] & 0x7FFF : 0;
}

static inline void PutObjPixel(struct Band *b, int ox, const struct Sprite *s, u16 color)
{
    int objMode = (s->attr0 >> 10) & 3;
    int prio = (s->attr2 >> 10) & 3;

    if (objMode == 2)
    {
        b->objWindow[ox] = 1;
        return;
    }
    if (b->objLine[ox] == TRANSPARENT || prio < b->objPrio[ox])
    {
        b->objLine[ox] = color;
        b->objPrio[ox] = prio;
        b->objSemi[ox] = objMode == 1;
    }
}

static void RenderObjs(const struct PpuState *state, struct Band *b, const struct PpuLine *line, int outY, int outPixels)
{
    const struct PpuRenderArgs *args = &state->args;
    const struct PpuFrame *f = args->frame;
    int scale = args->scale;
    u16 dispcnt = IO(line, REG_DISPCNT);
    u16 mosaic = IO(line, REG_MOSAIC);
    int oneDim = dispcnt & 0x40;
    int bitmapMode = (dispcnt & 7) >= 3;
    int mosaicH = ((mosaic >> 8) & 0xF) + 1;
    int mosaicV = ((mosaic >> 12) & 0xF) + 1;
    int originX = args->outLeft * scale;
    int i;

    memset(b->objPrio, 4, outPixels);
    memset(b->objSemi, 0, outPixels);
    memset(b->objWindow, 0, outPixels);
    for (i = 0; i < outPixels; i++)
        b->objLine[i] = TRANSPARENT;
    b->anyObj = 0;

    if (!(dispcnt & 0x1000))
        return;

    for (i = state->firstSprite; i <= state->lastSprite; i++)
    {
        const struct Sprite *s = &state->sprites[i];
        int dySub, dy;
        int sx, firstSx, lastSx;

        if (!s->visible)
            continue;
        if (bitmapMode && (s->attr2 & 0x3FF) < 512)
            continue;

        dySub = ((outY - s->ySub) % (256 * scale) + 256 * scale) % (256 * scale);
        dy = dySub / scale;
        if (dy >= s->boundH)
            continue;
        if (s->attr0 & 0x1000)
            dy -= dy % mosaicV;

        b->anyObj = 1;
        firstSx = FloorDiv(originX - s->xSub, scale);
        lastSx = FloorDiv(originX + outPixels - 1 - s->xSub, scale);
        if (firstSx < 0)
            firstSx = 0;
        if (lastSx >= s->boundW)
            lastSx = s->boundW - 1;

        if (s->attr0 & 0x100)
        {
            // Rotated and scaled sprites: sample once per output pixel.
            int oxStart = firstSx * scale + s->xSub - originX;
            int oxEnd = (lastSx + 1) * scale + s->xSub - originX;
            int iy = dy * scale + dySub % scale * ((s->attr0 & 0x1000) ? 0 : 1) - s->boundH * scale / 2;
            int ox;

            if (oxStart < 0)
                oxStart = 0;
            if (oxEnd > outPixels)
                oxEnd = outPixels;
            for (ox = oxStart; ox < oxEnd; ox++)
            {
                int ix = ox + originX - s->xSub - s->boundW * scale / 2;
                int tx = FloorDiv((s->pa * ix + s->pb * iy) >> 8, scale) + s->w / 2;
                int ty = FloorDiv((s->pc * ix + s->pd * iy) >> 8, scale) + s->h / 2;
                int index;
                u16 color;

                if (tx < 0 || ty < 0 || tx >= s->w || ty >= s->h)
                    continue;
                if (s->attr0 & 0x1000)
                    tx -= tx % mosaicH;
                color = ObjPixel(f, s, tx, ty, oneDim, &index);
                if (index)
                    PutObjPixel(b, ox, s, color);
            }
            continue;
        }

        for (sx = firstSx; sx <= lastSx; sx++)
        {
            int tx = (s->attr1 & 0x1000) ? s->w - 1 - sx : sx;
            int ty = (s->attr1 & 0x2000) ? s->h - 1 - dy : dy;
            int index, ox, end;
            u16 color;

            if (s->attr0 & 0x1000)
                tx -= tx % mosaicH;
            color = ObjPixel(f, s, tx, ty, oneDim, &index);
            if (!index)
                continue;

            ox = sx * scale + s->xSub - originX;
            end = ox + scale;
            if (ox < 0)
                ox = 0;
            if (end > outPixels)
                end = outPixels;
            for (; ox < end; ox++)
                PutObjPixel(b, ox, s, color);
        }
    }
}

static int InsideRange(int pos, int start, int end, int limit)
{
    if (end > limit || start > end)
        end = limit;
    return pos >= start && pos < end;
}

static inline u16 Blend(u16 a, u16 b, int eva, int evb)
{
    int r = ((a & 0x1F) * eva + (b & 0x1F) * evb) >> 4;
    int g = (((a >> 5) & 0x1F) * eva + ((b >> 5) & 0x1F) * evb) >> 4;
    int bl = (((a >> 10) & 0x1F) * eva + ((b >> 10) & 0x1F) * evb) >> 4;
    if (r > 31) r = 31;
    if (g > 31) g = 31;
    if (bl > 31) bl = 31;
    return r | (g << 5) | (bl << 10);
}

static inline u16 Brighten(u16 c, int evy)
{
    int r = c & 0x1F, g = (c >> 5) & 0x1F, b = (c >> 10) & 0x1F;
    r += ((31 - r) * evy) >> 4;
    g += ((31 - g) * evy) >> 4;
    b += ((31 - b) * evy) >> 4;
    return r | (g << 5) | (b << 10);
}

static inline u16 Darken(u16 c, int evy)
{
    int r = c & 0x1F, g = (c >> 5) & 0x1F, b = (c >> 10) & 0x1F;
    r -= (r * evy) >> 4;
    g -= (g * evy) >> 4;
    b -= (b * evy) >> 4;
    return r | (g << 5) | (b << 10);
}

// Blends over what is already in the output (the table view's overlay).
static inline u32 BlendOver(u16 color, u32 under, int eva, int evb)
{
    u32 top = sRgb[color];
    int r = (((top >> 16) & 0xFF) * eva + ((under >> 16) & 0xFF) * evb) >> 4;
    int g = (((top >> 8) & 0xFF) * eva + ((under >> 8) & 0xFF) * evb) >> 4;
    int bl = ((top & 0xFF) * eva + (under & 0xFF) * evb) >> 4;
    if (r > 255) r = 255;
    if (g > 255) g = 255;
    if (bl > 255) bl = 255;
    return 0xFF000000 | (r << 16) | (g << 8) | bl;
}

// Offset of a background in output pixels for this line of the newest frame.
static void BgOffsets(const struct PpuRenderArgs *args, int lineNum, int bg, int *hSub, int *vSub)
{
    const struct PpuLine *line = &args->frame->lines[lineNum];
    int scale = args->scale;
    int hofs = IO(line, REG_BGHOFS(bg)) & 0x1FF;
    int vofs = IO(line, REG_BGVOFS(bg)) & 0x1FF;

    *hSub = hofs * scale;
    *vSub = vofs * scale;
    if (args->prev && args->alpha < 256)
    {
        const struct PpuLine *prev = &args->prev->lines[lineNum];
        int dh = ((hofs - IO(prev, REG_BGHOFS(bg)) + 256) & 0x1FF) - 256;
        int dv = ((vofs - IO(prev, REG_BGVOFS(bg)) + 256) & 0x1FF) - 256;

        if (abs(dh) <= MAX_BG_STEP && abs(dv) <= MAX_BG_STEP)
        {
            *hSub = Lerp(hofs, dh, args->alpha, scale);
            *vSub = Lerp(vofs, dv, args->alpha, scale);
        }
    }
}

static void RenderOutLine(const struct PpuState *state, struct Band *b, int outY, u32 *out)
{
    const struct PpuRenderArgs *args = &state->args;
    const struct PpuFrame *f = args->frame;
    int scale = args->scale;
    int lineNum = outY / scale;
    const struct PpuLine *line = &f->lines[lineNum];
    u16 dispcnt = IO(line, REG_DISPCNT);
    int mode = dispcnt & 7;
    int outPixels = args->width * scale;
    u16 mosaic = IO(line, REG_MOSAIC);
    u16 bldcnt = IO(line, REG_BLDCNT);
    int blendMode = (bldcnt >> 6) & 3;
    int eva = IO(line, REG_BLDALPHA) & 0x1F;
    int evb = (IO(line, REG_BLDALPHA) >> 8) & 0x1F;
    int evy = IO(line, REG_BLDY) & 0x1F;
    int windows = dispcnt & 0xE000;
    u16 backdrop = f->pltt[0] & 0x7FFF;
    int bgEnabled[4] = {0, 0, 0, 0};
    int order[4], orderPrio[4], numBg = 0;
    int transparent = args->transparent;
    u16 *lines[4];
    int win0 = 0, win1 = 0;
    int i, ox;

    if (eva > 16) eva = 16;
    if (evb > 16) evb = 16;
    if (evy > 16) evy = 16;

    if (dispcnt & 0x80)
    {
        if (!transparent)
        {
            for (ox = 0; ox < outPixels; ox++)
                out[ox] = 0xFFFFFFFF;
        }
        return;
    }

    switch (mode)
    {
    case 0:
        bgEnabled[0] = bgEnabled[1] = bgEnabled[2] = bgEnabled[3] = 1;
        break;
    case 1:
        bgEnabled[0] = bgEnabled[1] = bgEnabled[2] = 1;
        break;
    case 2:
        bgEnabled[2] = bgEnabled[3] = 1;
        break;
    case 3:
    case 4:
    case 5:
        bgEnabled[2] = 1;
        break;
    }

    for (i = 0; i < 4; i++)
    {
        u16 cnt = IO(line, REG_BGCNT(i));
        u16 *row = b->row[i];
        int col, phase;

        if (!(dispcnt & (0x100 << i)) || !(args->layerMask & (1 << i)))
            bgEnabled[i] = 0;
        if (!bgEnabled[i])
            continue;

        phase = 0;
        if (mode == 0 || (mode == 1 && i < 2))
        {
            int mosaicV = (cnt & 0x40) ? ((mosaic >> 4) & 0xF) + 1 : 1;
            int hSub, vSub, y;

            BgOffsets(args, lineNum, i, &hSub, &vSub);
            if (mosaicV > 1)
                y = (lineNum - lineNum % mosaicV) + (vSub / scale);
            else
                y = FloorDiv(outY + vSub, scale);
            col = FloorDiv(args->outLeft * scale + hSub, scale);
            phase = (args->outLeft * scale + hSub) - col * scale;

            if (b->rowKey[i][0] != y || b->rowKey[i][1] != col || b->rowLine[i] != line)
            {
                FetchTextRow(f, line, i, y, col, args->width + 1, row);
                b->rowKey[i][0] = y;
                b->rowKey[i][1] = col;
                b->rowLine[i] = line;
                b->lineKey[i][0] = -1;
            }
        }
        else
        {
            if (b->rowLine[i] != line)
            {
                if (mode >= 3)
                    FetchBitmapRow(f, line, mode, row);
                else
                    FetchAffineRow(f, line, i, row);
                b->rowLine[i] = line;
                b->lineKey[i][0] = -1;
            }
            row[args->width] = TRANSPARENT;
        }

        if ((cnt & 0x40) && (mosaic & 0xF) && b->lineKey[i][0] == -1)
        {
            int mosaicH = (mosaic & 0xF) + 1;
            int x;

            for (x = 0; x < PPU_WIDTH; x++)
                row[x] = row[x - x % mosaicH];
        }

        if (scale == 1)
        {
            lines[i] = row;
        }
        else
        {
            // Stretch the GBA pixels to output pixels.
            if (b->lineKey[i][0] != phase)
            {
                u16 *dst = b->bgLine[i];
                int run = scale - phase;
                int src = 0;

                for (ox = 0; ox < outPixels; )
                {
                    u16 c = row[src++];
                    int k = run;

                    if (k > outPixels - ox)
                        k = outPixels - ox;
                    while (k-- > 0)
                        dst[ox++] = c;
                    run = scale;
                }
                b->lineKey[i][0] = phase;
            }
            lines[i] = b->bgLine[i];
        }

        // Sorted by priority, then by number.
        {
            int prio = cnt & 3;
            int k = numBg++;

            while (k > 0 && orderPrio[k - 1] > prio)
            {
                order[k] = order[k - 1];
                orderPrio[k] = orderPrio[k - 1];
                k--;
            }
            order[k] = i;
            orderPrio[k] = prio;
        }
    }

    if (args->layerMask & 0x10)
    {
        RenderObjs(state, b, line, outY, outPixels);
    }
    else
    {
        memset(b->objPrio, 4, outPixels);
        memset(b->objSemi, 0, outPixels);
        memset(b->objWindow, 0, outPixels);
        for (ox = 0; ox < outPixels; ox++)
            b->objLine[ox] = TRANSPARENT;
        b->anyObj = 0;
    }

    if (dispcnt & 0x2000)
        win0 = InsideRange(lineNum, IO(line, REG_WIN0V) >> 8, IO(line, REG_WIN0V) & 0xFF, PPU_HEIGHT);
    if (dispcnt & 0x4000)
        win1 = InsideRange(lineNum, IO(line, REG_WIN1V) >> 8, IO(line, REG_WIN1V) & 0xFF, PPU_HEIGHT);

    for (ox = 0; ox < outPixels; ox++)
    {
        int winMask = 0x3F;
        int layers[2] = {LAYER_BD, LAYER_BD};
        u16 colors[2] = {backdrop, backdrop};
        int found = 0;
        int objPrio = 4;
        u16 obj = b->objLine[ox];
        u16 color;
        int k;

        if (windows)
        {
            int col = FloorDiv(ox + args->outLeft * scale, scale);

            winMask = IO(line, REG_WINOUT) & 0x3F;
            if ((dispcnt & 0x8000) && b->objWindow[ox])
                winMask = (IO(line, REG_WINOUT) >> 8) & 0x3F;
            if (win1 && InsideRange(col, IO(line, REG_WIN1H) >> 8, IO(line, REG_WIN1H) & 0xFF, PPU_WIDTH))
                winMask = (IO(line, REG_WININ) >> 8) & 0x3F;
            if (win0 && InsideRange(col, IO(line, REG_WIN0H) >> 8, IO(line, REG_WIN0H) & 0xFF, PPU_WIDTH))
                winMask = IO(line, REG_WININ) & 0x3F;
        }

        if (obj != TRANSPARENT && (winMask & 0x10))
            objPrio = b->objPrio[ox];

        for (k = 0; k < numBg && found < 2; k++)
        {
            int bg = order[k];
            u16 c;

            if (objPrio <= orderPrio[k])
            {
                layers[found] = LAYER_OBJ;
                colors[found] = obj;
                found++;
                objPrio = 4;
                if (found == 2)
                    break;
            }
            if (!(winMask & (1 << bg)))
                continue;
            c = lines[bg][ox];
            if (c != TRANSPARENT)
            {
                layers[found] = bg;
                colors[found] = c;
                found++;
            }
        }
        if (found < 2 && objPrio < 4)
        {
            layers[found] = LAYER_OBJ;
            colors[found] = obj;
            found++;
        }

        if (transparent && found == 0)
            continue;

        color = colors[0];
        if (winMask & 0x20)
        {
            int topIsTarget1 = (bldcnt >> layers[0]) & 1;
            int bottomIsTarget2 = (bldcnt >> (8 + layers[1])) & 1;
            int semi = layers[0] == LAYER_OBJ && b->objSemi[ox];

            if (transparent && found == 1)
            {
                // The layer below is the table already in the output.
                if (semi || (topIsTarget1 && blendMode == 1))
                {
                    out[ox] = BlendOver(color, out[ox], eva, evb);
                    continue;
                }
            }

            if (semi && bottomIsTarget2)
                color = Blend(colors[0], colors[1], eva, evb);
            else if (topIsTarget1)
            {
                if (blendMode == 1 && bottomIsTarget2)
                    color = Blend(colors[0], colors[1], eva, evb);
                else if (blendMode == 2)
                    color = Brighten(colors[0], evy);
                else if (blendMode == 3)
                    color = Darken(colors[0], evy);
            }
        }
        out[ox] = sRgb[color];
    }
}

size_t Ppu_StateSize(void)
{
    return sizeof(struct PpuState);
}

void Ppu_Prepare(struct PpuState *state, const struct PpuRenderArgs *args)
{
    state->args = *args;
    PrepareSprites(state);
}

// The lines count output lines from the top of args->out, so each thread can
// draw its own part of the frame.
void Ppu_RenderBand(const struct PpuState *state, int firstOutLine, int lastOutLine)
{
    const struct PpuRenderArgs *args = &state->args;
    struct Band b;
    int y;

    memset(b.rowKey, 0xFF, sizeof(b.rowKey));
    memset(b.lineKey, 0xFF, sizeof(b.lineKey));
    memset(b.rowLine, 0, sizeof(b.rowLine));
    for (y = firstOutLine; y < lastOutLine; y++)
        RenderOutLine(state, &b, args->firstLine * args->scale + y, args->out + y * args->stride);
}

void Ppu_Render(const struct PpuRenderArgs *args)
{
    static struct PpuState state;

    Ppu_Prepare(&state, args);
    Ppu_RenderBand(&state, 0, (args->lastLine - args->firstLine) * args->scale);
}
