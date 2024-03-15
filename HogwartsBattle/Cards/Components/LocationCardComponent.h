#pragma once
#include "../CardComponent.h"

namespace HB
{
	class LocationCardComponent final : public CardComponent
	{
	public:
		LocationCardComponent(Engine::GameObject* pObject, int MaxControl);
		virtual ~LocationCardComponent() = default;
		LocationCardComponent(const LocationCardComponent& other) = delete;
		LocationCardComponent(LocationCardComponent&& other) noexcept = delete;
		LocationCardComponent& operator=(const LocationCardComponent& other) = delete;
		LocationCardComponent& operator=(LocationCardComponent&& other) = delete;

		void Render() const override {};
		void Update(float /*deltaTime*/) override {};
		void FixedUpdate(float /*deltaTime*/) override {};

		void CardClicked() override;

		void AddControl(int amount);
		void RemoveControl(int amount);

	private:
		void LocationLost(int remainder);

		int MaxControl{};
		int Control{};
	};
}