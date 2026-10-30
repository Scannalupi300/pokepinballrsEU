// What goes above the game: the menu, the side panels, the debug overlay and
// short messages. All of it is drawn on the CPU into one picture of the window's
// size (alpha premultiplied), with GDI for the text, on the display's thread.
// The menu is also driven from the window's thread, hence sLock.

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#include "pc.h"

#define LANGUAGE_ITALIAN 3
#define LANGUAGE_UNSET 99

#define MENU_CANVAS_WIDTH 240
#define MENU_CANVAS_HEIGHT 160

#define COLOR_TEXT 0xFFF2F2F2
#define COLOR_GOOD 0xFF70E080

static CRITICAL_SECTION sLock;
static uint32_t *sPixels;
static int sWidth, sHeight;
static volatile LONG sWantWidth, sWantHeight;
static int sDirty;
static int sHeld;   // the display is copying it
static RECT sGameRect;
static double sGameScale;

static wchar_t sToast[128];
static DWORD sToastEnd;
static int sToastShown;

static DWORD sLastPanels, sLastFps, sLastMenu;
static int sCheckFrame;
static uint32_t sLastDebugFrame;
static int sWasVisible;

// The menu
enum Page
{
    PAGE_MAIN, PAGE_VIDEO, PAGE_CONTROLS, PAGE_KEYS, PAGE_PAD, PAGE_GAME, PAGE_TRAINING, PAGE_TRAINING_MODES,
    PAGE_REPLAYS, PAGE_LANGUAGE, PAGE_STATS, PAGE_ACHIEVEMENTS, PAGE_ONLINE, PAGE_COUNT
};

enum ItemKind { ITEM_ACTION, ITEM_PAGE, ITEM_TOGGLE, ITEM_CYCLE, ITEM_FLAG, ITEM_TEXT, ITEM_BIND_KEY, ITEM_BIND_PAD };

enum Action2
{
    DO_RESUME, DO_QUICK_SAVE, DO_QUICK_LOAD, DO_RESUME_SUSPENDED, DO_SUSPEND_EXIT, DO_QUIT, DO_RESTART,
    DO_TRAIN, DO_REPLAY, DO_REPLAY_LAST, DO_STOP_REPLAY, DO_LANGUAGE, DO_FULLSCREEN, DO_RESET_BINDINGS,
    DO_ONLINE_SUBMIT, DO_ONLINE_REFRESH,
};

struct Item
{
    wchar_t label[80];
    wchar_t value[64];
    wchar_t hint[80];
    int kind;
    int arg, arg2;
    int32_t *option;
    const wchar_t *const *names;
    int count;
    const int *values;
};

#define MAX_ITEMS 64

static struct Item sItems[MAX_ITEMS];
static int sNumItems;
static wchar_t sPageHint[80];
static int sPage;
static int sMenuOpen;
static int sCursor[PAGE_COUNT];
static int sPageStack[8];
static int sStackDepth;
static int sTrainingField;
static int sCaptureAction = -1, sCaptureSlot, sCapturePad;
static int sMenuDirty;
static uint32_t sPrevPadActions;

static char sReplayNames[32][260];
static int sNumReplays;
static struct LeaderboardEntry sBoard[12];
static int sBoardCount;
static volatile LONG sOnlineBusy;

int Input_HeldActions(void);
void Video_WorldOrigin(int *x, int *y);
const uint32_t *Video_Minimap(int *width, int *height);

static int Italian(void)
{
    int language = Video_LatestInfo()->language;

    if (language == LANGUAGE_ITALIAN)
        return 1;
    return language >= 5 && PRIMARYLANGID(GetUserDefaultUILanguage()) == LANG_ITALIAN;
}

#define T(it, en) (Italian() ? (it) : (en))

void Ui_ToastW(const wchar_t *text)
{
    EnterCriticalSection(&sLock);
    wcsncpy(sToast, text, 127);
    sToastEnd = GetTickCount() + 3000;
    LeaveCriticalSection(&sLock);
}

int Ui_MenuOpen(void)
{
    return sMenuOpen;
}

static void BuildPage(void);

void Ui_OpenMenu(void)
{
    EnterCriticalSection(&sLock);
    if (!sMenuOpen)
    {
        sMenuOpen = 1;
        sPage = PAGE_MAIN;
        sStackDepth = 0;
        sCursor[PAGE_MAIN] = 0;
        sCaptureAction = -1;
        Input_ReleaseKeys();
        Host_SetPaused(PAUSE_MENU, 1);
        BuildPage();
        sMenuDirty = 1;
    }
    LeaveCriticalSection(&sLock);
}

void Ui_CloseMenu(void)
{
    EnterCriticalSection(&sLock);
    if (sMenuOpen)
    {
        sMenuOpen = 0;
        sMenuDirty = 1;
        Settings_Save();
        Host_SetPaused(PAUSE_MENU, 0);
    }
    LeaveCriticalSection(&sLock);
}

static struct Item *AddItem(int kind, const wchar_t *label)
{
    struct Item *item;

    if (sNumItems >= MAX_ITEMS)
        sNumItems = MAX_ITEMS - 1;
    item = &sItems[sNumItems++];
    memset(item, 0, sizeof(*item));
    item->kind = kind;
    wcsncpy(item->label, label, 79);
    return item;
}

static void AddAction(const wchar_t *label, int action, int arg, int arg2)
{
    struct Item *item = AddItem(ITEM_ACTION, label);

    item->arg = action;
    item->arg2 = arg;
    item->count = arg2;
}

static void AddPage(const wchar_t *label, int page, int arg)
{
    struct Item *item = AddItem(ITEM_PAGE, label);

    item->arg = page;
    item->arg2 = arg;
}

static void AddToggle(const wchar_t *label, int32_t *option)
{
    struct Item *item = AddItem(ITEM_TOGGLE, label);

    item->option = option;
    wcscpy(item->value, *option ? T(L"Sì", L"On") : T(L"No", L"Off"));
}

static void AddFlag(const wchar_t *label, int32_t *option, int flag)
{
    struct Item *item = AddItem(ITEM_FLAG, label);

    item->option = option;
    item->arg = flag;
    wcscpy(item->value, (*option & flag) ? T(L"Sì", L"On") : T(L"No", L"Off"));
}

static void AddCycle(const wchar_t *label, int32_t *option, const wchar_t *const *names, const int *values, int count)
{
    struct Item *item = AddItem(ITEM_CYCLE, label);
    int i;

    item->option = option;
    item->names = names;
    item->values = values;
    item->count = count;
    for (i = 0; i < count; i++)
    {
        if ((values ? values[i] : i) == *option)
            wcsncpy(item->value, names[i], 63);
    }
}

static void SetHint(const wchar_t *text)
{
    wcsncpy(sItems[sNumItems - 1].hint, text, 79);
}

static void SetPageHint(const wchar_t *text)
{
    wcsncpy(sPageHint, text, 79);
}

static void AddText(const wchar_t *label, const wchar_t *value)
{
    struct Item *item = AddItem(ITEM_TEXT, label);

    if (value)
        wcsncpy(item->value, value, 63);
}

static void AddBinding(int kind, const wchar_t *label, int action)
{
    struct Item *item = AddItem(kind, label);
    wchar_t name[64];
    int a, b;

    item->arg = action;
    if (kind == ITEM_BIND_KEY)
    {
        a = gBindings.keys[action][0];
        b = gBindings.keys[action][1];
        _snwprintf(name, 63, L"%hs", Input_KeyName(a));
        wcsncpy(item->value, name, 30);
        _snwprintf(name, 63, L"  /  %hs", Input_KeyName(b));
    }
    else
    {
        a = gBindings.pad[action][0];
        b = gBindings.pad[action][1];
        _snwprintf(name, 63, L"%hs", Input_PadName(a));
        wcsncpy(item->value, name, 30);
        _snwprintf(name, 63, L"  /  %hs", Input_PadName(b));
    }
    name[63] = 0;
    wcsncat(item->value, name, 63 - wcslen(item->value));
}

