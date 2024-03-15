#include "HogwartsBattle.h"
#include "Core/2D-SDL-Engine.h"
#include "Core/SceneManager.h"
#include "SceneGraph/GameObject.h"
#include "SceneGraph/Scene.h"
#include "Components/TextureComponent.h"
#include "Window/WindowManager.h"
#include "Cards/CardClickObserver.h"
#include "Cards/CardComponent.h"
#include "Cards/Components/DarkArtsCardComponent.h"
#include "Cards/Deck/Deck.h"

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

	//Create dark arts deck object
	auto darkArtsDeckGo = std::make_shared<Engine::GameObject>("Dark Arts Deck", &scene);
	scene.AddObject(darkArtsDeckGo);
	darkArtsDeckGo->SetPosition(750.0f, 265.0f);

	//Creat + add dark arts deck texture
	textureComponent = std::make_unique<Engine::TextureComponent>(darkArtsDeckGo.get(), "dark_arts_event.png");
	darkArtsDeckGo->AddComponent(std::move(textureComponent));

	//Create dark arts card object
	auto darkArtsEventGo = std::make_shared<Engine::GameObject>("DarkArtsCard", &scene);
	scene.AddObject(darkArtsEventGo);
	darkArtsEventGo->SetPosition(800.0f, 265.0f);

	//Create + add dark arts card texture
	textureComponent = std::make_unique<Engine::TextureComponent>(darkArtsDeckGo.get(), "dark_arts_event.png");
	darkArtsEventGo->AddComponent(std::move(textureComponent));

	//Create dark arts card component
	auto cardComponent = std::make_unique<DarkArtsCardComponent>(darkArtsEventGo.get());

	//Create dark arts deck component
	auto deckComponent = std::make_unique<Deck>(darkArtsDeckGo.get(), true);

	//Add dark arts card to deck
	deckComponent->AddCard(cardComponent.get());

	//Create + add click observer for dark arts card
	auto cardClickComponent = std::make_unique<CardClickObserver>(darkArtsEventGo.get());
	darkArtsEventGo->AddComponent(std::move(cardClickComponent));

	//Add dark arts card component
	darkArtsEventGo->AddComponent(std::move(cardComponent));

	//Add deck component
	darkArtsDeckGo->AddComponent(std::move(deckComponent));
	
}