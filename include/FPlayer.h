#pragma once
#include "FInputManager.h"
#include "FItem.h"
#include "FObject.h"
#include "raylib.h"
#include "FAnimation.h"

class FPlayer : public FObject
{
public:
    FPlayer(Vector2 position);
    // FPlayer(Vector2 position, Texture texture);
    void AddItem(FItem item);
    void TakeDamage(int damage);
    int GetHP();
    int Attack();

    void Update();
    void Draw(float dt);

    FAnimation animation;

private:
    FInputManager m_inputManager;
    std::vector<FItem> m_inventory;
    int m_hp;
    std::vector<FItem> m_activeGuns;
    int m_activeGun;
    bool isDead;
};