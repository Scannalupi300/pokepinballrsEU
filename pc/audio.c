// Sound output of the native build: the Direct Sound samples mixed by the m4a
// engine, plus the four PSG channels driven by the sound registers, resampled
// to the host rate.

#include "host.h"

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;

#define IO8(offset) (*(volatile u8 *)(GBA_IO + (offset)))

// Registers
#define NR10 0x60
#define NR11 0x62
#define NR12 0x63
#define NR13 0x64
#define NR14 0x65
#define NR21 0x68
#define NR22 0x69
#define NR23 0x6C
#define NR24 0x6D
#define NR30 0x70
#define NR31 0x72
#define NR32 0x73
#define NR33 0x74
#define NR34 0x75
#define NR41 0x78
#define NR42 0x79
#define NR43 0x7C
#define NR44 0x7D
#define NR50 0x80
#define NR51 0x81
#define SOUNDCNT_H 0x82
#define SOUNDCNT_X 0x84
#define WAVE_RAM 0x90

#define GB_CLOCK 4194304.0

struct PsgChannel
{
    int on;
    int volume;
    int envDir;
    int envPeriod;
    int envTimer;
    int length;
    double phase;
    // channel 1
    int sweepTimer;
    int sweepFreq;
    // channel 4
    u16 lfsr;
};

// The state of the sound generators, saved with the game.
static struct
{
    struct PsgChannel psg[4];
    double sequencer;
    int sequencerStep;
} sAudio;

#define sPsg sAudio.psg
#define sSequencer sAudio.sequencer
#define sSequencerStep sAudio.sequencerStep

void *Audio_StateData(int *size)
{
    *size = sizeof(sAudio);
    return &sAudio;
}

static const u8 sDuty[4][8] = {
    {0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 1, 1, 1},
    {0, 1, 1, 1, 1, 1, 1, 0},
};

static const u8 sEnvelopeReg[4] = {NR12, NR22, 0, NR42};
static const u8 sControlReg[4] = {NR14, NR24, NR34, NR44};

static void Trigger(int ch)
{
    struct PsgChannel *c = &sPsg[ch];

    if (ch == 2)
    {
        c->on = (IO8(NR30) & 0x80) != 0;
        c->length = 256 - IO8(NR31);
        c->phase = 0;
        return;
    }

    {
        u8 env = IO8(sEnvelopeReg[ch]);
        c->on = (env & 0xF8) != 0;
        c->volume = env >> 4;
        c->envDir = (env & 8) ? 1 : -1;
        c->envPeriod = env & 7;
        c->envTimer = c->envPeriod;
    }
    c->length = 64 - (IO8(ch == 0 ? NR11 : ch == 1 ? NR21 : NR41) & 0x3F);
    if (ch == 0)
    {
        c->sweepFreq = IO8(NR13) | ((IO8(NR14) & 7) << 8);
        c->sweepTimer = (IO8(NR10) >> 4) & 7;
    }
    if (ch == 3)
        c->lfsr = (IO8(NR43) & 8) ? 0x7F : 0x7FFF;
}

// After the m4a engine has written the registers for this frame: a write with
// the restart bit (which reads back as 0 on the GBA) starts the channel.
void Psg_Update(void)
{
    int ch;

    for (ch = 0; ch < 4; ch++)
    {
        u8 control = IO8(sControlReg[ch]);

        if (control & 0x80)
        {
            IO8(sControlReg[ch]) = control & 0x7F;
            Trigger(ch);
        }
    }
    if (!(IO8(NR30) & 0x80))
        sPsg[2].on = 0;
}

