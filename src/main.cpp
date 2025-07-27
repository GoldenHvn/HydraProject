#include <windows.h>
#include <wrl.h>
#include <d3d12.h>
#include <dxgi1_6.h>

#include "game/GameState.h"
#include "game/NPC.h"
#include "game/Player.h"
#include "game/World.h"
#include "game/NetworkClient.h"
#include "game/Quest.h"
#include "ui/LoadingScreen.h"
#include "ui/UIManager.h"
#include "game/TaskManager.h"

using Microsoft::WRL::ComPtr;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg) {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow) {
    const wchar_t CLASS_NAME[] = L"DX12WindowClass";

    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0, CLASS_NAME, L"HydraProject DX12", WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 1280, 720,
        nullptr, nullptr, hInstance, nullptr);

    ShowWindow(hwnd, nCmdShow);

    // Initialize DirectX 12 device
    ComPtr<ID3D12Device> device;
    D3D12CreateDevice(nullptr, D3D_FEATURE_LEVEL_11_0, IID_PPV_ARGS(&device));

    hydra::LoadingScreen loader;
    loader.show();
    for (int p = 0; p <= 100; p += 20) {
        loader.setProgress(p);
        Sleep(50);
    }
    loader.hide();

    hydra::UIManager ui;
    ui.initialize();
    hydra::TaskManager tasks;

    // Simple game state setup
    hydra::GameState game;
    hydra::NPC guardian("Guardian");
    guardian.setPosition({0.f,0.f,5.f});
    game.addNPC(guardian);
    game.addQuest(hydra::Quest("Save Yourself", hydra::QuestType::TimeTravel));

    hydra::Player player("Hero");
    player.setPosition({0.f,0.f,0.f});
    hydra::World world;
    world.addPlayer(player);

    hydra::NetworkClient net;
    tasks.startTask([&net](){
        net.connect("127.0.0.1", 7000); // placeholder connection
    });

    MSG msg = {};
    while (msg.message != WM_QUIT) {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        ui.render();

        world.update();

        // Example gameplay hook: NPC mood could change based on player actions
        auto npc = game.findNPC("Guardian");
        if (npc)
            npc->adjustMood(1); // placeholder for actual interaction logic

        auto quest = game.getCurrentQuest();
        if (quest && !quest->isCompleted()) {
            // In real gameplay, conditions would be checked here
            quest->complete();
        }
    }

    net.disconnect();
    return 0;
}
