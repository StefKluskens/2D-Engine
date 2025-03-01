#pragma once
#include "../Core/SceneManager.h"

namespace Engine
{
	class GameObject;
	class Scene final
	{
		friend Scene& SceneManager::CreateScene(const std::string& name);
	public:
		~Scene() = default;
		Scene(const Scene& other) = delete;
		Scene(Scene&& other) = delete;
		Scene& operator=(const Scene& other) = delete;
		Scene& operator=(Scene&& other) = delete;

		void Start();
		void Update(float deltaTime);
		void FixedUpdate(float deltaTime);
		void Render();
		void OnGuiRender();

		void AddObject(std::shared_ptr<GameObject> pObject);

		const std::string GetName() const { return m_Name; }

	private:
		explicit Scene(const std::string& name);

		std::string m_Name;

		std::vector<std::shared_ptr<GameObject>> m_pObjects;
	};
}