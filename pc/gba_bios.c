// BIOS calls, DMA and the frame/interrupt timing for the native build.
// VBlankIntrWait runs the scanlines since the previous call: it records the
// registers of each line, raises the V-count and V-blank interrupts at their
// lines and hands the finished frame to the display, which draws it on its
// own thread.

#include "global.h"
#include "main.h"
#include "host.h"
#include "hooks.h"

// AgbMain copies the interrupt handler to IWRAM; here it is never run.
u32 IntrMain[0x200];

// The state of the display that is saved with the game.
static struct
{
    int line;
    // Internal reference points of the affine backgrounds: latched at the start
    // of the frame and when the game writes the registers, then advanced by
    // PB/PD every line.
    s32 affineX[2], affineY[2];
    u32 affineRegX[2], affineRegY[2];
} sDisplay = {DISPLAY_HEIGHT + 1};

// Where the lines of the current frame go.
static struct PpuFrame *sCapture;

void *Bios_StateData(int *size)
{
    *size = sizeof(sDisplay);
    return &sDisplay;
}

#define REG_BGX(n)  GBA_IO32(0x28 + ((n) - 2) * 0x10)
#define REG_BGY(n)  GBA_IO32(0x2C + ((n) - 2) * 0x10)
#define REG_BGPB(n) ((s16)GBA_IO16(0x22 + ((n) - 2) * 0x10))
#define REG_BGPD(n) ((s16)GBA_IO16(0x26 + ((n) - 2) * 0x10))

static s32 SignExtend28(u32 value)
{
    return (s32)(value << 4) >> 4;
}

static void StartFrameCapture(struct PpuFrame *frame)
{
    int i;

    sCapture = frame;
    for (i = 0; i < 2; i++)
    {
        sDisplay.affineRegX[i] = REG_BGX(i + 2);
        sDisplay.affineRegY[i] = REG_BGY(i + 2);
        sDisplay.affineX[i] = SignExtend28(sDisplay.affineRegX[i]);
        sDisplay.affineY[i] = SignExtend28(sDisplay.affineRegY[i]);
    }
}

static void CaptureLine(int line)
{
    struct PpuLine *out = &sCapture->lines[line];
    int i;

    // A write to an affine reference point register restarts it mid-frame.
    for (i = 0; i < 2; i++)
    {
        if (REG_BGX(i + 2) != sDisplay.affineRegX[i])
        {
            sDisplay.affineRegX[i] = REG_BGX(i + 2);
            sDisplay.affineX[i] = SignExtend28(sDisplay.affineRegX[i]);
        }
        if (REG_BGY(i + 2) != sDisplay.affineRegY[i])
        {
            sDisplay.affineRegY[i] = REG_BGY(i + 2);
            sDisplay.affineY[i] = SignExtend28(sDisplay.affineRegY[i]);
        }
    }

    Host_Memcpy(out->io, (const void *)GBA_IO, PPU_IO_SIZE);
    for (i = 0; i < 2; i++)
    {
        out->affineX[i] = sDisplay.affineX[i];
        out->affineY[i] = sDisplay.affineY[i];
        sDisplay.affineX[i] += REG_BGPB(i + 2);
        sDisplay.affineY[i] += REG_BGPD(i + 2);
    }
}

static void CaptureFrameMemory(struct PpuFrame *frame)
{
    Host_Memcpy(frame->vram, (const void *)GBA_VRAM, PPU_VRAM_SIZE);
    Host_Memcpy(frame->pltt, (const void *)GBA_PLTT, PPU_PLTT_SIZE);
    Host_Memcpy(frame->oam, (const void *)GBA_OAM, PPU_OAM_SIZE);
}

static int IsGbaRam(u32 addr, u32 size)
{
    static const u32 regions[][2] = {
        {GBA_EWRAM, GBA_EWRAM_SIZE},
        {GBA_IWRAM, GBA_IWRAM_SIZE},
        {GBA_IO, GBA_IO_SIZE},
        {GBA_PLTT, GBA_PLTT_SIZE},
        {GBA_VRAM, GBA_VRAM_SIZE},
        {GBA_OAM, GBA_OAM_SIZE},
        {GBA_SRAM, 0x10000},
    };
    u32 i;

    for (i = 0; i < ARRAY_COUNT(regions); i++)
    {
        if (addr >= regions[i][0] && addr + size <= regions[i][0] + regions[i][1])
            return TRUE;
    }
    return FALSE;
}

