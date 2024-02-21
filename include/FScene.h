#pragma once
#include <vector>
#include "enums.h"
#include "raylib.h"
#include "FObject.h"
#include "FPlayer.h"
#include "FCamera.h"
#include <memory>

class FScene
{
public:
    FScene(SceneType type);
    ~FScene();
    int AddObject(FObject object);
    int RemoveObject(int index);
    FObject GetObject(int index);
    FCamera camera;

    void Physics();
    void Logic(float dt);
    void Render(float dt);

private:
    SceneType type;
    std::unique_ptr<FPlayer> player;
    std::vector<FObject> objects;
};
