#pragma once
#include "raylib.h"
#include "FObject.h"
#include "FAmmo.h"
#include <vector>
#include <memory>

class FGun : public FObject
{
public:
    FGun();
    ~FGun();
    void Shoot(Vector2 target);
    void Update(float dt) override;
    void Draw(float dt) override;
    void SetPosition(Vector2 position);
    void SetRotation(float rotation);
    void SetTexture(Texture2D texture);
    void SetFireRate(int fireRate);
    void SetOwner(FObject *const owner);

private:
    FObject *m_owner;
    Vector2 m_position;
    float m_rotation;
    Texture2D m_texture;
    int m_fireRate;
    std::vector<std::unique_ptr<FAmmo>> m_ammos;
};