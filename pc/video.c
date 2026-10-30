// The display: takes the frames the game publishes, draws them with the
// renderer in pc/ppu.c and shows them with Direct3D 11. It has its own thread,
// so it can show more frames than the game makes: between two game frames it
// draws the ball and the camera at positions in between (the game itself stays
// at 60 Hz).
//
// Above the game goes one overlay: a picture of the window's size, drawn by
// pc/ui.c, with the menu, the side panels, the debug text and the messages.
//
// If Direct3D 11 isn't there at all, the same picture is drawn with GDI, without
// the filters.

#define COBJMACROS
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <initguid.h>
#include <d3d11.h>
#include <dxgi1_5.h>
#include <d3dcompiler.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "host.h"
#include "pc.h"

#define NUM_SLOTS 5
#define NUM_WORKERS 4
#define MAX_SCALE 4
#define MAX_GAME_WIDTH (TABLE_WIDTH * MAX_SCALE)
#define MAX_GAME_HEIGHT (TABLE_MAX_HEIGHT * MAX_SCALE)

static struct FrameSet *sSlots[NUM_SLOTS];
static CRITICAL_SECTION sSlotLock;
static int sSlotHeld[2] = {-1, -1};   // being drawn
static int sLatest = -1, sPrevious = -1;
static int sWriting = -1;
static LONG sPublishCount;
static LARGE_INTEGER sLatestTime;
static LARGE_INTEGER sTimerFrequency;
static HANDLE sFrameEvent;
static HANDLE sDrawnEvent;
static volatile LONG sDrawnCount;
static volatile LONG sQuit;
static HANDLE sThread;

static HWND sWindow;
static volatile LONG sClientWidth, sClientHeight;

// The game image
static uint32_t *sGamePixels;
static int sGameWidth, sGameHeight;   // output pixels
static int sGameScale;
static int sGameColumns, sGameLines;  // GBA pixels
static int sLastDrawnPublish = -1;
static int sLastShownPublish = -1;
static int sLastDrawnAlpha = -1;
static int sLastDrawnView = -1;

// Test mode
static char sDumpPath[MAX_PATH];
static volatile LONG sDumpRequested;
static volatile LONG sForcedAlpha = -1;
static volatile LONG sSyncMode;

// Direct3D
static ID3D11Device *sDevice;
static ID3D11DeviceContext *sContext;
static IDXGISwapChain1 *sSwapChain;
static ID3D11RenderTargetView *sTarget;
static ID3D11Texture2D *sBackBuffer;
static ID3D11Texture2D *sGameTexture;
static ID3D11ShaderResourceView *sGameView;
static int sTextureWidth, sTextureHeight;
static ID3D11Texture2D *sOverlayTexture;
static ID3D11ShaderResourceView *sOverlayView;
static int sOverlayWidth, sOverlayHeight;
static ID3D11VertexShader *sVertexShader;
static ID3D11PixelShader *sPixelShaders[FILTER_COUNT + 2];
static ID3D11Buffer *sConstants;
static ID3D11SamplerState *sPointSampler, *sLinearSampler;
static ID3D11BlendState *sOverlayBlend;
static ID3D11RasterizerState *sRasterizer;
static HANDLE sLatencyWaitable;
static int sAllowTearing;
static int sUseD3D;
static int sBackWidth, sBackHeight;
static double sRefreshRate = 60;
static int sFlipModel;

// The table, small, for the side panel
static uint32_t *sMinimap;
static int sMinimapWidth, sMinimapHeight;
static int sWorldX, sWorldY;

// From reading the keys to showing the frame they made
static LARGE_INTEGER sLatestInputTime;
static double sLatencySum, sLatencyAverage;
static int sLatencyCount;
static double sLatencyTotal;
static unsigned sLatencyTotalCount;
static unsigned sFramesShown;

static LONG sFpsFrames;
static LONG sFpsGameFrames;
static double sFps, sGameFps;
static LARGE_INTEGER sFpsTime;

// Workers for the renderer
struct Worker
{
    HANDLE start, done;
    const struct PpuState *state;
    int first, last;
};

static struct Worker sWorkers[NUM_WORKERS];
static int sNumWorkers;

struct Constants
{
    float destOrigin[2];   // pixels
    float destSize[2];     // pixels
    float targetSize[2];
    float gameSize[2];     // GBA pixels
    float uvMax[2];
    float time;
    float pad;
};

// The pixel shaders work in GBA pixels, so a filter looks the same at any
// internal scale. PS_Nearest needs nothing more: the sampler picks the pixel.
static const char sShaderSource[] =
"cbuffer C : register(b0) {\n"
"  float2 destOrigin, destSize, targetSize, gameSize, uvMax; float time, pad;\n"
"};\n"
"Texture2D game : register(t0);\n"
"SamplerState pointS : register(s0);\n"
"SamplerState linearS : register(s1);\n"
"struct V { float4 pos : SV_Position; float2 uv : TEXCOORD0; };\n"
"V VS(uint id : SV_VertexID) {\n"
"  V o; float2 c = float2(id & 1, (id >> 1) & 1);\n"
"  float2 p = destOrigin + c * destSize;\n"
"  o.pos = float4(p.x / targetSize.x * 2 - 1, 1 - p.y / targetSize.y * 2, 0, 1);\n"
"  o.uv = c; return o;\n"
"}\n"
"float4 PS_Nearest(V i) : SV_Target { return game.Sample(pointS, i.uv * uvMax); }\n"
// Keeps the pixels square at any size: bilinear only across the edge of a pixel.
"float4 PS_Sharp(V i) : SV_Target {\n"
"  float2 size = gameSize; float2 t = i.uv * size; float2 base = floor(t);\n"
"  float2 w = fwidth(t); float2 f = saturate((t - base - 0.5) / max(w, 1e-5) + 0.5);\n"
"  return game.Sample(linearS, (base + f) / size * uvMax);\n"
"}\n"
// The GBA screen: a grid around each pixel, the three colour stripes in it,
// and the screen's own washed-out colours.
"float4 PS_Lcd(V i) : SV_Target {\n"
"  float2 t = i.uv * gameSize; float2 f = frac(t);\n"
"  float3 c = game.Sample(pointS, i.uv * uvMax).rgb;\n"
"  c = pow(c, 1.15); c = float3(dot(c, float3(.86,.10,.04)), dot(c, float3(.03,.84,.13)), dot(c, float3(.04,.11,.85)));\n"
"  float scale = destSize.y / gameSize.y; float g = saturate(scale / 4);\n"
"  float2 e = abs(f - 0.5) * 2; float2 grid = 1 - g * 0.28 * pow(e, 6);\n"
"  float3 stripes = 1 + g * 0.16 * cos(6.2832 * (f.x - float3(1,3,5) / 6));\n"
"  return float4(c * grid.x * grid.y * stripes + 0.012, 1);\n"
"}\n"
// A TV: curved glass, scanlines that get thinner in the dark, an aperture
// grille and darker corners.
"float4 PS_Crt(V i) : SV_Target {\n"
"  float2 p = i.uv * 2 - 1; p *= 1 + 0.035 * dot(p, p).xx * float2(0.8, 1.2);\n"
"  float2 uv = p * 0.5 + 0.5;\n"
"  if (any(uv < 0) || any(uv > 1)) return float4(0, 0, 0, 1);\n"
"  float2 t = uv * gameSize; float2 cell = floor(t) + 0.5;\n"
"  float dy = t.y - cell.y;\n"
"  float3 sum = 0, weight = 0;\n"
"  for (int k = -1; k <= 1; k++) {\n"
"    float3 c = pow(game.SampleLevel(linearS, float2(t.x, cell.y + k) / gameSize * uvMax, 0).rgb, 2.4);\n"
"    float d = dy - k; float3 sigma = 0.30 + 0.20 * sqrt(c);\n"
"    float3 b = exp(-d * d / (2 * sigma * sigma)) / sigma;\n"
"    sum += c * b; weight += b;\n"
"  }\n"
"  float3 c = sum / max(weight * 0.62, 1e-4);\n"
"  float m = fmod(floor(i.pos.x), 3);\n"
"  float3 mask = m < 1 ? float3(1.15,.82,.82) : m < 2 ? float3(.82,1.15,.82) : float3(.82,.82,1.15);\n"
"  float scale = destSize.y / gameSize.y; c *= lerp(1, mask, saturate((scale - 1.5) / 2));\n"
"  float v = 1 - 0.28 * dot(p * p, p * p);\n"
"  return float4(pow(saturate(c * v), 1 / 2.2), 1);\n"
"}\n"
"float4 PS_Overlay(V i) : SV_Target { return game.Sample(pointS, i.uv); }\n";

