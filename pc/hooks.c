// The native build's additions on the game side: everything here works at the
// top of the main loop, where the game has nothing on the stack, or is called
// from a few marked places in the game code (#ifdef PLATFORM_PC).
//
// A game on PC starts from a known state: when one is about to start, the
// program restarts as if switched on and goes straight into it, with the
// values the game would have had (see BuildRunHeader). That is what makes a
// replay work: the same header and the same keys give the same game.
//
// The table view runs the frame's game code a few more times from a saved
// state, with the camera somewhere else, and keeps only the picture: see
// RunCameraPasses.

#include "global.h"
#include "main.h"
#include "m4a.h"
#include "gbplayer.h"
#include "titlescreen.h"
#include "constants/fields.h"
#include "constants/board/main_board.h"
#include "constants/mem_layout/ruby.h"
#include "hooks.h"

#define RUN_MAGIC 0x31525050  // "PPR1"
#define RUN_VERSION 1

extern const struct PokemonSpecies gSpeciesInfo[];
extern const Palette *gMonPortraitGroupPals[];
extern const u8 *gMonPortraitGroupGfx[];
extern const u8 gPokedexTextGlyphs_Gfx[];
extern const Palette gOptionsBackground_Pals[];
extern const Palette gGBAButtonIcons_Pals[];
extern const u8 gOptionsBackground_Gfx_EnFr[], gOptionsBackground_Gfx_De[], gOptionsBackground_Gfx_It[], gOptionsBackground_Gfx_Es[];
extern const u8 gOptionsBackground_Tilemap_EnDe[], gOptionsBackground_Tilemap_Fr[], gOptionsBackground_Tilemap_It[], gOptionsBackground_Tilemap_Es[];
extern const u8 gOptionsSprites_Gfx_En[], gOptionsSprites_Gfx_Fr[], gOptionsSprites_Gfx_De[], gOptionsSprites_Gfx_It[], gOptionsSprites_Gfx_Es[];

void ClearBG0Tilemap(void);
void RequestBoardStateTransition(u8 boardState);
extern const s16 gScrollTileUpdateTable[][4];
extern u8 gBoardBGTileBuffer[];
extern u8 gBoardBGTileBufferAlt[];

// What a game keeps outside the GBA memory: saved with the game.
static struct
{
    int active;           // inside a game
    int recording;
    int noReplay;         // resumed from a save: can't be replayed from a header
    int trainingMode;
    int trainingStarted;
    int tainted;
    struct PcGameplay game;
    // Previous values, to see what happened since the last frame
    s32 prevLives;
    u32 prevScoreHi, prevScoreLo;
    u32 prevCaught, prevEvo, prevBonus, prevTravel, prevCoins, prevHits;
    u32 saverFrame;
    u32 playFrames;
    u8 prevSaving;
} sRun;

static struct RunHeader sPending;
static int sPendingValid;
static int sPendingPlayback;
static int sPendingTraining;

// Passes of the table view
static int sCameraPass;
static int sPassX, sPassY;
static struct FrameSet *sPassFrame;
static void *sPassState;
static void *sPassJump[5];

void *Hook_StateData(int *size)
{
    *size = sizeof(sRun);
    return &sRun;
}

static const struct PcGameplay *Gameplay(void)
{
    return &sRun.game;
}

int PcHook_Fix(int fix)
{
    return sRun.active && !Gameplay()->vanilla && (Gameplay()->fixes & fix);
}

// Vanilla switches off everything, and the game then runs as on the GBA.
static int InfiniteBalls(void)
{
    return sRun.active && !Gameplay()->vanilla && Gameplay()->infiniteBalls;
}

int PcHook_KeepBall(void)
{
    return InfiniteBalls();
}

// With the longer ball saver its timer only counts down every few frames.
int PcHook_SaverTick(void)
{
    int rate;

    if (!sRun.active || Gameplay()->vanilla)
        return TRUE;
    rate = Gameplay()->ballSaver;
    if (rate <= 1)
        return TRUE;
    return (++sRun.saverFrame % rate) == 0;
}

int PcHook_PokedexScrollWait(int frames)
{
    int speed = gPcOptions.pokedexSpeed;

    if (speed <= 1)
        return frames;
    return (frames + speed - 1) / speed - 1;
}

void PcHook_Rumble(int pattern)
{
    if (!sCameraPass)
        Host_Rumble(pattern);
}

