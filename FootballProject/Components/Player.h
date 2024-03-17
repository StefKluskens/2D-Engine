#pragma once
#include "Components/BaseComponent.h"
#include "../FootballProject/Interfaces/ISelectable.h"
#include "Observer/Observer.h"
#include <memory>
#include <string>
#include "../Circle.h"

struct SDL_Renderer;

namespace FP
{
	class Player final : public Engine::BaseComponent, public FP::ISelectable, public Engine::Observer
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

		bool m_CanBeSelected{ false };

	private:
		virtual void OnSelect() override;
		virtual void OnDeselect() override;

		void Notify(Engine::Event event) override;

		bool PointInWindow(glm::vec2 minBounds, glm::vec2 maxBounds) const;

		bool m_InPossession{ false };
		bool m_IsSelected{ false };

		std::unique_ptr<Circle> m_pCircle;

		int m_PlayerRadius{ 10 };

		glm::vec2 m_MousePos{ 0, 0 };

		mutable glm::vec2 m_minBoundsWindow;
		mutable glm::vec2 m_maxBoundsWindow;

		std::string m_ObjectName;
		std::string m_PlayerText;
	};
}