# HydraProject

HydraProject aims to become a 3D massively multiplayer online role‑playing game inspired by Cabal Online. The current code base provides only a very small DirectX 12 prototype and some simple gameplay scaffolding.

### Current features

* Console-based loading screen with progress updates
* Initial UI manager stub preparing for future interfaces
* Updated vertex shader for DirectX 12 meshes
* New HLSL terrain shader
* Basic networking skeleton using WinSock
* Player and world classes with simple leveling logic
* Quest system prototype with time‑travel hooks

## Game vision

* Actions have lasting consequences: NPCs react to your behavior through a basic mood system.
* Time travel quests allow the player to revisit earlier moments with their earned power, while enemies grow stronger.

These ideas are just starting points and will require significant development effort.

## Building

1. Install CMake and the Visual Studio build tools with DirectX 12 headers.
2. From a Developer Command Prompt, run:
   ```
   cmake -S . -B build
   cmake --build build --config Release
   ```
3. Launch `HydraMMORPG.exe` from the `build` directory.

This repository is a minimal skeleton and does not yet implement networking or content creation tools.

All rights are reserved as outlined in the LICENSE.
