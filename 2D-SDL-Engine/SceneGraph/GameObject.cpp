#include "GameObject.h"
#include "Scene.h"

Engine::GameObject::GameObject(std::string name, Scene* pScene)
	: m_Name(name)
	, m_pScene(pScene)
{
	//TODO: Add transform component
}

void Engine::GameObject::Update(float deltaTime)
{
	for (size_t i = 0; i < m_pComponents.size(); ++i)
	{
		m_pComponents[i]->Update(deltaTime);
	}
}

void Engine::GameObject::FixedUpdate(float deltaTime)
{
	for (size_t i = 0; i < m_pComponents.size(); ++i)
	{
		m_pComponents[i]->FixedUpdate(deltaTime);
	}
}

void Engine::GameObject::Render() const
{
	for (size_t i = 0; i < m_pComponents.size(); ++i)
	{
		m_pComponents[i]->Render();
	}
}

void Engine::GameObject::AddComponent(std::unique_ptr<BaseComponent> pComponent)
{
	m_pComponents.emplace_back(std::move(pComponent));
}