static void BuildRunHeader(struct RunHeader *header)
{
    int i, j;

    memset(header, 0, sizeof(*header));
    header->magic = RUN_MAGIC;
    header->version = RUN_VERSION;
    header->field = gMain.selectedField;
    header->isBonusField = gMain.isBonusField;
    header->rngValue = gMain.rngValue;
    header->frameCount = gMain.systemFrameCount;
    header->language = gMain_saveData.language;
    for (i = 0; i < NUM_EREADER_CARDS; i++)
        header->eReaderBonuses[i] = gMain.eReaderBonuses[i];
    for (i = 0; i < NUM_PINBALL_INPUTS; i++)
        for (j = 0; j < 2; j++)
            header->buttonConfigs[i * 2 + j] = gMain.buttonConfigs[i][j];
    header->game = gPcOptions.game;
    Host_Memcpy(header->saveData, &gMain_saveData, sizeof(gMain_saveData));
}

static void ApplyRunHeader(const struct RunHeader *header)
{
    int i, j;

    Host_Memcpy(&gMain_saveData, header->saveData, sizeof(gMain_saveData));
    gMain_saveData.language = header->language;
    for (i = 0; i < NUM_EREADER_CARDS; i++)
        gMain.eReaderBonuses[i] = header->eReaderBonuses[i];
    for (i = 0; i < NUM_PINBALL_INPUTS; i++)
        for (j = 0; j < 2; j++)
            gMain.buttonConfigs[i][j] = header->buttonConfigs[i * 2 + j];
    gMain.selectedField = header->field;
    gMain.tempField = header->field;
    gMain.isBonusField = header->isBonusField;
    gMain.continueFromSave = FALSE;
    gMain.rngValue = header->rngValue;
    gMain.systemFrameCount = header->frameCount;
    gAutoDisplayTitlescreenMenu = TRUE;
    SetMainGameState(STATE_GAME_MAIN);
}

// A hash of what decides the rest of the game, to see that a replay went the same way.
static u32 GameHash(void)
{
    u32 hash = State_Hash(gCurrentPinballGame, sizeof(*gCurrentPinballGame));
    return hash ^ gMain.rngValue;
}

int PcHook_SkipBootScreens(void)
{
    return sPendingValid;
}

void PcHook_AfterBoot(void)
{
    if (!sPendingValid)
        return;

    ApplyRunHeader(&sPending);
    memset(&sRun, 0, sizeof(sRun));
    sRun.active = TRUE;
    sRun.game = sPending.game;
    sRun.trainingMode = sPending.trainingMode;
    if (!sPendingPlayback)
    {
        sRun.recording = TRUE;
        Replay_StartRecording(&sPending);
    }
    if (!sPendingPlayback && !sPending.trainingMode)
        Stats_Event(EVENT_GAME_START, sPending.field, 0);
    if (sPending.trainingMode)
        Host_SetSramGuard(1);
    sPendingValid = FALSE;
    sPendingPlayback = FALSE;
}

static void SetTrainingHeader(int field, int mode)
{
    BuildRunHeader(&sPending);
    sPending.field = field;
    sPending.isBonusField = field >= FIELD_BONUS_START;
    sPending.trainingMode = mode ? mode : 0xFF;
    sPendingValid = TRUE;
}

// Modes of the training menu; 0 = the stage on its own.
enum { TRAIN_NONE, TRAIN_CATCH, TRAIN_HATCH, TRAIN_EVOLUTION, TRAIN_TRAVEL, TRAIN_JIRACHI, TRAIN_BONUS_HOLE, TRAIN_BOSS_HOLE };