static const wchar_t *ActionName(int action)
{
    switch (action)
    {
    case ACTION_A: return L"A";
    case ACTION_B: return L"B";
    case ACTION_SELECT: return L"Select";
    case ACTION_START: return L"Start";
    case ACTION_RIGHT: return T(L"Destra", L"Right");
    case ACTION_LEFT: return T(L"Sinistra", L"Left");
    case ACTION_UP: return T(L"Su", L"Up");
    case ACTION_DOWN: return T(L"Giù", L"Down");
    case ACTION_R: return L"R";
    case ACTION_L: return L"L";
    case ACTION_MENU: return L"Menu";
    case ACTION_FAST_FORWARD: return T(L"Avanti veloce", L"Fast forward");
    case ACTION_QUICK_SAVE: return T(L"Salva rapido", L"Quick save");
    case ACTION_QUICK_LOAD: return T(L"Carica rapido", L"Quick load");
    case ACTION_DEBUG: return T(L"Debug", L"Debug");
    }
    return L"";
}

static const wchar_t *ActionHint(int action)
{
    switch (action)
    {
    case ACTION_A: return T(L"Di norma il flipper destro", L"By default the right flipper");
    case ACTION_LEFT: return T(L"Di norma il flipper sinistro", L"By default the left flipper");
    case ACTION_R: return T(L"Di norma scuote a destra", L"By default nudges right");
    case ACTION_L: return T(L"Di norma scuote a sinistra", L"By default nudges left");
    }
    return T(L"Invio/Spazio: cambia  Canc: togli", L"Enter/Space: change  Del: clear");
}

static void BuildMain(void)
{
    AddAction(T(L"Riprendi", L"Resume"), DO_RESUME, 0, 0);
    if (State_Exists(STATE_SLOT_AUTO))
        AddAction(T(L"Partita sospesa", L"Suspended game"), DO_RESUME_SUSPENDED, 0, 0);
    if (Video_LatestInfo()->inGame)
        AddAction(T(L"Sospendi ed esci", L"Suspend and quit"), DO_SUSPEND_EXIT, 0, 0);
    AddAction(T(L"Salvataggio rapido", L"Quick save"), DO_QUICK_SAVE, 0, 0);
    if (State_Exists(STATE_SLOT_QUICK))
        AddAction(T(L"Caricamento rapido", L"Quick load"), DO_QUICK_LOAD, 0, 0);
    AddPage(T(L"Allenamento", L"Training"), PAGE_TRAINING, 0);
    AddPage(T(L"Replay", L"Replays"), PAGE_REPLAYS, 0);
    AddPage(T(L"Video", L"Video"), PAGE_VIDEO, 0);
    AddPage(T(L"Controlli", L"Controls"), PAGE_CONTROLS, 0);
    AddPage(T(L"Opzioni di gioco", L"Game options"), PAGE_GAME, 0);
    AddPage(T(L"Lingua", L"Language"), PAGE_LANGUAGE, 0);
    AddPage(T(L"Statistiche", L"Statistics"), PAGE_STATS, 0);
    AddPage(T(L"Obiettivi", L"Achievements"), PAGE_ACHIEVEMENTS, 0);
    AddPage(T(L"Classifica", L"Leaderboard"), PAGE_ONLINE, 0);
    AddAction(T(L"Riavvia", L"Restart"), DO_RESTART, 0, 0);
    AddAction(T(L"Esci", L"Quit"), DO_QUIT, 0, 0);
}

static void BuildVideo(void)
{
    static const wchar_t *const viewsIt[] = {L"Normale", L"Tavolo intero"};
    static const wchar_t *const viewsEn[] = {L"Normal", L"Whole table"};
    static const wchar_t *const scalesIt[] = {L"Intero", L"Adatta"};
    static const wchar_t *const scalesEn[] = {L"Integer", L"Fit"};
    static const wchar_t *const filtersIt[] = {L"Nessuno", L"LCD", L"CRT"};
    static const wchar_t *const filtersEn[] = {L"None", L"LCD", L"CRT"};
    static const wchar_t *const internalIt[] = {L"Automatica", L"1x", L"2x", L"3x", L"4x"};
    static const wchar_t *const internalEn[] = {L"Automatic", L"1x", L"2x", L"3x", L"4x"};

    AddCycle(T(L"Vista", L"View"), &gPcOptions.view, Italian() ? viewsIt : viewsEn, NULL, VIEW_COUNT);
    AddToggle(T(L"Pannelli laterali", L"Side panels"), &gPcOptions.panels);
    AddToggle(T(L"Oltre 60 fps", L"Above 60 fps"), &gPcOptions.interpolate);
    SetHint(T(L"Tra i frame: il gioco resta a 60", L"Between frames: game stays at 60"));
    AddCycle(T(L"Risoluzione", L"Resolution"), &gPcOptions.internalScale, Italian() ? internalIt : internalEn, NULL, 5);
    AddCycle(T(L"Scala", L"Scaling"), &gPcOptions.scaleMode, Italian() ? scalesIt : scalesEn, NULL, SCALE_COUNT);
    AddCycle(T(L"Filtro", L"Filter"), &gPcOptions.filter, Italian() ? filtersIt : filtersEn, NULL, FILTER_COUNT);
    AddToggle(L"VSync", &gPcOptions.vsync);
    AddToggle(T(L"Mostra gli FPS", L"Show FPS"), &gPcOptions.showFps);
    AddToggle(T(L"Overlay di debug", L"Debug overlay"), &gPcOptions.debugOverlay);
    AddToggle(T(L"Mappa collisioni", L"Collision map"), &gPcOptions.debugCollision);
    AddAction(T(L"Schermo intero", L"Full screen"), DO_FULLSCREEN, 0, 0);
}

static void BuildControls(void)
{
    static const wchar_t *const rumbleNames[] = {L"0", L"25", L"50", L"75", L"100"};
    static const int rumbleValues[] = {0, 25, 50, 75, 100};
    wchar_t pad[80];

    AddPage(T(L"Tastiera", L"Keyboard"), PAGE_KEYS, 0);
    AddPage(T(L"Controller", L"Controller"), PAGE_PAD, 0);
    AddToggle(T(L"Latenza ridotta", L"Reduced latency"), &gPcOptions.lowLatency);
    AddCycle(T(L"Vibrazione", L"Rumble"), &gPcOptions.rumble, rumbleNames, rumbleValues, 5);
    SetHint(T(L"Intensità, da 0 a 100", L"Strength, from 0 to 100"));
    AddToggle(T(L"Vibrazione sui flipper", L"Rumble on flippers"), &gPcOptions.rumbleFlippers);
    _snwprintf(pad, 79, L"%hs", Input_PadConnected() ? Input_PadDescription() : "-");
    pad[79] = 0;
    AddText(T(L"Collegato", L"Connected"), pad);
    AddAction(T(L"Tasti predefiniti", L"Default controls"), DO_RESET_BINDINGS, 0, 0);
}

static void BuildBindings(int kind)
{
    int action;

    for (action = 0; action < NUM_ACTIONS; action++)
    {
        AddBinding(kind, ActionName(action), action);
        SetHint(ActionHint(action));
    }
}

