#include "CardComponent.h"
#include "Observer/Observer.h"
#include <iostream>

HB::CardComponent::CardComponent(Engine::GameObject* pObject)
	: Engine::BaseComponent(pObject)
	, m_CardClicked(false)
	, m_IsActive(false)
	, m_OnTopOfDeck(false)
{

}

void HB::CardComponent::CardClicked()
{
	std::cout << "Card clicked\n";
}
