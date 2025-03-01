#pragma once
#include "BaseComponent.h"

namespace Engine
{
	class Camera final : public BaseComponent
	{
	public:
		Camera(GameObject* pObject, glm::vec2 pos, glm::vec2 speed);
		virtual ~Camera() = default;
		Camera(const Camera& other) = delete;
		Camera(Camera&& other) noexcept = delete;
		Camera& operator=(const Camera& other) = delete;
		Camera& operator=(Camera&& other) = delete;

		void Start() override {};
		void Render() const override {};
		void OnGuiRender() override {};
		void Update(float deltaTime) override;
		void FixedUpdate(float /*deltaTime*/) override {};

		void SetPosition(const glm::vec2& pos) { m_Position = pos; }
		void Move(const glm::vec2& pos) { m_Position += pos; }
		const glm::vec2& GetPosition() const { return m_Position; }
		void SetMovementSpeed(const glm::vec2& speed) { m_MovementSpeed = speed; }
		const glm::vec2& GetMovementSpeed() const { return m_MovementSpeed; }

	private:
		glm::vec2 m_Position{};
		glm::vec2 m_MovementSpeed{};
	};
}