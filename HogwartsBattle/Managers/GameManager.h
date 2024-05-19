#pragma once
#include "Core/Singleton.h"
#include "../Cards/Components/DarkArtsCardComponent.h"

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
		DarkArtsCardComponent* GetDarkArtsCard() { return m_pActiveDarkArtsCard; }

	private:
		GameState m_CurrentState = GameState::DarkArtsEvent;

		DarkArtsCardComponent* m_pActiveDarkArtsCard = nullptr;
	};
}


