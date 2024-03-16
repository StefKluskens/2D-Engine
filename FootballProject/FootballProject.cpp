#include "FootballProject.h"
#include "Core/2D-SDL-Engine.h"
#include "Core/SceneManager.h"
#include "SceneGraph/Scene.h"
#include "SceneGraph/GameObject.h"

#include "Components/Player.h"
#include "Components/PlayerSpawner.h"

void FP::FootballProject::Load()
{
	auto& scene = Engine::SceneManager::GetInstance().CreateScene("Perfect Passing");
	Engine::SceneManager::GetInstance().SetActiveScene(&scene);

	auto playerSpawnerGo = std::make_shared<Engine::GameObject>("PlayerSpawner", &scene);
	scene.AddObject(playerSpawnerGo);

	auto playerSpawnerComponent = std::make_unique<PlayerSpawner>(playerSpawnerGo.get());
	playerSpawnerGo->AddComponent(std::move(playerSpawnerComponent));
}