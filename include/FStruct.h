#pragma once
#include "raylib.h"

struct FBoundingBox
{
    Vector2 min;
    Vector2 max;
};

struct FCameraViewport
{
    Vector2 topLeft;
    Vector2 bottomRight;
};
