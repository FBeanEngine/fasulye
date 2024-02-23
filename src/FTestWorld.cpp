#include "FTestWorld.h"
#include <iostream>

FTestWorld::FTestWorld()
{
	std::cout << "FTestWorld constructor" << std::endl;
}

void FTestWorld::Init()
{

	player = std::unique_ptr<FPlayer>(new FPlayer({static_cast<float>(GetScreenWidth() / 2), static_cast<float>(GetScreenHeight() / 2)}));
}

void FTestWorld::BeforeLoad()
{
	std::cout << "FTestWorld BeforeLoad" << std::endl;
	int a = 0;
	for (size_t i = 0; i < 2000 * 32; i++)
	{
		for (size_t j = 0; j < 2000 * 32; j++)
		{
			a += i * j;
		}
	}
	std::cout << "a: " << a << std::endl;
}

FTestWorld::~FTestWorld()
{
	// TODO
}
