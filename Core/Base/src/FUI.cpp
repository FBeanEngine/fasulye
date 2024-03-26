#include "FUI.h"
#include "FInputManager.h"

FUI::FUI(Vector2 position, Vector2 size, std::string name)
{
    m_position = position;
    m_size = size;
    m_name = name;
}

FUIEvent FUI::Logic()
{
    uiState = UIComponentState::NoneEvent;
    Vector2 mousePosition = FInputManager::GetMouse();

    if (CheckCollisionPointRec(mousePosition, {m_position.x, m_position.y, m_size.x, m_size.y}))
    {
        uiState = UIComponentState::MouseHover;
        if (FInputManager::GetPerfomedAction() == PerformedAction::LeftHandUse)
        {
            uiState = UIComponentState::MouseClicked;
        }
    }

    return {m_name, uiState};
}

void FUI::Draw()
{
    //* Populate in child clases
}