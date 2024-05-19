#pragma once
#include "CardComponent.h"

namespace HB
{
	class DarkArtsCardComponent final : public CardComponent
	{
		enum class CardEffect 
		{
			LoseHealth,
			DiscardCard,
			NoExtraCards,
			AddControl
		};

	public:
		DarkArtsCardComponent(Engine::GameObject* pObject, const std::string& cardName);
		virtual ~DarkArtsCardComponent() = default;
		DarkArtsCardComponent(const DarkArtsCardComponent& other) = delete;
		DarkArtsCardComponent(DarkArtsCardComponent&& other) noexcept = delete;
		DarkArtsCardComponent& operator=(const DarkArtsCardComponent& other) = delete;
		DarkArtsCardComponent& operator=(DarkArtsCardComponent&& other) = delete;

		void Start() override;
		void Render() const override;
		void Update(float /*deltaTime*/) override {};
		void FixedUpdate(float /*deltaTime*/) override {};

		void SetEffects(int healthToLose, int cardsToDiscard, int controlToAdd, bool noExtraCards);

		void CardClicked() override;
		void PlayCard() override;

	private:
		int m_HealthToLose;
		int m_CardsToDiscard;
		int m_ControlToAdd;
		bool m_NoExtraCards;
	};
}