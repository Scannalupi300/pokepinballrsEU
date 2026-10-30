// C version of src/m4a_1.s (the m4a sound engine's assembly half) for the
// native build: mixer, sequencer and the sequence commands. It follows the
// assembly step by step, including the 8-bit wrapping of the mix buffer.

// The header declares these with the assembly's calling convention in mind
// (no arguments, or not the ones the callers pass).
#define MPlayMain MPlayMain_Declared
#define SoundMainBTM SoundMainBTM_Declared
#define ply_note ply_note_Declared
#include "gba/m4a_internal.h"
#undef MPlayMain
#undef SoundMainBTM
#undef ply_note
#include "host.h"

u32 MidiKeyToFreq(struct WaveData *wav, u8 key, u8 fineAdjust);

extern const u8 gClockTable[];
extern const s8 gDeltaEncodingTable[];
extern s8 gDpcmSampleBuffer[];
extern void *const gMPlayJumpTableTemplate[];

// The assembly's xpi/xpc halfwords are one word: the decoded DPCM block.
#define DPCM_BLOCK(chan) (*(u32 *)&(chan)->xpi)

typedef void (*PlyFunc)(struct MusicPlayerInfo *, struct MusicPlayerTrack *);
typedef void (*ChainFunc)(void *);
typedef u32 (*CgbFreqFunc)(u8, u8, u8);

u32 umul3232H32(u32 multiplier, u32 multiplicand)
{
    return (u32)(((u64)multiplier * multiplicand) >> 32);
}

// One mixed sample: the high byte of sample * volume, added with 8-bit wrap.
static inline void MixSample(s8 *right, s8 *left, s32 sample, u32 er, u32 el)
{
    *right = (s8)(u8)((u8)*right + (u8)((sample * (s32)er) >> 8));
    *left = (s8)(u8)((u8)*left + (u8)((sample * (s32)el) >> 8));
}

static s32 GetDpcmSample(struct SoundChannel *chan, u32 index)
{
    u32 block = index >> 6;

    if (DPCM_BLOCK(chan) != block)
    {
        const u8 *src = (const u8 *)chan->wav->data + block * 0x21;
        s8 *dst = gDpcmSampleBuffer;
        s32 value;
        u32 byte;
        int i;

        DPCM_BLOCK(chan) = block;
        value = (s8)*src++;
        *dst++ = value;
        byte = *src++;
        value += gDeltaEncodingTable[byte & 0xF];
        *dst++ = value;
        for (i = 0x40 - 2; i > 0; i -= 2)
        {
            byte = *src++;
            value += gDeltaEncodingTable[byte >> 4];
            *dst++ = value;
            value += gDeltaEncodingTable[byte & 0xF];
            *dst++ = value;
        }
    }

    return gDpcmSampleBuffer[index & 0x3F];
}

struct MixState
{
    s8 *out;
    u32 count;
    u32 er, el;
    u32 loopStart; // pointer, or index for compressed samples
    s32 loopLength;
};