static void ClockSequencer(void)
{
    int ch;

    // Length counters at 256 Hz
    if ((sSequencerStep & 1) == 0)
    {
        for (ch = 0; ch < 4; ch++)
        {
            if ((IO8(sControlReg[ch]) & 0x40) && sPsg[ch].length > 0)
            {
                if (--sPsg[ch].length == 0)
                    sPsg[ch].on = 0;
            }
        }
    }

    // Sweep at 128 Hz
    if ((sSequencerStep & 3) == 2)
    {
        struct PsgChannel *c = &sPsg[0];
        u8 sweep = IO8(NR10);
        int time = (sweep >> 4) & 7;

        if (time && --c->sweepTimer <= 0)
        {
            int delta = c->sweepFreq >> (sweep & 7);
            int freq = (sweep & 8) ? c->sweepFreq - delta : c->sweepFreq + delta;

            c->sweepTimer = time;
            if (freq > 2047)
            {
                c->on = 0;
            }
            else if ((sweep & 7) && freq >= 0)
            {
                c->sweepFreq = freq;
                IO8(NR13) = freq & 0xFF;
                IO8(NR14) = (IO8(NR14) & ~7) | (freq >> 8);
            }
        }
    }

    // Envelopes at 64 Hz
    if (sSequencerStep == 7)
    {
        for (ch = 0; ch < 4; ch++)
        {
            struct PsgChannel *c = &sPsg[ch];

            if (ch == 2 || c->envPeriod == 0)
                continue;
            if (--c->envTimer <= 0)
            {
                c->envTimer = c->envPeriod;
                if (c->volume + c->envDir >= 0 && c->volume + c->envDir <= 15)
                    c->volume += c->envDir;
            }
        }
    }

    sSequencerStep = (sSequencerStep + 1) & 7;
}

// Output of a channel in half steps of the 4-bit level, centered on zero.
static int ChannelSample(int ch, double rate)
{
    struct PsgChannel *c = &sPsg[ch];
    int freqReg;
    int out = 0;

    if (!c->on)
        return 0;

    switch (ch)
    {
    case 0:
    case 1:
        freqReg = ch == 0 ? (IO8(NR13) | ((IO8(NR14) & 7) << 8)) : (IO8(NR23) | ((IO8(NR24) & 7) << 8));
        c->phase += (GB_CLOCK / 32.0 / (2048 - freqReg)) / rate;
        c->phase -= (int)c->phase;
        out = sDuty[IO8(ch == 0 ? NR11 : NR21) >> 6][(int)(c->phase * 8)] ? c->volume : -c->volume;
        break;
    case 2:
    {
        static const u8 shifts[4] = {8, 0, 1, 2};
        u8 volume = IO8(NR32);
        int index, sample;

        freqReg = IO8(NR33) | ((IO8(NR34) & 7) << 8);
        c->phase += (GB_CLOCK / 2.0 / (2048 - freqReg)) / rate;
        while (c->phase >= 32)
            c->phase -= 32;
        index = (int)c->phase;
        sample = IO8(WAVE_RAM + index / 2);
        sample = (index & 1) ? (sample & 0xF) : (sample >> 4);
        out = sample * 2 - 15;
        if (volume & 0x80)
            out = out * 3 / 4;
        else if (shifts[(volume >> 5) & 3] == 8)
            out = 0;
        else
            out >>= shifts[(volume >> 5) & 3];
        break;
    }
    case 3:
    {
        u8 poly = IO8(NR43);
        double divisor = (poly & 7) ? (poly & 7) : 0.5;
        double clock = GB_CLOCK / 8.0 / divisor / (double)(2 << (poly >> 4));

        c->phase += clock / rate;
        while (c->phase >= 1.0)
        {
            int bit = (c->lfsr ^ (c->lfsr >> 1)) & 1;
            c->phase -= 1.0;
            c->lfsr >>= 1;
            if (poly & 8)
                c->lfsr = (c->lfsr & ~0x40) | (bit << 6);
            else
                c->lfsr |= bit << 14;
        }
        out = (c->lfsr & 1) ? -c->volume : c->volume;
        break;
    }
    }
    return out;
}