// Sets up the board so that the mode can start, then asks for it.
static void StartTrainingMode(void)
{
    struct PinballGame *g = gCurrentPinballGame;

    switch (sRun.trainingMode)
    {
    case TRAIN_CATCH:
        RequestBoardStateTransition(MAIN_BOARD_STATE_CATCH_EM_MODE);
        break;
    case TRAIN_HATCH:
        RequestBoardStateTransition(MAIN_BOARD_STATE_EGG_HATCH_MODE);
        break;
    case TRAIN_EVOLUTION:
        // A caught Pokémon that can evolve: Ralts' family is on both boards.
        g->evolvablePartySpecies[0] = SPECIES_RALTS;
        g->evolvablePartySize = 1;
        g->evolvingPartyIndex = 0;
        g->currentSpecies = SPECIES_RALTS;
        g->evoTargetSpecies = gSpeciesInfo[SPECIES_RALTS].evolutionTarget;
        RequestBoardStateTransition(MAIN_BOARD_STATE_EVO_MODE);
        break;
    case TRAIN_TRAVEL:
        RequestBoardStateTransition(MAIN_BOARD_STATE_TRAVEL_MODE);
        break;
    case TRAIN_JIRACHI:
        RequestBoardStateTransition(MAIN_BOARD_STATE_JIRACHI_CATCH_MODE);
        break;
    case TRAIN_BONUS_HOLE:
        RequestBoardStateTransition(MAIN_BOARD_STATE_BONUS_HOLE_ACTIVE);
        break;
    case TRAIN_BOSS_HOLE:
        RequestBoardStateTransition(MAIN_BOARD_STATE_BOSS_HOLE_ACTIVE);
        break;
    }
}

static void EndRun(void)
{
    if (sRun.active)
    {
        u32 hash = GameHash();
        // Left halfway (Restart, another game), the final score isn't there yet.
        int finished = gMain.mainState != STATE_GAME_MAIN && gMain.gameExitState == 0;
        u32 scoreHi = finished ? gMain.finalScoreHi : gCurrentPinballGame->scoreHi;
        u32 scoreLo = finished ? gMain.finalScoreLo : gCurrentPinballGame->scoreLo;

        if (sRun.trainingMode)
            Host_SetSramGuard(0);

        if (Replay_IsPlaying())
        {
            Replay_FinishPlayback(scoreHi, scoreLo, hash);
        }
        else
        {
            if (sRun.recording)
                Replay_StopRecording(scoreHi, scoreLo, hash, finished);
            if (!sRun.trainingMode)
            {
                Stats_Event(EVENT_PLAY_TIME, sRun.playFrames, 0);
                Stats_Event(EVENT_GAME_OVER, scoreHi, scoreLo);
            }
        }
    }
    sRun.active = FALSE;
    sRun.recording = FALSE;
}

// What changed in the game since the last frame.
static void PollRunEvents(void)
{
    struct PinballGame *g = gCurrentPinballGame;
    u32 value;

    if (gMain.subState != 1)
        return;

    if (gPcOptions.rumbleFlippers && (g->newButtonActions[PINBALL_INPUT_LEFT_FLIPPER] || g->newButtonActions[PINBALL_INPUT_RIGHT_FLIPPER]))
        Host_Rumble(RUMBLE_FLIPPER);

    if (Replay_IsPlaying() || sRun.trainingMode)
        return;

    sRun.playFrames++;
    value = (gMain.modeChangeFlags & MODE_CHANGE_BALL_SAVER) != 0;
    if (value && !sRun.prevSaving)
        Stats_Event(EVENT_BALL_SAVED, 0, 0);
    sRun.prevSaving = value;

    if (g->numLives < sRun.prevLives)
        Stats_Event(EVENT_BALL_LOST, 0, 0);
    sRun.prevLives = g->numLives;

    if (g->scoreHi != sRun.prevScoreHi || g->scoreLo != sRun.prevScoreLo)
    {
        Stats_Event(EVENT_SCORE, g->scoreHi, g->scoreLo);
        sRun.prevScoreHi = g->scoreHi;
        sRun.prevScoreLo = g->scoreLo;
    }

    value = g->caughtMonCount;
    if (value > sRun.prevCaught)
        Stats_Event(EVENT_CATCH, g->lastCatchSpecies, 0);
    sRun.prevCaught = value;

    value = g->bonusMonEvoCount;
    if (value > sRun.prevEvo)
        Stats_Event(EVENT_EVOLUTION, g->evoTargetSpecies, 0);
    sRun.prevEvo = value;

    value = g->numCompletedBonusStages;
    if (value > sRun.prevBonus)
        Stats_Event(EVENT_BONUS_CLEARED, gMain.selectedField, 0);
    sRun.prevBonus = value;

    value = g->travelModeCompletionCount;
    if (value > sRun.prevTravel)
        Stats_Event(EVENT_TRAVEL, 0, 0);
    sRun.prevTravel = value;

    value = g->coins;
    if (value != sRun.prevCoins)
        Stats_Event(EVENT_COINS, value, 0);
    sRun.prevCoins = value;

    value = g->bumperHitsSinceReset;
    if (value > sRun.prevHits)
        Stats_Event(EVENT_BUMPER, value - sRun.prevHits, 0);
    sRun.prevHits = value;

    value = (g->newButtonActions[PINBALL_INPUT_LEFT_FLIPPER] ? 1 : 0) + (g->newButtonActions[PINBALL_INPUT_RIGHT_FLIPPER] ? 1 : 0);
    if (value)
        Stats_Event(EVENT_FLIPPER, value, 0);
}

