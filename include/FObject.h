#pragma once
#include <vector>
#include "raylib.h"
#include "FStruct.h"

class FObject
{
public:
    FObject();
    //~FObject();

    void Update(float dt);
    void Draw(float dt);

    Vector2 position;
    Vector2 rotation;
    FBoundingBox boundingBox;
    bool enableBoundingBox;
    std::vector<FObject> collidedObjects;

protected:
    Texture texture;
};