#pragma once
#include "Components/BaseComponent.h"
#include <vector>
#include "SDL_rect.h"

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

		void Render() const override {};
		void Update(float /*deltaTime*/) override {};
		void FixedUpdate(float /*deltaTime*/) override {};

		void AddCard(CardComponent* CardPtr);
		void Shuffle();

	private:
		std::vector<CardComponent*> m_Cards{};
		SDL_Rect m_CardRect;
		bool m_ShouldShuffle = false;
	};
}