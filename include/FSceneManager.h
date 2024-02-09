#pragma once
#include <vector>
#include "FScene.h"

class FSceneManager
{
public:
    FSceneManager();
    int AddScene(FScene scene);
    int RemoveScene(int index);
    FScene GetScene(int index);

    FScene GetActiveScene();
    int LoadScene(int index);

private:
    uint8_t m_loadadSceneCount;
    uint8_t m_sceneCount;

    int m_active_scene;
    std::vector<FScene> m_sceneList;
};