#include "CardComponent.h"
#include "Observer/Observer.h"
#include "../2D-SDL-Engine/SceneGraph/GameObject.h"
#include "../2D-SDL-Engine/Components/TextureComponent.h"

HB::CardComponent::CardComponent(Engine::GameObject* pObject)
	: Engine::BaseComponent(pObject)
	, m_CardClicked(false)
	, m_IsActive(false)
	, m_OnTopOfDeck(false)
	, m_CardRect()
{
	const auto pos = GetOwner()->GetTransform()->GetWorldPosition();
	const auto texturePtr = pObject->GetComponent<Engine::TextureComponent>();

	if (texturePtr)
	{
		m_CardRect.x = static_cast<int>(pos.x);
		m_CardRect.y = static_cast<int>(pos.y);
		m_CardRect.w = static_cast<int>(texturePtr->GetTextureSize().x);
		m_CardRect.h = static_cast<int>(texturePtr->GetTextureSize().y);
	}
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