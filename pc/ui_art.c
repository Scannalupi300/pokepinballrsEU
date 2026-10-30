// The game's own art for the menus and panels: the Pokédex font, the frame of
// the Options screen and its sprites. Everything is drawn in GBA pixels and
// then scaled by a whole number, so it sits on the same pixel grid as the game.

#include <stdlib.h>
#include <string.h>

#include "pc.h"

// Glyphs: each is 8 pixels wide and two tiles high, the lower tile one row of
// tiles (0x400 bytes) after the upper. The code is the offset of the upper
// tile, with the width to advance in its low 4 bits. The table is the one the
// European Pokédex text uses (ApplyEuropeanDexEncoding in tools/preproc).
#define GLYPH_LOWER_OFFSET 0x400
#define SPACE_WIDTH 4

struct Glyph
{
    wchar_t c;
    uint16_t code;
};

static const struct Glyph sGlyphs[] = {
    {L'-', 0x2826}, {L'0', 0x2886}, {L'1', 0x28A4}, {L'2', 0x28C6}, {L'3', 0x28E6}, {L'4', 0x2906}, {L'5', 0x2926},
    {L'6', 0x2946}, {L'7', 0x2966}, {L'8', 0x2986}, {L'9', 0x29A6},
    {L'A', 0x29E6}, {L'B', 0x2A06}, {L'C', 0x2A26}, {L'D', 0x2A46}, {L'E', 0x2A66}, {L'F', 0x2A86}, {L'G', 0x2AA6},
    {L'H', 0x2AC6}, {L'I', 0x2AE2}, {L'J', 0x2B06}, {L'K', 0x2B26}, {L'L', 0x2B46}, {L'M', 0x2B66}, {L'N', 0x2B86},
    {L'O', 0x2BA6}, {L'P', 0x2BC6}, {L'Q', 0x2BE6}, {L'R', 0x3006}, {L'S', 0x3026}, {L'T', 0x3046}, {L'U', 0x3066},
    {L'V', 0x3086}, {L'W', 0x30A6}, {L'X', 0x30C6}, {L'Y', 0x30E6}, {L'Z', 0x3106},
    {L'a', 0x3126}, {L'b', 0x3146}, {L'c', 0x3166}, {L'd', 0x3186}, {L'e', 0x31A6}, {L'f', 0x31C6}, {L'g', 0x31E6},
    {L'h', 0x3206}, {L'i', 0x3222}, {L'j', 0x3246}, {L'k', 0x3265}, {L'l', 0x3284}, {L'm', 0x32A6}, {L'n', 0x32C6},
    {L'o', 0x32E6}, {L'p', 0x3306}, {L'q', 0x3326}, {L'r', 0x3346}, {L's', 0x3366}, {L't', 0x3386}, {L'u', 0x33A6},
    {L'v', 0x33C6}, {L'w', 0x33E6}, {L'x', 0x3806}, {L'y', 0x3826}, {L'z', 0x3845},
    {L'×', 0x38E6}, {L'!', 0x3946}, {L'?', 0x3968}, {L':', 0x3986}, {L';', 0x39A6}, {L',', 0x39C4}, {L'.', 0x39E4},
    {L'(', 0x3A24}, {L')', 0x3A44}, {L'/', 0x4AC6}, {L'\'', 0x3AC4}, {L'»', 0x4A66}, {L'«', 0x4A46},
    {L'é', 0x43E6}, {L'è', 0x4806}, {L'à', 0x4286}, {L'á', 0x4266}, {L'â', 0x4246}, {L'ä', 0x4226},
    {L'ì', 0x4304}, {L'í', 0x42E4}, {L'î', 0x42C4}, {L'ò', 0x4886}, {L'ó', 0x4866}, {L'ô', 0x4846}, {L'ö', 0x4826},
    {L'ù', 0x4386}, {L'ú', 0x4366}, {L'û', 0x4346}, {L'ü', 0x4326}, {L'ê', 0x43C6}, {L'ç', 0x48C6}, {L'ñ', 0x48A5},
    {L'ß', 0x4906}, {L'À', 0x3BA6}, {L'Á', 0x3B86}, {L'Ä', 0x3B46}, {L'É', 0x4106}, {L'È', 0x4126}, {L'Í', 0x4004},
    {L'Ó', 0x4186}, {L'Ö', 0x4146}, {L'Ú', 0x4086}, {L'Ü', 0x4046}, {L'Ñ', 0x41C6},
    // The font doesn't have these: the closest it has.
    {L'Ù', 0x4086}, {L'Ì', 0x4004}, {L'Ò', 0x4186}, {L'+', 0x38E6}, {L'>', 0x4A66}, {L'<', 0x4A46},
};

