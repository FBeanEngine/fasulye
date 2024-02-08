#include "FScene.h"

FScene::FScene(SceneType type)
{
    this->type = type;
}

int FScene::AddObject(FObject object)
{
    this->objects.insert(object);
    return this->objects.size() - 1;
}

int FScene::RemoveObject(int index)
{
    if (index >= this->objects.size())
    {
        return 1;
    }
    else if (index < 0)
    {
        return 1;
    }

    this->objects.erase(index);

    return 0;
}

FObject FScene::GetObject(int index)
{
    if (index >= this->objects.size())
    {
        return this->objects[0];
    }
    else if (index < 0)
    {
        return this->objects[0];
    }

    return this->objects[index];
}

void FScene::Physics()
{
    // ToDo: Collision check
}

void FScene::Logic()
{
    for (int i = 0; i < this->objects.size(); i++)
    {
        this->objects[i]->Update();
    }
}

void FScene::Render()
{
    for (int i = 0; i < this->objects.size(); i++)
    {
        this->objects[i]->Draw();
    }
}