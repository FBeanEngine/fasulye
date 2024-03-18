#pragma once
#include "FObject.h"
#include "FAnimation.h"
#include "FAnimationClip.h"

class FItem : public FObject
{
public:
    FItem(Vector2 position, Texture2D texture);
    ~FItem() override;
    void Draw(float dt) override;
    void Physics(std::string tag) override;

private:
    FAnimation m_animation;
};