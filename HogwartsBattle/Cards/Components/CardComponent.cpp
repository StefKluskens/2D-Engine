#include "CardComponent.h"
#include "Observer/Observer.h"
#include "../2D-SDL-Engine/SceneGraph/GameObject.h"
#include "../2D-SDL-Engine/Components/TextureComponent.h"
#include <iostream>

HB::CardComponent::CardComponent(Engine::GameObject* pObject, const std::string& cardName)
	: Engine::BaseComponent(pObject)
	, m_CardClicked(false)
	, m_IsActive(false)
	, m_OnTopOfDeck(false)
	, m_CardRect()
	, m_CardName(cardName)
{
}

bool HB::CardComponent::IsPointInCard(const glm::vec2& pos)
{
	SDL_Point point{ static_cast<int>(pos.x), static_cast<int>(pos.y) };
	return SDL_PointInRect(&point, &m_CardRect);
}

bool HB::CardComponent::IsPointInCard(const float X, const float Y)
{
	SDL_Point point{ static_cast<int>(X), static_cast<int>(Y) };
	return SDL_PointInRect(&point, &m_CardRect);
}

bool HB::CardComponent::IsPointInCard(const int X, const int Y)
{
	SDL_Point point{ X, Y };
	return SDL_PointInRect(&point, &m_CardRect);
}

void HB::CardComponent::CreateCardRect()
{
	const auto pos = m_pOwner->GetTransform()->GetWorldPosition();
	const auto texturePtr = m_pOwner->GetComponent<Engine::TextureComponent>();

	if (texturePtr)
	{
		m_CardRect.x = static_cast<int>(pos.x);
		m_CardRect.y = static_cast<int>(pos.y);
		m_CardRect.w = static_cast<int>(texturePtr->GetTextureSize().x);
		m_CardRect.h = static_cast<int>(texturePtr->GetTextureSize().y);
	}
}
