#pragma once
#include "enums.h"
#include "raylib.h"

class FInputManager
{

public:
    FInputManager();

    static PerformedAction GetPerfomedAction();
    static Vector2 GetMovementVector();
    static Vector2 GetAimVector(Vector2 origin);
};
