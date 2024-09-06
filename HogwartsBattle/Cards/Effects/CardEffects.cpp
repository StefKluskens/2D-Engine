#include "CardEffects.h"
#include "../2D-SDL-Engine/SceneGraph/GameObject.h"
#include <iostream>
#include "../../Managers/GameManager.h"
#include "../../Components/HealthComponent.h"
#include "../../Cards/Components/LocationCardComponent.h"

HB::CardEffects::CardEffects()
{
}

HB::LoseHealthEffect::LoseHealthEffect(int healthToLose)
	: CardEffects()
	, m_HealthToLose(healthToLose)
{
}

void HB::LoseHealthEffect::PlayEffect(Engine::GameObject* pPlayer)
{
	if (!pPlayer)
	{
		std::cout << "Player pointer nullptr in LoseHealthEffect::PlayEffect\n";
		return;
	}

	auto healthComponent = pPlayer->GetComponent<HealthComponent>();

	if (!healthComponent)
	{
		std::cout << "Health component nullptr in LoseHealthEffect::PlayEffect\n";
		return;
	}

	healthComponent->RemoveHealth(m_HealthToLose);

	std::cout << "Player lost " << m_HealthToLose << " health\n";
	std::cout << "Player health: " << healthComponent->GetHealth() << '\n';
}

HB::AddControlEffect::AddControlEffect(int amountOfControl)
	: CardEffects()
	, m_ControlToAdd(amountOfControl)
{
}

void HB::AddControlEffect::PlayEffect(Engine::GameObject* pObject)
{
	if (!pObject)
	{
		std::cout << "Object pointer nullptr in AddControlEffect::PlayEffect\n";
		return;
	}

	auto locationCard = GameManager::GetInstance().GetLocationCard();

	if (!locationCard)
	{
		std::cout << "No active locationCard in AddControlEffect::PlayEffect\n";
		return;
	}

	locationCard->AddControl(m_ControlToAdd);
}