static void BuildGame(void)
{
    static const wchar_t *const saver[] = {L"x1", L"x2", L"x3", L"x4"};
    static const int saverValues[] = {1, 2, 3, 4};
    static const wchar_t *const speed[] = {L"x1", L"x2", L"x3", L"x4"};
    static const int speedValues[] = {1, 2, 3, 4};

    AddToggle(T(L"Vanilla", L"Vanilla"), &gPcOptions.game.vanilla);
    SetHint(T(L"Gioco originale: spegne le voci sotto", L"Original game: turns off what is below"));
    AddCycle(T(L"Durata ball save", L"Ball save length"), &gPcOptions.game.ballSaver, saver, saverValues, 4);
    SetHint(T(L"Dalla prossima partita, senza Vanilla", L"From the next game, without Vanilla"));
    AddToggle(T(L"Palline infinite", L"Infinite balls"), &gPcOptions.game.infiniteBalls);
    SetHint(T(L"Dalla prossima partita, senza Vanilla", L"From the next game, without Vanilla"));
    AddFlag(T(L"Fix carta del viaggio", L"Fix travel card"), &gPcOptions.game.fixes, FIX_TRAVEL_CARD_PALETTE);
    SetHint(T(L"Palette sbagliata per un frame", L"Wrong palette for one frame"));
    AddFlag(T(L"Fix lingua partita salvata", L"Fix saved game language"), &gPcOptions.game.fixes, FIX_SAVED_LANGUAGE);
    SetHint(T(L"Riprendendo resta la lingua scelta", L"Resuming keeps your language"));
    AddCycle(T(L"Velocità Pokédex", L"Pokédex speed"), &gPcOptions.pokedexSpeed, speed, speedValues, 4);
}

static const wchar_t *FieldName(int field)
{
    static const wchar_t *const names[] = {L"Ruby", L"Sapphire", L"Dusclops", L"Kecleon", L"Kyogre", L"Groudon", L"Rayquaza", L"Spheal"};

    return names[field];
}

static void BuildTraining(void)
{
    int field;

    AddPage(FieldName(0), PAGE_TRAINING_MODES, 0);
    AddPage(FieldName(1), PAGE_TRAINING_MODES, 1);
    for (field = 2; field < 8; field++)
        AddAction(FieldName(field), DO_TRAIN, field, 0);
    SetPageHint(T(L"In allenamento non si salva nulla", L"Nothing is saved in training"));
}

static void BuildTrainingModes(void)
{
    AddAction(T(L"Tavolo normale", L"Normal table"), DO_TRAIN, sTrainingField, 0xFF);
    AddAction(T(L"Cattura", L"Catch"), DO_TRAIN, sTrainingField, 1);
    AddAction(T(L"Schiusa", L"Hatch"), DO_TRAIN, sTrainingField, 2);
    AddAction(T(L"Evoluzione", L"Evolution"), DO_TRAIN, sTrainingField, 3);
    AddAction(T(L"Viaggio", L"Travel"), DO_TRAIN, sTrainingField, 4);
    AddAction(T(L"Cattura di Jirachi", L"Jirachi catch"), DO_TRAIN, sTrainingField, 5);
    AddAction(T(L"Roulette dei premi", L"Prize roulette"), DO_TRAIN, sTrainingField, 6);
    AddAction(T(L"Buca del bonus", L"Bonus hole"), DO_TRAIN, sTrainingField, 7);
}

static void BuildReplays(void)
{
    int i;
    char path[MAX_PATH];

    if (Replay_IsPlaying())
        AddAction(T(L"Ferma il replay", L"Stop the replay"), DO_STOP_REPLAY, 0, 0);
    Host_UserFile(path, "replays\\last.ppr");
    if (GetFileAttributesA(path) != INVALID_FILE_ATTRIBUTES)
        AddAction(T(L"Ultima partita", L"Last game"), DO_REPLAY_LAST, 0, 0);
    sNumReplays = Replay_ListFiles(sReplayNames, 32);
    for (i = 0; i < sNumReplays && i < 24; i++)
    {
        wchar_t label[80];
        int year, month, day, hour, minute, second, field;
        char score[32];

        if (sscanf(sReplayNames[i], "%4d%2d%2d-%2d%2d%2d-f%d-%31[0-9]", &year, &month, &day, &hour, &minute, &second, &field, score) == 8 && field >= 0 && field < 8)
        {
            const char *digits = score;

            while (*digits == '0' && digits[1])
                digits++;
            _snwprintf(label, 79, L"%02d/%02d %02d:%02d %ls", day, month, hour, minute, FieldName(field));
            label[79] = 0;
            AddAction(label, DO_REPLAY, i, 0);
            _snwprintf(sItems[sNumItems - 1].value, 63, L"%hs", digits);
        }
        else
        {
            _snwprintf(label, 79, L"%.30hs", sReplayNames[i]);
            label[79] = 0;
            AddAction(label, DO_REPLAY, i, 0);
        }
    }
    SetPageHint(T(L"Si salvano da soli a fine partita", L"Saved by themselves after each game"));
}

static void BuildLanguage(void)
{
    static const wchar_t *const names[] = {L"English", L"Français", L"Deutsch", L"Italiano", L"Español"};
    int i;

    for (i = 0; i < 5; i++)
        AddAction(names[i], DO_LANGUAGE, i, 0);
    SetPageHint(T(L"Cambiare lingua riavvia il gioco", L"Changing language restarts the game"));
}

static void AddStat(const wchar_t *label, unsigned long long value)
{
    wchar_t text[32];

    _snwprintf(text, 31, L"%I64u", value);
    text[31] = 0;
    AddText(label, text);
}

static void BuildStats(void)
{
    const struct Stats *stats = Stats_Get();
    wchar_t best[40];

    wchar_t time[32];

    AddStat(T(L"Partite giocate", L"Games played"), stats->games);
    _snwprintf(time, 31, L"%I64u h %02I64u min", stats->frames / (60 * 3600), (stats->frames / 3600) % 60);
    time[31] = 0;
    AddText(T(L"Tempo di gioco", L"Time played"), time);
    if (stats->bestScore[0])
        _snwprintf(best, 39, L"%I64u%08I64u", stats->bestScore[0], stats->bestScore[1]);
    else
        _snwprintf(best, 39, L"%I64u", stats->bestScore[1]);
    best[39] = 0;
    AddText(T(L"Punteggio migliore", L"Best score"), best);
    AddStat(T(L"Pokémon catturati", L"Pokémon caught"), stats->catches);
    AddStat(T(L"Evoluzioni", L"Evolutions"), stats->evolutions);
    AddStat(T(L"Viaggi completati", L"Travels completed"), stats->travels);
    AddStat(T(L"Livelli bonus superati", L"Bonus stages cleared"), stats->bonusCleared);
    AddStat(T(L"Palline perse", L"Balls lost"), stats->ballsLost);
    AddStat(T(L"Palline salvate", L"Balls saved"), stats->ballsSaved);
    AddStat(T(L"Colpi di flipper", L"Flipper presses"), stats->flips);
    AddStat(T(L"Colpi ai respingenti", L"Bumper hits"), stats->bumpers);
    AddStat(T(L"Monete, massimo", L"Most coins"), stats->coinsMax);
}

static void BuildAchievements(void)
{
    const struct Stats *stats = Stats_Get();
    int language = Video_LatestInfo()->language;
    int i;

    for (i = 0; i < NUM_ACHIEVEMENTS; i++)
    {
        const struct AchievementInfo *info = Stats_Achievement(i, language);

        AddText(info->name, (stats->achievements >> i) & 1 ? T(L"Preso!", L"Got it!") : L"-");
        SetHint(info->description);
    }
}

