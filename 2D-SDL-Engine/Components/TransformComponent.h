#pragma once
#include "BaseComponent.h"

namespace Engine
{
	class TransformComponent final : public BaseComponent
	{
	public:
		TransformComponent(GameObject* pObject);
		virtual ~TransformComponent() = default;
		TransformComponent(const TransformComponent& other) = delete;
		TransformComponent(TransformComponent&& other) noexcept = delete;
		TransformComponent& operator=(const TransformComponent& other) = delete;
		TransformComponent& operator=(TransformComponent&& other) = delete;
		
		void Start() override {};
		void Render() const override {};
		void OnGuiRender() override {};
		void Update(float /*deltaTime*/) override {};
		void FixedUpdate(float /*deltaTime*/) override {};

		const glm::vec2 GetLocalPosition() const { return m_LocalPosition; }
		const glm::vec2& GetWorldPosition();
		void UpdateWorldPosition();

		void SetLocalPosition(const glm::vec2& pos);
		void SetLocalPosition(float x, float y);
		void SetWorldPosition(const glm::vec2& pos) { m_WorldPosition = pos; }
		void SetWorldPosition(float x, float y) { m_WorldPosition = { x, y }; }
		void SetPositionDirty();

	private:
		glm::vec2 m_LocalPosition{};
		glm::vec2 m_WorldPosition{};

		bool m_PositionIsDirty{ true };
	};
}