// SoundMainRAM_MixReversedOrCompressed
static void MixReversedOrCompressed(struct SoundChannel *chan, struct MixState *ms, u32 divFreq,
                                    u32 *cpOut, s32 *ctOut, u32 *fwOut)
{
    struct WaveData *wav = chan->wav;
    u32 cp = chan->cp;
    s32 ct = chan->ct;
    u32 fw = chan->fw;
    u32 step;
    s32 s0, delta;
    u32 i;

    if (!(chan->status & 0x20))
    {
        chan->status |= 0x20;
        if (chan->type & 0x10)
        {
            cp = wav->size + (u32)wav * 2 + 0x20 - cp;
            chan->cp = cp;
        }
        if (wav->type != 0)
        {
            cp = cp - (u32)wav - 0x10;
            chan->cp = cp;
        }
    }

    step = (chan->type & 8) ? 0x800000 : chan->freq * divFreq;

    if (wav->type != 0)
    {
        DPCM_BLOCK(chan) = 0xFF000000;
        if (!(chan->type & 0x10))
        {
            s0 = GetDpcmSample(chan, cp);
            cp++;
            delta = GetDpcmSample(chan, cp) - s0;
            for (i = 0; i < ms->count; i++)
            {
                MixSample(&ms->out[i], &ms->out[i + PCM_DMA_BUF_SIZE], s0 + (((s32)fw * delta) >> 23), ms->er, ms->el);
                fw += step;
                if (fw >> 23)
                {
                    u32 n = fw >> 23;
                    s32 skip;

                    fw &= ~0x3F800000;
                    ct -= n;
                    if (ct <= 0)
                    {
                        if (ms->loopLength == 0)
                            goto stop;
                        cp = wav->loopStart;
                        skip = -ct;
                        while ((ct += ms->loopLength) <= 0)
                            skip -= ms->loopLength;
                        cp += skip;
                        s0 = GetDpcmSample(chan, cp);
                    }
                    else if (n - 1 != 0)
                    {
                        cp += n - 1;
                        s0 = GetDpcmSample(chan, cp);
                    }
                    else
                    {
                        s0 += delta;
                    }
                    cp++;
                    delta = GetDpcmSample(chan, cp) - s0;
                }
            }
            cp--;
        }
        else
        {
            cp--;
            s0 = GetDpcmSample(chan, cp);
            cp--;
            delta = GetDpcmSample(chan, cp) - s0;
            for (i = 0; i < ms->count; i++)
            {
                MixSample(&ms->out[i], &ms->out[i + PCM_DMA_BUF_SIZE], s0 + (((s32)fw * delta) >> 23), ms->er, ms->el);
                fw += step;
                if (fw >> 23)
                {
                    u32 n = fw >> 23;

                    fw &= ~0x3F800000;
                    ct -= n;
                    if (ct <= 0)
                        goto stop;
                    if (n - 1 != 0)
                    {
                        cp -= n - 1;
                        s0 = GetDpcmSample(chan, cp);
                    }
                    else
                    {
                        s0 += delta;
                    }
                    cp--;
                    delta = GetDpcmSample(chan, cp) - s0;
                }
            }
            cp += 2;
        }
    }
    else if (chan->type & 0x10)
    {
        const s8 *p = (const s8 *)cp;

        p--;
        s0 = p[0];
        delta = p[-1] - s0;
        for (i = 0; i < ms->count; i++)
        {
            MixSample(&ms->out[i], &ms->out[i + PCM_DMA_BUF_SIZE], s0 + (((s32)fw * delta) >> 23), ms->er, ms->el);
            fw += step;
            if (fw >> 23)
            {
                u32 n = fw >> 23;

                fw &= ~0x3F800000;
                ct -= n;
                if (ct <= 0)
                {
                    cp = (u32)p;
                    goto stop;
                }
                p -= n;
                s0 = p[0];
                delta = p[-1] - s0;
            }
        }
        cp = (u32)(p + 1);
    }

    *cpOut = cp;
    *ctOut = ct;
    *fwOut = fw;
    return;

stop:
    chan->status = 0;
    *cpOut = cp;
    *ctOut = 0;
    *fwOut = fw;
}

