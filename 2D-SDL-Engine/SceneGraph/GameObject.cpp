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

		/*std::unique_ptr<GameObject> child;

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
		}*/
	}
}
