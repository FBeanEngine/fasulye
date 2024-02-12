#pragma once
#include "enums.h"
#include "raylib.h"

class FInputManager
{

public:
    FInputManager();

    PerformedAction GetPerfomedAction();
    Vector2 GetMovementVector();
    Vector2 GetAimVector(Vector2 origin);
};
