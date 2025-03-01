#pragma once
#include "Components/BaseComponent.h"
#include "SDL_rect.h"
#include <vector>

namespace HB
{
	class CardComponent;

	class Deck : public Engine::BaseComponent
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
		void OnGuiRender() override {};
		void Update(float /*deltaTime*/) override {};
		void FixedUpdate(float /*deltaTime*/) override {};

		virtual void AddCard(CardComponent* CardPtr);
		virtual void Shuffle();
		virtual void DeckClicked();

		bool IsPointInDeck(const glm::vec2& pos);
		bool IsPointInDeck(const float X, const float Y);
		bool IsPointInDeck(const int X, const int Y);

	protected:
		void DealCard();

	private:
		std::vector<CardComponent*> m_Cards{};
		std::vector<CardComponent*> m_PlayedCards{};
		bool m_ShouldShuffle = false;

		SDL_Rect m_DeckRect{};
	};
}