#include "Deck.h"
#include "../Components/CardComponent.h"
#include "../2D-SDL-Engine/SceneGraph/GameObject.h"
#include "../2D-SDL-Engine/Components/TextureComponent.h"
#include <random>
#include <iostream>
#include "../../Managers/GameManager.h"

HB::Deck::Deck(Engine::GameObject* pObject, bool shouldShuffle)
	: Engine::BaseComponent(pObject)
	, m_ShouldShuffle(shouldShuffle)
{
	m_pOwner->SetPosition(750.0f, 135.0f);

	const auto pos = m_pOwner->GetTransform()->GetWorldPosition();
	const auto texturePtr = m_pOwner->GetComponent<Engine::TextureComponent>();

	if (texturePtr)
	{
		m_DeckRect.x = static_cast<int>(pos.x);
		m_DeckRect.y = static_cast<int>(pos.y);
		m_DeckRect.w = static_cast<int>(texturePtr->GetTextureSize().x);
		m_DeckRect.h = static_cast<int>(texturePtr->GetTextureSize().y);
	}
}

void HB::Deck::AddCard(CardComponent* CardPtr)
{
	m_Cards.push_back(CardPtr);
}

void HB::Deck::Shuffle()
{
	std::random_device rd{};
	std::mt19937 gen(rd());

	if (m_Cards.empty())
	{
		for (size_t i = 0; i < m_PlayedCards.size(); ++i)
		{
			auto card = m_PlayedCards[i];
			m_PlayedCards.erase(m_PlayedCards.begin() + i);
			m_Cards.push_back(card);
		}
	}

	std::shuffle(m_Cards.begin(), m_Cards.end(), gen);
}

void HB::Deck::DeckClicked()
{
	if (GameManager::GetInstance().GetState() == GameState::DarkArtsEvent)
	{
		DealCard();
		GameManager::GetInstance().SetState(GameState::Villains);
	}
}

void HB::Deck::DealCard()
{
	auto card = m_Cards.front();

	card->PlayCard();

	m_Cards.erase(m_Cards.begin());

	if (card)
	{
		m_PlayedCards.push_back(card);
	}
}

bool HB::Deck::IsPointInDeck(const glm::vec2& pos)
{
	SDL_Point point{ static_cast<int>(pos.x), static_cast<int>(pos.y) };
	return SDL_PointInRect(&point, &m_DeckRect);
}

bool HB::Deck::IsPointInDeck(const float X, const float Y)
{
	SDL_Point point{ static_cast<int>(X), static_cast<int>(Y) };
	return SDL_PointInRect(&point, &m_DeckRect);
}

bool HB::Deck::IsPointInDeck(const int X, const int Y)
{
	SDL_Point point{ X, Y };
	return SDL_PointInRect(&point, &m_DeckRect);
}