typedef HRESULT(WINAPI *D3DCompileFunc)(LPCVOID, SIZE_T, LPCSTR, const D3D_SHADER_MACRO *, ID3DInclude *, LPCSTR, LPCSTR, UINT, UINT, ID3DBlob **, ID3DBlob **);
static D3DCompileFunc sD3DCompile;

static ID3DBlob *CompileShader(const char *entry, const char *profile)
{
    ID3DBlob *code = NULL, *errors = NULL;

    if (FAILED(sD3DCompile(sShaderSource, sizeof(sShaderSource) - 1, "pinball", NULL, NULL, entry, profile, 0, 0, &code, &errors)))
    {
        Host_Log("Shader %s: %s\n", entry, errors ? (const char *)ID3D10Blob_GetBufferPointer(errors) : "?");
        if (errors)
            ID3D10Blob_Release(errors);
        return NULL;
    }
    return code;
}

static int CreateShaders(void)
{
    static const char *const entries[] = {"PS_Nearest", "PS_Lcd", "PS_Crt", "PS_Sharp", "PS_Overlay"};
    HMODULE module = LoadLibraryA("d3dcompiler_47.dll");
    D3D11_BUFFER_DESC buffer;
    D3D11_SAMPLER_DESC sampler;
    D3D11_BLEND_DESC blend;
    D3D11_RASTERIZER_DESC raster;
    ID3DBlob *code;
    unsigned i;

    if (!module)
        module = LoadLibraryA("d3dcompiler_43.dll");
    if (!module)
        return 0;
    sD3DCompile = (D3DCompileFunc)(void *)GetProcAddress(module, "D3DCompile");
    if (!sD3DCompile)
        return 0;

    code = CompileShader("VS", "vs_4_0");
    if (!code)
        return 0;
    ID3D11Device_CreateVertexShader(sDevice, ID3D10Blob_GetBufferPointer(code), ID3D10Blob_GetBufferSize(code), NULL, &sVertexShader);
    ID3D10Blob_Release(code);

    for (i = 0; i < sizeof(entries) / sizeof(entries[0]); i++)
    {
        code = CompileShader(entries[i], "ps_4_0");
        if (!code)
            return 0;
        ID3D11Device_CreatePixelShader(sDevice, ID3D10Blob_GetBufferPointer(code), ID3D10Blob_GetBufferSize(code), NULL, &sPixelShaders[i]);
        ID3D10Blob_Release(code);
    }

    memset(&buffer, 0, sizeof(buffer));
    buffer.ByteWidth = sizeof(struct Constants);
    buffer.Usage = D3D11_USAGE_DYNAMIC;
    buffer.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
    buffer.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
    ID3D11Device_CreateBuffer(sDevice, &buffer, NULL, &sConstants);

    memset(&sampler, 0, sizeof(sampler));
    sampler.AddressU = sampler.AddressV = sampler.AddressW = D3D11_TEXTURE_ADDRESS_CLAMP;
    sampler.MaxLOD = D3D11_FLOAT32_MAX;
    sampler.Filter = D3D11_FILTER_MIN_MAG_MIP_POINT;
    ID3D11Device_CreateSamplerState(sDevice, &sampler, &sPointSampler);
    sampler.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
    ID3D11Device_CreateSamplerState(sDevice, &sampler, &sLinearSampler);

    memset(&blend, 0, sizeof(blend));
    blend.RenderTarget[0].BlendEnable = TRUE;
    blend.RenderTarget[0].SrcBlend = D3D11_BLEND_ONE;
    blend.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
    blend.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;
    blend.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ONE;
    blend.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_INV_SRC_ALPHA;
    blend.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;
    blend.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;
    ID3D11Device_CreateBlendState(sDevice, &blend, &sOverlayBlend);

    memset(&raster, 0, sizeof(raster));
    raster.FillMode = D3D11_FILL_SOLID;
    raster.CullMode = D3D11_CULL_NONE;
    ID3D11Device_CreateRasterizerState(sDevice, &raster, &sRasterizer);
    return 1;
}

static void ReleaseTarget(void)
{
    if (sTarget)
    {
        ID3D11RenderTargetView_Release(sTarget);
        sTarget = NULL;
    }
    if (sBackBuffer)
    {
        ID3D11Texture2D_Release(sBackBuffer);
        sBackBuffer = NULL;
    }
}

static int CreateTarget(void)
{
    if (FAILED(IDXGISwapChain1_GetBuffer(sSwapChain, 0, &IID_ID3D11Texture2D, (void **)&sBackBuffer)))
        return 0;
    if (FAILED(ID3D11Device_CreateRenderTargetView(sDevice, (ID3D11Resource *)sBackBuffer, NULL, &sTarget)))
        return 0;
    return 1;
}

