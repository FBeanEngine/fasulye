#include "FCanvas.h"

FCanvas::FCanvas()
{
    // todo: Constructor function
}

FCanvas::~FCanvas()
{
    // todo: Deconstructor function
}

std::vector<FUIEvent> FCanvas::Draw()
{
    std::vector<FUIEvent> events;
    for (int i = 0; i < m_ui.size(); i++)
    {
        events.push_back(m_ui[i]->Logic());
        m_ui[i]->Draw();
    }
    return events;
}

int FCanvas::AddUIComponent(std::unique_ptr<FUI> component)
{
    m_ui.push_back(component);
    return m_ui.size() - 1;
}

FUI FCanvas::GetUIComponent(int index)
{
    if (index >= m_ui.size())
    {
        return *m_ui[0];
    }
    else if (index < 0)
    {
        return *m_ui[0];
    }

    return *m_ui[index];
}

int FCanvas::RemoveUIComponent(int index)
{
    if (index >= m_ui.size())
    {
        return 1;
    }
    else if (index < 0)
    {
        return 1;
    }

    m_ui.erase(m_ui.begin() + index);
    return 0;
}