static const wchar_t *OnlineStatusText(void)
{
    static wchar_t text[140];
    const char *status = Online_Status();

    if (sOnlineBusy)
        return T(L"Attendere...", L"Please wait...");
    if (!Online_Url()[0] || strcmp(status, "no_url") == 0)
        return T(L"Server: online_url nel file .ini", L"Server: online_url in the .ini file");
    if (strcmp(status, "no_server") == 0)
        return T(L"Server non raggiungibile", L"Can't reach the server");
    if (strcmp(status, "no_replay") == 0)
        return T(L"Nessun replay da inviare", L"No replay to send");
    if (strcmp(status, "ok") == 0)
        return T(L"Fatto", L"Done");
    _snwprintf(text, 139, L"%.38hs", status);
    text[139] = 0;
    return text;
}

static void BuildOnline(void)
{
    int i;

    AddAction(T(L"Invia l'ultima partita", L"Send the last game"), DO_ONLINE_SUBMIT, 0, 0);
    AddAction(T(L"Aggiorna", L"Refresh"), DO_ONLINE_REFRESH, 0, 0);
    SetPageHint(OnlineStatusText());
    for (i = 0; i < sBoardCount; i++)
    {
        wchar_t label[80], value[64];

        _snwprintf(label, 79, L"%d. %.16hs (%hs)", i + 1, sBoard[i].name, sBoard[i].field);
        label[79] = 0;
        _snwprintf(value, 63, L"%hs", sBoard[i].score);
        value[63] = 0;
        AddText(label, value);
    }
}

static const wchar_t *PageTitle(void)
{
    switch (sPage)
    {
    case PAGE_MAIN: return L"Menu";
    case PAGE_VIDEO: return T(L"Video", L"Video");
    case PAGE_CONTROLS: return T(L"Controlli", L"Controls");
    case PAGE_KEYS: return T(L"Tastiera", L"Keyboard");
    case PAGE_PAD: return T(L"Controller", L"Controller");
    case PAGE_GAME: return T(L"Opzioni di gioco", L"Game options");
    case PAGE_TRAINING: return T(L"Allenamento", L"Training");
    case PAGE_TRAINING_MODES: return FieldName(sTrainingField);
    case PAGE_REPLAYS: return T(L"Replay", L"Replays");
    case PAGE_LANGUAGE: return T(L"Lingua", L"Language");
    case PAGE_STATS: return T(L"Statistiche", L"Statistics");
    case PAGE_ACHIEVEMENTS: return T(L"Obiettivi", L"Achievements");
    case PAGE_ONLINE: return T(L"Classifica", L"Leaderboard");
    }
    return L"";
}

static void BuildPage(void)
{
    sNumItems = 0;
    sPageHint[0] = 0;
    switch (sPage)
    {
    case PAGE_MAIN: BuildMain(); break;
    case PAGE_VIDEO: BuildVideo(); break;
    case PAGE_CONTROLS: BuildControls(); break;
    case PAGE_KEYS: BuildBindings(ITEM_BIND_KEY); break;
    case PAGE_PAD: BuildBindings(ITEM_BIND_PAD); break;
    case PAGE_GAME: BuildGame(); break;
    case PAGE_TRAINING: BuildTraining(); break;
    case PAGE_TRAINING_MODES: BuildTrainingModes(); break;
    case PAGE_REPLAYS: BuildReplays(); break;
    case PAGE_LANGUAGE: BuildLanguage(); break;
    case PAGE_STATS: BuildStats(); break;
    case PAGE_ACHIEVEMENTS: BuildAchievements(); break;
    case PAGE_ONLINE: BuildOnline(); break;
    }
    if (sCursor[sPage] >= sNumItems)
        sCursor[sPage] = sNumItems ? sNumItems - 1 : 0;
}

static DWORD WINAPI OnlineThread(LPVOID param)
{
    char path[MAX_PATH];

    if (param)
    {
        Host_UserFile(path, "replays\\last.ppr");
        Online_Submit(path);
    }
    sBoardCount = Online_Fetch(sBoard, 12);
    InterlockedExchange(&sOnlineBusy, 0);
    EnterCriticalSection(&sLock);
    if (sMenuOpen && sPage == PAGE_ONLINE)
        BuildPage();
    sMenuDirty = 1;
    LeaveCriticalSection(&sLock);
    return 0;
}

static void PostSimple(int type, int a, int b, const char *path)
{
    struct HostCommand command;

    memset(&command, 0, sizeof(command));
    command.type = type;
    command.a = a;
    command.b = b;
    if (path)
        strncpy(command.path, path, sizeof(command.path) - 1);
    Host_PostCommand(&command);
}

static void DoAction(const struct Item *item)
{
    char path[MAX_PATH];
    char name[300];

    switch (item->arg)
    {
    case DO_RESUME:
        Ui_CloseMenu();
        break;
    case DO_QUICK_SAVE:
        PostSimple(CMD_SAVE_STATE, STATE_SLOT_QUICK, 0, NULL);
        Ui_ToastW(T(L"Partita salvata", L"Game saved"));
        Ui_CloseMenu();
        break;
    case DO_QUICK_LOAD:
        PostSimple(CMD_LOAD_STATE, STATE_SLOT_QUICK, 0, NULL);
        Ui_CloseMenu();
        break;
    case DO_RESUME_SUSPENDED:
        PostSimple(CMD_LOAD_STATE, STATE_SLOT_AUTO, 0, NULL);
        Ui_CloseMenu();
        break;
    case DO_SUSPEND_EXIT:
        gPcOptions.autoSuspend = 1;
        Host_RequestQuit();
        break;
    case DO_QUIT:
        Host_RequestQuit();
        break;
    case DO_RESTART:
        PostSimple(CMD_REBOOT, 0, 0, NULL);
        Ui_CloseMenu();
        break;
    case DO_TRAIN:
        PostSimple(CMD_TRAINING, item->arg2, item->count, NULL);
        Ui_CloseMenu();
        break;
    case DO_REPLAY:
        snprintf(name, sizeof(name), "replays\\%s", sReplayNames[item->arg2]);
        Host_UserFile(path, name);
        PostSimple(CMD_PLAY_REPLAY, 0, 0, path);
        Ui_CloseMenu();
        break;
    case DO_REPLAY_LAST:
        Host_UserFile(path, "replays\\last.ppr");
        PostSimple(CMD_PLAY_REPLAY, 0, 0, path);
        Ui_CloseMenu();
        break;
    case DO_STOP_REPLAY:
        PostSimple(CMD_STOP_REPLAY, 0, 0, NULL);
        Ui_CloseMenu();
        break;
    case DO_LANGUAGE:
        PostSimple(CMD_SET_LANGUAGE, item->arg2, 0, NULL);
        Ui_CloseMenu();
        break;
    case DO_FULLSCREEN:
        Host_ToggleFullscreen();
        break;
    case DO_RESET_BINDINGS:
        Input_DefaultBindings(&gBindings);
        break;
    case DO_ONLINE_SUBMIT:
    case DO_ONLINE_REFRESH:
        if (!sOnlineBusy)
        {
            InterlockedExchange(&sOnlineBusy, 1);
            CreateThread(NULL, 0, OnlineThread, (LPVOID)(uintptr_t)(item->arg == DO_ONLINE_SUBMIT), 0, NULL);
        }
        break;
    }
}

static void Back(void)
{
    if (sStackDepth > 0)
    {
        sPage = sPageStack[--sStackDepth];
        BuildPage();
    }
    else
    {
        Ui_CloseMenu();
    }
}

