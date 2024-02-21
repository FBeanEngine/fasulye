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
