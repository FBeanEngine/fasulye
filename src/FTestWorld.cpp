#include "FTestWorld.h"
#include <iostream>
#include "utils.h"

FTestWorld::FTestWorld()
{
	std::cout << "FTestWorld constructor" << std::endl;
}

void FTestWorld::Init()
{
	// Works after loading but only called when setActiveScene called
	player = std::unique_ptr<FPlayer>(new FPlayer({static_cast<float>(GetScreenWidth() / 2), static_cast<float>(GetScreenHeight() / 2)}));
	camera.AddEffect(CameraEffect::NoneEffect);
}

void FTestWorld::BeforeLoad()
{
	std::cout << "FTestWorld BeforeLoad" << std::endl;
	grid = std::unique_ptr<FGrid>(new FGrid(100, 100));

	for (int i = 0; i < grid->GetWidth(); i++)
	{
		for (int j = 0; j < grid->GetHeight(); j++)
		{
			if (RandomRange(0, 10) < 5)
				grid->SetTile(i, j, 0);
			else
				grid->SetTile(i, j, 1);
		}
	}

	std::cout << grid->GetWidth() << std::endl;
}

void FTestWorld::Render(float dt)
{
    Vector2 vec = GetScreenToWorld2D(GetMousePosition(), camera.GetCamera());
    camera.SetTarget({player->position.x + 48, player->position.y + 40});
    
	Rectangle cameraBox = camera.GetCameraViewportAsRectangle();
	DrawRectangle(cameraBox.x - 64, cameraBox.y - 64, cameraBox.width + 64, cameraBox.height + 64, BLUE);
	
	for (int x = RoundAccordingToRef(cameraBox.x, 32); x < grid->GetWidth() * 32; x += 32)
	{
    	for (int y = RoundAccordingToRef(cameraBox.y, 32); y < grid->GetHeight() * 32; y += 32)
    	{
       	 	if (CheckCollisionRecs({(float)x, (float)y, 32, 32}, cameraBox))
			{
            	if (grid->GetTileWithWorldPosition({(float)x, (float)y}) == 1)
            	{
            	    DrawRectangle(x, y, 32, 32, RED);
            	}
            	else
            	{
            	    DrawRectangle(x, y, 32, 32, GREEN);
            	}
			}

			if (y > (cameraBox.y + cameraBox.height + 64)) break;
    	}

		if (x > (cameraBox.x + cameraBox.width + 64)) break;
	}

    for (int i = 0; i < objects.size(); i++)
    {
        objects[i]->SetMousePosition(vec);
        objects[i]->Draw(dt);
    }
	
    this->player->SetMousePosition(vec);
    this->player->Draw(dt);
}

void FTestWorld::Logic(float dt)
{
    std::vector<int> destroyedObjects;
    player->Update(dt);
    for (int i = 0; i < objects.size(); i++)
    {
        if (objects[i]->isDestroyed)
        {
            destroyedObjects.push_back(i);
        }
        else
        {
            objects[i]->Update(dt);
        }
    }
    for (size_t i = 0; i < destroyedObjects.size(); i++)
    {
        objects[destroyedObjects[i]].reset();
        objects.erase(objects.begin() + destroyedObjects[i]);
    }
    destroyedObjects.clear();
}
