// Statistics and achievements, kept in a file next to the program. They count
// real games only: replays and training don't reach here.

#include <stdio.h>
#include <string.h>

#include "pc.h"

#define STATS_MAGIC 0x53525050  // "PPRS"
#define FIELD_DUSCLOPS 2
#define FIELD_KECLEON 3
#define FIELD_KYOGRE 4
#define FIELD_GROUDON 5
#define FIELD_RAYQUAZA 6
#define FIELD_SPHEAL 7

static struct Stats sStats;
static CRITICAL_SECTION sLock;
static int sDirty;

enum
{
    ACH_FIRST_GAME,
    ACH_FIRST_CATCH,
    ACH_TEN_CATCHES,
    ACH_FIFTY_CATCHES,
    ACH_EVOLUTION,
    ACH_TRAVEL,
    ACH_BONUS,
    ACH_LEGENDARY,
    ACH_RAYQUAZA,
    ACH_MILLION,
    ACH_100_MILLION,
    ACH_BILLION,
    ACH_COINS,
    ACH_BUMPERS,
    ACH_FLIPPERS,
    ACH_ALL_BONUS,
};

static const struct AchievementInfo sAchievementsIt[NUM_ACHIEVEMENTS] = {
    {L"Prima pallina", L"Gioca la tua prima partita"},
    {L"Preso!", L"Cattura il tuo primo Pokémon"},
    {L"Collezionista", L"Cattura 10 Pokémon"},
    {L"Allenatore esperto", L"Cattura 50 Pokémon"},
    {L"Cambiamento", L"Fai evolvere un Pokémon"},
    {L"Giramondo", L"Completa un viaggio"},
    {L"Bonus!", L"Supera un livello bonus"},
    {L"Leggenda", L"Sconfiggi Groudon o Kyogre"},
    {L"Nel cielo", L"Sconfiggi Rayquaza"},
    {L"Un milione", L"Fai 1.000.000 di punti"},
    {L"Cento milioni", L"Fai 100.000.000 di punti"},
    {L"Un miliardo", L"Fai 1.000.000.000 di punti"},
    {L"Tasche piene", L"Arriva a 99 monete"},
    {L"Respingente", L"Colpisci 1.000 respingenti"},
    {L"Dita d'acciaio", L"Usa i flipper 10.000 volte"},
    {L"Tutti i bonus", L"Supera tutti i livelli bonus"},
};

static const struct AchievementInfo sAchievementsEn[NUM_ACHIEVEMENTS] = {
    {L"First ball", L"Play your first game"},
    {L"Gotcha!", L"Catch your first Pokémon"},
    {L"Collector", L"Catch 10 Pokémon"},
    {L"Expert trainer", L"Catch 50 Pokémon"},
    {L"Changes", L"Evolve a Pokémon"},
    {L"Globetrotter", L"Complete a travel"},
    {L"Bonus!", L"Clear a bonus stage"},
    {L"Legend", L"Defeat Groudon or Kyogre"},
    {L"Sky high", L"Defeat Rayquaza"},
    {L"One million", L"Score 1,000,000 points"},
    {L"A hundred million", L"Score 100,000,000 points"},
    {L"One billion", L"Score 1,000,000,000 points"},
    {L"Full pockets", L"Reach 99 coins"},
    {L"Bumper car", L"Hit 1,000 bumpers"},
    {L"Iron fingers", L"Use the flippers 10,000 times"},
    {L"All bonuses", L"Clear every bonus stage"},
};

const struct AchievementInfo *Stats_Achievement(int index, int language)
{
    return language == 3 ? &sAchievementsIt[index] : &sAchievementsEn[index];
}

static void Unlock(int achievement)
{
    if (sStats.achievements & (1u << achievement))
        return;
    sStats.achievements |= 1u << achievement;
    sDirty = 1;
    Ui_ToastW(Stats_Achievement(achievement, Video_LatestInfo()->language)->name);
}

