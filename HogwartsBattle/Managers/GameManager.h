#pragma once
#include "Core/Singleton.h"
#include "../Cards/Components/DarkArtsCardComponent.h"
#include "../Cards/Components/LocationCardComponent.h"

namespace HB 
{
	enum class GameState
	{
		DarkArtsEvent,
		Villains,
		PlayerCards,
		AssignDamage,
		AssignCurrency,
		ResolveVillainDeath,
		CheckLocation
	};

	class GameManager final : public Engine::Singleton<GameManager>
	{
	public:
		GameManager();

		void SetState(GameState state) { m_CurrentState = state; }
		const GameState& GetState() const { return m_CurrentState; }

		void SetDarkArtsCard(DarkArtsCardComponent* pCard) { m_pActiveDarkArtsCard = pCard; }
		DarkArtsCardComponent* GetDarkArtsCard() const { return m_pActiveDarkArtsCard; }

		void SetLocationCard(LocationCardComponent* pCard) { m_pActiveLocationCard = pCard; }
		LocationCardComponent* GetLocationCard() const { return m_pActiveLocationCard; }

	private:
		GameState m_CurrentState = GameState::DarkArtsEvent;

		DarkArtsCardComponent* m_pActiveDarkArtsCard = nullptr;
		LocationCardComponent* m_pActiveLocationCard = nullptr;
	};
}