static void RunCommand(const struct HostCommand *command, int *reboot)
{
    switch (command->type)
    {
    case CMD_SAVE_STATE:
        State_Save(command->a);
        break;
    case CMD_LOAD_STATE:
        // A replay has to run to its end on its own keys.
        if (!Replay_IsPlaying() && State_Load(command->a))
        {
            // The state decides: a training game comes back as one.
            Host_SetSramGuard(sRun.trainingMode != 0);
            if (sRun.recording)
            {
                sRun.tainted = TRUE;
                Replay_Taint();
            }
        }
        break;
    case CMD_REBOOT:
        EndRun();
        *reboot = TRUE;
        break;
    case CMD_TRAINING:
        EndRun();
        SetTrainingHeader(command->a, command->b);
        *reboot = TRUE;
        break;
    case CMD_PLAY_REPLAY:
        EndRun();
        if (Replay_Load(command->path, &sPending))
        {
            sPendingValid = TRUE;
            sPendingPlayback = TRUE;
            *reboot = TRUE;
        }
        break;
    case CMD_STOP_REPLAY:
        if (Replay_IsPlaying())
        {
            EndRun();
            *reboot = TRUE;
        }
        break;
    case CMD_PLACE_BALL:
        if (sRun.active)
        {
            struct BallState *ball = gCurrentPinballGame->ball;

            ball->positionQ0.x = command->a;
            ball->positionQ0.y = command->b;
            ball->positionQ1.x = command->a * 2;
            ball->positionQ1.y = command->b * 2;
            ball->positionQ8.x = command->a << 8;
            ball->positionQ8.y = command->b << 8;
            ball->velocity.x = command->c;
            ball->velocity.y = command->d;
            gCurrentPinballGame->boardLayerDepth = command->e;
        }
        break;
    case CMD_SET_LANGUAGE:
        EndRun();
        gMain_saveData.language = command->a;
        SaveFile_WriteToSram();
        *reboot = TRUE;
        break;
    }
}

int PcHook_LoopTop(void)
{
    struct HostCommand command;
    int reboot = FALSE;

    Host_GameReady();
    for (;;)
    {
        while (Host_NextCommand(&command))
            RunCommand(&command, &reboot);
        if (reboot)
            return TRUE;
        if (!Host_IsPaused())
            break;
        Host_PauseWait();
    }

    if (gMain.mainState == STATE_GAME_MAIN && gMain.subState == 0 && !sRun.active)
    {
        if (!gMain.continueFromSave && gMain.tempField == gMain.selectedField)
        {
            // A new game: start it from the known state.
            BuildRunHeader(&sPending);
            sPendingValid = TRUE;
            return TRUE;
        }
        memset(&sRun, 0, sizeof(sRun));
        sRun.active = TRUE;
        sRun.noReplay = TRUE;
        sRun.game = gPcOptions.game;
    }

    if (sRun.active)
    {
        if (gMain.mainState != STATE_GAME_MAIN)
        {
            int leaveToTitle = sRun.trainingMode != 0 || Replay_IsPlaying();

            EndRun();
            if (leaveToTitle)
                return TRUE;
        }
        else if (Replay_IsPlaying() && !Replay_KeysLeft())
        {
            // The game was left at this point when it was played.
            EndRun();
            return TRUE;
        }
        else
        {
            PollRunEvents();
            if (sRun.trainingMode && !sRun.trainingStarted && gMain.subState == 1
                && gCurrentPinballGame->boardState == MAIN_BOARD_STATE_DEFAULT && gMain.selectedField < MAIN_FIELD_COUNT)
            {
                StartTrainingMode();
                sRun.trainingStarted = TRUE;
            }
        }
    }

    Host_PollInput();
    return FALSE;
}

unsigned short PcHook_FilterKeys(unsigned short keys)
{
    if (Replay_IsPlaying())
    {
        u32 replayKeys;

        if (Replay_NextKeys(&replayKeys))
            return replayKeys & KEYS_MASK;
        return 0;
    }
    if (sRun.recording)
        Replay_RecordKeys(keys);
    return keys;
}

