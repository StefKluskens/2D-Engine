#pragma once
#include "Components/BaseComponent.h"

namespace HB
{
	class HealthComponent final : public Engine::BaseComponent
	{
	public:
		HealthComponent(Engine::GameObject* pObject, int initialHealth);
		virtual ~HealthComponent() = default;
		HealthComponent(const HealthComponent& other) = delete;
		HealthComponent(HealthComponent&& other) noexcept = delete;
		HealthComponent& operator=(const HealthComponent& other) = delete;
		HealthComponent& operator=(HealthComponent&& other) = delete;

		void Start() override {};
		void Render() const override {};
		void Update(float /*deltaTime*/) override {};
		void FixedUpdate(float /*deltaTime*/) override {};

		void AddHealth(int healthToAdd) { m_Health += healthToAdd; }
		void RemoveHealth(int healthToRemove) { m_Health -= healthToRemove; }
		const int GetHealth() const { return m_Health; }
	private:
		int m_Health{};
	};
}