static int CreateSwapChain(void)
{
    IDXGIDevice *dxgiDevice = NULL;
    IDXGIAdapter *adapter = NULL;
    IDXGIFactory2 *factory = NULL;
    IDXGIFactory5 *factory5 = NULL;
    DXGI_SWAP_CHAIN_DESC1 desc;
    IDXGISwapChain2 *chain2 = NULL;
    HRESULT hr;
    BOOL tearing = FALSE;

    ID3D11Device_QueryInterface(sDevice, &IID_IDXGIDevice, (void **)&dxgiDevice);
    IDXGIDevice_GetAdapter(dxgiDevice, &adapter);
    IDXGIAdapter_GetParent(adapter, &IID_IDXGIFactory2, (void **)&factory);
    if (!factory)
    {
        IDXGIAdapter_Release(adapter);
        IDXGIDevice_Release(dxgiDevice);
        return 0;
    }

    if (SUCCEEDED(IDXGIFactory2_QueryInterface(factory, &IID_IDXGIFactory5, (void **)&factory5)))
    {
        if (FAILED(IDXGIFactory5_CheckFeatureSupport(factory5, DXGI_FEATURE_PRESENT_ALLOW_TEARING, &tearing, sizeof(tearing))))
            tearing = FALSE;
        IDXGIFactory5_Release(factory5);
    }
    sAllowTearing = tearing;

    memset(&desc, 0, sizeof(desc));
    desc.Width = sClientWidth;
    desc.Height = sClientHeight;
    desc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
    desc.SampleDesc.Count = 1;
    desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    desc.BufferCount = 2;
    desc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
    desc.Flags = DXGI_SWAP_CHAIN_FLAG_FRAME_LATENCY_WAITABLE_OBJECT | (tearing ? DXGI_SWAP_CHAIN_FLAG_ALLOW_TEARING : 0);
    hr = IDXGIFactory2_CreateSwapChainForHwnd(factory, (IUnknown *)sDevice, sWindow, &desc, NULL, NULL, &sSwapChain);
    sFlipModel = SUCCEEDED(hr);
    if (FAILED(hr))
    {
        // Windows 7: the old presentation model.
        desc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
        desc.BufferCount = 1;
        desc.Flags = 0;
        sAllowTearing = 0;
        hr = IDXGIFactory2_CreateSwapChainForHwnd(factory, (IUnknown *)sDevice, sWindow, &desc, NULL, NULL, &sSwapChain);
    }
    if (SUCCEEDED(hr))
        IDXGIFactory2_MakeWindowAssociation(factory, sWindow, DXGI_MWA_NO_ALT_ENTER);

    IDXGIFactory2_Release(factory);
    IDXGIAdapter_Release(adapter);
    IDXGIDevice_Release(dxgiDevice);
    if (FAILED(hr))
        return 0;

    if (sFlipModel && SUCCEEDED(IDXGISwapChain1_QueryInterface(sSwapChain, &IID_IDXGISwapChain2, (void **)&chain2)))
    {
        IDXGISwapChain2_SetMaximumFrameLatency(chain2, 1);
        sLatencyWaitable = IDXGISwapChain2_GetFrameLatencyWaitableObject(chain2);
        IDXGISwapChain2_Release(chain2);
    }

    sBackWidth = sClientWidth;
    sBackHeight = sClientHeight;
    return CreateTarget();
}

static int CreateDevice(void)
{
    static const D3D_FEATURE_LEVEL levels[] = {D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_1, D3D_FEATURE_LEVEL_10_0};
    D3D_DRIVER_TYPE types[2] = {D3D_DRIVER_TYPE_HARDWARE, D3D_DRIVER_TYPE_WARP};
    HRESULT(WINAPI *create)(IDXGIAdapter *, D3D_DRIVER_TYPE, HMODULE, UINT, const D3D_FEATURE_LEVEL *, UINT, UINT, ID3D11Device **, D3D_FEATURE_LEVEL *, ID3D11DeviceContext **);
    HMODULE module = LoadLibraryA("d3d11.dll");
    int i;

    if (!module)
        return 0;
    *(FARPROC *)&create = GetProcAddress(module, "D3D11CreateDevice");
    if (!create)
        return 0;

    for (i = getenv("PINBALL_WARP") ? 1 : 0; i < 2; i++)
    {
        if (SUCCEEDED(create(NULL, types[i], NULL, D3D11_CREATE_DEVICE_BGRA_SUPPORT, levels, 3, D3D11_SDK_VERSION, &sDevice, NULL, &sContext)))
            break;
    }
    if (!sDevice)
        return 0;
    return CreateShaders() && CreateSwapChain();
}

static void ReadRefreshRate(void)
{
    MONITORINFOEXA info;
    DEVMODEA mode;

    memset(&info, 0, sizeof(info));
    info.cbSize = sizeof(info);
    memset(&mode, 0, sizeof(mode));
    mode.dmSize = sizeof(mode);
    if (GetMonitorInfoA(MonitorFromWindow(sWindow, MONITOR_DEFAULTTOPRIMARY), (MONITORINFO *)&info)
        && EnumDisplaySettingsA(info.szDevice, ENUM_CURRENT_SETTINGS, &mode) && mode.dmDisplayFrequency > 1)
        sRefreshRate = mode.dmDisplayFrequency;
    if (getenv("PINBALL_REFRESH"))
        sRefreshRate = atof(getenv("PINBALL_REFRESH"));
}

// The rectangle of the game in the window, and how many output pixels make a
// GBA pixel.
void Video_GameRect(int clientWidth, int clientHeight, int columns, int lines, int panelSpace, int integerScale, RECT *rect, double *scale)
{
    int availableWidth = clientWidth - panelSpace * 2;
    double sx = (double)availableWidth / columns;
    double sy = (double)clientHeight / lines;
    double s = sx < sy ? sx : sy;
    int w, h;

    if (integerScale && s >= 1)
        s = (int)s;
    if (s <= 0)
        s = 1;
    w = (int)(columns * s + 0.5);
    h = (int)(lines * s + 0.5);
    rect->left = (clientWidth - w) / 2;
    rect->top = (clientHeight - h) / 2;
    rect->right = rect->left + w;
    rect->bottom = rect->top + h;
    *scale = s;
}

static DWORD WINAPI WorkerThread(LPVOID param)
{
    struct Worker *worker = param;

    for (;;)
    {
        WaitForSingleObject(worker->start, INFINITE);
        Ppu_RenderBand(worker->state, worker->first, worker->last);
        SetEvent(worker->done);
    }
    return 0;
}

