#pragma once
#include <vector>
#include <memory>
#include "FScene.h"

class FSceneManager
{
public:
    FSceneManager();
    int AddScene(std::unique_ptr<FScene> scene);
    int RemoveScene(int index);
    std::unique_ptr<FScene> GetScene(int index);

    std::unique_ptr<FScene> &GetActiveScene();
    int SetActiveScene(int index);
    int LoadScene(int index);

private:
    int m_loadadSceneCount;
    int m_sceneCount;

    int m_active_scene;
    std::vector<std::unique_ptr<FScene>> m_sceneList;
};