#define MENU_WIDTH 240
#define MENU_HEIGHT 160

// The Options screen, with its big panel made tall enough for a list.
static uint32_t sBackground[MENU_WIDTH * MENU_HEIGHT];
static uint32_t sStripes[MENU_HEIGHT];      // a column of the frame
static uint32_t sPanelStripes[16];          // a column of the panel
static uint32_t sTabColor;
static uint32_t sSprites[ART_SPRITE_COUNT][32 * 48];
static const struct { uint8_t x, y, w, h, palette; } sSpriteBlocks[ART_SPRITE_COUNT] = {
    [ART_HAND] = {1, 0, 2, 2, 0},
    [ART_ARROW_LEFT] = {3, 0, 1, 1, 0},
    [ART_ARROW_RIGHT] = {9, 1, 1, 1, 0},
    [ART_TORCHIC_0] = {0, 2, 4, 6, 2},
    [ART_TORCHIC_1] = {4, 2, 4, 6, 2},
    [ART_TORCHIC_2] = {8, 2, 4, 6, 2},
    [ART_TORCHIC_3] = {12, 2, 4, 6, 2},
    [ART_TORCHIC_4] = {16, 2, 4, 6, 2},
};
static int sLanguage = -1;

static uint16_t GlyphCode(wchar_t c)
{
    unsigned i;

    if (c == L' ')
        return 0;
    for (i = 0; i < sizeof(sGlyphs) / sizeof(sGlyphs[0]); i++)
    {
        if (sGlyphs[i].c == c)
            return sGlyphs[i].code;
    }
    return 0x3968;  // ?
}

int Art_TextWidth(const wchar_t *text)
{
    int width = 0;

    for (; *text; text++)
    {
        int advance = GlyphCode(*text) & 0xF;

        width += advance ? advance : SPACE_WIDTH;
    }
    return width;
}

void Art_Text(uint32_t *target, int targetWidth, int targetHeight, int x, int y, const wchar_t *text, uint32_t color, int scale)
{
    const uint8_t *font = Hook_FontTiles();

    for (; *text; text++)
    {
        uint16_t code = GlyphCode(*text);
        int advance = code & 0xF;
        int offset = code & ~0xF;
        int gx, gy, sx, sy;

        if (!advance)
            advance = SPACE_WIDTH;
        for (gy = 0; code && gy < 16; gy++)
        {
            const uint8_t *row = font + offset + (gy < 8 ? 0 : GLYPH_LOWER_OFFSET) + (gy & 7) * 4;

            for (gx = 0; gx < 8; gx++)
            {
                int value = (gx & 1) ? (row[gx / 2] >> 4) : (row[gx / 2] & 0xF);

                if (!value)
                    continue;
                for (sy = 0; sy < scale; sy++)
                {
                    int py = y + gy * scale + sy;

                    if (py < 0 || py >= targetHeight)
                        continue;
                    for (sx = 0; sx < scale; sx++)
                    {
                        int px = x + gx * scale + sx;

                        if (px >= 0 && px < targetWidth)
                            target[py * targetWidth + px] = color;
                    }
                }
            }
        }
        x += advance * scale;
    }
}

void Art_Sprite(uint32_t *target, int targetWidth, int targetHeight, int x, int y, int sprite, int hFlip, int scale)
{
    int w = sSpriteBlocks[sprite].w * 8;
    int h = sSpriteBlocks[sprite].h * 8;
    int i, j, sx, sy;

    for (j = 0; j < h; j++)
    {
        for (i = 0; i < w; i++)
        {
            uint32_t c = sSprites[sprite][j * 32 + (hFlip ? w - 1 - i : i)];

            if (!(c >> 24))
                continue;
            for (sy = 0; sy < scale; sy++)
            {
                int py = y + j * scale + sy;

                if (py < 0 || py >= targetHeight)
                    continue;
                for (sx = 0; sx < scale; sx++)
                {
                    int px = x + i * scale + sx;

                    if (px >= 0 && px < targetWidth)
                        target[py * targetWidth + px] = c;
                }
            }
        }
    }
}

