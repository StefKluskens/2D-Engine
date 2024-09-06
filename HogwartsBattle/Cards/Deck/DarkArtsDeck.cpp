#include "DarkArtsDeck.h"
#include "../../Managers/GameManager.h"

HB::DarkArtsDeck::DarkArtsDeck(Engine::GameObject* pObject, bool shouldShuffle)
	: Deck(pObject, shouldShuffle)
{
}

void HB::DarkArtsDeck::AddCard(CardComponent* CardPtr)
{
	Deck::AddCard(CardPtr);
}

void HB::DarkArtsDeck::Shuffle()
{
	Deck::Shuffle();
}

void HB::DarkArtsDeck::DeckClicked()
{
	if (GameManager::GetInstance().GetState() == GameState::DarkArtsEvent)
	{
		DealCard();
		GameManager::GetInstance().SetState(GameState::Villains);
	}
}