static void MixChannel(struct SoundInfo *soundInfo, struct SoundChannel *chan, s8 *out, u32 count)
{
    struct WaveData *wav = chan->wav;
    u8 status = chan->status;
    u32 ev;
    u32 volume;
    struct MixState ms;
    u32 i;

    if (status & 0x80)
    {
        if (status & 0x40)
        {
            chan->status = 0;
            return;
        }
        status = 3;
        chan->status = status;
        chan->cp = (u32)wav->data + chan->ct;
        chan->ct = wav->size - chan->ct;
        ev = 0;
        chan->ev = 0;
        chan->fw = 0;
        if (wav->status & 0xC000)
        {
            status |= 0x10;
            chan->status = status;
        }
        goto attack;
    }

    ev = chan->ev;
    if (status & 0x04)
    {
        u8 echoLength = chan->echoLength;
        chan->echoLength = echoLength - 1;
        if (echoLength <= 1)
        {
            chan->status = 0;
            return;
        }
    }
    else if (status & 0x40)
    {
        ev = (ev * chan->release) >> 8;
        if (ev <= chan->echoVolume)
        {
        echo:
            ev = chan->echoVolume;
            if (ev == 0)
            {
                chan->status = 0;
                return;
            }
            status |= 0x04;
            chan->status = status;
        }
    }
    else if ((status & 3) == 2)
    {
        ev = (ev * chan->decay) >> 8;
        if (ev <= chan->sustain)
        {
            ev = chan->sustain;
            if (ev == 0)
                goto echo;
            status--;
            chan->status = status;
        }
    }
    else if ((status & 3) == 3)
    {
    attack:
        ev += chan->attack;
        if (ev >= 0xFF)
        {
            ev = 0xFF;
            status--;
            chan->status = status;
        }
    }

    chan->ev = ev;
    volume = (ev * (soundInfo->masterVolume + 1)) >> 4;
    chan->er = (chan->rightVolume * volume) >> 8;
    chan->el = (chan->leftVolume * volume) >> 8;

    ms.out = out;
    ms.count = count;
    ms.er = chan->er;
    ms.el = chan->el;
    ms.loopLength = 0;
    if (status & 0x10)
    {
        if (chan->type & 0x30)
            ms.loopStart = wav->loopStart;
        else
            ms.loopStart = (u32)wav->data + wav->loopStart;
        ms.loopLength = wav->size - wav->loopStart;
    }

    if (chan->type & 0x30)
    {
        u32 cp, fw;
        s32 ct;

        MixReversedOrCompressed(chan, &ms, soundInfo->divFreq, &cp, &ct, &fw);
        chan->fw = fw;
        chan->ct = ct;
        chan->cp = cp;
    }
    else if (chan->type & 0x08)
    {
        s32 ct = chan->ct;
        const s8 *p = (const s8 *)chan->cp;

        for (i = 0; i < count; i++)
        {
            MixSample(&out[i], &out[i + PCM_DMA_BUF_SIZE], *p++, ms.er, ms.el);
            if (--ct == 0)
            {
                if (ms.loopLength == 0)
                {
                    chan->status = 0;
                    return;
                }
                p = (const s8 *)ms.loopStart;
                ct = ms.loopLength;
            }
        }
        chan->ct = ct;
        chan->cp = (u32)p;
    }
    else
    {
        s32 ct = chan->ct;
        const s8 *p = (const s8 *)chan->cp;
        u32 fw = chan->fw;
        u32 step = chan->freq * soundInfo->divFreq;
        s32 s0 = p[0];
        s32 delta;

        p++;
        delta = p[0] - s0;
        for (i = 0; i < count; i++)
        {
            MixSample(&out[i], &out[i + PCM_DMA_BUF_SIZE], s0 + (((s32)fw * delta) >> 23), ms.er, ms.el);
            fw += step;
            if (fw >> 23)
            {
                u32 n = fw >> 23;
                s32 skip;

                fw &= ~0x3F800000;
                ct -= n;
                if (ct <= 0)
                {
                    if (ms.loopLength == 0)
                    {
                        chan->status = 0;
                        return;
                    }
                    p = (const s8 *)ms.loopStart;
                    skip = -ct;
                    while ((ct += ms.loopLength) <= 0)
                        skip -= ms.loopLength;
                    p += skip;
                    s0 = p[0];
                }
                else if (n - 1 != 0)
                {
                    p += n - 1;
                    s0 = p[0];
                }
                else
                {
                    s0 += delta;
                }
                p++;
                delta = p[0] - s0;
            }
        }
        chan->fw = fw;
        chan->ct = ct;
        chan->cp = (u32)(p - 1);
    }
}

