#ifndef GUARD_PC_HOOKS_H
#define GUARD_PC_HOOKS_H

// Where the game code calls into the native build (only under PLATFORM_PC, so
// the ROM doesn't change).

#include "host.h"

// main.c
int PcHook_LoopTop(void);
void PcHook_AfterKeys(void);
unsigned short PcHook_FilterKeys(unsigned short keys);
int PcHook_SkipBootScreens(void);
void PcHook_AfterBoot(void);

// gba_bios.c
void Hook_OnVBlankWait(void);
struct FrameSet *Hook_FrameForCapture(void);
void Hook_FrameDone(struct FrameSet *frame);
void Bios_ApplyDisplayRegisters(void);
void Bios_CaptureLines(struct PpuFrame *frame);

// Game code
void PcHook_Rumble(int pattern);
void PcHook_CameraPass(void);
int PcHook_ScrollCatchUp(void);
int PcHook_SaverTick(void);
int PcHook_KeepBall(void);
int PcHook_Fix(int fix);
int PcHook_PokedexScrollWait(int frames);

#endif // GUARD_PC_HOOKS_H
