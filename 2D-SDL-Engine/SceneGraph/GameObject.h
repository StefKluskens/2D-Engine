#pragma once
#include <string>
#include <vector>
#include <memory>
#include "../Components/BaseComponent.h"
#include "../Components/TransformComponent.h"

namespace Engine
{
	class Scene;
	class GameObject final
	{
	public:
		GameObject(std::string name, Scene* pScene);
		~GameObject() = default;
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) noexcept = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

		void Update(float deltaTime);
		void FixedUpdate(float deltaTime);
		void Render() const;

		TransformComponent* GetTransform() const { return m_pTransform.get(); }

		void AddComponent(std::unique_ptr<BaseComponent> pComponent);
		template <typename T> T* GetComponent() const;
		template <typename T> void RemoveComponent();

		const std::string GetName() const;
		void SetName(const std::string& name);

		void SetParent(GameObject* pParent, bool keepWorldPos);
		const GameObject* GetParent() const { return m_pParent; };

		const GameObject* GetChildByName(const std::string& name) const;

		void SetPosition(float x, float y);
		void SetPosition(int x, int y);
		void SetPosition(glm::vec2 pos);

		Scene* GetScene() const { return m_pScene; }

	private:
		std::string m_Name{ "GameObject" };
		std::string m_Tag{ "" };

		Scene* m_pScene{ nullptr };

		std::vector<std::unique_ptr<BaseComponent>> m_pComponents;
		std::unique_ptr<TransformComponent> m_pTransform;

		GameObject* m_pParent{ nullptr };
		std::vector<std::unique_ptr<GameObject>> m_pChildren;
	};

	template<typename T>
	inline T* GameObject::GetComponent() const
	{
		static_assert(std::is_base_of<BaseComponent, T>::value, "T must be derived from Component");

		T* temp{};

		for (size_t i = 0; i < m_pComponents.size(); ++i)
		{
			temp = dynamic_cast<T*>(m_pComponents[i].get());
			if (temp)
				return temp;
		}

		return nullptr;
	}

	template<typename T>
	inline void GameObject::RemoveComponent()
	{
		m_pComponents.erase(
			std::remove_if(
				m_pComponents.begin(),
				m_pComponents.end(),
				[](const std::unique_ptr<BaseComponent>& pComponent)
				{
					return dynamic_cast<T*>(pComponent.get()) != nullptr;
				}
			),
			m_pComponents.end()
					);
	}
}