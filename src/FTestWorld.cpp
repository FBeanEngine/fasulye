#include "FTestWorld.h"
#include <iostream>

FTestWorld::FTestWorld()
{
	std::cout << "FTestWorld constructor" << std::endl;
}

void FTestWorld::Init()
{
	std::cout << "FTestWorld Init" << std::endl;
	player = std::unique_ptr<FPlayer>(new FPlayer({static_cast<float>(GetScreenWidth() / 2), static_cast<float>(GetScreenHeight() / 2)}));
}

FTestWorld::~FTestWorld()
{
	// TODO
}

void FTestWorld::Render(float dt)
{
	Vector2 vec = GetScreenToWorld2D(GetMousePosition(), camera.GetCamera());
	camera.SetTarget({player->position.x + 48, player->position.y + 40});
	// std::cout << "FScene::Render()" << objects.size() << std::endl;

	for (int i = 0; i < objects.size(); i++)
	{
		objects[i]->SetMousePosition(vec);
		objects[i]->Draw(dt);
	}
	this->player->SetMousePosition(vec);
	this->player->Draw(dt);
}
