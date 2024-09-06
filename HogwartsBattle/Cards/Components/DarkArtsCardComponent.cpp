#include "DarkArtsCardComponent.h"
#include <SDL_render.h>
#include "Renderer/Renderer.h"
#include "SceneGraph/GameObject.h"
#include "../2D-SDL-Engine/Components/TextureComponent.h"
#include "../../Managers/GameManager.h"
#include "SceneGraph/GameObject.h"
#include "../Effects/CardEffects.h"
#include <iostream>

HB::DarkArtsCardComponent::DarkArtsCardComponent(Engine::GameObject* pObject, const std::string& cardName)
	: CardComponent(pObject, cardName)
{
	m_pOwner->SetPosition(933.0f, 135.0f);
}

void HB::DarkArtsCardComponent::Start()
{
	CreateCardRect();
}

void HB::DarkArtsCardComponent::Render() const
{
}

void HB::DarkArtsCardComponent::SetEffects(int healthToLose, int cardsToDiscard, int controlToAdd, bool noExtraCards)
{
	m_HealthToLose = healthToLose;
	m_CardsToDiscard = cardsToDiscard;
	m_ControlToAdd = controlToAdd;
	m_NoExtraCards = noExtraCards;
}

void HB::DarkArtsCardComponent::CardClicked()
{
	std::cout << "Dark Arts Card: " << m_CardName <<  " clicked\n";
}

void HB::DarkArtsCardComponent::PlayCard()
{
	auto previousCard = GameManager::GetInstance().GetDarkArtsCard();
	if (previousCard)
	{
		previousCard->m_pOwner->SetActive(false);
	}	

	GameManager::GetInstance().SetDarkArtsCard(this);

	m_pOwner->SetActive(true);

	std::cout<<"Played Dark Arts Card: " << m_CardName << "\n";

	for (size_t i = 0; i < m_CardEffects.size(); ++i)
	{
		m_CardEffects[i]->PlayEffect(nullptr);
	}
}