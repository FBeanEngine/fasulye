#pragma once
#include "raylib.h"
#include "FObject.h"
#include <vector>
#include "FAmmo.h"

class FGun : public FObject
{
public:
    FGun();
    void Shoot(Vector2 target);
    void Update(Vector2 position, float dt);
    void Draw(float dt);
    void SetPosition(Vector2 position);
    void SetRotation(float rotation);
    void SetTexture(Texture2D texture);
    void SetFireRate(int fireRate);

private:
    Vector2 m_position;
    float m_rotation;
    Texture2D m_texture;
    int m_fireRate;
    std::vector<FAmmo> m_ammos;
};