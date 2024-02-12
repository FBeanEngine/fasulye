#include "FInputManager.h"
#include "math.h"

FInputManager::FInputManager() {}

Vector2 FInputManager::GetAimVector(Vector2 origin)
{
    Vector2 mousePosition = GetMousePosition();
    double rad = atan2(mousePosition.y - origin.y, mousePosition.x - origin.x);

    return {(float)cos(rad), (float)sin(rad)};
}

Vector2 FInputManager::GetMovementVector()
{
    Vector2 movementVector = {0, 0};

    if (IsKeyDown(KEY_A))
        movementVector.x = -1;
    else if (IsKeyDown(KEY_D))
        movementVector.x = 1;

    if (IsKeyDown(KEY_W))
        movementVector.y = -1;
    else if (IsKeyDown(KEY_S))
        movementVector.y = 1;

    return movementVector;
}

PerformedAction FInputManager::GetPerfomedAction()
{
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        return PerformedAction::LeftHandUse;
    }

    if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
    {
        return PerformedAction::RightHandUse;
    }

    return PerformedAction::NoneAction;
}
