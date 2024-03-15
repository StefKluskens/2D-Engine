#include "LocationCardComponent.h"
#include <iostream>

HB::LocationCardComponent::LocationCardComponent(Engine::GameObject* pObject, int MaxControl)
	: CardComponent(pObject)
	, MaxControl(MaxControl)
	, Control(0)
{
}

void HB::LocationCardComponent::CardClicked()
{
	std::cout << "Location Card clicked\n";
}

void HB::LocationCardComponent::AddControl(int amount)
{
	Control += amount;

	if (Control >= MaxControl)
	{
		int remainder = Control - MaxControl;
		LocationLost(remainder);
	}
}

void HB::LocationCardComponent::RemoveControl(int amount)
{
	Control -= amount;
}

void HB::LocationCardComponent::LocationLost(int remainder)
{
	std::cout << "Location lost\n";

	Control = 0;
	AddControl(remainder);
}
