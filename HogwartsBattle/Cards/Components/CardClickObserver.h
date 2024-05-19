#pragma once
#include "Components/BaseComponent.h"
#include "Observer/Observer.h"

namespace Engine
{
	class InputManager;
}

namespace HB
{
	class CardComponent;

	class CardClickObserver final : public Engine::BaseComponent,  public Engine::Observer
	{
	public:
		CardClickObserver(Engine::GameObject* pObject);
		virtual ~CardClickObserver() = default;
		CardClickObserver(const CardClickObserver& other) = delete;
		CardClickObserver(CardClickObserver&& other) noexcept = delete;
		CardClickObserver& operator=(const CardClickObserver& other) = delete;
		CardClickObserver& operator=(CardClickObserver&& other) = delete;

		void Start() override;
		void Render() const override {};
		void Update(float /*deltaTime*/) override {};
		void FixedUpdate(float /*deltaTime*/) override {};

	private:
		void Notify(Engine::Event event) override;

		Engine::InputManager& m_InputManager;

		CardComponent* m_pCardComponent;
	};
}