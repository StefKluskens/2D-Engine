#pragma once
#include "Components/BaseComponent.h"
#include "Observer/Observer.h"
#include <vector>

namespace FP
{
	class Player;

	class PlayerSpawner final : public Engine::BaseComponent, public Engine::Observer
	{
	public:
		PlayerSpawner(Engine::GameObject* pObject);
		virtual ~PlayerSpawner() = default;
		PlayerSpawner(const PlayerSpawner& other) = delete;
		PlayerSpawner(PlayerSpawner&& other) noexcept = delete;
		PlayerSpawner& operator=(const PlayerSpawner& other) = delete;
		PlayerSpawner& operator=(PlayerSpawner&& other) = delete;

		void Render() const override;
		void Update(float /*deltaTime*/) override {};
		void FixedUpdate(float /*deltaTime*/) override {};

	private:
		void Notify(Engine::Event event) override;
		bool PointInWindow(glm::vec2 minBounds, glm::vec2 maxBounds) const;

		void SetPlayersSelectable(bool selectable);

		std::vector<Player*> m_pPlayers{};

		glm::vec2 m_MousePos{ 0, 0 };
		mutable glm::vec2 m_minBoundsWindow{};
		mutable glm::vec2 m_maxBoundsWindow{};

		mutable bool m_SpawnPlayer{ false };
	};
}