void SoundMain(void)
{
    struct SoundInfo *soundInfo = SOUND_INFO_PTR;
    s32 count;
    s8 *out;
    u8 dmaCounter;
    s32 i;

    if (soundInfo->ident != ID_NUMBER)
        return;
    soundInfo->ident++;

    if (soundInfo->func)
        ((void (*)(u32))soundInfo->func)(soundInfo->intp);
    soundInfo->CgbSound();

    count = soundInfo->pcmSamplesPerVBlank;
    out = soundInfo->pcmBuffer;
    dmaCounter = soundInfo->pcmDmaCounter;
    if (dmaCounter > 1)
        out += (soundInfo->pcmDmaPeriod - (dmaCounter - 1)) * count;

    if (soundInfo->reverb)
    {
        s8 *prev = (dmaCounter == 2) ? soundInfo->pcmBuffer : out + count;

        for (i = 0; i < count; i++)
        {
            s32 value = out[i + PCM_DMA_BUF_SIZE] + out[i] + prev[i + PCM_DMA_BUF_SIZE] + prev[i];
            value = (value * soundInfo->reverb) >> 9;
            if (value & 0x80)
                value++;
            out[i + PCM_DMA_BUF_SIZE] = value;
            out[i] = value;
        }
    }
    else
    {
        for (i = 0; i < count; i++)
        {
            out[i] = 0;
            out[i + PCM_DMA_BUF_SIZE] = 0;
        }
    }

    for (i = 0; i < soundInfo->maxChans; i++)
    {
        struct SoundChannel *chan = &soundInfo->chans[i];

        if (chan->status & 0xC7)
            MixChannel(soundInfo, chan, out, count);
    }

    Audio_PushPcm(out, out + PCM_DMA_BUF_SIZE, count, soundInfo->pcmFreq);

    soundInfo->ident = ID_NUMBER;
}

// Clear64byte
void SoundMainBTM(void *x)
{
    u32 *p = x;
    int i;

    for (i = 0; i < 16; i++)
        p[i] = 0;
}

// ClearChain
void RealClearChain(void *x)
{
    struct SoundChannel *chan = x;
    struct MusicPlayerTrack *track = chan->track;
    struct SoundChannel *next, *prev;

    if (track == NULL)
        return;
    next = (struct SoundChannel *)chan->np;
    prev = (struct SoundChannel *)chan->pp;
    if (prev)
        prev->np = (u32)next;
    else
        track->chan = next;
    if (next)
        next->pp = (u32)prev;
    chan->track = NULL;
}

void ply_fine(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    struct SoundChannel *chan;

    for (chan = track->chan; chan != NULL; chan = (struct SoundChannel *)chan->np)
    {
        if (chan->status & 0xC7)
            chan->status |= 0x40;
        RealClearChain(chan);
    }
    track->flags = 0;
}

void MPlayJumpTableCopy(void **mplayJumpTable)
{
    int i;

    for (i = 0; i < 36; i++)
        mplayJumpTable[i] = gMPlayJumpTableTemplate[i];
}

static u8 ReadCmdByte(struct MusicPlayerTrack *track)
{
    return *track->cmdPtr++;
}

static u8 *ReadCmdPointer(const u8 *p)
{
    return (u8 *)(p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24));
}

void ply_goto(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    track->cmdPtr = ReadCmdPointer(track->cmdPtr);
}

void ply_patt(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    if (track->patternLevel >= 3)
    {
        ply_fine(mplayInfo, track);
        return;
    }
    track->patternStack[track->patternLevel] = track->cmdPtr + 4;
    track->patternLevel++;
    ply_goto(mplayInfo, track);
}

void ply_pend(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    if (track->patternLevel != 0)
    {
        track->patternLevel--;
        track->cmdPtr = track->patternStack[track->patternLevel];
    }
}

void ply_rept(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    u8 *p = track->cmdPtr;

    if (*p == 0)
    {
        track->cmdPtr = p + 1;
        ply_goto(mplayInfo, track);
        return;
    }

    track->repN++;
    track->cmdPtr = p + 1;
    if (track->repN < *p)
    {
        ply_goto(mplayInfo, track);
    }
    else
    {
        track->repN = 0;
        track->cmdPtr = p + 5;
    }
}

