#pragma once
#include <glm/glm.hpp>

namespace Engine
{
	class GameObject;
	class BaseComponent
	{
	public:
		BaseComponent(GameObject* pObject);
		virtual ~BaseComponent() = default;
		BaseComponent(const BaseComponent& other) = delete;
		BaseComponent(BaseComponent&& other) noexcept = delete;
		BaseComponent& operator=(const BaseComponent& other) = delete;
		BaseComponent& operator=(BaseComponent&& other) = delete;

		virtual void Start() = 0;
		virtual void Render() const = 0;
		virtual void Update(float deltaTime) = 0;
		virtual void FixedUpdate(float deltaTime) = 0;

		const GameObject* GetOwner() const { return m_pOwner; }

	protected:
		GameObject* m_pOwner;
	};
}