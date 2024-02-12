#include "FPlayer.h"
#include "raylib.h"
#include <iostream>
#include "FAnimation.h"
#include "FAnimationClip.h"

FPlayer::FPlayer(Vector2 position)
{
    this->position = position;
    m_hp = 100;
    m_activeGun = -1;
    isDead = false;

    FAnimationClip idleAnim = FAnimationClip("resources/assets/idle.png", 1, 96, 80, 1);
    animation.AddAnimation("idle", idleAnim);

    FAnimationClip rightAnim = FAnimationClip("resources/assets/run.png", 4, 96, 80, 5);
    animation.AddAnimation("right", rightAnim);
}

// FPlayer::FPlayer(Vector2 position, Texture texture){
// TODO
// }

void FPlayer::Update()
{
    // std::cout << "Update call for player" << std::endl;
    Vector2 movementVector = m_inputManager.GetMovementVector();
    Vector2 aimVector = m_inputManager.GetAimVector(this->position);
    // PerformedAction action = FInputManager::GetPerfomedAction(

    if (movementVector.x != 0 || movementVector.y != 0)
    {
        this->position.x += movementVector.x * 2.5f;
        this->position.y += movementVector.y * 2.5f;
        animation.BindAnimation("right");
    }
    else
    {
        this->position.x += movementVector.x * 5;
        this->position.y += movementVector.y * 5;
        animation.BindAnimation("idle");
    }

    // std::cout << "Aim vector: " << aimVector.x << ", " << aimVector.y << std::endl;
}

void FPlayer::Draw(float dt)
{
    // std::cout << "Draw call for player" << std::endl;
    // DrawCircle(this->position.x, this->position.y, 50, RED);
    // DrawTextureEx(texture, this->position, 0.0f, 5.0f, WHITE);

    animation.Animate(this->position, dt);
}

void FPlayer::AddItem(FItem item)
{
    m_inventory.push_back(item);
}

void FPlayer::TakeDamage(int damage)
{
    m_hp -= damage;
    if (m_hp <= 0)
    {
        isDead = true;
    }
}

int FPlayer::GetHP()
{
    return m_hp;
}

int FPlayer::Attack()
{
    if (m_activeGun >= 0)
    {
        // TODO: change damage when guns added
        return 25;
    }
    return 0;
}
