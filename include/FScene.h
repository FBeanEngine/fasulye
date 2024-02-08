#pragma once
#include <vector>
#include "enums.h"
#include "raylib.h"

class FScene
{
public:
    FScene(SceneType type);
    //~FScene();
    int AddObject(FObject object);
    int RemoveObject(int index);
    FObject GetObject(int index);

    void Physics();
    void Logic();
    void Render();

private:
    SceneType type;
    std::vector<FObject> objects;
};
