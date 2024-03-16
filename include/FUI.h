#pragma once
#include "raylib.h"
#include "enums.h"
#include "FStruct.h"
#include <string>

class FUI
{
public:
    FUI(Vector2 position, Vector2 size, std::string name);
    FUIEvent Logic();
    void Draw();
    private:
    std::string m_name;
    Vector2 m_position;
    Vector2 m_size;
    UIComponentState uiState;
};