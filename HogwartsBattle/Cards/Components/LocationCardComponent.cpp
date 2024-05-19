#include "LocationCardComponent.h"
#include "SceneGraph/GameObject.h"
#include "../2D-SDL-Engine/Components/TextureComponent.h"
#include <iostream>

HB::LocationCardComponent::LocationCardComponent(Engine::GameObject* pObject, int m_MaxControl, const std::string& cardName)
	: CardComponent(pObject, cardName)
	, m_MaxControl(m_MaxControl)
	, m_Control(0)
{
	m_pOwner->SetPosition(451.0f, 135.0f);
}

void HB::LocationCardComponent::Start()
{
	CreateCardRect();
}

void HB::LocationCardComponent::CardClicked()
{
	std::cout << "Location Card clicked\n";
}

void HB::LocationCardComponent::PlayCard()
{

}

void HB::LocationCardComponent::AddControl(int amount)
{
	m_Control += amount;

	if (m_Control >= m_MaxControl)
	{
		int remainder = m_Control - m_MaxControl;
		LocationLost(remainder);
	}
}

void HB::LocationCardComponent::RemoveControl(int amount)
{
	m_Control -= amount;
}

void HB::LocationCardComponent::LocationLost(int remainder)
{
	std::cout << "Location lost\n";

	m_Control = 0;
	AddControl(remainder);
}