static void StartWorkers(void)
{
    SYSTEM_INFO info;
    int i;

    GetSystemInfo(&info);
    sNumWorkers = (int)info.dwNumberOfProcessors - 2;
    if (sNumWorkers > NUM_WORKERS)
        sNumWorkers = NUM_WORKERS;
    if (sNumWorkers < 1)
        sNumWorkers = 0;
    for (i = 0; i < sNumWorkers; i++)
    {
        sWorkers[i].start = CreateEventA(NULL, FALSE, FALSE, NULL);
        sWorkers[i].done = CreateEventA(NULL, FALSE, FALSE, NULL);
        CreateThread(NULL, 1 << 20, WorkerThread, &sWorkers[i], 0, NULL);
    }
}

// Draws args in as many bands as there are workers.
static void RenderParallel(const struct PpuRenderArgs *args)
{
    static struct PpuState *state;
    int outLines = (args->lastLine - args->firstLine) * args->scale;
    int parts = sNumWorkers + 1;
    HANDLE done[NUM_WORKERS];
    int i;

    if (!state)
        state = malloc(Ppu_StateSize());
    Ppu_Prepare(state, args);

    if (outLines < 64 || sNumWorkers == 0)
    {
        Ppu_RenderBand(state, 0, outLines);
        return;
    }

    for (i = 0; i < sNumWorkers; i++)
    {
        sWorkers[i].state = state;
        sWorkers[i].first = outLines * (i + 1) / parts;
        sWorkers[i].last = outLines * (i + 2) / parts;
        done[i] = sWorkers[i].done;
        SetEvent(sWorkers[i].start);
    }
    Ppu_RenderBand(state, 0, outLines / parts);
    WaitForMultipleObjects(sNumWorkers, done, TRUE, INFINITE);
}

static int ChooseScale(int columns, int lines)
{
    RECT rect;
    double scale;
    int s;

    if (gPcOptions.internalScale > 0)
        return gPcOptions.internalScale;
    if (!gPcOptions.interpolate)
        return 1;
    Video_GameRect(sClientWidth, sClientHeight, columns, lines, 0, gPcOptions.scaleMode == SCALE_INTEGER, &rect, &scale);
    s = (int)scale;
    return s < 1 ? 1 : s > MAX_SCALE ? MAX_SCALE : s;
}

// Draws the frame into sGamePixels.
static void RenderGame(const struct FrameSet *frame, const struct FrameSet *prev, int alpha)
{
    struct PpuRenderArgs args;
    int table = gPcOptions.view == VIEW_TABLE && frame->numStrips > 0;
    int scale, i;

    sGameColumns = table ? frame->tableWidth : PPU_WIDTH;
    sGameLines = table ? frame->tableHeight : PPU_HEIGHT;
    scale = ChooseScale(sGameColumns, sGameLines);
    sGameScale = scale;
    sGameWidth = sGameColumns * scale;
    sGameHeight = sGameLines * scale;

    memset(&args, 0, sizeof(args));
    args.scale = scale;
    args.stride = MAX_GAME_WIDTH;
    args.layerMask = 0x1F;
    args.alpha = alpha;

    if (!table)
    {
        args.frame = &frame->main;
        args.prev = prev ? &prev->main : NULL;
        args.out = sGamePixels;
        args.firstLine = 0;
        args.lastLine = PPU_HEIGHT;
        args.width = PPU_WIDTH;
        RenderParallel(&args);
        return;
    }

    // The table: each strip is the game drawn with the camera somewhere else.
    // Status bar, banners and the other things tied to the screen stay out of
    // these and go on top, from the frame the player's camera really sees.
    args.width = frame->tableWidth;
    args.outLeft = -frame->tableLeft;
    args.layerMask = 0x1E;
    for (i = 0; i < frame->numStrips; i++)
    {
        int top = frame->stripY[i];
        int count = i + 1 < frame->numStrips ? frame->stripY[i + 1] - top : frame->tableHeight - top;

        if (count > PPU_HEIGHT)
            count = PPU_HEIGHT;
        args.frame = &frame->strip[i];
        args.prev = prev && prev->numStrips == frame->numStrips ? &prev->strip[i] : NULL;
        args.out = sGamePixels + top * scale * MAX_GAME_WIDTH;
        args.firstLine = 0;
        args.lastLine = count;
        args.spriteMask = frame->screenSprites;
        args.spriteMaskInvert = 1;
        RenderParallel(&args);
    }

    // Everything of the real frame that isn't table, above the part it shows.
    args.frame = &frame->main;
    args.prev = NULL;
    args.width = PPU_WIDTH;
    args.outLeft = 0;
    args.layerMask = 0x11;
    args.spriteMask = frame->screenSprites;
    args.spriteMaskInvert = 0;
    args.transparent = 1;
    args.firstLine = 0;
    args.lastLine = STRIP_LINES;
    {
        int y = frame->mainY;

        if (y < 0)
            y = 0;
        if (y + STRIP_LINES > frame->tableHeight - (PPU_HEIGHT - STRIP_LINES))
            y = frame->tableHeight - PPU_HEIGHT;
        args.out = sGamePixels + y * scale * MAX_GAME_WIDTH + (frame->mainX > 0 ? frame->mainX : 0) * scale;
        RenderParallel(&args);
    }

    // The status bar stays at the bottom of the table.
    args.firstLine = STRIP_LINES;
    args.lastLine = PPU_HEIGHT;
    args.out = sGamePixels + (frame->tableHeight - (PPU_HEIGHT - STRIP_LINES)) * scale * MAX_GAME_WIDTH + (frame->tableWidth - PPU_WIDTH) * scale / 2;
    RenderParallel(&args);
}

static void EnsureGameTexture(void)
{
    D3D11_TEXTURE2D_DESC desc;
    D3D11_SHADER_RESOURCE_VIEW_DESC view;

    if (sGameTexture && sTextureWidth >= sGameWidth && sTextureHeight >= sGameHeight)
        return;
    if (sGameView)
        ID3D11ShaderResourceView_Release(sGameView);
    if (sGameTexture)
        ID3D11Texture2D_Release(sGameTexture);

    sTextureWidth = sGameWidth > sTextureWidth ? sGameWidth : sTextureWidth;
    sTextureHeight = sGameHeight > sTextureHeight ? sGameHeight : sTextureHeight;
    memset(&desc, 0, sizeof(desc));
    desc.Width = sTextureWidth;
    desc.Height = sTextureHeight;
    desc.MipLevels = 1;
    desc.ArraySize = 1;
    desc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
    desc.SampleDesc.Count = 1;
    desc.Usage = D3D11_USAGE_DYNAMIC;
    desc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
    desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
    ID3D11Device_CreateTexture2D(sDevice, &desc, NULL, &sGameTexture);
    memset(&view, 0, sizeof(view));
    view.Format = desc.Format;
    view.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
    view.Texture2D.MipLevels = 1;
    ID3D11Device_CreateShaderResourceView(sDevice, (ID3D11Resource *)sGameTexture, &view, &sGameView);
}

