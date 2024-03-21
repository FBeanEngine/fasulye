#include "FMainMenu.h"
#include "raylib.h"
#include "FSceneManager.h"
#include <iostream>

FMainMenu::FMainMenu()
{
	m_isLoaded = false;
}

FMainMenu::~FMainMenu()
{
	// TODO
}

void FMainMenu::Init()
{
	// TODO
}

void FMainMenu::Render(float dt)
{
	Vector2 vec = GetScreenToWorld2D(GetMousePosition(), camera.GetCamera());
	// background color set
	DrawRectangle(-GetScreenWidth() / 2, -GetScreenHeight() / 2, GetScreenWidth(), GetScreenHeight(), {0, 8, 17, 255});

	// background images
	// top left
	DrawCircle(-GetScreenWidth() / 2 + 100, -GetScreenHeight() / 2, 200, {7, 29, 27, 255});
	DrawCircle(-GetScreenWidth() / 2 + 300, -GetScreenHeight() / 2, 100, {7, 29, 27, 255});
	DrawCircle(-GetScreenWidth() / 2 + 50, -GetScreenHeight() / 2 + 250, 100, {7, 29, 27, 255});
	// bottom right
	DrawCircle(400, 400, 200, {7, 29, 27, 255});
	DrawCircle(200, 375, 100, {7, 29, 27, 255});
	DrawCircle(600, 300, 100, {7, 29, 27, 255});

	// title
	int textLength = MeasureText("Fasulye", 50);
	DrawText("Fasulye", 0 - textLength / 2, -150, 50, {225, 213, 103, 255});

	// play button
	int buttonLength = MeasureText("Play", 35);
	DrawText("Play", 0 - buttonLength / 2, 0, 35, {246, 238, 92, 255});

	if (CheckCollisionPointRec(vec, {float(-buttonLength / 2), 0, float(buttonLength), 35}))
	{
		SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
		DrawText("Play", 0 - buttonLength / 2, 0, 35, {196, 190, 71, 255});
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			std::cout << "Play button clicked" << std::endl;
			FSceneManager::LoadScene(1);
			std::cout << "loading screen" << std::endl;
			m_isLoaded = true;
		}
	}
	else
	{
		SetMouseCursor(MOUSE_CURSOR_DEFAULT);
	}
	if (m_isLoaded)
	{
		bool isReady = FSceneManager::IsSceneReady();
		// loading text button
		int loadingTextLength = MeasureText("Loading...", 35);
		DrawText("Loading...", -loadingTextLength / 2, 0 + 100, 35, {246, 92, 92, 255});
	}
}
