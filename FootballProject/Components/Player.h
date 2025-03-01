#pragma once
#include "Components/BaseComponent.h"
#include "../FootballProject/Interfaces/ISelectable.h"
#include "Observer/Observer.h"
#include <memory>
#include <string>
//#include "Shapes/Shapes.h"

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

		void Start() override {};
		void Render() const override;
		void OnGuiRender() override;
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

		//std::unique_ptr<Engine::Circle> m_pCircle;

		int m_PlayerRadius{ 10 };

		glm::vec2 m_MousePos{ 0, 0 };

		glm::vec2 m_minBoundsWindow{ 0, 0 };
		glm::vec2 m_maxBoundsWindow{ 0, 0 };

		std::string m_ObjectName;
		std::string m_PlayerText;
	};
}