static void RunDma(u32 dmaNum)
{
    vu32 *regs = (vu32 *)(REG_ADDR_DMA0 + dmaNum * 12);
    u32 src = regs[0];
    u32 dest = regs[1];
    u16 control = regs[2] >> 16;
    u32 count = regs[2] & 0xFFFF;
    u32 unit = (control & DMA_32BIT) ? 4 : 2;
    int srcStep, destStep;
    u32 i;

    if (dmaNum != 3)
        count &= 0x3FFF;
    if (count == 0)
        count = (dmaNum == 3) ? 0x10000 : 0x4000;

    src &= ~(unit - 1);
    dest &= ~(unit - 1);
    switch ((control >> 7) & 3)
    {
    case 0: srcStep = unit; break;
    case 1: srcStep = -unit; break;
    default: srcStep = 0; break;
    }
    switch ((control >> 5) & 3)
    {
    case 1: destStep = -unit; break;
    case 2: destStep = 0; break;
    default: destStep = unit; break;
    }

    if (!IsGbaRam(destStep < 0 ? dest - (count - 1) * unit : dest, destStep ? count * unit : unit))
    {
        Host_Log("DMA%u to %08X (%u units) ignored\n", dmaNum, dest, count);
    }
    else
    {
        // Below 0x02000000 is the BIOS, which the GBA doesn't let DMA read:
        // count it as zeros.
        int fromBios = src < GBA_EWRAM;

        for (i = 0; i < count; i++)
        {
            if (unit == 4)
                *(vu32 *)dest = fromBios ? 0 : *(vu32 *)src;
            else
                *(vu16 *)dest = fromBios ? 0 : *(vu16 *)src;
            src += srcStep;
            dest += destStep;
        }
    }

    if (!(control & DMA_REPEAT) || (control & DMA_START_MASK) == DMA_START_NOW)
        regs[2] &= ~(DMA_ENABLE << 16);
}

void HostDmaSet(u32 dmaNum, u32 src, u32 dest, u32 control)
{
    vu32 *regs = (vu32 *)(REG_ADDR_DMA0 + dmaNum * 12);

    regs[0] = src;
    regs[1] = dest;
    regs[2] = control;
    if (src < GBA_EWRAM)
        Host_Log("DMA%u from %08X to %08X, called from %p\n", dmaNum, src, dest, __builtin_return_address(0));
    if ((control & (DMA_ENABLE << 16)) && ((control >> 16) & DMA_START_MASK) == DMA_START_NOW)
        RunDma(dmaNum);
}

// Runs the DMAs that start at H-blank or V-blank, and the immediate ones the
// game started by writing the registers itself.
static void RunTimedDmas(u16 timing)
{
    u32 i;

    for (i = 0; i < 4; i++)
    {
        u16 control = *(vu16 *)(REG_ADDR_DMA0 + i * 12 + 10);
        if ((control & DMA_ENABLE) && (control & DMA_START_MASK) == timing)
            RunDma(i);
    }
}

static const u16 sIntrOrder[] = {
    INTR_FLAG_SERIAL, INTR_FLAG_TIMER3, INTR_FLAG_VBLANK, INTR_FLAG_HBLANK,
    INTR_FLAG_VCOUNT, INTR_FLAG_TIMER0, INTR_FLAG_TIMER1, INTR_FLAG_TIMER2,
    INTR_FLAG_DMA0, INTR_FLAG_DMA1, INTR_FLAG_DMA2, INTR_FLAG_DMA3,
    INTR_FLAG_KEYPAD, INTR_FLAG_GAMEPAK,
};

// IntrMain: the handler for the interrupt is gIntrTable[its position in IntrMain's order].
static void RaiseInterrupt(u16 flag)
{
    u32 i;

    REG_IF |= flag;
    if (!(REG_IME & 1) || !(REG_IE & flag))
        return;

    for (i = 0; i < ARRAY_COUNT(sIntrOrder); i++)
    {
        if (sIntrOrder[i] == flag)
        {
            REG_IF &= ~flag;
            if (gIntrTable[i])
                gIntrTable[i]();
            break;
        }
    }
}

