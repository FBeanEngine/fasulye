#include "FPlayer.h"
#include "raylib.h"
#include <iostream>
#include "FObject.h"
#include "FAnimation.h"
#include "FAnimationClip.h"
#include "FShader.h"

FPlayer::FPlayer(Vector2 position)
{
    this->position = position;
    m_hp = 100;
    m_activeGun = -1;
    isDead = false;

    FAnimationClip idleAnim = FAnimationClip("resources/assets/idle.png", 1, 96, 80, 1, false);
    animation.AddAnimation("idle", idleAnim);

    FAnimationClip rightAnim = FAnimationClip("resources/assets/run.png", 4, 96, 80, 5, false);
    animation.AddAnimation("right", rightAnim);

    FAnimationClip leftAnim = FAnimationClip("resources/assets/run_left.png", 4, 96, 80, 5, true);
    animation.AddAnimation("left", leftAnim);

    // shader.FLoadShader("grayscale.fs", ShaderType::Fragment);
    // TraceLog(LOG_INFO, "Shader count: %d", shader.m_shaderCount);
}

FPlayer::~FPlayer()
{
    std::cout << "FPlayer destructor: " << std::endl;
}

// FPlayer::FPlayer(Vector2 position, Texture texture){
// TODO
// }

void FPlayer::Update(float dt)
{
    // std::cout << "Update call for player" << std::endl;
    Vector2 movementVector = m_inputManager.GetMovementVector();
    Vector2 aimVector = m_inputManager.GetAimVector(this->position);
    // PerformedAction action = FInputManager::GetPerfomedAction(

    if (movementVector.x != 0 && movementVector.y != 0)
    {
        // Diagnol movement
        this->position.x += movementVector.x * 75 * dt;
        this->position.y += movementVector.y * 75 * dt;
    }
    else if (movementVector.x != 0 || movementVector.y != 0)
    {
        this->position.x += movementVector.x * 150 * dt;
        this->position.y += movementVector.y * 150 * dt;
        // animation.BindAnimation("left");
    }

    if (movementVector.x > 0)
    {
        animation.BindAnimation("right");
    }
    else if (movementVector.x < 0)
    {
        animation.BindAnimation("left");
    }
    else
    {
        animation.BindAnimation("idle");
    }

    // std::cout << "Aim vector: " << aimVector.x << ", " << aimVector.y << std::endl;
}

void FPlayer::Draw(float dt)
{
    // std::cout << "Draw call for player" << std::endl;
    // DrawCircle(this->position.x, this->position.y, 50, RED);
    // DrawTextureEx(texture, this->position, 0.0f, 5.0f, WHITE);
    // TraceLog(LOG_INFO, "Shader count: %d", shader.m_shaderCount);
    if (shader.m_shaderCount > 0)
    {
        BeginShaderMode(shader.m_shaders[0]);
        animation.Animate(this->position, dt);
        EndShaderMode();
    }
    else
    {
        animation.Animate(this->position, dt);
    }
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
