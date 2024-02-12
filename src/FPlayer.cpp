#include "FPlayer.h"
#include "raylib.h"
#include <iostream>

FPlayer::FPlayer(Vector2 position)
{
    this->position = position;
    m_hp = 100;
    m_activeGun = -1;
    isDead = false;

    texture = LoadTexture("resources/assets/idle.png");
    this->position.y -= texture.height / 2 * 5;
    this->position.x -= texture.width / 2 * 5;
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
    }
    else
    {
        this->position.x += movementVector.x * 5;
        this->position.y += movementVector.y * 5;
    }

    // std::cout << "Aim vector: " << aimVector.x << ", " << aimVector.y << std::endl;
}

void FPlayer::Draw()
{
    // std::cout << "Draw call for player" << std::endl;
    // DrawCircle(this->position.x, this->position.y, 50, RED);
    DrawTextureEx(texture, this->position, 0.0f, 5.0f, WHITE);
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