static void RunLine(int line)
{
    u16 dispstat;

    REG_VCOUNT = line;
    dispstat = REG_DISPSTAT & ~(DISPSTAT_VBLANK | DISPSTAT_HBLANK | DISPSTAT_VCOUNT);
    if (line >= DISPLAY_HEIGHT && line < 227)
        dispstat |= DISPSTAT_VBLANK;
    if (line == (dispstat >> 8))
        dispstat |= DISPSTAT_VCOUNT;
    REG_DISPSTAT = dispstat;

    if (line == DISPLAY_HEIGHT)
    {
        RunTimedDmas(DMA_START_VBLANK);
        if (dispstat & DISPSTAT_VBLANK_INTR)
            RaiseInterrupt(INTR_FLAG_VBLANK);
    }

    // The V-count handler waits for the H-blank of its line and then changes
    // the registers for the lines below, so the line is recorded before it runs.
    if (line < DISPLAY_HEIGHT)
        CaptureLine(line);

    REG_DISPSTAT |= DISPSTAT_HBLANK;
    if ((REG_DISPSTAT & DISPSTAT_VCOUNT) && (REG_DISPSTAT & DISPSTAT_VCOUNT_INTR))
        RaiseInterrupt(INTR_FLAG_VCOUNT);
    if (line < DISPLAY_HEIGHT)
        RunTimedDmas(DMA_START_HBLANK);
    if (REG_DISPSTAT & DISPSTAT_HBLANK_INTR)
        RaiseInterrupt(INTR_FLAG_HBLANK);
}

// The writes of DefaultMainCallback that change the picture. The game makes
// them after the V-blank, so the frame it just computed would be on screen one
// frame later; on a PC nothing stops it being drawn right away.
void Bios_ApplyDisplayRegisters(void)
{
    DmaCopy32(3, gOamBuffer, OAM, OAM_SIZE);
    REG_DISPCNT = gMain.dispcntBackup;
    REG_BG0HOFS = gMain.bgOffsets[0].xOffset;
    REG_BG0VOFS = gMain.bgOffsets[0].yOffset;
    REG_BG1HOFS = gMain.bgOffsets[1].xOffset;
    REG_BG1VOFS = gMain.bgOffsets[1].yOffset;
    REG_BG2HOFS = gMain.bgOffsets[2].xOffset;
    REG_BG2VOFS = gMain.bgOffsets[2].yOffset;
    REG_BG3HOFS = gMain.bgOffsets[3].xOffset;
    REG_BG3VOFS = gMain.bgOffsets[3].yOffset;
    if (gMain.blendEnabled)
    {
        REG_BLDCNT = gMain.blendControl;
        REG_BLDALPHA = gMain.blendAlpha;
        REG_BLDY = gMain.blendBrightness;
    }
}

// The lines of a frame, for the extra passes of the table view (pc/hooks.c):
// the same as the real frame's lines.
void Bios_CaptureLines(struct PpuFrame *frame)
{
    StartFrameCapture(frame);
    for (sDisplay.line = 0; sDisplay.line <= DISPLAY_HEIGHT; sDisplay.line++)
        RunLine(sDisplay.line);
    CaptureFrameMemory(frame);
}

// Runs the scanlines from the line after the previous V-blank to the next
// V-blank, then shows the frame and waits for its time.
void VBlankIntrWait(void)
{
    struct FrameSet *frame;

    Hook_OnVBlankWait();
    RunTimedDmas(DMA_START_NOW);
    INTR_CHECK &= ~INTR_FLAG_VBLANK;

    for (; sDisplay.line < 228; sDisplay.line++)
        RunLine(sDisplay.line);

    frame = Hook_FrameForCapture();
    if (gPcOptions.lowLatency && gMainCallback == DefaultMainCallback && (REG_DISPSTAT & DISPSTAT_VBLANK_INTR))
        Bios_ApplyDisplayRegisters();

    Bios_CaptureLines(&frame->main);
    Hook_FrameDone(frame);
    Host_PublishFrame(frame);
    Host_WaitFrame();
}

void CpuSet(const void *src, void *dest, u32 control)
{
    u32 count = control & 0x1FFFFF;
    int fixed = control & CPU_SET_SRC_FIXED;
    u32 i;

    if (control & CPU_SET_32BIT)
    {
        const vu32 *s = (const vu32 *)((u32)src & ~3);
        vu32 *d = (vu32 *)((u32)dest & ~3);
        for (i = 0; i < count; i++)
        {
            *d++ = *s;
            if (!fixed)
                s++;
        }
    }
    else
    {
        const vu16 *s = (const vu16 *)((u32)src & ~1);
        vu16 *d = (vu16 *)((u32)dest & ~1);
        for (i = 0; i < count; i++)
        {
            *d++ = *s;
            if (!fixed)
                s++;
        }
    }
}

void CpuFastSet(const void *src, void *dest, u32 control)
{
    u32 count = ((control & 0x1FFFFF) + 7) & ~7;

    CpuSet(src, dest, CPU_SET_32BIT | (control & CPU_FAST_SET_SRC_FIXED) | count);
}

