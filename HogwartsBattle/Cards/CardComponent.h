#pragma once
#include "Components/BaseComponent.h"

namespace Engine
{
	class Observer;
}

namespace HB
{
	class CardComponent final : public Engine::BaseComponent
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

		void CardClicked();

	private:
		bool m_CardClicked;
		bool m_IsActive;
		bool m_OnTopOfDeck;
	};
}