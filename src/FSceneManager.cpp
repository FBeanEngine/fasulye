#include "FSceneManager.h"
#include <memory>

// initialize static variables
int FSceneManager::m_loadadSceneCount = 0;
int FSceneManager::m_sceneCount = 0;
int FSceneManager::m_active_scene = -1;
std::vector<std::unique_ptr<FScene>> FSceneManager::m_sceneList;

FSceneManager::FSceneManager()
{
    m_loadadSceneCount = 0;
    m_sceneCount = 0;
    m_active_scene = -1;
}

int FSceneManager::AddScene(std::unique_ptr<FScene> scene)
{
    m_sceneList.push_back(std::move(scene));
    m_sceneCount += 1;
    return m_sceneList.size() - 1;
}

int FSceneManager::RemoveScene(int index)
{
    m_sceneList.erase(m_sceneList.begin() + index);
    m_sceneCount -= 1;
    return index;
}

std::unique_ptr<FScene> FSceneManager::GetScene(int index)
{
    return std::move(m_sceneList[index]);
}

std::unique_ptr<FScene> &FSceneManager::GetActiveScene()
{
    return m_sceneList[m_active_scene];
}

int FSceneManager::SetActiveScene(int index)
{
    m_active_scene = index;
    return index;
}

int FSceneManager::LoadScene(int index)
{
    m_active_scene = index;
    return index;
}
