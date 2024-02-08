#include "FGame.h"
#include "raylib.h"

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
        // Physics update loop

        // Game logic update loop

        // Drawing loop
        BeginDrawing();

        ClearBackground(BLACK);
        DrawText("Fasulye", GetScreenWidth() / 2, GetScreenHeight() / 2, 20, WHITE);

        EndDrawing();
    }
}