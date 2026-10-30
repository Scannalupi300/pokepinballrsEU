// A whole game in one block: all the GBA memory, plus what the native build
// keeps outside it. Taken at the top of the main loop, where the game has
// nothing on the stack, so this is all there is.
//
// The memory holds pointers into the program, so a saved state only loads in
// the same build: the header has a hash of the program's code.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pc.h"

#define STATE_MAGIC 0x54535050  // "PPST"
#define STATE_VERSION 1

void *Hook_StateData(int *size) HOST_SYM(Hook_StateData);

struct Region
{
    uint32_t address;
    uint32_t size;
};

static const struct Region sRegions[] = {
    {GBA_EWRAM, GBA_EWRAM_SIZE},
    {GBA_IWRAM, GBA_IWRAM_SIZE},
    {GBA_IO, GBA_IO_SIZE},
    {GBA_PLTT, GBA_PLTT_SIZE},
    {GBA_VRAM, GBA_VRAM_SIZE},
    {GBA_OAM, GBA_OAM_SIZE},
};

#define NUM_REGIONS (sizeof(sRegions) / sizeof(sRegions[0]))

// Pointers of the save data, kept when a state is loaded: the player's Pokédex
// and scores must not go back with it.
#define SAVE_DATA_OFFSET 0x74
#define SAVE_DATA_SIZE 0x274

extern uint8_t gMain[] HOST_SYM(gMain);

static int HostBlocks(void *blocks[3], int sizes[3])
{
    blocks[0] = Audio_StateData(&sizes[0]);
    blocks[1] = Bios_StateData(&sizes[1]);
    blocks[2] = Hook_StateData(&sizes[2]);
    return 3;
}

int State_Size(void)
{
    void *blocks[3];
    int sizes[3];
    int i, total = 0;

    HostBlocks(blocks, sizes);
    for (i = 0; i < (int)NUM_REGIONS; i++)
        total += sRegions[i].size;
    return total + sizes[0] + sizes[1] + sizes[2];
}

int State_Copy(void *dest)
{
    uint8_t *out = dest;
    void *blocks[3];
    int sizes[3];
    int i;

    HostBlocks(blocks, sizes);
    for (i = 0; i < (int)NUM_REGIONS; i++)
    {
        memcpy(out, (const void *)sRegions[i].address, sRegions[i].size);
        out += sRegions[i].size;
    }
    for (i = 0; i < 3; i++)
    {
        memcpy(out, blocks[i], sizes[i]);
        out += sizes[i];
    }
    return (int)(out - (uint8_t *)dest);
}

void State_Paste(const void *src)
{
    const uint8_t *in = src;
    void *blocks[3];
    int sizes[3];
    int i;

    HostBlocks(blocks, sizes);
    for (i = 0; i < (int)NUM_REGIONS; i++)
    {
        memcpy((void *)sRegions[i].address, in, sRegions[i].size);
        in += sRegions[i].size;
    }
    for (i = 0; i < 3; i++)
    {
        memcpy(blocks[i], in, sizes[i]);
        in += sizes[i];
    }
}

uint32_t State_Hash(const void *data, size_t size)
{
    const uint8_t *p = data;
    uint32_t hash = 2166136261u;
    size_t i;

    for (i = 0; i < size; i++)
        hash = (hash ^ p[i]) * 16777619u;
    return hash;
}

static uint32_t BuildHash(void)
{
    static uint32_t hash;

    if (!hash)
    {
        HMODULE module = GetModuleHandleA(NULL);
        const IMAGE_DOS_HEADER *dos = (const IMAGE_DOS_HEADER *)module;
        const IMAGE_NT_HEADERS *nt = (const IMAGE_NT_HEADERS *)((const uint8_t *)module + dos->e_lfanew);
        const IMAGE_SECTION_HEADER *section = IMAGE_FIRST_SECTION(nt);
        int i;

        hash = 1;
        for (i = 0; i < nt->FileHeader.NumberOfSections; i++)
        {
            if (section[i].Characteristics & IMAGE_SCN_CNT_CODE)
                hash ^= State_Hash((const uint8_t *)module + section[i].VirtualAddress, section[i].Misc.VirtualSize);
        }
    }
    return hash;
}

static void SlotPath(char *path, int slot)
{
    char name[64];

    snprintf(name, sizeof(name), "states\\slot%d.state", slot);
    Host_UserFile(path, name);
}

int State_Exists(int slot)
{
    char path[MAX_PATH];

    SlotPath(path, slot);
    return GetFileAttributesA(path) != INVALID_FILE_ATTRIBUTES;
}

void State_Delete(int slot)
{
    char path[MAX_PATH];

    SlotPath(path, slot);
    DeleteFileA(path);
}

int State_Save(int slot)
{
    char path[MAX_PATH];
    uint32_t header[4];
    uint8_t *data;
    FILE *file;
    int size = State_Size();

    data = malloc(size);
    if (!data)
        return 0;
    State_Copy(data);

    SlotPath(path, slot);
    {
        char dir[MAX_PATH];

        Host_UserFile(dir, "states");
        CreateDirectoryA(dir, NULL);
    }
    file = fopen(path, "wb");
    if (!file)
    {
        free(data);
        return 0;
    }
    header[0] = STATE_MAGIC;
    header[1] = STATE_VERSION;
    header[2] = BuildHash();
    header[3] = size;
    fwrite(header, sizeof(header), 1, file);
    fwrite(data, size, 1, file);
    fclose(file);
    free(data);
    return 1;
}

int State_Load(int slot)
{
    char path[MAX_PATH];
    uint32_t header[4];
    uint8_t *data;
    uint8_t saveData[SAVE_DATA_SIZE];
    FILE *file;
    int size = State_Size();

    SlotPath(path, slot);
    file = fopen(path, "rb");
    if (!file)
        return 0;
    if (fread(header, sizeof(header), 1, file) != 1 || header[0] != STATE_MAGIC || header[1] != STATE_VERSION
        || header[3] != (uint32_t)size)
    {
        fclose(file);
        Host_Toast("state_bad");
        return 0;
    }
    if (header[2] != BuildHash())
    {
        fclose(file);
        Host_Toast("state_old");
        return 0;
    }

    data = malloc(size);
    if (!data || fread(data, size, 1, file) != 1)
    {
        free(data);
        fclose(file);
        return 0;
    }
    fclose(file);

    // The game goes back; the Pokédex and the high scores don't.
    memcpy(saveData, gMain + SAVE_DATA_OFFSET, SAVE_DATA_SIZE);
    State_Paste(data);
    memcpy(gMain + SAVE_DATA_OFFSET, saveData, SAVE_DATA_SIZE);
    free(data);
    if (slot == STATE_SLOT_AUTO)
        State_Delete(STATE_SLOT_AUTO);
    return 1;
}
