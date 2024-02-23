#pragma once
#include "FScene.h"

class FMainMenu : public FScene
{
public:
    FMainMenu();
    ~FMainMenu();
    void Init();
    void Render(float dt) override;

private:
    bool m_isActive;
    bool m_isLoaded;
    std::string m_name;
    int m_index;
};