#pragma once
#include "FInputManager.h"
#include "FItem.h"
#include "FObject.h"
#include "raylib.h"
#include "FAnimation.h"
#include "FShader.h"
#include "FGun.h"
#include <memory>

class FPlayer : public FObject
{
public:
    FPlayer(Vector2 position);
    ~FPlayer();
    // FPlayer(Vector2 position, Texture texture);
    void AddItem(FItem item);
    void TakeDamage(int damage);
    int GetHP();
    int Attack();

    void Update(float dt);
    void Draw(float dt);
    void Physics(std::string tag, Rectangle collisionBox) override;

    FAnimation up_animation;
    FAnimation down_animation;
    void SetMousePosition(Vector2 mousePosition);

private:
    FInputManager m_inputManager;
    std::vector<FItem> m_inventory;
    int m_hp;
    std::vector<FItem> m_activeGuns;
    int m_activeGun;
    bool isDead;
    FShader shader;
    Vector2 m_mousePosition;
    std::string lastMovementDirection;
    Rectangle collisionArea;
};