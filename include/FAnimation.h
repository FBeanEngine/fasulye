#pragma once
#include <vector>
#include <string>
#include "raylib.h"
#include "FAnimationClip.h"

class FAnimation
{
public:
    FAnimation();
    ~FAnimation();
    void AddAnimation(std::string animationName, FAnimationClip clip);
    FAnimationClip *GetAnimation(std::string animationName);

    void Animate(Vector2 position, float dt);
    void BindAnimation(std::string animationName);
    bool IsAnimationFinished(std::string animationName);

protected:
    std::vector<std::string> m_animationsNames;
    std::vector<FAnimationClip> m_animations;
    std::string m_currentAnimation;
};