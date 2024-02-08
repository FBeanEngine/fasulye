#pragma once
#include <vector>
#include "raylb.h"
#include "FStruct.h"

class FObject
{
public:
    FObject();
    //~FObject();

    void Update();
    void Draw();

    Vector2 position;
    Vector2 rotation;
    FBoundingBox boundingBox;
    bool enableBoundingBox;
    std::vector<FObject> collidedObjects;

private:
    Texture texture;
}