void ply_prio(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    track->priority = ReadCmdByte(track);
}

void ply_tempo(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    u16 tempo = ReadCmdByte(track) * 2;

    mplayInfo->tempoD = tempo;
    mplayInfo->tempoI = (tempo * mplayInfo->tempoU) >> 8;
}

void ply_keysh(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    track->keyShift = ReadCmdByte(track);
    track->flags |= MPT_FLG_PITCHG;
}

void ply_voice(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    u8 voice = ReadCmdByte(track);

    track->tone = mplayInfo->tone[voice];
}

void ply_vol(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    track->vol = ReadCmdByte(track);
    track->flags |= MPT_FLG_VOLCHG;
}

void ply_pan(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    track->pan = ReadCmdByte(track) - C_V;
    track->flags |= MPT_FLG_VOLCHG;
}

void ply_bend(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    track->bend = ReadCmdByte(track) - C_V;
    track->flags |= MPT_FLG_PITCHG;
}

void ply_bendr(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    track->bendRange = ReadCmdByte(track);
    track->flags |= MPT_FLG_PITCHG;
}

void ply_lfodl(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    track->lfoDelay = ReadCmdByte(track);
}

void ply_modt(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    u8 modT = ReadCmdByte(track);

    if (track->modT != modT)
    {
        track->modT = modT;
        track->flags |= MPT_FLG_VOLCHG | MPT_FLG_PITCHG;
    }
}

void ply_tune(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    track->tune = ReadCmdByte(track) - C_V;
    track->flags |= MPT_FLG_PITCHG;
}

void ply_port(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    u8 reg = ReadCmdByte(track);
    u8 value = ReadCmdByte(track);

    *(vu8 *)(REG_ADDR_SOUND1CNT_L + reg) = value;
}

static void ClearModMInternal(struct MusicPlayerTrack *track)
{
    track->modM = 0;
    track->lfoSpeedC = 0;
    track->flags |= track->modT == 0 ? MPT_FLG_PITCHG : MPT_FLG_VOLCHG;
}

void ply_lfos(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    track->lfoSpeed = ReadCmdByte(track);
    if (track->lfoSpeed == 0)
        ClearModMInternal(track);
}

void ply_mod(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    track->mod = ReadCmdByte(track);
    if (track->mod == 0)
        ClearModMInternal(track);
}

void m4aSoundVSync(void)
{
    struct SoundInfo *soundInfo = SOUND_INFO_PTR;
    s32 counter;

    if (soundInfo->ident - ID_NUMBER > 1)
        return;

    counter = soundInfo->pcmDmaCounter - 1;
    soundInfo->pcmDmaCounter = counter;
    if (counter > 0)
        return;
    soundInfo->pcmDmaCounter = soundInfo->pcmDmaPeriod;

    if (REG_DMA1CNT & (DMA_REPEAT << 16))
        REG_DMA1CNT = ((DMA_ENABLE | DMA_START_NOW | DMA_32BIT | DMA_SRC_INC | DMA_DEST_FIXED) << 16) | 4;
    if (REG_DMA2CNT & (DMA_REPEAT << 16))
        REG_DMA2CNT = ((DMA_ENABLE | DMA_START_NOW | DMA_32BIT | DMA_SRC_INC | DMA_DEST_FIXED) << 16) | 4;
    REG_DMA1CNT_H = DMA_32BIT;
    REG_DMA2CNT_H = DMA_32BIT;
    REG_DMA1CNT_H = DMA_ENABLE | DMA_START_SPECIAL | DMA_32BIT | DMA_REPEAT;
    REG_DMA2CNT_H = DMA_ENABLE | DMA_START_SPECIAL | DMA_32BIT | DMA_REPEAT;
}