static void CheckScore(uint32_t hi, uint32_t lo)
{
    // scoreLo counts to 99,999,999 and then carries into scoreHi.
    if (hi || lo >= 1000000)
        Unlock(ACH_MILLION);
    if (hi >= 1)
        Unlock(ACH_100_MILLION);
    if (hi >= 10)
        Unlock(ACH_BILLION);
}

void Stats_Event(int event, uint32_t a, uint32_t b)
{
    EnterCriticalSection(&sLock);
    switch (event)
    {
    case EVENT_GAME_START:
        sStats.games++;
        sDirty = 1;
        Unlock(ACH_FIRST_GAME);
        break;
    case EVENT_GAME_OVER:
        if (a > sStats.bestScore[0] || (a == sStats.bestScore[0] && b > sStats.bestScore[1]))
        {
            sStats.bestScore[0] = a;
            sStats.bestScore[1] = b;
        }
        CheckScore(a, b);
        sDirty = 1;
        Stats_Save();
        break;
    case EVENT_BALL_LOST:
        sStats.ballsLost++;
        break;
    case EVENT_BALL_SAVED:
        sStats.ballsSaved++;
        break;
    case EVENT_CATCH:
        sStats.catches++;
        Unlock(ACH_FIRST_CATCH);
        if (sStats.catches >= 10)
            Unlock(ACH_TEN_CATCHES);
        if (sStats.catches >= 50)
            Unlock(ACH_FIFTY_CATCHES);
        break;
    case EVENT_EVOLUTION:
        sStats.evolutions++;
        Unlock(ACH_EVOLUTION);
        break;
    case EVENT_PLAY_TIME:
        sStats.frames += a;
        break;
    case EVENT_BONUS_CLEARED:
        sStats.bonusCleared++;
        sStats.bonusFieldsCleared |= 1u << a;
        Unlock(ACH_BONUS);
        if (a == FIELD_GROUDON || a == FIELD_KYOGRE)
            Unlock(ACH_LEGENDARY);
        if (a == FIELD_RAYQUAZA)
            Unlock(ACH_RAYQUAZA);
        if ((sStats.bonusFieldsCleared & 0xFC) == 0xFC)
            Unlock(ACH_ALL_BONUS);
        break;
    case EVENT_TRAVEL:
        sStats.travels++;
        Unlock(ACH_TRAVEL);
        break;
    case EVENT_FLIPPER:
        sStats.flips += a;
        if (sStats.flips >= 10000)
            Unlock(ACH_FLIPPERS);
        break;
    case EVENT_BUMPER:
        sStats.bumpers += a;
        if (sStats.bumpers >= 1000)
            Unlock(ACH_BUMPERS);
        break;
    case EVENT_COINS:
        if (a > sStats.coinsMax)
            sStats.coinsMax = a;
        if (a >= 99)
            Unlock(ACH_COINS);
        break;
    case EVENT_SCORE:
        CheckScore(a, b);
        break;
    }
    sDirty = 1;
    LeaveCriticalSection(&sLock);
}

const struct Stats *Stats_Get(void)
{
    return &sStats;
}

void Stats_Save(void)
{
    char path[MAX_PATH];
    uint32_t magic = STATS_MAGIC;
    FILE *file;

    if (!sDirty)
        return;
    Host_UserFile(path, "pokepinballrs_pc.stats");
    file = fopen(path, "wb");
    if (file)
    {
        fwrite(&magic, sizeof(magic), 1, file);
        fwrite(&sStats, sizeof(sStats), 1, file);
        fclose(file);
    }
    sDirty = 0;
}

void Stats_Init(void)
{
    char path[MAX_PATH];
    uint32_t magic = 0;
    FILE *file;

    InitializeCriticalSection(&sLock);
    Host_UserFile(path, "pokepinballrs_pc.stats");
    file = fopen(path, "rb");
    if (file)
    {
        if (fread(&magic, sizeof(magic), 1, file) != 1 || magic != STATS_MAGIC || fread(&sStats, sizeof(sStats), 1, file) != 1)
            memset(&sStats, 0, sizeof(sStats));
        fclose(file);
    }
}
