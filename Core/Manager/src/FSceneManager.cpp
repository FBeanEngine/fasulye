#include "FSceneManager.h"
#include <memory>
#include <thread>

// initialize static variables
int FSceneManager::m_loadadSceneCount = 0;
int FSceneManager::m_sceneCount = 0;
int FSceneManager::m_active_scene = -1;
std::vector<std::unique_ptr<FScene>> FSceneManager::m_sceneList;
std::future<void> FSceneManager::m_mapLoaderThread;

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
    m_sceneList[index]->Init();
    return index;
}

int FSceneManager::LoadScene(int index)
{
    m_mapLoaderThread = std::async(std::launch::async, &FScene::BeforeLoad, m_sceneList[index].get());
    // m_active_scene = index;
    return index;
}

bool FSceneManager::IsSceneReady()
{
    bool is_ready = m_mapLoaderThread.wait_for(std::chrono::seconds(0)) == std::future_status::ready;
    if (is_ready)
    {
        m_loadadSceneCount += 1;
        // TODO: burası şu an sürekli 1 yapıyor burayı dinamik yap
        m_active_scene = 1;
        m_sceneList[m_active_scene]->Init();
    }
    return is_ready;
}

void FSceneManager::AddObjectToActiveScene(std::unique_ptr<FObject> object)
{
    m_sceneList[m_active_scene]->AddObject(std::move(object));
}