static void ChangeValue(struct Item *item, int direction)
{
    int i;

    switch (item->kind)
    {
    case ITEM_TOGGLE:
        *item->option = !*item->option;
        if (item->option == &gPcOptions.panels)
            Host_ApplyWindowSize();
        break;
    case ITEM_FLAG:
        *item->option ^= item->arg;
        break;
    case ITEM_CYCLE:
        for (i = 0; i < item->count; i++)
        {
            if ((item->values ? item->values[i] : i) == *item->option)
                break;
        }
        i = (i + direction + item->count) % item->count;
        *item->option = item->values ? item->values[i] : i;
        if (item->option == &gPcOptions.view)
            Host_ApplyWindowSize();
        break;
    }
}

static void Activate(int slot)
{
    struct Item *item = &sItems[sCursor[sPage]];

    if (sNumItems == 0)
        return;
    switch (item->kind)
    {
    case ITEM_ACTION:
        DoAction(item);
        break;
    case ITEM_PAGE:
        if (item->arg == PAGE_TRAINING_MODES)
            sTrainingField = item->arg2;
        if (sStackDepth < 8)
            sPageStack[sStackDepth++] = sPage;
        sPage = item->arg;
        sCursor[sPage] = 0;
        break;
    case ITEM_TOGGLE:
    case ITEM_FLAG:
    case ITEM_CYCLE:
        ChangeValue(item, 1);
        break;
    case ITEM_BIND_KEY:
    case ITEM_BIND_PAD:
        sCaptureAction = item->arg;
        sCaptureSlot = slot;
        sCapturePad = item->kind == ITEM_BIND_PAD;
        Input_CapturePad();
        break;
    }
}

static void MoveCursor(int delta)
{
    if (sNumItems)
        sCursor[sPage] = (sCursor[sPage] + delta + sNumItems) % sNumItems;
}

void Ui_MenuKey(int vk)
{
    EnterCriticalSection(&sLock);
    if (sMenuOpen)
    {
        if (sCaptureAction >= 0)
        {
            if (!sCapturePad && vk != VK_ESCAPE)
                gBindings.keys[sCaptureAction][sCaptureSlot] = vk;
            sCaptureAction = -1;
        }
        else
        {
            struct Item *item = sNumItems ? &sItems[sCursor[sPage]] : NULL;

            switch (vk)
            {
            case VK_UP: MoveCursor(-1); break;
            case VK_DOWN: MoveCursor(1); break;
            case VK_LEFT:
                if (item)
                    ChangeValue(item, -1);
                break;
            case VK_RIGHT:
                if (item)
                    ChangeValue(item, 1);
                break;
            case VK_RETURN: Activate(0); break;
            case VK_SPACE:
                Activate(item && (item->kind == ITEM_BIND_KEY || item->kind == ITEM_BIND_PAD) ? 1 : 0);
                break;
            case VK_DELETE:
                if (item && item->kind == ITEM_BIND_KEY)
                    gBindings.keys[item->arg][0] = gBindings.keys[item->arg][1] = 0;
                if (item && item->kind == ITEM_BIND_PAD)
                    gBindings.pad[item->arg][0] = gBindings.pad[item->arg][1] = 0;
                break;
            case VK_ESCAPE:
            case VK_BACK:
                Back();
                break;
            }
        }
        if (sMenuOpen)
            BuildPage();
        sMenuDirty = 1;
    }
    LeaveCriticalSection(&sLock);
}

// The pad drives the menu too: it is read here, on every drawn frame.
static void PollPad(void)
{
    uint32_t held = Input_HeldActions();
    uint32_t pressed = held & ~sPrevPadActions;

    sPrevPadActions = held;

    // While waiting for a button, every button is the answer, even one that
    // already does something.
    if (sCaptureAction >= 0 && sCapturePad)
    {
        int code = Input_CapturePad();

        if (code)
        {
            EnterCriticalSection(&sLock);
            gBindings.pad[sCaptureAction][sCaptureSlot] = code;
            sCaptureAction = -1;
            BuildPage();
            sMenuDirty = 1;
            LeaveCriticalSection(&sLock);
        }
        return;
    }

    if (!pressed)
        return;

    if (!sMenuOpen)
    {
        if (pressed & (1 << ACTION_MENU))
            Ui_OpenMenu();
        return;
    }
    if (pressed & (1 << ACTION_MENU))
    {
        Ui_CloseMenu();
        return;
    }
    if (sCaptureAction >= 0)
        return;
    if (pressed & (1 << ACTION_UP))
        Ui_MenuKey(VK_UP);
    if (pressed & (1 << ACTION_DOWN))
        Ui_MenuKey(VK_DOWN);
    if (pressed & (1 << ACTION_LEFT))
        Ui_MenuKey(VK_LEFT);
    if (pressed & (1 << ACTION_RIGHT))
        Ui_MenuKey(VK_RIGHT);
    if (pressed & (1 << ACTION_A))
        Ui_MenuKey(VK_RETURN);
    if (pressed & (1 << ACTION_B))
        Ui_MenuKey(VK_ESCAPE);
}

// Drawing

static void Fill(int x, int y, int w, int h, uint32_t color)
{
    uint32_t a = color >> 24;
    uint32_t r = ((color >> 16) & 0xFF) * a / 255;
    uint32_t g = ((color >> 8) & 0xFF) * a / 255;
    uint32_t b = (color & 0xFF) * a / 255;
    uint32_t premultiplied = (a << 24) | (r << 16) | (g << 8) | b;
    int i, j;

    if (x < 0)
    {
        w += x;
        x = 0;
    }
    if (y < 0)
    {
        h += y;
        y = 0;
    }
    if (x + w > sWidth)
        w = sWidth - x;
    if (y + h > sHeight)
        h = sHeight - y;
    for (j = 0; j < h; j++)
    {
        uint32_t *row = sPixels + (y + j) * sWidth + x;

        if (a == 255)
        {
            for (i = 0; i < w; i++)
                row[i] = premultiplied;
        }
        else
        {
            for (i = 0; i < w; i++)
            {
                uint32_t d = row[i];
                uint32_t inverse = 255 - a;
                uint32_t da = ((d >> 24) * inverse) / 255 + a;
                uint32_t dr = (((d >> 16) & 0xFF) * inverse) / 255 + r;
                uint32_t dg = (((d >> 8) & 0xFF) * inverse) / 255 + g;
                uint32_t db = ((d & 0xFF) * inverse) / 255 + b;

                row[i] = (da << 24) | (dr << 16) | (dg << 8) | db;
            }
        }
    }
}

// Text on the overlay: size is the height wanted, in window pixels.
static int TextScale(int size)
{
    int scale = (size + 6) / 13;

    return scale < 1 ? 1 : scale;
}

// align: 0 left of x, 1 centred on x, 2 right of x
static int Text(int x, int y, const wchar_t *text, int size, uint32_t color, int bold, int align)
{
    int scale = TextScale(size);
    int width = Art_TextWidth(text) * scale;

    (void)bold;
    if (align == 1)
        x -= width / 2;
    else if (align == 2)
        x -= width;
    Art_Text(sPixels, sWidth, sHeight, x, y, text, color, scale);
    return width;
}

static void Image(int x, int y, const uint32_t *pixels, int w, int h, int stride, int scale)
{
    int i, j, sx, sy;

    for (j = 0; j < h; j++)
    {
        for (i = 0; i < w; i++)
        {
            uint32_t c = pixels[j * stride + i];

            if (!(c >> 24))
                continue;
            for (sy = 0; sy < scale; sy++)
            {
                int py = y + j * scale + sy;

                if (py < 0 || py >= sHeight)
                    continue;
                for (sx = 0; sx < scale; sx++)
                {
                    int px = x + i * scale + sx;

                    if (px >= 0 && px < sWidth)
                        sPixels[py * sWidth + px] = c | 0xFF000000;
                }
            }
        }
    }
}

