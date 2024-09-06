#include "HealthComponent.h"

HB::HealthComponent::HealthComponent(Engine::GameObject* pObject, int initialHealth)
	: Engine::BaseComponent(pObject)
	, m_Health(initialHealth)
{
}