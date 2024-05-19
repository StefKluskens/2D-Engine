#pragma once
#include "Components/BaseComponent.h"
#include "SDL_rect.h"
#include <vector>

namespace HB
{
	class CardComponent;

	class Deck final : public Engine::BaseComponent
	{
	public:
		Deck(Engine::GameObject* pObject, bool shouldShuffle);
		virtual ~Deck() = default;
		Deck(const Deck& other) = delete;
		Deck(Deck&& other) noexcept = delete;
		Deck& operator=(const Deck& other) = delete;
		Deck& operator=(Deck&& other) = delete;

		void Start() override {};
		void Render() const override {};
		void Update(float /*deltaTime*/) override {};
		void FixedUpdate(float /*deltaTime*/) override {};

		void AddCard(CardComponent* CardPtr);
		void Shuffle();
		void DeckClicked();

		bool IsPointInDeck(const glm::vec2& pos);
		bool IsPointInDeck(const float X, const float Y);
		bool IsPointInDeck(const int X, const int Y);

	private:
		void DealCard();

		std::vector<CardComponent*> m_Cards{};
		std::vector<CardComponent*> m_PlayedCards{};
		bool m_ShouldShuffle = false;

		SDL_Rect m_DeckRect;
	};
}