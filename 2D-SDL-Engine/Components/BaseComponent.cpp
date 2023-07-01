#include "BaseComponent.h"

Engine::BaseComponent::BaseComponent(GameObject* pObject)
	: m_pOwner(pObject)
{
}