static void UploadGameTexture(void)
{
    D3D11_MAPPED_SUBRESOURCE mapped;
    int y;

    EnsureGameTexture();
    if (FAILED(ID3D11DeviceContext_Map(sContext, (ID3D11Resource *)sGameTexture, 0, D3D11_MAP_WRITE_DISCARD, 0, &mapped)))
        return;
    for (y = 0; y < sGameHeight; y++)
        memcpy((uint8_t *)mapped.pData + y * mapped.RowPitch, sGamePixels + y * MAX_GAME_WIDTH, sGameWidth * 4);
    ID3D11DeviceContext_Unmap(sContext, (ID3D11Resource *)sGameTexture, 0);
}

static void UploadOverlay(void)
{
    D3D11_MAPPED_SUBRESOURCE mapped;
    const uint32_t *pixels;
    int width, height, y;

    pixels = Ui_TakeOverlay(&width, &height);
    if (!pixels)
        return;

    if (!sOverlayTexture || sOverlayWidth != width || sOverlayHeight != height)
    {
        D3D11_TEXTURE2D_DESC desc;
        D3D11_SHADER_RESOURCE_VIEW_DESC view;

        if (sOverlayView)
            ID3D11ShaderResourceView_Release(sOverlayView);
        if (sOverlayTexture)
            ID3D11Texture2D_Release(sOverlayTexture);
        memset(&desc, 0, sizeof(desc));
        desc.Width = width;
        desc.Height = height;
        desc.MipLevels = 1;
        desc.ArraySize = 1;
        desc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
        desc.SampleDesc.Count = 1;
        desc.Usage = D3D11_USAGE_DYNAMIC;
        desc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
        desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
        ID3D11Device_CreateTexture2D(sDevice, &desc, NULL, &sOverlayTexture);
        memset(&view, 0, sizeof(view));
        view.Format = desc.Format;
        view.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
        view.Texture2D.MipLevels = 1;
        ID3D11Device_CreateShaderResourceView(sDevice, (ID3D11Resource *)sOverlayTexture, &view, &sOverlayView);
        sOverlayWidth = width;
        sOverlayHeight = height;
    }

    if (SUCCEEDED(ID3D11DeviceContext_Map(sContext, (ID3D11Resource *)sOverlayTexture, 0, D3D11_MAP_WRITE_DISCARD, 0, &mapped)))
    {
        for (y = 0; y < height; y++)
            memcpy((uint8_t *)mapped.pData + y * mapped.RowPitch, pixels + y * width, width * 4);
        ID3D11DeviceContext_Unmap(sContext, (ID3D11Resource *)sOverlayTexture, 0);
    }
    Ui_ReleaseOverlay();
}

static void SetConstants(float x, float y, float w, float h, float gameW, float gameH, float uMax, float vMax)
{
    D3D11_MAPPED_SUBRESOURCE mapped;
    struct Constants *c;

    if (FAILED(ID3D11DeviceContext_Map(sContext, (ID3D11Resource *)sConstants, 0, D3D11_MAP_WRITE_DISCARD, 0, &mapped)))
        return;
    c = mapped.pData;
    c->destOrigin[0] = x;
    c->destOrigin[1] = y;
    c->destSize[0] = w;
    c->destSize[1] = h;
    c->targetSize[0] = (float)sBackWidth;
    c->targetSize[1] = (float)sBackHeight;
    c->gameSize[0] = gameW;
    c->gameSize[1] = gameH;
    c->uvMax[0] = uMax;
    c->uvMax[1] = vMax;
    c->time = 0;
    c->pad = 0;
    ID3D11DeviceContext_Unmap(sContext, (ID3D11Resource *)sConstants, 0);
}

static void DrawFrameD3D(void)
{
    static const float black[4] = {0, 0, 0, 1};
    D3D11_VIEWPORT viewport;
    ID3D11SamplerState *samplers[2];
    RECT rect;
    double scale;
    int shader;
    int panelSpace = Ui_PanelSpace(sGameColumns, sGameLines, sBackWidth, sBackHeight);

    Video_GameRect(sBackWidth, sBackHeight, sGameColumns, sGameLines, panelSpace, gPcOptions.scaleMode == SCALE_INTEGER, &rect, &scale);
    Ui_SetGameRect(&rect, scale);
    Ui_Tick();

    ID3D11DeviceContext_OMSetRenderTargets(sContext, 1, &sTarget, NULL);
    ID3D11DeviceContext_ClearRenderTargetView(sContext, sTarget, black);
    memset(&viewport, 0, sizeof(viewport));
    viewport.Width = (float)sBackWidth;
    viewport.Height = (float)sBackHeight;
    viewport.MaxDepth = 1;
    ID3D11DeviceContext_RSSetViewports(sContext, 1, &viewport);
    ID3D11DeviceContext_RSSetState(sContext, sRasterizer);
    ID3D11DeviceContext_IASetPrimitiveTopology(sContext, D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);
    ID3D11DeviceContext_IASetInputLayout(sContext, NULL);
    ID3D11DeviceContext_VSSetShader(sContext, sVertexShader, NULL, 0);
    ID3D11DeviceContext_VSSetConstantBuffers(sContext, 0, 1, &sConstants);
    ID3D11DeviceContext_PSSetConstantBuffers(sContext, 0, 1, &sConstants);
    samplers[0] = sPointSampler;
    samplers[1] = sLinearSampler;
    ID3D11DeviceContext_PSSetSamplers(sContext, 0, 2, samplers);

    // Game
    if (gPcOptions.filter == FILTER_LCD)
        shader = 1;
    else if (gPcOptions.filter == FILTER_CRT)
        shader = 2;
    else if (gPcOptions.scaleMode == SCALE_FIT)
        shader = 3;
    else
        shader = 0;
    SetConstants((float)rect.left, (float)rect.top, (float)(rect.right - rect.left), (float)(rect.bottom - rect.top),
                 (float)sGameColumns, (float)sGameLines, (float)sGameWidth / sTextureWidth, (float)sGameHeight / sTextureHeight);
    ID3D11DeviceContext_PSSetShader(sContext, sPixelShaders[shader], NULL, 0);
    ID3D11DeviceContext_PSSetShaderResources(sContext, 0, 1, &sGameView);
    ID3D11DeviceContext_OMSetBlendState(sContext, NULL, NULL, 0xFFFFFFFF);
    ID3D11DeviceContext_Draw(sContext, 4, 0);

    // Overlay
    UploadOverlay();
    if (sOverlayView)
    {
        SetConstants(0, 0, (float)sBackWidth, (float)sBackHeight, (float)sOverlayWidth, (float)sOverlayHeight, 1, 1);
        ID3D11DeviceContext_PSSetShader(sContext, sPixelShaders[4], NULL, 0);
        ID3D11DeviceContext_PSSetShaderResources(sContext, 0, 1, &sOverlayView);
        ID3D11DeviceContext_OMSetBlendState(sContext, sOverlayBlend, NULL, 0xFFFFFFFF);
        ID3D11DeviceContext_Draw(sContext, 4, 0);
    }
}

