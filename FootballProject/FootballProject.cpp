#include "FootballProject.h"
#include "Core/2D-SDL-Engine.h"
#include "Core/SceneManager.h"
#include "SceneGraph/Scene.h"
#include "SceneGraph/GameObject.h"

#include "Components/Player.h"

void FP::FootballProject::Load()
{
	auto& scene = Engine::SceneManager::GetInstance().CreateScene("Perfect Passing");
	Engine::SceneManager::GetInstance().SetActiveScene(&scene);

	auto player1Go = std::make_shared<Engine::GameObject>("Player1", &scene);
	scene.AddObject(player1Go);

	auto playerComponent = std::make_unique<Player>(player1Go.get());
	player1Go->AddComponent(std::move(playerComponent));
}