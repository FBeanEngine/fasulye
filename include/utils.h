#pragma once
#include "raylib.h"

Vector2 Vector2Distance(Vector2 a, Vector2 b);

Vector2 LerpVector2(Vector2 a, Vector2 b, float t);

Vector2 SmoothDamp(Vector2 current, Vector2 target, Vector2 *currentVelocity, float smoothTime, float maxSpeed, float deltaTime);