#pragma once

#include "FSceneManager.h"
class FGame
{
public:
    FGame(int width, int height);
    ~FGame();
    void Run();
private:
    FSceneManager SceneMenager;
    int m_width;
    int m_height;
};