// Table view

static int TableGeometry(int *top, int *height, int *width, int *left, int *cameraX)
{
    int field = gMain.selectedField;
    int minY = gBoardConfig.fieldLayout.cameraScrollMinY - 80;
    int maxY = gBoardConfig.fieldLayout.cameraScrollMaxY - 80;

    if (field < MAIN_FIELD_COUNT)
    {
        *left = 16;
        *width = 256;
        *cameraX = 16;
    }
    else
    {
        *left = 0;
        *width = 240;
        *cameraX = 0;
        minY += gCurrentPinballGame->cameraYAdjust;
        maxY += gCurrentPinballGame->cameraYAdjust;
    }
    // Sapphire's camera limit is above the table: bgOffsets are unsigned, and
    // the tile streaming can't take a negative position.
    if (field < MAIN_FIELD_COUNT && minY < 0)
        minY = 0;
    *top = minY;
    *height = maxY - minY + PPU_HEIGHT;
    return *height > PPU_HEIGHT;
}

void PcHook_CameraPass(void)
{
    struct PinballGame *g;

    if (!sCameraPass)
        return;
    g = gCurrentPinballGame;
    g->cameraBaseX = sPassX;
    g->cameraBaseY = sPassY;
    g->cameraYQ8 = sPassY << 8;
    g->cameraScrollOffset = 0;
    g->cameraScrollEnabled = FALSE;
    g->cameraYAdjust = 0;
    g->scrollEffectX = sPassY + g->tiltYOffset + g->screenShakeY;
    g->cameraYViewport = sPassY + g->tiltYOffset;
    gMain.bgOffsets[3].yOffset = sPassY + g->tiltYOffset;
}

// A camera that jumps needs all the tile rows in between, not only the next one.
int PcHook_ScrollCatchUp(void)
{
    struct PinballGame *g = gCurrentPinballGame;
    s16 target;

    if (!sCameraPass)
        return FALSE;

    target = gMain.bgOffsets[3].yOffset / 8;
    while (g->prevScrollYTileIx != target)
    {
        s16 step = g->prevScrollYTileIx < target ? g->prevScrollYTileIx + 1 : g->prevScrollYTileIx - 1;
        const s16 *data = gScrollTileUpdateTable[step];
        int offset = step > g->prevScrollYTileIx ? 0 : 2;
        u32 dest = BG_VRAM_ADDR_MAIN_SCROLL_SEGMENT_TILES + data[offset + 1] * MEM_SIZE_OF_TILE_ROW;

        if (data[offset] > 31)
            DmaCopy16(3, &gBoardBGTileBufferAlt[(data[offset] - 32) * 0x400], dest, MEM_SIZE_OF_TILE_ROW);
        else
            DmaCopy16(3, &gBoardBGTileBuffer[data[offset] * 0x400], dest, MEM_SIZE_OF_TILE_ROW);
        g->prevScrollYTileIx = step;
    }
    return TRUE;
}

void Hook_OnVBlankWait(void)
{
    // The game went into a fade or something else with its own wait.
    if (sCameraPass)
        __builtin_longjmp(sPassJump, 1);
}

static int RunOnePass(struct PpuFrame *frame)
{
    if (__builtin_setjmp(sPassJump))
        return FALSE;

    gMainFuncs[gMain.mainState]();
    Bios_ApplyDisplayRegisters();
    Bios_CaptureLines(frame);
    return TRUE;
}

static int IsSpriteOn(const u16 *oam, int i)
{
    u16 attr0 = oam[i * 4];
    return (attr0 & 0x100) || !(attr0 & 0x200);
}

// A sprite at the same place on the screen with the camera in two different
// places doesn't belong to the table.
static void FindScreenSprites(struct FrameSet *frame)
{
    int i, k;

    frame->screenSprites[0] = frame->screenSprites[1] = 0;
    frame->screenSprites[2] = frame->screenSprites[3] = 0;
    for (i = 0; i < 128; i++)
    {
        for (k = 1; k < frame->numStrips; k++)
        {
            const u16 *a = frame->strip[k - 1].oam;
            const u16 *b = frame->strip[k].oam;

            if (IsSpriteOn(a, i) && IsSpriteOn(b, i)
                && (a[i * 4] & 0xFF) == (b[i * 4] & 0xFF)
                && (a[i * 4 + 1] & 0x1FF) == (b[i * 4 + 1] & 0x1FF))
            {
                frame->screenSprites[i >> 5] |= 1u << (i & 31);
                break;
            }
        }
    }
}

