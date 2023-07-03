#include "TransformComponent.h"
#include "../SceneGraph/GameObject.h"

Engine::TransformComponent::TransformComponent(GameObject* pObject)
	: BaseComponent(pObject)
	, m_LocalPosition(glm::vec2{ 0.0f, 0.0f })
{
	m_WorldPosition = GetWorldPosition();
}

const glm::vec2& Engine::TransformComponent::GetWorldPosition()
{
	if (m_PositionIsDirty)
	{
		UpdateWorldPosition();
	}

	return m_WorldPosition;
}

void Engine::TransformComponent::UpdateWorldPosition()
{
	if (m_PositionIsDirty)
	{
		auto pOwner = GetOwner();
		if (pOwner == nullptr)
		{
			return;
		}

		auto parent{ pOwner->GetParent() };
		if (parent == nullptr)
		{
			m_WorldPosition = m_LocalPosition;
		}
		else
		{
			auto transform = parent->GetTransform();
			if (transform)
			{
				m_WorldPosition = transform->GetWorldPosition() + m_LocalPosition;
			}
		}
		m_PositionIsDirty = false;
	}
}

void Engine::TransformComponent::SetLocalPosition(const glm::vec2& pos)
{
	m_LocalPosition = pos;
	SetPositionDirty();
}

void Engine::TransformComponent::SetPositionDirty()
{
	m_PositionIsDirty = true;
}
