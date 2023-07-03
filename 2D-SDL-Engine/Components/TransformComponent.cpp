#include "TransformComponent.h"

Engine::TransformComponent::TransformComponent(GameObject* pObject)
	: BaseComponent(pObject)
{
}

const glm::vec3& Engine::TransformComponent::GetWorldPosition()
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


	}
}

void Engine::TransformComponent::SetLocalPosition(const glm::vec3& pos)
{
	m_LocalPosition = pos;
	SetPositionDirty();
}

void Engine::TransformComponent::SetPositionDirty()
{
	m_PositionIsDirty = true;
}
