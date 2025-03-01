#pragma once
#include "CardComponent.h"

namespace HB
{
	class LocationCardComponent final : public CardComponent
	{
	public:
		LocationCardComponent(Engine::GameObject* pObject, int m_MaxControl, const std::string& cardName);
		virtual ~LocationCardComponent() = default;
		LocationCardComponent(const LocationCardComponent& other) = delete;
		LocationCardComponent(LocationCardComponent&& other) noexcept = delete;
		LocationCardComponent& operator=(const LocationCardComponent& other) = delete;
		LocationCardComponent& operator=(LocationCardComponent&& other) = delete;

		void Start() override;
		void Render() const override {};
		void OnGuiRender() override {};
		void Update(float /*deltaTime*/) override {};
		void FixedUpdate(float /*deltaTime*/) override {};

		void CardClicked() override;
		void PlayCard() override;

		void AddControl(int amount);
		void RemoveControl(int amount);

	private:
		void LocationLost(int remainder);

		int m_MaxControl{};
		int m_Control{};
	};
}