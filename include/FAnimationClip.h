#pragma once
#include <vector>
#include <string>
#include "raylib.h"

class FAnimationClip
{
public:
    FAnimationClip(const char *fileName, int frame, int width, int height, int speed, bool inverse, bool wihoutBlock);
    ~FAnimationClip();
    void Play(Vector2 position, float dt);

public:
    std::vector<Rectangle> clip;
    int speed;
    int frame;
    float counter;
    int width;
    int height;
    bool withoutBlock;
    bool isFinished;
    Texture2D tileset;
};