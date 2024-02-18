#pragma once

#include "raylib.h"
#include "FObject.h"

class FAmmo : public FObject
{
public:
    FAmmo(Vector2 position, Vector2 target, int damage, int range, int bulletSpeed, Texture2D texture);
    ~FAmmo();
    void Update(float dt);
    void Draw();

    bool isDestroyed;

private:
    Vector2 m_position;
    Vector2 m_target;
    Texture2D m_texture;
    int m_damage;
    int m_range;
    int m_bulletSpeed;
};