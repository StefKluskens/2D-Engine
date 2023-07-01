#include "HogwartsBattle.h"
#include "Core/SceneManager.h"
#include "SceneGraph/GameObject.h"
#include "SceneGraph/Scene.h"

void HB::HogwartsBattle::Load()
{
	auto& scene = Engine::SceneManager::GetInstance().CreateScene("TestScene");

	auto go = std::make_shared<Engine::GameObject>("TestObject", &scene);
	scene.AddObject(go);
}