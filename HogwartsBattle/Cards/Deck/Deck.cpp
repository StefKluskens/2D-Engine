#include "Deck.h"
#include "../CardComponent.h"
#include "../2D-SDL-Engine/SceneGraph/GameObject.h"
#include "../2D-SDL-Engine/Components/TextureComponent.h"
#include <random>

HB::Deck::Deck(Engine::GameObject* pObject, bool shouldShuffle)
	: Engine::BaseComponent(pObject)
	, m_ShouldShuffle(shouldShuffle)
{
	const auto pos = GetOwner()->GetTransform()->GetWorldPosition();
	const auto texturePtr = pObject->GetComponent<Engine::TextureComponent>();
	m_CardRect.x = static_cast<int>(pos.x);
	m_CardRect.y = static_cast<int>(pos.y);
	m_CardRect.w = static_cast<int>(texturePtr->GetTextureSize().x);
	m_CardRect.h = static_cast<int>(texturePtr->GetTextureSize().y);
}

void HB::Deck::AddCard(CardComponent* CardPtr)
{
	m_Cards.push_back(CardPtr);
}

void HB::Deck::Shuffle()
{
	std::random_device rd{};
	std::mt19937 gen(rd());

	std::shuffle(m_Cards.begin(), m_Cards.end(), gen);
}