#include "FScene.h"
#include "raylib.h"
#include "FGame.h"

FGame::FGame()
{
    InitWindow(1280, 720, "FSun");
    SetTargetFPS(60);
}

FGame::~FGame()
{
    CloseWindow();
}

void FGame::Run()
{
    while (!WindowShouldClose())
    {
        FScene scene = SceneMenager.GetActiveScene();
        // Physics update loop
        scene.Physics();
        // Game logic update loop
        scene.Logic();
        // Drawing loop
        BeginMode2D(scene.camera);
        scene.Render();
        EndMode2D();
    }
}