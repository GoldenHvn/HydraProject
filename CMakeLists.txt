cmake_minimum_required(VERSION 3.10)
project(HydraProject)

set(SOURCES
    src/main.cpp
    src/game/NPC.cpp
    src/game/GameState.cpp
    src/game/Quest.cpp
    src/game/Player.cpp
    src/game/World.cpp
    src/game/NetworkClient.cpp
    src/game/TaskManager.cpp
    src/ui/LoadingScreen.cpp
    src/ui/UIManager.cpp
)

add_executable(HydraMMORPG ${SOURCES})

# Link DirectX libraries
if (WIN32)
    target_link_libraries(HydraMMORPG d3d12 dxgi dxguid)
endif()
