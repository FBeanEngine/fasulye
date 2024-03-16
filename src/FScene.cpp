#include "FScene.h"
#include "FObject.h"
#include "FPlayer.h"
#include "raylib.h"
#include "utils.h"
#include "FSceneManager.h"
#include <iostream>
#include <memory>

FScene::FScene()
{
    std::cout << "FScene constructor: " << std::endl;
    //camera.AddEffect(CameraEffect::None);
    // camera.AddEffect(CameraEffect::Shake);
}

FScene::~FScene()
{
    std::cout << "FScene destructor: " << std::endl;
}

void FScene::Init()
{
    // init scene that effect fSceneManager
}

void FScene::BeforeLoad()
{
    // init scene that effect fSceneManager
}

int FScene::AddObject(std::unique_ptr<FObject> object)
{
    objects.push_back(std::move(object));
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
        return *objects[0];
    }
    else if (index < 0)
    {
        return *objects[0];
    }

    return *objects[index];
}

void FScene::Physics() {

}

void FScene::Logic(float dt) {

}

void FScene::Render(float dt) {
    
}