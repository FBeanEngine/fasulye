#pragma once
#include <vector>
#include <memory>
#include "raylib.h"
#include "FStruct.h"

class FObject
{
public:
    FObject();
    virtual ~FObject();

    virtual void Update(float dt);
    virtual void Draw(float dt);
    virtual void Physics(std::string tag);
    void SetMousePosition(Vector2 mousePosition);
    void ActivateBoundingBox();
    void DeactivateBoundingBox();
    void SetBoundingBox(float x, float y, float width, float height);
    Rectangle GetBoundingBox();
    std::string GetTag();
    void ShowBoundingBox();

    Vector2 position;
    Vector2 rotation;
    bool isDestroyed;
    std::vector<FObject> collidedObjects;

protected:
    Rectangle boundingBox;
    bool enableBoundingBox;
    Vector2 m_mousePosition;
    Texture texture;
    std::string tag;
};