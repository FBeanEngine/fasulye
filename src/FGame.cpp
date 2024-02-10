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
        //BeginMode2D(activeScene->camera);
        activeScene->Render();
        EndDrawing();
        //EndMode2D();
    }
}