// The Options screen has three panels. The menu needs one big list: it keeps
// the top of the screen, moves the lower panel up to just below it and repeats
// the panel's plain rows to fill the gap.
#define HEADER_ROWS 16
#define PANEL_FIRST_ROW 60     // of the Options screen: above the lower panel
#define PANEL_PLAIN_ROW 112    // 8 rows of panel, between the original's rows of text
#define PANEL_PLAIN_COLUMN 20  // nothing on it but the panel's stripes
#define PANEL_TAB_BOTTOM 34    // of the menu: the title's tab ends here
#define PANEL_LAST_ROWS 24     // the bottom of the screen

static void BuildBackground(int language)
{
    static uint32_t full[MENU_WIDTH * MENU_HEIGHT];
    int y;

    Hook_OptionsBackground(full, language);

    for (y = 0; y < MENU_HEIGHT; y++)
    {
        int from;

        if (y < HEADER_ROWS)
            from = y;
        else if (y < HEADER_ROWS + (PANEL_PLAIN_ROW - PANEL_FIRST_ROW))
            from = PANEL_FIRST_ROW + (y - HEADER_ROWS);
        else if (y < MENU_HEIGHT - PANEL_LAST_ROWS)
            from = PANEL_PLAIN_ROW + (y & 7);
        else
            from = y;
        memcpy(&sBackground[y * MENU_WIDTH], &full[from * MENU_WIDTH], MENU_WIDTH * 4);

        // The rows of the original have the yellow arrows of the button list on them.
        if (y >= PANEL_TAB_BOTTOM && y < MENU_HEIGHT - PANEL_LAST_ROWS + 4)
        {
            int x;

            for (x = PANEL_PLAIN_COLUMN; x < MENU_WIDTH - PANEL_PLAIN_COLUMN; x++)
                sBackground[y * MENU_WIDTH + x] = sBackground[y * MENU_WIDTH + PANEL_PLAIN_COLUMN];
        }
    }

    for (y = 0; y < MENU_HEIGHT; y++)
        sStripes[y] = full[y * MENU_WIDTH + 7];
    for (y = 0; y < 16; y++)
        sPanelStripes[y] = full[(PANEL_PLAIN_ROW + y % 8) * MENU_WIDTH + 120];
    sTabColor = full[(PANEL_FIRST_ROW + 8) * MENU_WIDTH + 40];
}

void Art_SetLanguage(int language)
{
    int i;

    if (language == sLanguage)
        return;
    sLanguage = language;
    BuildBackground(language);
    for (i = 0; i < ART_SPRITE_COUNT; i++)
        Hook_OptionsSprite(sSprites[i], sSpriteBlocks[i].x, sSpriteBlocks[i].y, sSpriteBlocks[i].w, sSpriteBlocks[i].h, sSpriteBlocks[i].palette, language);
}

const uint32_t *Art_MenuBackground(void)
{
    return sBackground;
}

// A panel of the same make as the Options screen's, on its striped frame. All
// sizes in GBA pixels.
void Art_Frame(uint32_t *target, int targetWidth, int targetHeight, int scale)
{
    int x, y;

    for (y = 0; y < targetHeight; y++)
    {
        uint32_t c = sStripes[16 + (y / scale) % 8];

        for (x = 0; x < targetWidth; x++)
            target[y * targetWidth + x] = c;
    }
}

void Art_Panel(uint32_t *target, int targetWidth, int targetHeight, int x, int y, int w, int h, int scale)
{
    int i, j, sx, sy;

    for (j = 0; j < h; j++)
    {
        int inset = j == 0 || j == h - 1 ? 2 : j == 1 || j == h - 2 ? 1 : 0;
        uint32_t c = sPanelStripes[j & 15];

        for (i = inset; i < w - inset; i++)
        {
            for (sy = 0; sy < scale; sy++)
            {
                int py = (y + j) * scale + sy;

                if (py < 0 || py >= targetHeight)
                    continue;
                for (sx = 0; sx < scale; sx++)
                {
                    int px = (x + i) * scale + sx;

                    if (px >= 0 && px < targetWidth)
                        target[py * targetWidth + px] = c;
                }
            }
        }
    }
}

uint32_t Art_TabColor(void)
{
    return sTabColor;
}
