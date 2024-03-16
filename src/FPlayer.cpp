#include "FPlayer.h"
#include "raylib.h"
#include <iostream>
#include "FObject.h"
#include "FAnimation.h"
#include "FAnimationClip.h"
#include "FShader.h"
#include "FSceneManager.h"
#include "raymath.h"
FPlayer::FPlayer(Vector2 position)
{
    this->position = position;
    m_hp = 100;
    m_activeGun = -1;
    isDead = false;
    lastMovementDirection = "right";

    // ----- upper body animation -----

    FAnimationClip forwardAnim = FAnimationClip("resources/assets/up_forward.png", 1, 32, 32, 1, false, false);
    forwardAnim.setScale(5);
    up_animation.AddAnimation("forward", forwardAnim);

    FAnimationClip forwardRightAnim = FAnimationClip("resources/assets/up_forward_right.png", 1, 32, 32, 1, false, false);
    forwardRightAnim.setScale(5);
    up_animation.AddAnimation("forward_right", forwardRightAnim);

    FAnimationClip rightAnim = FAnimationClip("resources/assets/up_right.png", 1, 32, 32, 1, false, false);
    rightAnim.setScale(5);
    up_animation.AddAnimation("right", rightAnim);

    FAnimationClip backRightAnim = FAnimationClip("resources/assets/up_back_right.png", 1, 32, 32, 1, false, false);
    backRightAnim.setScale(5);
    up_animation.AddAnimation("back_right", backRightAnim);

    FAnimationClip backAnim = FAnimationClip("resources/assets/up_back.png", 1, 32, 32, 1, false, false);
    backAnim.setScale(5);
    up_animation.AddAnimation("back", backAnim);

    FAnimationClip backLeftAnim = FAnimationClip("resources/assets/up_back_left.png", 1, 32, 32, 1, false, false);
    backLeftAnim.setScale(5);
    up_animation.AddAnimation("back_left", backLeftAnim);

    FAnimationClip leftAnim = FAnimationClip("resources/assets/up_left.png", 1, 32, 32, 1, false, false);
    leftAnim.setScale(5);
    up_animation.AddAnimation("left", leftAnim);

    FAnimationClip forwardLeftAnim = FAnimationClip("resources/assets/up_forward_left.png", 1, 32, 32, 1, false, false);
    forwardLeftAnim.setScale(5);
    up_animation.AddAnimation("forward_left", forwardLeftAnim);

    // ----- lower body animation -----

    FAnimationClip forwardAnimDown = FAnimationClip("resources/assets/down_forward.png", 1, 32, 32, 1, false, false);
    forwardAnimDown.setScale(5);
    forwardAnimDown.setOffset({0, 12});
    down_animation.AddAnimation("forward", forwardAnimDown);

    FAnimationClip rightAnimDown = FAnimationClip("resources/assets/down_right.png", 1, 32, 32, 1, false, false);
    rightAnimDown.setScale(5);
    rightAnimDown.setOffset({0, 12});
    down_animation.AddAnimation("right", rightAnimDown);

    FAnimationClip backAnimDown = FAnimationClip("resources/assets/down_back.png", 1, 32, 32, 1, false, false);
    backAnimDown.setScale(5);
    backAnimDown.setOffset({0, 12});
    down_animation.AddAnimation("back", backAnimDown);

    FAnimationClip leftAnimDown = FAnimationClip("resources/assets/down_left.png", 1, 32, 32, 1, false, false);
    leftAnimDown.setScale(5);
    leftAnimDown.setOffset({0, 12});
    down_animation.AddAnimation("left", leftAnimDown);

    std::unique_ptr<FGun> gun(new FGun());
    gun->SetOwner(this);
    gun->SetTexture(LoadTexture("resources/assets/gun.png"));
    FSceneManager::AddObjectToActiveScene(std::move(gun));

    // shader.FLoadShader("damage.fs", ShaderType::Fragment);
    // TraceLog(LOG_INFO, "Shader count: %d", shader.m_shaderCount);

    // shader.FLoadShader("wave.fs", ShaderType::Fragment);
    // shader.m_shaderFloatValues.push_back(0.0f);
    // TraceLog(LOG_INFO, "Shader count: %d", shader.m_shaderCount);

    // m_gun.SetTexture(LoadTexture("resources/assets/gun.png"));
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
    PerformedAction action = m_inputManager.GetPerfomedAction();

    if (movementVector.x != 0 && movementVector.y != 0)
    {
        // Diagnol movement
        this->position.x += movementVector.x * 75 * dt;
        this->position.y += movementVector.y * 75 * dt;
    }
    else if (movementVector.x != 0 || movementVector.y != 0)
    {
        //float beforeX = this->position.x;
        this->position.x += movementVector.x * 150 * dt;
        this->position.y += movementVector.y * 150 * dt;
    }
    float angle = Vector2LineAngle({this->position.x + 16 * 5, this->position.y + 16 * 5}, m_mousePosition) * 180 / PI + 180;

    // source: 8 direction movement angles from https://www.reddit.com/r/godot/comments/ypjiqs/it_might_be_helpful_360_degrees_for_godot_and_in/
    if (angle >= 22.5 && angle < 67.5)
    {
        up_animation.BindAnimation("back_left");
    }
    else if (angle >= 67.5 && angle < 112.5)
    {
        up_animation.BindAnimation("back");
    }
    else if (angle >= 112.5 && angle < 157.5)
    {
        up_animation.BindAnimation("back_right");
    }
    else if (angle >= 157.5 && angle < 202.5)
    {
        up_animation.BindAnimation("right");
    }
    else if (angle >= 202.5 && angle < 247.5)
    {
        up_animation.BindAnimation("forward_right");
    }
    else if (angle >= 247.5 && angle < 292.5)
    {
        up_animation.BindAnimation("forward");
    }
    else if (angle >= 292.5 && angle < 337.5)
    {
        up_animation.BindAnimation("forward_left");
    }
    else if (angle >= 337, 5 && angle <= 360 || angle >= 0 && angle < 22.5)
    {
        up_animation.BindAnimation("left");
    }

    if (movementVector.x > 0)
    {
        down_animation.BindAnimation("right");
        lastMovementDirection = "right";
    }
    else if (movementVector.x < 0)
    {
        down_animation.BindAnimation("left");
        lastMovementDirection = "left";
    }
    else if (movementVector.y < 0)
    {
        down_animation.BindAnimation("back");
        lastMovementDirection = "back";
    }
    else if (movementVector.y > 0)
    {
        down_animation.BindAnimation("forward");
        lastMovementDirection = "forward";
    }
    else
    {
        down_animation.BindAnimation(lastMovementDirection);
    }
    // m_gun.Update(dt);

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
        // shader.m_shaderFloatValues[0] += GetFrameTime();
        BeginShaderMode(shader.m_shaders[0]);
        // shader.FSetValue(0, GetShaderLocation(shader.m_shadKers[0], "seconds"), &shader.m_shaderFloatValues[0], SHADER_UNIFORM_FLOAT);
        down_animation.Animate(this->position, dt);
        up_animation.Animate(this->position, dt);
        EndShaderMode();
    }
    else
    {
        down_animation.Animate(this->position, dt);
        up_animation.Animate(this->position, dt);
    }
    // m_gun.Draw(dt);
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

void FPlayer::SetMousePosition(Vector2 mousePosition)
{
    m_mousePosition = mousePosition;
}
