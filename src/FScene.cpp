#include "FScene.h"
#include "FObject.h"
#include "FPlayer.h"
#include "raylib.h"
#include "utils.h"
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

void FScene::Logic(float dt)
{
    player->Update(dt);
    for (int i = 0; i < objects.size(); i++)
    {
        objects[i].Update(dt);
    }
}

void FScene::Render(float dt)
{
    Vector2 vec = GetScreenToWorld2D(GetMousePosition(), camera);
    camera.target = LerpVector2(camera.target, {(player->position.x + vec.x) / 2, (player->position.y + vec.y) / 2}, 0.035f);
    // camera.target = SmoothDamp(camera.target, {(player->position.x + vec.x) / 2, (player->position.y + vec.y) / 2}, new Vector2{0, 0}, 0.01f, 750, dt);
    // camera.target = {(player->position.x + vec.x) / 2, (player->position.y + vec.y) / 2};
    for (int i = 0; i < objects.size(); i++)
    {
        objects[i].Draw(dt);
    }

    this->player->Draw(dt);
}