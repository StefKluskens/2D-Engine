#pragma once
#include "Components/BaseComponent.h"
#include "Observer/Observer.h"

namespace Engine
{
	class InputManager;
}

namespace HB
{
	class Deck;

	class DeckClickObserver final : public Engine::BaseComponent, public Engine::Observer
	{
	public:
		DeckClickObserver(Engine::GameObject* pObject);
		virtual ~DeckClickObserver() = default;
		DeckClickObserver(const DeckClickObserver& other) = delete;
		DeckClickObserver(DeckClickObserver&& other) noexcept = delete;
		DeckClickObserver& operator=(const DeckClickObserver& other) = delete;
		DeckClickObserver& operator=(DeckClickObserver&& other) = delete;

		void Start() override;
		void Render() const override {};
		void Update(float /*deltaTime*/) override {};
		void FixedUpdate(float /*deltaTime*/) override {};

	private:
		void Notify(Engine::Event event) override;

		Engine::InputManager& m_InputManager;

		Deck* m_pDeckComponent;
	};
}