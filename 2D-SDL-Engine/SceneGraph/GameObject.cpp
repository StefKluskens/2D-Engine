#include "GameObject.h"
#include "Scene.h"

Engine::GameObject::GameObject(std::string name, Scene* pScene)
	: m_Name(name)
	, m_pScene(pScene)
{
	m_pTransform = std::make_unique<Engine::TransformComponent>(this);
}

void Engine::GameObject::Update(float deltaTime)
{
	for (size_t i = 0; i < m_pChildren.size(); ++i)
	{
		m_pChildren[i]->Update(deltaTime);
	}

	for (size_t i = 0; i < m_pComponents.size(); ++i)
	{
		m_pComponents[i]->Update(deltaTime);
	}
}

void Engine::GameObject::FixedUpdate(float deltaTime)
{
	for (size_t i = 0; i < m_pChildren.size(); ++i)
	{
		m_pChildren[i]->FixedUpdate(deltaTime);
	}

	for (size_t i = 0; i < m_pComponents.size(); ++i)
	{
		m_pComponents[i]->FixedUpdate(deltaTime);
	}
}

void Engine::GameObject::Render() const
{
	for (size_t i = 0; i < m_pChildren.size(); ++i)
	{
		m_pChildren[i]->Render();
	}

	for (size_t i = 0; i < m_pComponents.size(); ++i)
	{
		m_pComponents[i]->Render();
	}
}

void Engine::GameObject::AddComponent(std::unique_ptr<BaseComponent> pComponent)
{
	m_pComponents.emplace_back(std::move(pComponent));
}

const std::string Engine::GameObject::GetName() const
{
	return m_Name;
}

void Engine::GameObject::SetName(const std::string& name)
{
	m_Name = name;
}

void Engine::GameObject::SetParent(GameObject* pParent, bool keepWorldPos)
{
	if (pParent == nullptr)
	{
		m_pTransform->SetLocalPosition(m_pTransform->GetWorldPosition());
	}
	else
	{
		if (keepWorldPos)
		{
			auto parentTransform = pParent->GetTransform()->GetWorldPosition();
			m_pTransform->SetLocalPosition(m_pTransform->GetLocalPosition() + parentTransform);
		}

		m_pTransform->SetPositionDirty();

		std::unique_ptr<GameObject> child;

		if (m_pParent != nullptr)
		{
			for (auto it = m_pParent->m_pChildren.begin(); it != m_pParent->m_pChildren.end(); ++it)
			{
				if (it->get() == this)
				{
					child = std::move(*it);
					m_pParent->m_pChildren.erase(it);
					break;
				}
			}
		}

		m_pParent = pParent;

		if (m_pParent != nullptr)
		{
			if (child == nullptr)
			{
				child = std::unique_ptr<GameObject>(this);
			}
			m_pParent->m_pChildren.emplace_back(std::move(child));
		}
	}
}

const Engine::GameObject* Engine::GameObject::GetChildByName(const std::string& name) const
{
	for (const auto& child : m_pChildren)
	{
		if (child->GetName() == name)
		{
			return child.get();
		}
	}
	return nullptr;
}

void Engine::GameObject::SetPosition(float x, float y)
{
	m_pTransform->SetLocalPosition(glm::vec2(x, y));
}

void Engine::GameObject::SetPosition(int x, int y)
{
	m_pTransform->SetLocalPosition(glm::vec2(x, y));
}

void Engine::GameObject::SetPosition(glm::vec2 pos)
{
	m_pTransform->SetLocalPosition(pos);
}
