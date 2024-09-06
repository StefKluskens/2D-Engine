#include "HogwartsBattle.h"
#include "Core/2D-SDL-Engine.h"
#include "Core/SceneManager.h"
#include "SceneGraph/GameObject.h"
#include "SceneGraph/Scene.h"
#include "Components/TextureComponent.h"
#include "Window/WindowManager.h"
#include "Cards/Components/CardClickObserver.h"
#include "Cards/Components/CardComponent.h"
#include "Cards/Components/DarkArtsCardComponent.h"
#include "Cards/Components/LocationCardComponent.h"
#include "Cards/Deck/Deck.h"
#include <iostream>
#include "Cards/Deck/DeckClickObserver.h"
#include "Managers/GameManager.h"
#include "Cards/Deck/DarkArtsDeck.h"
#include "Cards/Effects/CardEffects.h"
#include "Components/HealthComponent.h"

void HB::HogwartsBattle::Load()
{
	auto& scene = Engine::SceneManager::GetInstance().CreateScene("TestScene");
	Engine::SceneManager::GetInstance().SetActiveScene(&scene);

	auto boardGo = std::make_shared<Engine::GameObject>("BoardObject", &scene);
	scene.AddObject(boardGo);

	auto textureComponent = std::make_unique<Engine::TextureComponent>(boardGo.get(), "Board.png");
	
	auto textureWidth = textureComponent->GetTextureSize().x;
	boardGo->SetPosition(Engine::g_WindowWidth / 2 - textureWidth / 2, 0.0f);
	boardGo->AddComponent(std::move(textureComponent));

	//Player
	auto playerGo = std::make_shared<Engine::GameObject>("Player", &scene);
	scene.AddObject(playerGo);

	auto healthComponent = std::make_unique<HealthComponent>(playerGo.get(), 10);


	//Dark arts card
	auto darkArtsEventGo = std::make_shared<Engine::GameObject>("DarkArtsCard", &scene);
	scene.AddObject(darkArtsEventGo);
	darkArtsEventGo->SetActive(false);

	textureComponent = std::make_unique<Engine::TextureComponent>(darkArtsEventGo.get(), "Front_Event.png");
	darkArtsEventGo->AddComponent(std::move(textureComponent));

	auto cardComponent = std::make_unique<DarkArtsCardComponent>(darkArtsEventGo.get(), "Flipendo!");
	cardComponent->SetEffects(1, 1, 0, false);

	auto lifeLossEffect = std::make_unique<LoseHealthEffect>(1);
	cardComponent->AddCardEffect(std::move(lifeLossEffect));

	//Dark arts deck
	auto darkArtsDeckGo = std::make_shared<Engine::GameObject>("Dark Arts Deck", &scene);
	scene.AddObject(darkArtsDeckGo);

	textureComponent = std::make_unique<Engine::TextureComponent>(darkArtsDeckGo.get(), "dark_arts_event.png");
	darkArtsDeckGo->AddComponent(std::move(textureComponent));

	auto deckComponent = std::make_unique<DarkArtsDeck>(darkArtsDeckGo.get(), true);
	deckComponent->AddCard(cardComponent.get());

	darkArtsEventGo->AddComponent(std::move(cardComponent));

	darkArtsDeckGo->AddComponent(std::move(deckComponent));

	auto cardClickComponent = std::make_unique<CardClickObserver>(darkArtsEventGo.get());
	darkArtsEventGo->AddComponent(std::move(cardClickComponent));

	auto deckClickComponent = std::make_unique<DeckClickObserver>(darkArtsDeckGo.get());
	darkArtsDeckGo->AddComponent(std::move(deckClickComponent));


	//Location deck
	auto locationDeckGo = std::make_shared<Engine::GameObject>("Location Deck", &scene);
	scene.AddObject(locationDeckGo);
	auto locationDeckComponent = std::make_unique<Deck>(locationDeckGo.get(), true);

	//Location card
	auto locationGo = std::make_shared<Engine::GameObject>("LocationCard", &scene);
	scene.AddObject(locationGo);

	textureComponent = std::make_unique<Engine::TextureComponent>(locationGo.get(), "Front_Location.png");
	locationGo->AddComponent(std::move(textureComponent));

	auto locationCardComponent = std::make_unique<LocationCardComponent>(locationGo.get(), 4, "Diagon Alley");
	locationDeckComponent->AddCard(locationCardComponent.get());

	////Create + add click observer for dark arts card
	//auto cardClickComponent = std::make_unique<CardClickObserver>(darkArtsEventGo.get());
	//darkArtsEventGo->AddComponent(std::move(cardClickComponent));

	locationGo->AddComponent(std::move(locationCardComponent));
	locationDeckGo->AddComponent(std::move(locationDeckComponent));
}