// Runs the next frame's game code once for each camera position, keeps the
// picture and puts everything back. The game doesn't see any of this, and what
// these runs do to the game state, sound and RAM is thrown away.
static void RunCameraPasses(void)
{
    struct FrameSet *frame;
    int top, height, width, left, cameraX, numStrips;
    int k, ok = TRUE;

    // The table for the panels' map is enough a few times a second.
    if (gPcOptions.view != VIEW_TABLE && !(gPcOptions.panels && (gMain.systemFrameCount & 7) == 0))
        return;
    if (Host_FastForward() || !sRun.active)
        return;
    if (gMain.mainState != STATE_GAME_MAIN || gMain.subState != 1 || gMain.gameExitState)
        return;
    if (gMain.modeChangeFlags & MODE_CHANGE_PAUSE)
        return;
    if (!TableGeometry(&top, &height, &width, &left, &cameraX))
        return;

    numStrips = (height - (PPU_HEIGHT - STRIP_LINES) + STRIP_LINES - 1) / STRIP_LINES;
    if (numStrips > MAX_STRIPS)
        numStrips = MAX_STRIPS;

    if (!sPassState)
        sPassState = (void *)Host_Alloc(State_Size());
    frame = Host_AcquireFrame();
    State_Copy(sPassState);
    for (k = 0; k < numStrips && ok; k++)
    {
        frame->stripY[k] = k * STRIP_LINES;
        sPassX = cameraX;
        sPassY = top + frame->stripY[k];
        sCameraPass = TRUE;
        ok = RunOnePass(&frame->strip[k]);
        sCameraPass = FALSE;
        State_Paste(sPassState);
    }

    if (ok)
    {
        frame->numStrips = numStrips;
        frame->tableWidth = width;
        frame->tableHeight = height;
        frame->tableLeft = left;
        FindScreenSprites(frame);
        sPassFrame = frame;
    }
    else
    {
        Host_ReleaseFrame(frame);
    }
}

void PcHook_AfterKeys(void)
{
    RunCameraPasses();
}

struct FrameSet *Hook_FrameForCapture(void)
{
    struct FrameSet *frame = sPassFrame;

    sPassFrame = NULL;
    if (frame)
        return frame;
    frame = Host_AcquireFrame();
    if (gPcOptions.view == VIEW_TABLE && sRun.active)
        Host_InheritStrips(frame);
    return frame;
}

#define HIT_BALL 1
#define HIT_BUMPER 2
#define HIT_TARGET 3
#define HIT_FLIPPER 4

static void AddHit(struct FrameInfo *info, int x, int y, int r, int kind)
{
    if (info->numHit < 16)
    {
        info->hit[info->numHit].x = x;
        info->hit[info->numHit].y = y;
        info->hit[info->numHit].r = r;
        info->hit[info->numHit].kind = kind;
        info->numHit++;
    }
}

