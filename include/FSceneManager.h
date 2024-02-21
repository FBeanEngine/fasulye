#pragma once
#include <vector>
#include <memory>
#include "FScene.h"

class FSceneManager
{
public:
    FSceneManager();
    static int AddScene(std::unique_ptr<FScene> scene);
    static int RemoveScene(int index);
    static std::unique_ptr<FScene> GetScene(int index);

    static std::unique_ptr<FScene> &GetActiveScene();
    static int SetActiveScene(int index);
    static int LoadScene(int index);
    static void AddObjectToActiveScene(std::unique_ptr<FObject> object);

private:
    static int m_loadadSceneCount;
    static int m_sceneCount;

    static int m_active_scene;
    static std::vector<std::unique_ptr<FScene>> m_sceneList;
};