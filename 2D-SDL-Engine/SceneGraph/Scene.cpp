#include "Scene.h"
#include "GameObject.h"

Engine::Scene::Scene(const std::string& name)
	: m_Name(name)
{
}

void Engine::Scene::Update(float deltaTime)
{
	for (size_t i = 0; i < m_pObjects.size(); ++i)
	{
		m_pObjects[i]->Update(deltaTime);
	}
}

void Engine::Scene::FixedUpdate(float deltaTime)
{
	for (size_t i = 0; i < m_pObjects.size(); ++i)
	{
		m_pObjects[i]->FixedUpdate(deltaTime);
	}
}

void Engine::Scene::Render()
{
	for (size_t i = 0; i < m_pObjects.size(); ++i)
	{
		m_pObjects[i]->Render();
	}
}

void Engine::Scene::AddObject(std::shared_ptr<GameObject> pObject)
{
	m_pObjects.push_back(pObject);
}
