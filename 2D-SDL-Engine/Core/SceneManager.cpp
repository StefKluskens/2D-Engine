#include "SceneManager.h"
#include "../SceneGraph/Scene.h"

Engine::Scene& Engine::SceneManager::CreateScene(const std::string& name)
{
    const auto& scene = std::shared_ptr<Scene>(new Scene(name));
    m_pScenes.push_back(scene);
    return *scene;
}

void Engine::SceneManager::Start()
{
    if (m_pActiveScene)
    {
		m_pActiveScene->Start();
	}
}

void Engine::SceneManager::Update(float deltaTime)
{
    if (m_pActiveScene)
    {
        m_pActiveScene->Update(deltaTime);
    }
}

void Engine::SceneManager::FixedUpdate(float deltaTime)
{
    if (m_pActiveScene)
    {
        m_pActiveScene->FixedUpdate(deltaTime);
    }
}

void Engine::SceneManager::Render()
{
    if (m_pActiveScene)
    {
        m_pActiveScene->Render();
    }
}

void Engine::SceneManager::OnGuiRender()
{
    if (m_pActiveScene)
    {
        m_pActiveScene->OnGuiRender();
    }
}

void Engine::SceneManager::SetActiveScene(Scene* scene)
{
    m_pActiveScene = scene;
}
