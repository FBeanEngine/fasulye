#pragma once
#include <vector>
#include <memory>
#include "FUI.h"

class FCanvas {
    public:
    FCanvas();
    ~FCanvas();
    std::vector<FUIEvent> Draw();
    int AddUIComponent(std::unique_ptr<FUI> component);
    FUI GetUIComponent(int index);
    int RemoveUIComponent(int index);
    private:
    std::vector<std::unique_ptr<FUI>> m_ui;
};