static void PsgSample(int *right, int *left, double rate)
{
    u8 nr50 = IO8(NR50);
    u8 nr51 = IO8(NR51);
    int ratio = IO8(SOUNDCNT_H) & 3;
    int r = 0, l = 0;
    int ch;

    sSequencer += 512.0 / rate;
    while (sSequencer >= 1.0)
    {
        sSequencer -= 1.0;
        ClockSequencer();
    }

    for (ch = 0; ch < 4; ch++)
    {
        int s = ChannelSample(ch, rate);
        if (nr51 & (1 << ch))
            r += s;
        if (nr51 & (0x10 << ch))
            l += s;
    }

    r *= (nr50 & 7) + 1;
    l *= ((nr50 >> 4) & 7) + 1;
    if (ratio < 2)
    {
        r >>= 2 - ratio;
        l >>= 2 - ratio;
    }
    // Half steps: a full channel at full volume is +-60.
    *right = r / 2;
    *left = l / 2;
}

#define MAX_OUTPUT_FRAMES 4096

static s16 sOutput[MAX_OUTPUT_FRAMES * 2];
static double sInputPos;
static s32 sPrevRight, sPrevLeft;

// The mixer rounds down, so its output drifts below zero; the GBA's analog
// output is AC coupled. A high-pass filter at about 8 Hz does the same.
struct HighPassState
{
    double in, out;
};

static struct HighPassState sHighPass[2];

static s32 HighPass(struct HighPassState *state, s32 value)
{
    state->out = 0.999 * (state->out + value - state->in);
    state->in = value;
    return (s32)state->out;
}

void Audio_PushPcm(const int8_t *right, const int8_t *left, uint32_t count, uint32_t rate)
{
    u16 soundcntH = GBA_IO16(SOUNDCNT_H);
    int shiftA = (soundcntH & 4) ? 1 : 0;
    int shiftB = (soundcntH & 8) ? 1 : 0;
    double step = (double)rate / HOST_AUDIO_RATE;
    u32 target = HOST_AUDIO_RATE / 20;
    u32 queued = Host_AudioQueued();
    u32 frames = 0;

    Psg_Update();
    if (!(IO8(SOUNDCNT_X) & 0x80))
        return;

    // Keep about 50 ms queued: consume the input a little faster or slower.
    if (queued > target * 3)
        return;
    step *= 1.0 + 0.005 * ((double)queued - target) / target;

    while (sInputPos < count && frames < MAX_OUTPUT_FRAMES)
    {
        int i = (int)sInputPos;
        double frac = sInputPos - i;
        s32 r0 = i == 0 ? sPrevRight : right[i - 1];
        s32 l0 = i == 0 ? sPrevLeft : left[i - 1];
        double a = r0 + (right[i] - r0) * frac;
        double b = l0 + (left[i] - l0) * frac;
        int psgRight, psgLeft;
        s32 outRight = 0, outLeft = 0;

        PsgSample(&psgRight, &psgLeft, HOST_AUDIO_RATE);

        // Direct Sound A and B: sample << 1 at 100%.
        if (soundcntH & 0x0100) outRight += (s32)(a * 2) >> !shiftA;
        if (soundcntH & 0x0200) outLeft += (s32)(a * 2) >> !shiftA;
        if (soundcntH & 0x1000) outRight += (s32)(b * 2) >> !shiftB;
        if (soundcntH & 0x2000) outLeft += (s32)(b * 2) >> !shiftB;
        outRight = HighPass(&sHighPass[0], (outRight + psgRight) * 64);
        outLeft = HighPass(&sHighPass[1], (outLeft + psgLeft) * 64);
        if (outRight > 32767) outRight = 32767;
        if (outRight < -32768) outRight = -32768;
        if (outLeft > 32767) outLeft = 32767;
        if (outLeft < -32768) outLeft = -32768;
        sOutput[frames * 2] = outLeft;
        sOutput[frames * 2 + 1] = outRight;
        frames++;
        sInputPos += step;
    }
    sInputPos -= count;
    sPrevRight = right[count - 1];
    sPrevLeft = left[count - 1];

    if (!Host_FastForward())
        Host_AudioWrite(sOutput, frames);
}
