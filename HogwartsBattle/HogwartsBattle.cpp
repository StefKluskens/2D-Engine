#include "HogwartsBattle.h"
#include "Core/2D-SDL-Engine.h"
#include "Core/SceneManager.h"
#include "SceneGraph/GameObject.h"
#include "SceneGraph/Scene.h"
#include "Components/TextureComponent.h"
#include "Window/WindowManager.h"

void HB::HogwartsBattle::Load()
{
	auto& scene = Engine::SceneManager::GetInstance().CreateScene("TestScene");
	Engine::SceneManager::GetInstance().SetActiveScene(&scene);

	auto boardGo = std::make_shared<Engine::GameObject>("BoardObject", &scene);
	scene.AddObject(boardGo);

	auto textureComponent = std::make_unique<Engine::TextureComponent>(boardGo.get(), "Board.JPG");
	
	auto textureWidth = textureComponent->GetTextureSize().x;
	auto textureHeight = textureComponent->GetTextureSize().y;

	boardGo->SetPosition(Engine::g_WindowWidth / 2 - textureWidth / 2, Engine::g_WindowHeight / 2 - textureHeight / 2);

	boardGo->AddComponent(std::move(textureComponent));
}