void Hook_FrameDone(struct FrameSet *frame)
{
    struct FrameInfo *info = &frame->info;
    struct PinballGame *g = gCurrentPinballGame;
    int top = 0, height, width, left, cameraX;
    int i;

    info->frameNumber = gMain.systemFrameCount;
    info->rng = gMain.rngValue;
    info->language = gMain_saveData.language;
    info->inGame = gMain.mainState == STATE_GAME_MAIN && gMain.subState == 1 && g != NULL;
    info->numHit = 0;
    if (info->inGame)
        Host_Trace(gMain.systemFrameCount, g->ball->positionQ0.x, g->ball->positionQ0.y, g->ball->velocity.x, g->ball->velocity.y,
                   g->numLives, g->saverTimeRemaining, g->boardState, g->boardLayerDepth, g->boardSubState, g->currentSpecies, g->evoTargetSpecies);
    info->pokedexCaught = gBoardConfig.caughtSpeciesCount;
    if (!info->inGame)
        return;

    info->field = gMain.selectedField;
    info->paused = (gMain.modeChangeFlags & MODE_CHANGE_PAUSE) != 0;
    info->mode = g->boardState;
    info->boardSubState = g->boardSubState;
    info->ballX = g->ball->positionQ0.x;
    info->ballY = g->ball->positionQ0.y;
    info->ballVelX = g->ball->velocity.x;
    info->ballVelY = g->ball->velocity.y;
    info->ballSpin = g->ball->spinSpeed;
    info->ballHidden = g->ball->ballHidden;
    info->physicsState = g->ballPhysicsState;
    info->cameraX = g->cameraXOffset;
    info->cameraY = g->cameraYOffset;
    info->flipperAngle[0] = g->flipper[0].position;
    info->flipperAngle[1] = g->flipper[1].position;
    info->fieldFrames = gMain.fieldFrameCount;
    info->scoreHi = g->scoreHi;
    info->scoreLo = g->scoreLo;
    info->lives = g->numLives;
    info->coins = g->coins;
    info->stageTimer = g->stageTimer;
    info->saverTime = g->saverTimeRemaining;
    info->modeTimer = g->eventTimer;
    info->bonusTimer = g->timerBonus;
    info->species = (g->boardState == MAIN_BOARD_STATE_CATCH_EM_MODE || g->boardState == MAIN_BOARD_STATE_EGG_HATCH_MODE
                     || g->boardState == MAIN_BOARD_STATE_EVO_MODE || g->boardState == MAIN_BOARD_STATE_JIRACHI_CATCH_MODE)
                        ? g->currentSpecies : -1;
    info->evolutionTarget = g->evoTargetSpecies;
    info->catchProgress = g->creatureHitCount;
    info->catchNeeded = 3;
    info->area = g->area;
    info->ballUpgrade = g->ballUpgradeType;

    if (gPcOptions.debugOverlay)
    {
        AddHit(info, g->ball->positionQ0.x, g->ball->positionQ0.y, 7, HIT_BALL);
        if (gMain.selectedField < MAIN_FIELD_COUNT)
        {
            for (i = 0; i < 3; i++)
                AddHit(info, g->rubyBumperCollisionPosition[i].x, g->rubyBumperCollisionPosition[i].y, 10, HIT_BUMPER);
            AddHit(info, g->catchTargetX, g->catchTargetY, 8, HIT_TARGET);
        }
    }

    if (frame->numStrips && TableGeometry(&top, &height, &width, &left, &cameraX))
    {
        frame->mainY = g->cameraYOffset - top;
        frame->mainX = g->cameraXOffset + left - cameraX;
    }
}

// For the panels

int Hook_Portrait(int species, uint32_t *pixels, int *width, int *height)
{
    const u8 *tiles;
    const u16 *palette;
    int x, y;

    if (species < 0 || species >= NUM_SPECIES)
        return FALSE;
    tiles = gMonPortraitGroupGfx[species / 15] + (species % 15) * SIZE_OF_VRAM_PORTRAIT_TILES;
    palette = (const u16 *)gMonPortraitGroupPals[species / 15][species % 15];

    // Six 16x16 sprites, three across.
    *width = 48;
    *height = 32;
    for (y = 0; y < 32; y++)
    {
        for (x = 0; x < 48; x++)
        {
            int tile = ((y / 16) * 3 + x / 16) * 4 + ((y & 15) / 8) * 2 + (x & 15) / 8;
            int row = y & 7, column = x & 7;
            u8 value = tiles[tile * 32 + row * 4 + column / 2];
            int index = (column & 1) ? (value >> 4) : (value & 0xF);
            u32 c = palette[index];
            u32 r = (c & 0x1F) * 255 / 31, g = ((c >> 5) & 0x1F) * 255 / 31, b = ((c >> 10) & 0x1F) * 255 / 31;

            pixels[y * 48 + x] = index ? 0xFF000000 | (r << 16) | (g << 8) | b : 0;
        }
    }
    return TRUE;
}

const char *Hook_SpeciesName(int species, int language)
{
    static char name[11];
    int set = language == LANGUAGE_FRENCH ? 1 : language == LANGUAGE_GERMAN ? 2 : 0;
    int i;

    if (species < 0 || species >= NUM_SPECIES)
        return "";
    for (i = 0; i < 10; i++)
        name[i] = gSpeciesInfo[species].name[set][i];
    name[10] = 0;
    for (i = 9; i >= 0 && name[i] == ' '; i--)
        name[i] = 0;
    return name;
}

int Hook_NumSpecies(void)
{
    return NUM_SPECIES;
}

const uint8_t *Hook_FontTiles(void)
{
    return gPokedexTextGlyphs_Gfx;
}

