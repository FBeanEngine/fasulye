#include "FScene.h"
#include "FObject.h"
#include "FPlayer.h"
#include <iostream>

FScene::FScene(SceneType type)
{
    this->type = type;
    if (type == SceneType::SpaceStation)
    {
        player = std::unique_ptr<FPlayer>(new FPlayer({100, 100}));
    }
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
}