static void Ring(int cx, int cy, int radius, uint32_t color)
{
    static const signed char sine[32] = {0, 12, 24, 35, 45, 53, 59, 62, 63, 62, 59, 53, 45, 35, 24, 12, 0, -12, -24, -35, -45, -53, -59, -62, -63, -62, -59, -53, -45, -35, -24, -12};
    int i, s;

    for (s = 0; s < 8; s++)
    {
        for (i = 0; i < 32; i++)
        {
            int k = (i * 8 + s) ;
            int a0 = (k / 8) & 31, a1 = (a0 + 1) & 31, f = k & 7;
            int sn = (sine[a0] * (8 - f) + sine[a1] * f) / 8;
            int b0 = (a0 + 8) & 31, b1 = (b0 + 1) & 31;
            int cs = (sine[b0] * (8 - f) + sine[b1] * f) / 8;

            Fill(cx + cs * radius / 63 - 1, cy + sn * radius / 63 - 1, 2, 2, color);
        }
    }
}

#define INK 0xFF181820
#define INK_SOFT 0xFF585860
#define INK_RED 0xFFC02808

#define LIST_LEFT 30
#define LIST_RIGHT 224
#define LIST_TOP 37
#define ROW_HEIGHT 12
#define LIST_ROWS 8
#define HINT_Y 133

static uint32_t sCanvas[MENU_CANVAS_WIDTH * MENU_CANVAS_HEIGHT];

static void CanvasText(int x, int y, const wchar_t *text, uint32_t color)
{
    Art_Text(sCanvas, MENU_CANVAS_WIDTH, MENU_CANVAS_HEIGHT, x, y, text, color, 1);
}

static void CanvasSprite(int x, int y, int sprite, int hFlip)
{
    Art_Sprite(sCanvas, MENU_CANVAS_WIDTH, MENU_CANVAS_HEIGHT, x, y, sprite, hFlip, 1);
}

static void CanvasBar(int x, int y, int w, int h, uint32_t color)
{
    int i, j;

    for (j = y; j < y + h; j++)
        for (i = x; i < x + w; i++)
            sCanvas[j * MENU_CANVAS_WIDTH + i] = color;
}

static void DrawMenuCanvas(void)
{
    int cursor = sCursor[sPage];
    int first, i;
    int showTorchic = sPage == PAGE_MAIN;
    int right = showTorchic ? LIST_RIGHT - 34 : LIST_RIGHT;

    Art_SetLanguage(Hook_Language());
    memcpy(sCanvas, Art_MenuBackground(), sizeof(sCanvas));
    CanvasText(16, 21, PageTitle(), INK);

    first = cursor - LIST_ROWS / 2;
    if (first > sNumItems - LIST_ROWS)
        first = sNumItems - LIST_ROWS;
    if (first < 0)
        first = 0;

    for (i = 0; i < LIST_ROWS && first + i < sNumItems; i++)
    {
        const struct Item *item = &sItems[first + i];
        int y = LIST_TOP + i * ROW_HEIGHT;
        int selected = first + i == cursor;

        if (selected)
        {
            CanvasBar(LIST_LEFT - 3, y + 2, right - LIST_LEFT + 6, ROW_HEIGHT, Art_TabColor());
            CanvasSprite(LIST_LEFT - 19, y, ART_HAND, 0);
        }
        CanvasText(LIST_LEFT, y, item->label, item->kind == ITEM_TEXT && !item->value[0] ? INK_SOFT : INK);

        if (item->kind == ITEM_PAGE)
        {
            CanvasSprite(right - 8, y + 4, ART_ARROW_RIGHT, 0);
        }
        else if (item->value[0])
        {
            int width = Art_TextWidth(item->value);
            int arrows = selected && (item->kind == ITEM_CYCLE || item->kind == ITEM_TOGGLE);
            int x = right - width - (arrows ? 9 : 0);

            CanvasText(x, y, item->value, selected ? INK_RED : INK);
            if (arrows)
            {
                CanvasSprite(x - 9, y + 4, ART_ARROW_RIGHT, 1);
                CanvasSprite(right - 8, y + 4, ART_ARROW_RIGHT, 0);
            }
        }
    }

    // More of the list above or below.
    for (i = 0; i < 3; i++)
    {
        if (first > 0)
            CanvasBar(LIST_RIGHT + 2 - i, 36 + i, 1 + i * 2, 1, INK_SOFT);
        if (first + LIST_ROWS < sNumItems)
            CanvasBar(LIST_RIGHT + 2 - i, 134 - i, 1 + i * 2, 1, INK_SOFT);
    }

    if (sNumItems && sItems[cursor].hint[0])
        CanvasText(LIST_LEFT - 8, HINT_Y, sItems[cursor].hint, INK_SOFT);
    else if (sPageHint[0])
        CanvasText(LIST_LEFT - 8, HINT_Y, sPageHint, INK_SOFT);

    if (showTorchic)
    {
        // Looks around, as on the Options screen.
        static const uint8_t frames[] = {0, 0, 0, 1, 0, 0, 2, 3, 2, 4, 0, 0};
        int frame = frames[(GetTickCount() / 160) % sizeof(frames)];

        CanvasSprite(LIST_RIGHT - 30, 56, ART_TORCHIC_0 + frame, 0);
    }

    if (sCaptureAction >= 0)
    {
        CanvasBar(40, 62, 160, 34, INK);
        CanvasBar(42, 64, 156, 30, Art_TabColor());
        {
            const wchar_t *text = sCapturePad
                ? T(L"Premi un tasto del controller", L"Press a controller button")
                : T(L"Premi un tasto (Esc annulla)", L"Press a key (Esc cancels)");

            CanvasText(120 - Art_TextWidth(text) / 2, 70, text, INK);
        }
    }
}

// The whole screen, like one of the game's: on the same pixels as the game,
// scaled by a whole number.
static void DrawMenu(void)
{
    int scale = sWidth / MENU_CANVAS_WIDTH < sHeight / MENU_CANVAS_HEIGHT ? sWidth / MENU_CANVAS_WIDTH : sHeight / MENU_CANVAS_HEIGHT;
    int left, top, x, y, sy;

    if (scale < 1)
        scale = 1;
    DrawMenuCanvas();

    Fill(0, 0, sWidth, sHeight, 0xC0000000);
    left = (sWidth - MENU_CANVAS_WIDTH * scale) / 2;
    top = (sHeight - MENU_CANVAS_HEIGHT * scale) / 2;
    for (y = 0; y < MENU_CANVAS_HEIGHT; y++)
    {
        for (sy = 0; sy < scale; sy++)
        {
            int py = top + y * scale + sy;

            if (py < 0 || py >= sHeight)
                continue;
            for (x = 0; x < MENU_CANVAS_WIDTH * scale; x++)
            {
                int px = left + x;

                if (px >= 0 && px < sWidth)
                    sPixels[py * sWidth + px] = sCanvas[y * MENU_CANVAS_WIDTH + x / scale];
            }
        }
    }
}

static void FormatScore(wchar_t *out, int size, uint32_t hi, uint32_t lo)
{
    char digits[32];
    int n, i, j = 0;

    if (hi)
        snprintf(digits, sizeof(digits), "%u%08u", (unsigned)hi, (unsigned)lo);
    else
        snprintf(digits, sizeof(digits), "%u", (unsigned)lo);
    n = (int)strlen(digits);
    for (i = 0; i < n && j < size - 2; i++)
    {
        out[j++] = digits[i];
        if ((n - i - 1) % 3 == 0 && i != n - 1)
            out[j++] = L'.';
    }
    out[j] = 0;
}