static u32 Rgba(u16 c)
{
    u32 r = c & 0x1F, g = (c >> 5) & 0x1F, b = (c >> 10) & 0x1F;

    r = (r << 3) | (r >> 2);
    g = (g << 3) | (g >> 2);
    b = (b << 3) | (b >> 2);
    return 0xFF000000 | (r << 16) | (g << 8) | b;
}

// The Options screen's frame layer, as the GBA shows it.
void Hook_OptionsBackground(uint32_t *out, int language)
{
    const u8 *tiles;
    const u16 *map;
    const u16 *palettes = (const u16 *)gOptionsBackground_Pals;
    int x, y;

    switch (language)
    {
    case LANGUAGE_FRENCH:
        tiles = gOptionsBackground_Gfx_EnFr;
        map = (const u16 *)gOptionsBackground_Tilemap_Fr;
        break;
    case LANGUAGE_GERMAN:
        tiles = gOptionsBackground_Gfx_De;
        map = (const u16 *)gOptionsBackground_Tilemap_EnDe;
        break;
    case LANGUAGE_ITALIAN:
        tiles = gOptionsBackground_Gfx_It;
        map = (const u16 *)gOptionsBackground_Tilemap_It;
        break;
    case LANGUAGE_SPANISH:
        tiles = gOptionsBackground_Gfx_Es;
        map = (const u16 *)gOptionsBackground_Tilemap_Es;
        break;
    default:
        tiles = gOptionsBackground_Gfx_EnFr;
        map = (const u16 *)gOptionsBackground_Tilemap_EnDe;
        break;
    }

    for (y = 0; y < 160; y++)
    {
        for (x = 0; x < 240; x++)
        {
            u16 entry = map[(y / 8) * 32 + x / 8];
            int px = (entry & 0x400) ? 7 - (x & 7) : x & 7;
            int py = (entry & 0x800) ? 7 - (y & 7) : y & 7;
            u8 value = tiles[(entry & 0x3FF) * 32 + py * 4 + px / 2];
            int index = (px & 1) ? (value >> 4) : (value & 0xF);

            out[y * 240 + x] = Rgba(palettes[index ? (entry >> 12) * 16 + index : 0]);
        }
    }
}

// A block of the Options sprite sheet: 32 tiles to a row. Pixels with nothing are 0.
void Hook_OptionsSprite(uint32_t *out, int tileX, int tileY, int widthTiles, int heightTiles, int palette, int language)
{
    const u8 *tiles;
    const u16 *pal = (const u16 *)gGBAButtonIcons_Pals + palette * 16;
    int x, y;

    switch (language)
    {
    case LANGUAGE_FRENCH: tiles = gOptionsSprites_Gfx_Fr; break;
    case LANGUAGE_GERMAN: tiles = gOptionsSprites_Gfx_De; break;
    case LANGUAGE_ITALIAN: tiles = gOptionsSprites_Gfx_It; break;
    case LANGUAGE_SPANISH: tiles = gOptionsSprites_Gfx_Es; break;
    default: tiles = gOptionsSprites_Gfx_En; break;
    }

    for (y = 0; y < heightTiles * 8; y++)
    {
        for (x = 0; x < widthTiles * 8; x++)
        {
            int tile = (tileY + y / 8) * 32 + tileX + x / 8;
            u8 value = tiles[tile * 32 + (y & 7) * 4 + (x & 7) / 2];
            int index = (x & 1) ? (value >> 4) : (value & 0xF);

            out[y * 32 + x] = index ? Rgba(pal[index]) : 0;
        }
    }
}

int Hook_Language(void)
{
    return gMain_saveData.language;
}

// Collision of one table pixel, for the debug overlay.
int Hook_CollisionAt(int x, int y)
{
    const struct BoardCollisionDataSet *set = &gBoardConfig.fieldLayout.collision;
    int layer = gCurrentPinballGame ? gCurrentPinballGame->boardLayerDepth : 0;
    int page, tileX = x / 8, tileY, subX, subY, tile;

    if (x < 0 || y < 0 || x >= 256 || y >= 1024 || layer < 0)
        return 0;
    page = y / (8 * 64);
    if (layer + page > 3)
        return 0;
    tileY = (y / 8) % 64;
    subX = x & 7;
    subY = y & 7;
    if (!set->tileData[layer + page] || !set->typeData[layer + page])
        return 0;
    tile = set->tileData[layer + page][tileY * 64 + tileX];
    return set->typeData[layer + page][tile * 64 + subY * 8 + subX];
}
