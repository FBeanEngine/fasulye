#pragma once
#include "raylib.h"
#include <string>
#include "enums.h"

struct CanMove
{
    bool up;
    bool down;
    bool left;
    bool right;
};

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

struct FUIEvent
{
    std::string componentName;
    UIComponentState eventType;
};