#pragma once
#include "Components/BaseComponent.h"
#include "../FootballProject/Interfaces/ISelectable.h"

namespace FP
{
	class Player : public Engine::BaseComponent, public FP::ISelectable
	{
	public:
		Player(Engine::GameObject* pObject);
		virtual ~Player() = default;
		Player(const Player& other) = delete;
		Player(Player&& other) noexcept = delete;
		Player& operator=(const Player& other) = delete;
		Player& operator=(Player&& other) = delete;

		void Render() const override;
		void Update(float /*deltaTime*/) override {};
		void FixedUpdate(float /*deltaTime*/) override {};

	private:
		bool m_InPossession{ false };
		bool m_IsSelected{ false };

		// Inherited via ISelectable
		virtual void OnSelect() override;
		virtual void OnDeselect() override;
	};
}