// Saves what is in the back buffer as a .bmp.
static void WriteBmp(const char *path, const uint32_t *pixels, int width, int height, int pitch)
{
    BITMAPFILEHEADER file;
    BITMAPINFOHEADER info;
    FILE *f = fopen(path, "wb");
    int y;

    if (!f)
        return;
    memset(&file, 0, sizeof(file));
    memset(&info, 0, sizeof(info));
    file.bfType = 0x4D42;
    file.bfOffBits = sizeof(file) + sizeof(info);
    file.bfSize = file.bfOffBits + width * height * 4;
    info.biSize = sizeof(info);
    info.biWidth = width;
    info.biHeight = -height;
    info.biPlanes = 1;
    info.biBitCount = 32;
    info.biCompression = BI_RGB;
    fwrite(&file, sizeof(file), 1, f);
    fwrite(&info, sizeof(info), 1, f);
    for (y = 0; y < height; y++)
        fwrite((const uint8_t *)pixels + y * pitch, width * 4, 1, f);
    fclose(f);
}

static void DumpBackBuffer(void)
{
    D3D11_TEXTURE2D_DESC desc;
    ID3D11Texture2D *staging = NULL;
    D3D11_MAPPED_SUBRESOURCE mapped;

    ID3D11Texture2D_GetDesc(sBackBuffer, &desc);
    desc.Usage = D3D11_USAGE_STAGING;
    desc.BindFlags = 0;
    desc.CPUAccessFlags = D3D11_CPU_ACCESS_READ;
    desc.MiscFlags = 0;
    if (FAILED(ID3D11Device_CreateTexture2D(sDevice, &desc, NULL, &staging)))
        return;
    ID3D11DeviceContext_CopyResource(sContext, (ID3D11Resource *)staging, (ID3D11Resource *)sBackBuffer);
    if (SUCCEEDED(ID3D11DeviceContext_Map(sContext, (ID3D11Resource *)staging, 0, D3D11_MAP_READ, 0, &mapped)))
    {
        WriteBmp(sDumpPath, mapped.pData, desc.Width, desc.Height, mapped.RowPitch);
        ID3D11DeviceContext_Unmap(sContext, (ID3D11Resource *)staging, 0);
    }
    ID3D11Texture2D_Release(staging);
}

static void PresentD3D(void)
{
    UINT interval = gPcOptions.vsync ? 1 : 0;
    UINT flags = (!gPcOptions.vsync && sAllowTearing) ? DXGI_PRESENT_ALLOW_TEARING : 0;

    IDXGISwapChain1_Present(sSwapChain, interval, flags);
}

static void ResizeIfNeeded(void)
{
    int width = sClientWidth, height = sClientHeight;

    if (width <= 0 || height <= 0 || (width == sBackWidth && height == sBackHeight))
        return;
    ReleaseTarget();
    ID3D11DeviceContext_OMSetRenderTargets(sContext, 0, NULL, NULL);
    ID3D11DeviceContext_Flush(sContext);
    IDXGISwapChain1_ResizeBuffers(sSwapChain, 0, width, height, DXGI_FORMAT_UNKNOWN,
                                  (sFlipModel ? DXGI_SWAP_CHAIN_FLAG_FRAME_LATENCY_WAITABLE_OBJECT : 0) | (sAllowTearing ? DXGI_SWAP_CHAIN_FLAG_ALLOW_TEARING : 0));
    sBackWidth = width;
    sBackHeight = height;
    CreateTarget();
    ReadRefreshRate();
}

// GDI: the fallback, and it needs no device.
static void DrawFrameGdi(void)
{
    static uint32_t *buffer;
    static int bufferWidth, bufferHeight;
    int width = sClientWidth, height = sClientHeight;
    int panelSpace = Ui_PanelSpace(sGameColumns, sGameLines, width, height);
    BITMAPINFO info;
    RECT rect;
    double scale;
    const uint32_t *overlay;
    int overlayWidth, overlayHeight;
    HDC dc;
    int x, y;

    if (width <= 0 || height <= 0)
        return;
    if (width != bufferWidth || height != bufferHeight)
    {
        free(buffer);
        buffer = malloc(width * height * 4);
        bufferWidth = width;
        bufferHeight = height;
    }
    Video_GameRect(width, height, sGameColumns, sGameLines, panelSpace, gPcOptions.scaleMode == SCALE_INTEGER, &rect, &scale);
    Ui_SetGameRect(&rect, scale);
    Ui_Tick();
    memset(buffer, 0, width * height * 4);

    for (y = rect.top > 0 ? rect.top : 0; y < rect.bottom && y < height; y++)
    {
        const uint32_t *src = sGamePixels + (int)((y - rect.top) * (double)sGameHeight / (rect.bottom - rect.top)) * MAX_GAME_WIDTH;
        uint32_t *dst = buffer + y * width;
        double step = (double)sGameWidth / (rect.right - rect.left);

        for (x = rect.left > 0 ? rect.left : 0; x < rect.right && x < width; x++)
            dst[x] = src[(int)((x - rect.left) * step)];
    }

    overlay = Ui_TakeOverlay(&overlayWidth, &overlayHeight);
    if (overlay)
    {
        static uint32_t *copy;
        static int copyWidth, copyHeight;

        if (overlayWidth != copyWidth || overlayHeight != copyHeight)
        {
            free(copy);
            copy = malloc(overlayWidth * overlayHeight * 4);
            copyWidth = overlayWidth;
            copyHeight = overlayHeight;
        }
        memcpy(copy, overlay, overlayWidth * overlayHeight * 4);
        Ui_ReleaseOverlay();
        overlay = copy;
    }
    else
    {
        overlay = Ui_LastOverlay(&overlayWidth, &overlayHeight);
    }

    if (overlay && overlayWidth == width && overlayHeight == height)
    {
        for (y = 0; y < height; y++)
        {
            for (x = 0; x < width; x++)
            {
                uint32_t o = overlay[y * width + x];
                uint32_t a = o >> 24;

                if (a == 255)
                {
                    buffer[y * width + x] = o;
                }
                else if (a)
                {
                    uint32_t d = buffer[y * width + x];
                    uint32_t r = ((o >> 16) & 0xFF) + (((d >> 16) & 0xFF) * (255 - a)) / 255;
                    uint32_t g = ((o >> 8) & 0xFF) + (((d >> 8) & 0xFF) * (255 - a)) / 255;
                    uint32_t b = (o & 0xFF) + ((d & 0xFF) * (255 - a)) / 255;
                    buffer[y * width + x] = (r << 16) | (g << 8) | b;
                }
            }
        }
    }

    memset(&info, 0, sizeof(info));
    info.bmiHeader.biSize = sizeof(info.bmiHeader);
    info.bmiHeader.biWidth = width;
    info.bmiHeader.biHeight = -height;
    info.bmiHeader.biPlanes = 1;
    info.bmiHeader.biBitCount = 32;
    info.bmiHeader.biCompression = BI_RGB;
    dc = GetDC(sWindow);
    SetDIBitsToDevice(dc, 0, 0, width, height, 0, 0, 0, height, buffer, &info, DIB_RGB_COLORS);
    ReleaseDC(sWindow, dc);

    if (sDumpRequested)
    {
        WriteBmp(sDumpPath, buffer, width, height, width * 4);
        InterlockedExchange(&sDumpRequested, 0);
    }
}

