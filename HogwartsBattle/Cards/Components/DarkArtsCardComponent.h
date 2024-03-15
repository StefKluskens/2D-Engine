#pragma once
#include "../CardComponent.h"

namespace HB
{
	class DarkArtsCardComponent final : public CardComponent
	{
	public:
		DarkArtsCardComponent(Engine::GameObject* pObject);
		virtual ~DarkArtsCardComponent() = default;
		DarkArtsCardComponent(const DarkArtsCardComponent& other) = delete;
		DarkArtsCardComponent(DarkArtsCardComponent&& other) noexcept = delete;
		DarkArtsCardComponent& operator=(const DarkArtsCardComponent& other) = delete;
		DarkArtsCardComponent& operator=(DarkArtsCardComponent&& other) = delete;

		void Render() const override;
		void Update(float /*deltaTime*/) override {};
		void FixedUpdate(float /*deltaTime*/) override {};

		void CardClicked() override;

	private:

	};
}