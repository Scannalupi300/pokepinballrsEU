// The settings file, a plain text file next to the program.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pc.h"

struct PcOptions gPcOptions;

struct Entry
{
    const char *name;
    int32_t *value;
};

static const struct Entry sEntries[] = {
    {"view", &gPcOptions.view},
    {"panels", &gPcOptions.panels},
    {"interpolate", &gPcOptions.interpolate},
    {"internal_scale", &gPcOptions.internalScale},
    {"scale_mode", &gPcOptions.scaleMode},
    {"filter", &gPcOptions.filter},
    {"vsync", &gPcOptions.vsync},
    {"show_fps", &gPcOptions.showFps},
    {"debug_collision", &gPcOptions.debugCollision},
    {"low_latency", &gPcOptions.lowLatency},
    {"rumble", &gPcOptions.rumble},
    {"rumble_flippers", &gPcOptions.rumbleFlippers},
    {"pokedex_speed", &gPcOptions.pokedexSpeed},
    {"auto_suspend", &gPcOptions.autoSuspend},
    {"vanilla", &gPcOptions.game.vanilla},
    {"ball_saver", &gPcOptions.game.ballSaver},
    {"infinite_balls", &gPcOptions.game.infiniteBalls},
    {"fixes", &gPcOptions.game.fixes},
    {"online", &gPcOptions.onlineEnabled},
};

#define NUM_ENTRIES (int)(sizeof(sEntries) / sizeof(sEntries[0]))

static const char *const sActionNames[NUM_ACTIONS] = {
    "a", "b", "select", "start", "right", "left", "up", "down", "r", "l",
    "menu", "fast_forward", "quick_save", "quick_load", "debug",
};

static void SetDefaults(void)
{
    memset(&gPcOptions, 0, sizeof(gPcOptions));
    gPcOptions.vsync = 1;
    gPcOptions.lowLatency = 1;
    gPcOptions.rumble = 75;
    gPcOptions.rumbleFlippers = 1;
    gPcOptions.pokedexSpeed = 1;
    gPcOptions.autoSuspend = 1;
    gPcOptions.game.vanilla = 1;
    gPcOptions.game.ballSaver = 1;
    Input_DefaultBindings(&gBindings);
}

void Settings_Load(void)
{
    char path[MAX_PATH];
    char line[256];
    FILE *file;

    SetDefaults();
    Host_UserFile(path, "pokepinballrs_pc.ini");
    file = fopen(path, "r");
    if (!file)
        return;

    while (fgets(line, sizeof(line), file))
    {
        char *equals = strchr(line, '=');
        char *value;
        int i;

        if (!equals || line[0] == '#')
            continue;
        *equals = 0;
        value = equals + 1;

        for (i = 0; i < NUM_ENTRIES; i++)
        {
            if (strcmp(line, sEntries[i].name) == 0)
                *sEntries[i].value = atoi(value);
        }
        for (i = 0; i < NUM_ACTIONS; i++)
        {
            char name[48];
            int a, b;

            snprintf(name, sizeof(name), "key_%s", sActionNames[i]);
            if (strcmp(line, name) == 0 && sscanf(value, "%d,%d", &a, &b) == 2)
            {
                gBindings.keys[i][0] = a;
                gBindings.keys[i][1] = b;
            }
            snprintf(name, sizeof(name), "pad_%s", sActionNames[i]);
            if (strcmp(line, name) == 0 && sscanf(value, "%d,%d", &a, &b) == 2)
            {
                gBindings.pad[i][0] = a;
                gBindings.pad[i][1] = b;
            }
        }
        if (strcmp(line, "online_url") == 0 || strcmp(line, "online_name") == 0)
        {
            char *end = value + strcspn(value, "\r\n");

            *end = 0;
            if (line[7] == 'u')
                Online_SetUrl(value);
            else
                Online_SetName(value);
        }
    }
    fclose(file);
}

void Settings_Save(void)
{
    char path[MAX_PATH];
    FILE *file;
    int i;

    Host_UserFile(path, "pokepinballrs_pc.ini");
    file = fopen(path, "w");
    if (!file)
        return;

    for (i = 0; i < NUM_ENTRIES; i++)
        fprintf(file, "%s=%d\n", sEntries[i].name, (int)*sEntries[i].value);
    for (i = 0; i < NUM_ACTIONS; i++)
    {
        fprintf(file, "key_%s=%d,%d\n", sActionNames[i], gBindings.keys[i][0], gBindings.keys[i][1]);
        fprintf(file, "pad_%s=%d,%d\n", sActionNames[i], gBindings.pad[i][0], gBindings.pad[i][1]);
    }
    fprintf(file, "online_url=%s\n", Online_Url());
    fprintf(file, "online_name=%s\n", Online_Name());
    fclose(file);
}
