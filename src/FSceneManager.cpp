#include "FSceneManager.h"

FSceneManager::FSceneManager()
{
    m_loadadSceneCount = 0;
    m_sceneCount = 0;
    m_active_scene = -1;
}

int FSceneManager::AddScene(FScene scene)
{
    m_sceneList.push_back(scene);
    m_sceneCount += 1;
    return m_sceneList.size() - 1;
}

int FSceneManager::RemoveScene(int index)
{
    m_sceneList.erase(m_sceneList.begin() + index);
    m_sceneCount -= 1;
    return index;
}

FScene FSceneManager::GetScene(int index)
{
    return m_sceneList[index];
}

FScene FSceneManager::GetActiveScene()
{
    return m_sceneList[m_active_scene];
}

int FSceneManager::LoadScene(int index)
{
    m_active_scene = index;
    return index;
}
