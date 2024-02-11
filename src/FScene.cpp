#include "FScene.h"
#include "FObject.h"
#include "FPlayer.h"
#include "raylib.h"
#include <iostream>

FScene::FScene(SceneType type)
{
    this->type = type;
    if (type == SceneType::SpaceStation)
    {
        player = std::unique_ptr<FPlayer>(new FPlayer({static_cast<float>(GetScreenWidth() / 2), static_cast<float>(GetScreenHeight() / 2)}));
    }
    camera.target = player->position;
    camera.offset = {static_cast<float>(GetScreenWidth() / 2), static_cast<float>(GetScreenHeight() / 2)};
    camera.rotation = 0;
    camera.zoom = 1;
}

FScene::~FScene()
{
    std::cout << "FScene destructor: " << std::endl;
}

int FScene::AddObject(FObject object)
{
    objects.push_back(object);
    return objects.size() - 1;
}

int FScene::RemoveObject(int index)
{
    if (index >= objects.size())
    {
        return 1;
    }
    else if (index < 0)
    {
        return 1;
    }
    objects.erase(objects.begin() + index);

    return 0;
}

FObject FScene::GetObject(int index)
{
    if (index >= objects.size())
    {
        return objects[0];
    }
    else if (index < 0)
    {
        return objects[0];
    }

    return objects[index];
}

void FScene::Physics()
{
    // ToDo: Collision check
}

void FScene::Logic()
{
    player->Update();
    camera.target = player->position;
    for (int i = 0; i < objects.size(); i++)
    {
        objects[i].Update();
    }
}

void FScene::Render()
{
    for (int i = 0; i < objects.size(); i++)
    {
        objects[i].Draw();
    }

    this->player->Draw();
}