static const wchar_t *ModeName(const struct FrameInfo *info)
{
    if (info->field >= 2)
        return T(L"Livello bonus", L"Bonus stage");
    switch (info->mode)
    {
    case 0: return T(L"Inizio", L"Start");
    case 2: return T(L"Buca bonus aperta", L"Bonus hole open");
    case 3: return T(L"Buca del boss aperta", L"Boss hole open");
    case 4: return T(L"Cattura", L"Catch");
    case 5: return T(L"Schiusa", L"Hatch");
    case 6: return T(L"Evoluzione", L"Evolution");
    case 7: return T(L"Viaggio", L"Travel");
    case 8: return T(L"Cattura di Jirachi", L"Jirachi catch");
    }
    return T(L"Tavolo", L"Table");
}

static const wchar_t *AreaName(int area)
{
    static const wchar_t *const it[] = {L"Foresta", L"Foresta", L"Pianura", L"Pianura", L"Oceano", L"Oceano", L"Grotta", L"Grotta",
                                        L"Zona Safari", L"Vulcano", L"Lago", L"Terre selvagge", L"Rovine", L"Rovine"};
    static const wchar_t *const en[] = {L"Forest", L"Forest", L"Plains", L"Plains", L"Ocean", L"Ocean", L"Cave", L"Cave",
                                        L"Safari Zone", L"Volcano", L"Lake", L"Wilderness", L"Ruins", L"Ruins"};

    if (area < 0 || area >= 14)
        return L"-";
    return Italian() ? it[area] : en[area];
}

static int sPanelScale;

static void PanelText(int x, int y, const wchar_t *text, uint32_t color)
{
    Art_Text(sPixels, sWidth, sHeight, x * sPanelScale, y * sPanelScale, text, color, sPanelScale);
}

static void PanelLine(int x, int *y, const wchar_t *label, const wchar_t *value)
{
    PanelText(x, *y, label, INK_SOFT);
    PanelText(x + 4, *y + 10, value, INK);
    *y += 24;
}

static void DrawPanels(const struct FrameInfo *info)
{
    int leftWidth = sGameRect.left;
    int rightWidth = sWidth - sGameRect.right;
    int scale = (int)sGameScale;
    int columns, rows, x, y, rightLeft, rightColumns, line;
    wchar_t text[64];

    if (scale > leftWidth / 80)
        scale = leftWidth / 80;
    if (!info->inGame || scale < 1 || rightWidth / scale < 80)
        return;
    sPanelScale = scale;
    columns = leftWidth / scale;
    rows = sHeight / scale;

    // The frame goes round the game, whose rectangle stays clear.
    Art_Frame(sPixels, sWidth, sHeight, 1);
    for (line = sGameRect.top < 0 ? 0 : sGameRect.top; line < sGameRect.bottom && line < sHeight; line++)
        memset(sPixels + line * sWidth + sGameRect.left, 0, (sGameRect.right - sGameRect.left) * 4);

    // Left: the game.
    Art_Panel(sPixels, sWidth, sHeight, 4, 4, columns - 8, rows - 8, scale);
    x = 10;
    y = 6;
    PanelText(x, y, FieldName(info->field), INK_RED);
    y += 16;
    FormatScore(text, 64, info->scoreHi, info->scoreLo);
    PanelLine(x, &y, T(L"Punteggio", L"Score"), text);
    _snwprintf(text, 63, L"%d", info->lives);
    text[63] = 0;
    PanelLine(x, &y, T(L"Palline", L"Balls"), text);
    _snwprintf(text, 63, L"%d", info->coins);
    text[63] = 0;
    PanelLine(x, &y, T(L"Monete", L"Coins"), text);
    PanelLine(x, &y, T(L"Modalità", L"Mode"), ModeName(info));
    if (info->modeTimer)
    {
        _snwprintf(text, 63, L"%d:%02d", info->modeTimer / 3600, (info->modeTimer / 60) % 60);
        text[63] = 0;
        PanelLine(x, &y, T(L"Tempo", L"Time"), text);
    }
    if (info->saverTime)
    {
        _snwprintf(text, 63, L"%d s", info->saverTime / 60);
        text[63] = 0;
        PanelLine(x, &y, L"Ball save", text);
    }

    // Right: Pokédex, the Pokémon on the table, the map.
    rightLeft = sGameRect.right / scale + 1;
    rightColumns = rightWidth / scale;
    Art_Panel(sPixels, sWidth, sHeight, rightLeft + 3, 4, rightColumns - 8, rows - 8, scale);
    x = rightLeft + 9;
    y = 6;
    _snwprintf(text, 63, L"%d", info->pokedexCaught);
    text[63] = 0;
    PanelLine(x, &y, L"Pokédex", text);
    if (info->field < 2)
        PanelLine(x, &y, T(L"Zona", L"Area"), AreaName(info->area));

    if (info->species >= 0)
    {
        static uint32_t portrait[48 * 32];
        int w, h;

        _snwprintf(text, 63, L"%hs", Hook_SpeciesName(info->species, info->language));
        text[63] = 0;
        PanelText(x, y, text, INK_RED);
        y += 12;
        if (info->mode == 6)
        {
            _snwprintf(text, 63, L"» %hs", Hook_SpeciesName(info->evolutionTarget, info->language));
            text[63] = 0;
            PanelText(x, y, text, INK);
            y += 12;
        }
        else if (info->mode == 4 || info->mode == 8)
        {
            _snwprintf(text, 63, T(L"Colpi %d/%d", L"Hits %d/%d"), info->catchProgress, info->catchNeeded);
            text[63] = 0;
            PanelText(x, y, text, INK);
            y += 12;
        }
        if (Hook_Portrait(info->species, portrait, &w, &h))
        {
            Image(x * scale, (y + 3) * scale, portrait, w, h, w, scale);
            y += h + 6;
        }
    }

    {
        int w, h;
        const uint32_t *map = gPcOptions.view == VIEW_TABLE ? NULL : Video_Minimap(&w, &h);

        if (map)
        {
            int available = (rows - 6 - y) * scale;
            int width = (rightColumns - 18) * scale;
            int reduce = 1, drawW, drawH, i, j;
            int left = x * scale, top = y * scale;

            while ((h * scale) / reduce > available || (w * scale) / reduce > width)
                reduce++;
            drawW = (w * scale) / reduce;
            drawH = (h * scale) / reduce;
            for (j = 0; j < drawH; j++)
            {
                for (i = 0; i < drawW; i++)
                {
                    int px = left + i, py = top + j;

                    if (px >= 0 && px < sWidth && py >= 0 && py < sHeight)
                        sPixels[py * sWidth + px] = map[(j * reduce / scale) * w + i * reduce / scale] | 0xFF000000;
                }
            }
        }
    }
}

