#pragma once
#include <vector>
#include <memory>
#include "raylib.h"
#include "FStruct.h"

class FObject
{
public:
    FObject();
    //~FObject();

    virtual void Update(float dt);
    virtual void Draw(float dt);
    void SetMousePosition(Vector2 mousePosition);

    Vector2 position;
    Vector2 rotation;
    FBoundingBox boundingBox;
    bool enableBoundingBox;
    std::vector<FObject> collidedObjects;

protected:
    Vector2 m_mousePosition;
    Texture texture;
};