static void ChnVolSet(struct SoundChannel *chan, struct MusicPlayerTrack *track)
{
    s32 rp = (s8)chan->rp;
    u32 v;

    v = (track->volMR * ((0x80 + rp) * chan->ve)) >> 14;
    chan->rightVolume = v > 0xFF ? 0xFF : v;
    v = (track->volML * ((0x7F - rp) * chan->ve)) >> 14;
    chan->leftVolume = v > 0xFF ? 0xFF : v;
}

void MPlayMain(struct MusicPlayerInfo *mplayInfo)
{
    struct SoundInfo *soundInfo;
    u16 tempoC;

    if (mplayInfo->ident != ID_NUMBER)
        return;
    mplayInfo->ident++;

    if (mplayInfo->func)
        ((void (*)(u32))mplayInfo->func)(mplayInfo->intp);

    if (mplayInfo->status < 0)
        goto done;
    soundInfo = SOUND_INFO_PTR;
    FadeOutBody(mplayInfo);
    if (mplayInfo->status < 0)
        goto done;

    tempoC = mplayInfo->tempoC + mplayInfo->tempoI;
    while (mplayInfo->tempoC = tempoC, tempoC >= 150)
    {
        struct MusicPlayerTrack *track = mplayInfo->tracks;
        s32 trackCount = mplayInfo->trackCount;
        u32 bit = 1;
        u32 activeTracks = 0;

        for (; trackCount > 0; trackCount--, track++, bit <<= 1)
        {
            struct SoundChannel *chan;

            if (!(track->flags & MPT_FLG_EXIST))
                continue;
            activeTracks |= bit;

            for (chan = track->chan; chan != NULL; chan = (struct SoundChannel *)chan->np)
            {
                if (chan->status & 0xC7)
                {
                    if (chan->gt && --chan->gt == 0)
                        chan->status |= 0x40;
                }
                else
                {
                    ((ChainFunc)gMPlayJumpTable[34])(chan);
                }
            }

            if (track->flags & MPT_FLG_START)
            {
                ((ChainFunc)gMPlayJumpTable[35])(track);
                track->flags = MPT_FLG_EXIST;
                track->bendRange = 2;
                track->volX = 64;
                track->lfoSpeed = 22;
                track->tone.type = 1;
            }

            while (track->wait == 0)
            {
                u8 cmd = *track->cmdPtr;

                if (cmd < 0x80)
                {
                    cmd = track->runningStatus;
                }
                else
                {
                    track->cmdPtr++;
                    if (cmd >= 0xBD)
                        track->runningStatus = cmd;
                }

                if (cmd >= 0xCF)
                {
                    ((void (*)(u32, struct MusicPlayerInfo *, struct MusicPlayerTrack *))soundInfo->plynote)(cmd - 0xCF, mplayInfo, track);
                }
                else if (cmd > 0xB0)
                {
                    mplayInfo->cmd = cmd - 0xB1;
                    ((PlyFunc)((void **)soundInfo->MPlayJumpTable)[cmd - 0xB1])(mplayInfo, track);
                    if (track->flags == 0)
                        goto nextTrack;
                }
                else
                {
                    track->wait = gClockTable[cmd - 0x80];
                }
            }

            track->wait--;
            if (track->lfoSpeed && track->mod)
            {
                if (track->lfoDelayC)
                {
                    track->lfoDelayC--;
                }
                else
                {
                    // The assembly keeps the sum unwrapped for the falling half.
                    u32 speedC = track->lfoSpeedC + track->lfoSpeed;
                    s32 wave;
                    s32 modM;

                    track->lfoSpeedC = speedC;
                    if ((s8)(speedC - 0x40) < 0)
                        wave = (s8)speedC;
                    else
                        wave = 0x80 - (s32)speedC;
                    modM = (track->mod * wave) >> 6;
                    if ((u8)(track->modM ^ modM) != 0)
                    {
                        track->modM = modM;
                        track->flags |= track->modT == 0 ? MPT_FLG_PITCHG : MPT_FLG_VOLCHG;
                    }
                }
            }
        nextTrack:;
        }

        mplayInfo->clock++;
        if (activeTracks == 0)
        {
            mplayInfo->status = MUSICPLAYER_STATUS_PAUSE;
            goto done;
        }
        mplayInfo->status = activeTracks;
        tempoC = mplayInfo->tempoC - 150;
    }

    {
        struct MusicPlayerTrack *track = mplayInfo->tracks;
        s32 trackCount = mplayInfo->trackCount;

        for (; trackCount > 0; trackCount--, track++)
        {
            struct SoundChannel *chan;

            if (!(track->flags & MPT_FLG_EXIST) || !(track->flags & 0xF))
                continue;

            TrkVolPitSet(mplayInfo, track);
            for (chan = track->chan; chan != NULL; chan = (struct SoundChannel *)chan->np)
            {
                u32 cgbType;
                s32 key;

                if (!(chan->status & 0xC7))
                {
                    ((ChainFunc)gMPlayJumpTable[34])(chan);
                    continue;
                }

                cgbType = chan->type & 7;
                if (track->flags & MPT_FLG_VOLCHG)
                {
                    ChnVolSet(chan, track);
                    if (cgbType)
                        ((struct CgbChannel *)chan)->mo |= 1;
                }
                if (track->flags & MPT_FLG_PITCHG)
                {
                    key = chan->ky + (s8)track->keyM;
                    if (key < 0)
                        key = 0;
                    if (cgbType)
                    {
                        ((struct CgbChannel *)chan)->fr = soundInfo->MidiKeyToCgbFreq(cgbType, key, track->pitM);
                        ((struct CgbChannel *)chan)->mo |= 2;
                    }
                    else
                    {
                        chan->freq = MidiKeyToFreq(chan->wav, key, track->pitM);
                    }
                }
            }
            track->flags &= 0xF0;
        }
    }

done:
    mplayInfo->ident = ID_NUMBER;
}

