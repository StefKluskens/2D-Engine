#pragma once
#include "Components/BaseComponent.h"
#include "SDL_rect.h"

namespace Engine
{
	class Observer;
}

namespace HB
{
	class CardComponent : public Engine::BaseComponent
	{
	public:
		CardComponent(Engine::GameObject* pObject);
		virtual ~CardComponent() = default;
		CardComponent(const CardComponent& other) = delete;
		CardComponent(CardComponent&& other) noexcept = delete;
		CardComponent& operator=(const CardComponent& other) = delete;
		CardComponent& operator=(CardComponent&& other) = delete;

		void Render() const override {};
		void Update(float /*deltaTime*/) override {};
		void FixedUpdate(float /*deltaTime*/) override {};

		virtual void CardClicked() = 0;
		bool IsPointInCard(const glm::vec2& pos);
		bool IsPointInCard(const float X, const float Y);

		const SDL_Rect& GetCardRect() const { return m_CardRect; }
		const bool IsOnTopOfDeck() const { return m_OnTopOfDeck; }
		const bool IsActive() const { return m_IsActive; }

	protected:
		bool m_CardClicked;
		bool m_IsActive;
		bool m_OnTopOfDeck;

		SDL_Rect m_CardRect;
	};

	/*
	* Card types:
	* Dark arts
	* Location
	* Enemies
	* Heroes
	* Proficiency
	* Horcruxes
	* Spell
	* Item
	* Ally
	*/
}