#include "HogwartsBattle.h"
#include "Core/2D-SDL-Engine.h"
#include "Core/SceneManager.h"
#include "SceneGraph/GameObject.h"
#include "SceneGraph/Scene.h"
#include "Components/TextureComponent.h"
#include "Window/WindowManager.h"
#include "Cards/CardClickObserver.h"
#include "Cards/CardComponent.h"

void HB::HogwartsBattle::Load()
{
	auto& scene = Engine::SceneManager::GetInstance().CreateScene("TestScene");
	Engine::SceneManager::GetInstance().SetActiveScene(&scene);

	auto boardGo = std::make_shared<Engine::GameObject>("BoardObject", &scene);
	scene.AddObject(boardGo);

	auto textureComponent = std::make_unique<Engine::TextureComponent>(boardGo.get(), "Board.png");
	
	auto textureWidth = textureComponent->GetTextureSize().x;
	auto textureHeight = textureComponent->GetTextureSize().y;

	boardGo->SetPosition(Engine::g_WindowWidth / 2 - textureWidth / 2, Engine::g_WindowHeight / 2 - textureHeight / 2);
	boardGo->AddComponent(std::move(textureComponent));

	auto darkArtsEventGo = std::make_shared<Engine::GameObject>("DarkArtsCard", &scene);
	scene.AddObject(darkArtsEventGo);
	textureComponent = std::make_unique<Engine::TextureComponent>(darkArtsEventGo.get(), "dark_arts_event.png");

	textureWidth = textureComponent->GetTextureSize().x;
	textureHeight = textureComponent->GetTextureSize().y;

	darkArtsEventGo->SetPosition(Engine::g_WindowWidth / 2 - textureWidth / 2, Engine::g_WindowHeight / 2 - textureHeight / 2);
	darkArtsEventGo->AddComponent(std::move(textureComponent));

	auto cardComponent = std::make_unique<CardComponent>(darkArtsEventGo.get());
	darkArtsEventGo->AddComponent(std::move(cardComponent));

	auto cardClickComponent = std::make_unique<CardClickObserver>(darkArtsEventGo.get());
	darkArtsEventGo->AddComponent(std::move(cardClickComponent));
}