#pragma once

#include "FSceneManager.h"
class FGame
{
public:
    FGame();
    ~FGame();
    void Run();
private:
    FSceneManager SceneMenager;
};