void TrackStop(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    struct SoundChannel *chan;

    if (!(track->flags & MPT_FLG_EXIST))
        return;

    for (chan = track->chan; chan != NULL; chan = (struct SoundChannel *)chan->np)
    {
        if (chan->status != 0)
        {
            if (chan->type & 7)
                SOUND_INFO_PTR->CgbOscOff(chan->type & 7);
            chan->status = 0;
        }
        chan->track = NULL;
    }
    track->chan = NULL;
}

void ply_note(u32 noteCmd, struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    struct SoundInfo *soundInfo = SOUND_INFO_PTR;
    u8 *cmdPtr = track->cmdPtr;
    struct ToneData *tone;
    s32 forcedPan = 0;
    u32 key;
    u32 priority;
    u32 cgbType;
    struct SoundChannel *chan;
    s32 midiKey;

    track->gateTime = gClockTable[noteCmd];
    if (*cmdPtr < 0x80)
    {
        track->key = *cmdPtr++;
        if (*cmdPtr < 0x80)
        {
            track->velocity = *cmdPtr++;
            if (*cmdPtr < 0x80)
                track->gateTime += *cmdPtr++;
        }
        track->cmdPtr = cmdPtr;
    }

    if (track->tone.type & (TONEDATA_TYPE_RHY | TONEDATA_TYPE_SPL))
    {
        u32 index = track->key;

        if (track->tone.type & TONEDATA_TYPE_SPL)
            index = (*(u8 **)&track->tone.attack)[track->key];
        tone = &((struct ToneData *)track->tone.wav)[index];
        if (tone->type & (TONEDATA_TYPE_RHY | TONEDATA_TYPE_SPL))
            return;
        key = track->key;
        if (track->tone.type & TONEDATA_TYPE_RHY)
        {
            if (tone->pan_sweep & 0x80)
                forcedPan = ((s32)tone->pan_sweep - 0xC0) * 2;
            key = tone->key;
        }
    }
    else
    {
        tone = &track->tone;
        key = track->key;
    }

    priority = mplayInfo->priority + track->priority;
    if (priority > 0xFF)
        priority = 0xFF;

    cgbType = tone->type & 7;
    if (cgbType)
    {
        if (soundInfo->cgbChans == NULL)
            return;
        chan = (struct SoundChannel *)&soundInfo->cgbChans[cgbType - 1];
        if ((chan->status & 0xC7) && !(chan->status & 0x40))
        {
            if (chan->pr > priority)
                return;
            if (chan->pr == priority && (u32)chan->track < (u32)track)
                return;
        }
    }
    else
    {
        u32 lowestPriority = priority;
        struct MusicPlayerTrack *lowestTrack = track;
        int foundReleasing = 0;
        struct SoundChannel *best = NULL;
        s32 n = soundInfo->maxChans;

        chan = soundInfo->chans;
        for (; n > 0; n--, chan++)
        {
            if (!(chan->status & 0xC7))
            {
                best = chan;
                goto found;
            }
            if (chan->status & 0x40)
            {
                if (!foundReleasing)
                {
                    foundReleasing = 1;
                    lowestPriority = chan->pr;
                    lowestTrack = chan->track;
                    best = chan;
                    continue;
                }
            }
            else if (foundReleasing)
            {
                continue;
            }

            if (chan->pr < lowestPriority)
            {
                lowestPriority = chan->pr;
                lowestTrack = chan->track;
                best = chan;
            }
            else if (chan->pr == lowestPriority && (u32)chan->track >= (u32)lowestTrack)
            {
                lowestTrack = chan->track;
                best = chan;
            }
        }
        if (best == NULL)
            return;
    found:
        chan = best;
    }

    ((ChainFunc)gMPlayJumpTable[34])(chan);
    chan->pp = 0;
    chan->np = (u32)track->chan;
    if (track->chan)
        track->chan->pp = (u32)chan;
    track->chan = chan;
    chan->track = track;

    track->lfoDelayC = track->lfoDelay;
    if (track->lfoDelay != 0)
        ClearModMInternal(track);
    TrkVolPitSet(mplayInfo, track);

    chan->gt = track->gateTime;
    chan->mk = track->key;
    chan->ve = track->velocity;
    chan->pr = priority;
    chan->ky = key;
    chan->rp = forcedPan;
    chan->type = tone->type;
    chan->wav = tone->wav;
    chan->attack = tone->attack;
    chan->decay = tone->decay;
    chan->sustain = tone->sustain;
    chan->release = tone->release;
    chan->echoVolume = track->echoVolume;
    chan->echoLength = track->echoLength;
    ChnVolSet(chan, track);

    midiKey = chan->ky + (s8)track->keyM;
    if (midiKey < 0)
        midiKey = 0;

    if (cgbType)
    {
        struct CgbChannel *cgb = (struct CgbChannel *)chan;
        u8 sweep = tone->pan_sweep;

        cgb->le = tone->length;
        if ((sweep & 0x80) || !(sweep & 0x70))
            sweep = 8;
        cgb->sw = sweep;
        chan->freq = soundInfo->MidiKeyToCgbFreq(cgbType, midiKey, track->pitM);
    }
    else
    {
        chan->ct = track->unk_3C;
        chan->freq = MidiKeyToFreq(tone->wav, midiKey, track->pitM);
    }

    chan->status = 0x80;
    track->flags &= 0xF0;
}

void ply_endtie(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    u8 *cmdPtr = track->cmdPtr;
    u8 key;
    struct SoundChannel *chan;

    if (*cmdPtr < 0x80)
    {
        key = *cmdPtr;
        track->key = key;
        track->cmdPtr = cmdPtr + 1;
    }
    else
    {
        key = track->key;
    }

    for (chan = track->chan; chan != NULL; chan = (struct SoundChannel *)chan->np)
    {
        if ((chan->status & 0x83) && !(chan->status & 0x40) && chan->mk == key)
        {
            chan->status |= 0x40;
            return;
        }
    }
}