static void CountFps(void)
{
    LARGE_INTEGER now;
    double elapsed;

    sFpsFrames++;
    QueryPerformanceCounter(&now);
    elapsed = (double)(now.QuadPart - sFpsTime.QuadPart) / sTimerFrequency.QuadPart;
    sFramesShown++;
    if (elapsed >= 1.0)
    {
        if (sLatencyCount)
            sLatencyAverage = sLatencySum / sLatencyCount;
        sLatencySum = 0;
        sLatencyCount = 0;
        sFps = sFpsFrames / elapsed;
        sGameFps = (sPublishCount - sFpsGameFrames) / elapsed;
        sFpsGameFrames = sPublishCount;
        sFpsFrames = 0;
        sFpsTime = now;
    }
}

double Video_Latency(void)
{
    return sLatencyAverage;
}

void Video_PrintStats(void)
{
    if (getenv("PINBALL_STATS"))
        printf("{\"pictures\": %u, \"gameFrames\": %u, \"fps\": %.1f, \"gameFps\": %.2f, \"latencyMs\": %.2f, \"refresh\": %.0f, \"d3d\": %d}\n",
               sFramesShown, (unsigned)sPublishCount, sFps, sGameFps, sLatencyTotalCount ? sLatencyTotal / sLatencyTotalCount : 0.0, sRefreshRate, sUseD3D);
    fflush(stdout);
}

void Video_GetFps(double *display, double *game)
{
    *display = sFps;
    *game = sGameFps;
}

const struct FrameInfo *Video_LatestInfo(void)
{
    static struct FrameInfo info;

    EnterCriticalSection(&sSlotLock);
    if (sLatest >= 0)
        info = sSlots[sLatest]->info;
    LeaveCriticalSection(&sSlotLock);
    return &info;
}

void Video_WorldOrigin(int *x, int *y)
{
    *x = sWorldX;
    *y = sWorldY;
}

const uint32_t *Video_Minimap(int *width, int *height)
{
    *width = sMinimapWidth;
    *height = sMinimapHeight;
    return sMinimapWidth ? sMinimap : NULL;
}

static void RenderMinimap(const struct FrameSet *frame)
{
    struct PpuRenderArgs args;
    int i;

    if (!sMinimap)
        sMinimap = malloc(TABLE_WIDTH * TABLE_MAX_HEIGHT * 4);
    memset(&args, 0, sizeof(args));
    args.scale = 1;
    args.stride = frame->tableWidth;
    args.layerMask = 0x1E;
    args.alpha = 256;
    args.width = frame->tableWidth;
    args.outLeft = -frame->tableLeft;
    args.spriteMask = frame->screenSprites;
    args.spriteMaskInvert = 1;
    for (i = 0; i < frame->numStrips; i++)
    {
        int top = frame->stripY[i];
        int count = i + 1 < frame->numStrips ? frame->stripY[i + 1] - top : frame->tableHeight - top;

        if (count > PPU_HEIGHT)
            count = PPU_HEIGHT;
        args.frame = &frame->strip[i];
        args.out = sMinimap + top * frame->tableWidth;
        args.lastLine = count;
        Ppu_Render(&args);
    }
    sMinimapWidth = frame->tableWidth;
    sMinimapHeight = frame->tableHeight;
}

// One pass of the display: chooses the frames, draws and shows.
static void DisplayFrame(void)
{
    const struct FrameSet *frame = NULL, *prev = NULL;
    int publish, alpha = 256;
    LARGE_INTEGER now, frameTime, inputTime;

    EnterCriticalSection(&sSlotLock);
    publish = sPublishCount;
    frameTime = sLatestTime;
    inputTime = sLatestInputTime;
    if (sLatest >= 0)
    {
        sSlotHeld[0] = sLatest;
        frame = sSlots[sLatest];
        if (sPrevious >= 0)
        {
            sSlotHeld[1] = sPrevious;
            prev = sSlots[sPrevious];
        }
    }
    LeaveCriticalSection(&sSlotLock);

    if (frame)
    {
        if (gPcOptions.interpolate && prev && !Host_FastForward())
        {
            double period = 1.0 / GBA_FRAME_RATE;

            QueryPerformanceCounter(&now);
            alpha = (int)(((double)(now.QuadPart - frameTime.QuadPart) / sTimerFrequency.QuadPart) / period * 256);
            if (alpha > 256 || Host_IsPaused())
                alpha = 256;
            if (alpha < 0)
                alpha = 0;
        }
        if (sForcedAlpha >= 0)
            alpha = sForcedAlpha;

        if (publish != sLastDrawnPublish || alpha != sLastDrawnAlpha || gPcOptions.view != sLastDrawnView)
        {
            RenderGame(frame, alpha < 256 ? prev : NULL, alpha);
            if (gPcOptions.panels && frame->numStrips && publish != sLastDrawnPublish)
                RenderMinimap(frame);
            sWorldX = gPcOptions.view == VIEW_TABLE && frame->numStrips ? 0 : frame->info.cameraX;
            sWorldY = gPcOptions.view == VIEW_TABLE && frame->numStrips ? frame->info.cameraY - frame->mainY : frame->info.cameraY;
            sLastDrawnPublish = publish;
            sLastDrawnAlpha = alpha;
            sLastDrawnView = gPcOptions.view;
            if (sUseD3D)
                UploadGameTexture();
        }
    }

    EnterCriticalSection(&sSlotLock);
    sSlotHeld[0] = sSlotHeld[1] = -1;
    LeaveCriticalSection(&sSlotLock);

    if (sUseD3D)
    {
        ResizeIfNeeded();
        DrawFrameD3D();
        if (sDumpRequested)
        {
            DumpBackBuffer();
            InterlockedExchange(&sDumpRequested, 0);
        }
        PresentD3D();
    }
    else
    {
        DrawFrameGdi();
    }

    if (publish != sLastShownPublish && frame)
    {
        double latency;

        QueryPerformanceCounter(&now);
        latency = (double)(now.QuadPart - inputTime.QuadPart) * 1000.0 / sTimerFrequency.QuadPart;
        if (latency < 200)
        {
            sLatencySum += latency;
            sLatencyCount++;
            sLatencyTotal += latency;
            sLatencyTotalCount++;
        }
        sLastShownPublish = publish;
    }

    CountFps();
    InterlockedExchange(&sDrawnCount, publish);
    SetEvent(sDrawnEvent);
}