static void DrawDebug(const struct FrameInfo *info)
{
    int size = sHeight / 42 < 12 ? 12 : sHeight / 42;
    int x = sGameRect.left + size / 2, y = sGameRect.top + size / 2;
    wchar_t line[96];
    int worldX, worldY, i;

    Fill(x - size / 3, y - size / 3, size * 17, size * 12, 0xA0000000);

#define LINE(...) do { _snwprintf(line, 95, __VA_ARGS__); line[95] = 0; Text(x, y, line, size, COLOR_GOOD, 0, 0); y += size * 5 / 4; } while (0)
    LINE(L"frame %u  field %u", (unsigned)info->frameNumber, (unsigned)info->fieldFrames);
    LINE(L"RNG %08X", (unsigned)info->rng);
    if (info->inGame)
    {
        int speed = (int)(sqrt((double)info->ballVelX * info->ballVelX + (double)info->ballVelY * info->ballVelY) + 0.5);

        LINE(L"ball %d, %d  vel %d, %d", info->ballX, info->ballY, info->ballVelX, info->ballVelY);
        LINE(L"speed %d  spin %d  physics %d", speed, info->ballSpin, info->physicsState);
        LINE(L"camera %d, %d", info->cameraX, info->cameraY);
        LINE(L"flippers %d %d", info->flipperAngle[0], info->flipperAngle[1]);
        LINE(L"state %d.%d  timer %u", info->mode, info->boardSubState, info->stageTimer);
        LINE(L"event %u  bonus %u  saver %u", info->modeTimer, info->bonusTimer, info->saverTime);
        LINE(L"catch %d/%d  species %d", info->catchProgress, info->catchNeeded, info->species);
    }
#undef LINE

    if (!info->inGame)
        return;

    Video_WorldOrigin(&worldX, &worldY);

    if (gPcOptions.debugCollision)
    {
        int cols = (int)((sGameRect.right - sGameRect.left) / sGameScale);
        int rows = (int)((sGameRect.bottom - sGameRect.top) / sGameScale);
        int block = (int)(sGameScale + 0.99);
        int cx, cy;

        for (cy = 0; cy < rows; cy++)
        {
            for (cx = 0; cx < cols; cx++)
            {
                int type = Hook_CollisionAt(worldX + cx, worldY + cy);

                if (type)
                    Fill(sGameRect.left + (int)(cx * sGameScale), sGameRect.top + (int)(cy * sGameScale), block, block,
                         (type & 0xF0) ? 0x60FF40FF : 0x6040C0FF);
            }
        }
    }

    for (i = 0; i < info->numHit; i++)
    {
        static const uint32_t colors[] = {0, 0xFFFFFF40, 0xFFFF6040, 0xFF40FF80, 0xFF60C0FF};
        int kind = info->hit[i].kind;

        Ring(sGameRect.left + (int)((info->hit[i].x - worldX) * sGameScale),
             sGameRect.top + (int)((info->hit[i].y - worldY) * sGameScale),
             (int)(info->hit[i].r * sGameScale), colors[kind & 3]);
    }
}

static void DrawToast(void)
{
    int scale = (int)sGameScale;
    int width, x;

    if (scale < 1)
        scale = 1;
    width = Art_TextWidth(sToast) + 16;
    x = (sWidth / scale - width) / 2;
    Art_Panel(sPixels, sWidth, sHeight, x - 2, 6, width + 4, 22, scale);
    Art_Panel(sPixels, sWidth, sHeight, x, 8, width, 18, scale);
    Art_Text(sPixels, sWidth, sHeight, (x + 8) * scale, 8 * scale, sToast, INK, scale);
}

// Test: does every line of every page fit? (PINBALL_UI_CHECK)
static void CheckPages(void)
{
    int page, i;

    for (page = 0; page < PAGE_COUNT; page++)
    {
        sPage = page;
        BuildPage();
        for (i = 0; i < sNumItems; i++)
        {
            const struct Item *item = &sItems[i];
            int right = page == PAGE_MAIN ? LIST_RIGHT - 34 : LIST_RIGHT;
            int width = Art_TextWidth(item->label) + Art_TextWidth(item->value) + 22;

            if (width > right - LIST_LEFT)
                Host_Log("Too wide: page %d, %ls | %ls (%d)\n", page, item->label, item->value, width);
            if (Art_TextWidth(item->hint) > LIST_RIGHT - LIST_LEFT + 8)
                Host_Log("Too wide: page %d hint %ls\n", page, item->hint);
        }
        if (Art_TextWidth(sPageHint) > LIST_RIGHT - LIST_LEFT + 8)
            Host_Log("Too wide: page %d hint %ls\n", page, sPageHint);
    }
    sPage = PAGE_MAIN;
    Host_Log("Pages checked\n");
}

// Runs on the display's thread, once per picture.
void Ui_Tick(void)
{
    DWORD now = GetTickCount();
    const struct FrameInfo *info = Video_LatestInfo();
    int toast = sToast[0] && now < sToastEnd;
    int panels = gPcOptions.panels && info->inGame;
    int debug = gPcOptions.debugOverlay != 0;
    int fps = gPcOptions.showFps != 0;
    int replay = Replay_IsPlaying();
    int visible = sMenuOpen || toast || panels || debug || fps || replay;
    int redraw = sMenuDirty || toast != sToastShown || visible != sWasVisible;

    PollPad();

    if (sCheckFrame && info->frameNumber > 120)
    {
        sCheckFrame = 0;
        EnterCriticalSection(&sLock);
        CheckPages();
        LeaveCriticalSection(&sLock);
    }

    if (sWidth != sWantWidth || sHeight != sWantHeight)
    {
        if (sHeld || sWantWidth <= 0 || sWantHeight <= 0)
            return;
        free(sPixels);
        sWidth = sWantWidth;
        sHeight = sWantHeight;
        sPixels = malloc(sWidth * sHeight * 4);
        redraw = 1;
    }
    if (!sPixels)
        return;

    // The hitboxes have to stay on the things they mark: new frame, new overlay.
    if (debug && info->frameNumber != sLastDebugFrame)
    {
        sLastDebugFrame = info->frameNumber;
        redraw = 1;
    }
    if (panels && now - sLastPanels >= 125)
        redraw = 1;
    if ((fps || replay) && now - sLastFps >= 500)
        redraw = 1;
    if (sMenuOpen && sPage == PAGE_MAIN && now - sLastMenu >= 160)
    {
        sLastMenu = now;
        redraw = 1;
    }
    if (!redraw || sHeld)
        return;

    sLastPanels = sLastFps = now;
    sWasVisible = visible;
    sToastShown = toast;

    memset(sPixels, 0, sWidth * sHeight * 4);
    if (visible)
    {
        Art_SetLanguage(Hook_Language());
        if (panels)
            DrawPanels(info);
        if (debug)
            DrawDebug(info);
        if (fps)
        {
            double display, game;
            wchar_t line[64];

            Video_GetFps(&display, &game);
            _snwprintf(line, 63, L"%.0f fps  (%.1f)  %.1f ms", display, game, Video_Latency());
            line[63] = 0;
            Text(sWidth - 8, 8, line, 18, COLOR_GOOD, 1, 2);
        }
        if (replay)
            Text(sGameRect.left + 8, sGameRect.bottom - 30, L"REPLAY", 26, COLOR_GOOD, 1, 0);
        if (toast)
            DrawToast();
        EnterCriticalSection(&sLock);
        if (sMenuOpen)
            DrawMenu();
        sMenuDirty = 0;
        LeaveCriticalSection(&sLock);
    }
    sMenuDirty = 0;
    sDirty = 1;
}

const uint32_t *Ui_TakeOverlay(int *width, int *height)
{
    if (!sDirty)
        return NULL;
    *width = sWidth;
    *height = sHeight;
    sDirty = 0;
    sHeld = 1;
    return sPixels;
}

void Ui_ReleaseOverlay(void)
{
    sHeld = 0;
}

const uint32_t *Ui_LastOverlay(int *width, int *height)
{
    *width = sWidth;
    *height = sHeight;
    return sPixels;
}

void Ui_Resize(int width, int height)
{
    InterlockedExchange(&sWantWidth, width);
    InterlockedExchange(&sWantHeight, height);
}

void Ui_SetGameRect(const RECT *rect, double scale)
{
    sGameRect = *rect;
    sGameScale = scale;
}

// There is no shrinking the game for the panels: they use the sides that are
// left over. Host_ApplyWindowSize makes the window wide enough for them.
int Ui_PanelSpace(int columns, int lines, int clientWidth, int clientHeight)
{
    (void)columns;
    (void)lines;
    (void)clientWidth;
    (void)clientHeight;
    return 0;
}

void Ui_Init(void)
{
    InitializeCriticalSection(&sLock);
    sCheckFrame = getenv("PINBALL_UI_CHECK") != NULL;
}
