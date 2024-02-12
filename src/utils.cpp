#include "utils.h"

Vector2 LerpVector2(Vector2 a, Vector2 b, float t)
{
    return Vector2{a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t};
}