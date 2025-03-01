#pragma once
#include <vector>
#include <string>
#include <memory>
#include "Singleton.h"

namespace Engine
{
	class Scene;
	class SceneManager final : public Singleton<SceneManager>
	{
	public:
		Scene& CreateScene(const std::string& name);

		void Start();
		void Update(float deltaTime);
		void FixedUpdate(float deltaTime);
		void Render();
		void OnGuiRender();

		void SetActiveScene(Scene* scene);
		const Scene* GetActiveScene() const { return m_pActiveScene; }

	private:
		friend class Singleton<SceneManager>;
		SceneManager() = default;

		std::vector<std::shared_ptr<Scene>> m_pScenes;
		Scene* m_pActiveScene = nullptr;
	};
}


