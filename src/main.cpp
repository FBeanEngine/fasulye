#include "raylib.h"
#include <string>

int main(void)
{
    const int currentMonitor = GetCurrentMonitor();

    InitWindow(0, 0, "Fasulye");
    SetTargetFPS(60);
    const int screenWidth = GetMonitorWidth(currentMonitor);
    const int screenHeight = GetMonitorHeight(currentMonitor);
    //SetWindowState(FLAG_FULLSCREEN_MODE);

    std::string sh = std::to_string(currentMonitor);
    TraceLog(LOG_INFO, sh.c_str());

    while (!WindowShouldClose())
    {

        if (GetKeyPressed() == KEY_F) {
            if (IsWindowFullscreen()) {
                ToggleFullscreen();
                SetWindowSize(screenWidth / 2, screenHeight / 2);
            } else {
                ToggleFullscreen();
                SetWindowSize(screenWidth, screenHeight);
            }
        }

        ClearBackground(BLACK);

        DrawText("Fasulye2", 190, 200, 20, WHITE);

        EndDrawing();
    }

    CloseWindow(); 
    return -1;
}