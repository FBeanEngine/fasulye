#include "FScene.h"
#include "raylib.h"
#include "FGame.h"
#include "FSceneManager.h"
#include <iostream>

FGame::FGame()
{
    InitWindow(1280, 720, "FSun");
    SetTargetFPS(60);

    SceneMenager = FSceneManager();
    std::unique_ptr<FScene> scene = std::unique_ptr<FScene>(new FScene(SceneType::SpaceStation));
    SceneMenager.AddScene(std::move(scene));

    SceneMenager.SetActiveScene(0);
}

FGame::~FGame()
{
    CloseWindow();
}


void DrawGridChat(Camera2D camera, int gridSize) {
    // Calculate the starting point of the grid based on the camera offset
    int startX = (int)(camera.target.x - (GetScreenWidth() / 2.0f));
    int startY = (int)(camera.target.y - (GetScreenHeight() / 2.0f));

    // Draw vertical lines
    for (int x = startX - (startX % gridSize); x < camera.target.x + (GetScreenWidth() / 2.0f); x += gridSize) {
        DrawLine(x, -GetScreenHeight(), x, GetScreenHeight() * 2, LIGHTGRAY);
    }

    // Draw horizontal lines
    for (int y = startY - (startY % gridSize); y < camera.target.y + (GetScreenHeight() / 2.0f); y += gridSize) {
        DrawLine(-GetScreenWidth(), y, GetScreenWidth() * 2, y, LIGHTGRAY);
    }
}

void FGame::Run()
{
    std::cout << "FGame::Run()" << std::endl;
    while (!WindowShouldClose())
    {

        //DrawText("Fasulye", GetScreenWidth() / 2, GetScreenHeight() / 2, 20, WHITE);

        std::unique_ptr<FScene> &activeScene = SceneMenager.GetActiveScene();
        // Physics update loop
        activeScene->Physics();
        // Game logic update loop
        activeScene->Logic();
        // Drawing loop
        ClearBackground(BLACK);
        BeginDrawing();
        BeginMode2D(activeScene->camera);
        activeScene->Render();
        DrawGridChat(activeScene->camera, 50);
        EndMode2D();
        EndDrawing();
    }
}