static DWORD WINAPI DisplayThread(LPVOID param)
{
    (void)param;
    StartWorkers();
    sUseD3D = !getenv("PINBALL_GDI") && CreateDevice();
    if (!sUseD3D)
        Host_Log("No Direct3D 11: drawing with GDI, without filters\n");
    ReadRefreshRate();
    QueryPerformanceCounter(&sFpsTime);

    while (!sQuit)
    {
        int smooth = gPcOptions.interpolate && !sSyncMode;

        if (sLatencyWaitable && sUseD3D)
            WaitForSingleObjectEx(sLatencyWaitable, 100, TRUE);

        if (smooth && sUseD3D && gPcOptions.vsync)
        {
            // Present waits for the monitor: every refresh shows a new picture.
        }
        else if (smooth)
        {
            // No vsync, or no Direct3D: as often as the monitor could show one.
            Sleep((DWORD)(1000 / sRefreshRate));
        }
        else
        {
            // One picture per game frame; overlays that change without one
            // still get drawn.
            WaitForSingleObject(sFrameEvent, sSyncMode ? INFINITE : 34);
        }
        DisplayFrame();
    }
    return 0;
}

void Video_Init(HWND window)
{
    int i;

    sWindow = window;
    InitializeCriticalSection(&sSlotLock);
    QueryPerformanceFrequency(&sTimerFrequency);
    Ppu_Init();
    for (i = 0; i < NUM_SLOTS; i++)
    {
        sSlots[i] = calloc(1, sizeof(struct FrameSet));
        if (!sSlots[i])
            Host_Fatal("Out of memory");
    }
    sGamePixels = calloc(MAX_GAME_WIDTH * MAX_GAME_HEIGHT, 4);
    sGameWidth = PPU_WIDTH;
    sGameHeight = PPU_HEIGHT;
    sGameColumns = PPU_WIDTH;
    sGameLines = PPU_HEIGHT;
    sGameScale = 1;
    sFrameEvent = CreateEventA(NULL, FALSE, FALSE, NULL);
    sDrawnEvent = CreateEventA(NULL, FALSE, FALSE, NULL);
    if (getenv("PINBALL_SYNC"))
        sSyncMode = 1;
    if (getenv("PINBALL_ALPHA"))
        sForcedAlpha = atoi(getenv("PINBALL_ALPHA"));
    sThread = CreateThread(NULL, 1 << 20, DisplayThread, NULL, 0, NULL);
}

void Video_Resize(int width, int height)
{
    InterlockedExchange(&sClientWidth, width);
    InterlockedExchange(&sClientHeight, height);
    Ui_Resize(width, height);
}

void Video_Stop(void)
{
    InterlockedExchange(&sQuit, 1);
    SetEvent(sFrameEvent);
    WaitForSingleObject(sThread, 500);
}

// The next free slot: not the newest frames, nor the ones being drawn.
struct FrameSet *Host_AcquireFrame(void)
{
    int i;

    EnterCriticalSection(&sSlotLock);
    for (i = 0; i < NUM_SLOTS; i++)
    {
        if (i != sLatest && i != sPrevious && i != sSlotHeld[0] && i != sSlotHeld[1])
        {
            sWriting = i;
            break;
        }
    }
    LeaveCriticalSection(&sSlotLock);
    if (i == NUM_SLOTS)
        Host_Fatal("No free frame");
    sSlots[sWriting]->numStrips = 0;
    return sSlots[sWriting];
}

void Host_ReleaseFrame(struct FrameSet *frame)
{
    (void)frame;
    EnterCriticalSection(&sSlotLock);
    sWriting = -1;
    LeaveCriticalSection(&sSlotLock);
}

// A frame without its own passes (a pause, a fade) keeps the last table.
void Host_InheritStrips(struct FrameSet *frame)
{
    const struct FrameSet *from = sLatest >= 0 ? sSlots[sLatest] : NULL;

    if (!from || !from->numStrips)
        return;
    memcpy(frame->strip, from->strip, sizeof(from->strip));
    frame->numStrips = from->numStrips;
    frame->tableWidth = from->tableWidth;
    frame->tableHeight = from->tableHeight;
    frame->tableLeft = from->tableLeft;
    memcpy(frame->stripY, from->stripY, sizeof(frame->stripY));
    memcpy(frame->screenSprites, from->screenSprites, sizeof(frame->screenSprites));
}

void Host_PublishFrame(struct FrameSet *frame)
{
    LONG drawTarget;

    (void)frame;
    EnterCriticalSection(&sSlotLock);
    if (sWriting >= 0)
    {
        sPrevious = sLatest;
        sLatest = sWriting;
        sWriting = -1;
        sPublishCount++;
        QueryPerformanceCounter(&sLatestTime);
        sLatestInputTime = gInputTime;
    }
    drawTarget = sPublishCount;
    LeaveCriticalSection(&sSlotLock);
    SetEvent(sFrameEvent);

    if (sSyncMode)
    {
        while (sDrawnCount < drawTarget && !sQuit)
            WaitForSingleObject(sDrawnEvent, 50);
    }
}

// Test mode: the next picture shown is saved, then the call returns.
void Video_DumpNext(const char *path)
{
    strncpy(sDumpPath, path, sizeof(sDumpPath) - 1);
    InterlockedExchange(&sDumpRequested, 1);
    SetEvent(sFrameEvent);
    while (sDumpRequested && !sQuit)
    {
        Sleep(1);
        SetEvent(sFrameEvent);
    }
}

double Video_RefreshRate(void)
{
    return sRefreshRate;
}

int Video_UsesD3D(void)
{
    return sUseD3D;
}
