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
    void setScale(int scale);
    void setOffset(Vector2 offset);

public:
    std::vector<Rectangle> clip;
    int scale;
    Vector2 offset;
    int speed;
    int frame;
    float counter;
    int width;
    int height;
    bool withoutBlock;
    bool isFinished;
    Texture2D tileset;
};