void LZ77UnCompWram(const void *src, void *dest)
{
    const u8 *s = src;
    u8 *d = dest;
    u32 size = (s[1] | (s[2] << 8) | (s[3] << 16));
    u32 written = 0;

    s += 4;
    while (written < size)
    {
        u8 flags = *s++;
        int bit;

        for (bit = 0; bit < 8 && written < size; bit++, flags <<= 1)
        {
            if (flags & 0x80)
            {
                u32 length = (s[0] >> 4) + 3;
                u32 disp = (((s[0] & 0xF) << 8) | s[1]) + 1;
                s += 2;
                while (length-- && written < size)
                {
                    d[written] = d[written - disp];
                    written++;
                }
            }
            else
            {
                d[written++] = *s++;
            }
        }
    }
}

void LZ77UnCompVram(const void *src, void *dest)
{
    LZ77UnCompWram(src, dest);
}

void RegisterRamReset(u32 resetFlags)
{
    u32 i;

    if (resetFlags & RESET_EWRAM)
        CpuFill32(0, (void *)GBA_EWRAM, GBA_EWRAM_SIZE);
    if (resetFlags & RESET_IWRAM)
        CpuFill32(0, (void *)GBA_IWRAM, GBA_IWRAM_SIZE - 0x200);
    if (resetFlags & RESET_PALETTE)
        CpuFill32(0, (void *)GBA_PLTT, GBA_PLTT_SIZE);
    if (resetFlags & RESET_VRAM)
        CpuFill32(0, (void *)GBA_VRAM, GBA_VRAM_SIZE);
    if (resetFlags & RESET_OAM)
        CpuFill32(0, (void *)GBA_OAM, GBA_OAM_SIZE);
    if (resetFlags & RESET_SIO_REGS)
    {
        for (i = 0x120; i < 0x160; i += 2)
            if (i != 0x130 && i != 0x132)
                GBA_IO16(i) = 0;
    }
    if (resetFlags & RESET_SOUND_REGS)
    {
        for (i = 0x60; i < 0xB0; i += 2)
            GBA_IO16(i) = 0;
    }
    if (resetFlags & RESET_REGS)
    {
        for (i = 0; i < 0x60; i += 2)
            GBA_IO16(i) = 0;
        for (i = 0xB0; i < 0x120; i += 2)
            GBA_IO16(i) = 0;
        for (i = 0x200; i < 0x210; i += 2)
            GBA_IO16(i) = 0;
        REG_DISPCNT = DISPCNT_FORCED_BLANK;
        REG_BG2PA = 0x100;
        REG_BG2PD = 0x100;
        REG_BG3PA = 0x100;
        REG_BG3PD = 0x100;
    }
    REG_KEYINPUT = KEYS_MASK;
}

u16 Sqrt(u32 num)
{
    u32 root = 0;
    u32 bit = 1u << 30;

    while (bit > num)
        bit >>= 2;
    while (bit)
    {
        if (num >= root + bit)
        {
            num -= root + bit;
            root = (root >> 1) + bit;
        }
        else
        {
            root >>= 1;
        }
        bit >>= 2;
    }
    return root;
}

// The BIOS polynomial, so that angles match the GBA exactly.
static s32 ArcTanBios(s32 i)
{
    s32 a = -((i * i) >> 14);
    s32 b = ((0xA9 * a) >> 14) + 0x390;

    b = ((b * a) >> 14) + 0x91C;
    b = ((b * a) >> 14) + 0xFB6;
    b = ((b * a) >> 14) + 0x16AA;
    b = ((b * a) >> 14) + 0x2081;
    b = ((b * a) >> 14) + 0x3651;
    b = ((b * a) >> 14) + 0xA2F9;
    return (i * b) >> 16;
}

u16 ArcTan2(s16 x16, s16 y16)
{
    s32 x = x16;
    s32 y = y16;

    if (y == 0)
        return x >= 0 ? 0 : 0x8000;
    if (x == 0)
        return y >= 0 ? 0x4000 : 0xC000;

    if (y >= 0)
    {
        if (x >= 0)
        {
            if (x >= y)
                return ArcTanBios((y << 14) / x);
        }
        else if (-x >= y)
        {
            return ArcTanBios((y << 14) / x) + 0x8000;
        }
        return 0x4000 - ArcTanBios((x << 14) / y);
    }
    else
    {
        if (x <= 0)
        {
            if (-x > -y)
                return ArcTanBios((y << 14) / x) + 0x8000;
        }
        else if (x >= -y)
        {
            return ArcTanBios((y << 14) / x) + 0x10000;
        }
        return 0xC000 - ArcTanBios((x << 14) / y);
    }
}

void SoftReset(u32 resetFlags)
{
    Host_Fatal("SoftReset(%X) is not supported", resetFlags);
}
