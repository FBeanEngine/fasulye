#include "FInputManager.h"
#include "FCamera.h"
#include <cmath>

FInputManager::FInputManager() {}

Vector2 FInputManager::GetAimVector(Vector2 origin)
{
    Vector2 mousePosition = GetScreenToWorld2D(GetMousePosition(), FCamera::GetCamera());

    Vector2 direction = {mousePosition.x - origin.x, origin.y - mousePosition.y};
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    return {direction.x / length, direction.y / length};
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
