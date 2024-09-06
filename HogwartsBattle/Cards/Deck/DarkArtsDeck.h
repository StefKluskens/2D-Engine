#pragma once
#include "Deck.h"

namespace HB 
{
	class DarkArtsDeck final : public Deck
	{
	public:
		DarkArtsDeck(Engine::GameObject* pObject, bool shouldShuffle);
		virtual ~DarkArtsDeck() = default;
		DarkArtsDeck(const DarkArtsDeck& other) = delete;
		DarkArtsDeck(DarkArtsDeck&& other) noexcept = delete;
		DarkArtsDeck& operator=(const DarkArtsDeck& other) = delete;
		DarkArtsDeck& operator=(DarkArtsDeck&& other) = delete;

		virtual void AddCard(CardComponent* CardPtr) override;
		virtual void Shuffle() override;
		virtual void DeckClicked() override;
	};
}