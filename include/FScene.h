#pragma once
#include <vector>
#include "enums.h"
#include "raylib.h"
#include "FObject.h"
#include "FPlayer.h"
#include "FCamera.h"
#include "FGrid.h"
#include <memory>

class FScene
{
public:
    FScene();
    ~FScene();
    virtual void Init();
    int AddObject(std::unique_ptr<FObject> object);
    int RemoveObject(int index);
    FObject GetObject(int index);
    FCamera camera;

    virtual void BeforeLoad();
    virtual void Physics();
    virtual void Logic(float dt);
    virtual void Render(float dt);

protected:
    SceneType type;
    std::vector<std::unique_ptr<FObject>> objects;
};
