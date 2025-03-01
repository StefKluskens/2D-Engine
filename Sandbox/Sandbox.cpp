#include "Sandbox.h"
#include "Core/SceneManager.h"
#include "SceneGraph/Scene.h"

#include <SceneGraph/GameObject.h>
#include "Commands.h"

#include "Input/InputManager.h"

#include "Physics/Rigidbody.h"
#include "Shapes/Shapes.h"

#include "ShapeObject.h"
#include "Window/WindowManager.h"

#include <iostream>

void SB::SandBox::Load()
{
	auto& scene = Engine::SceneManager::GetInstance().CreateScene("Moving Camera Test");
	Engine::SceneManager::GetInstance().SetActiveScene(&scene);

	auto playerGo = std::make_shared<Engine::GameObject>("Player", &scene);
	scene.AddObject(playerGo);
	playerGo->SetPosition(300, 200);
	
	auto moveCommand = std::make_unique<SB::MoveCommand>(playerGo.get());
	Engine::InputManager::GetInstance().AddCommand(SDL_SCANCODE_W, std::move(moveCommand));

	auto shapeObject = std::make_unique<ShapeObject>(playerGo.get());
	playerGo->AddComponent(std::move(shapeObject));

	/*auto circleShape = std::make_unique<Engine::Circle>(300, 200, 20, 255, 255, 255);
	auto circle = Engine::Rigidbody::CreateCircleBody(2.0f, glm::vec2(0.0f, 0.0f), 2.0f, false, 0.5f);
	if (circle != nullptr)
	{
		std::cout << "Circle created\n";
	}

	auto box = Engine::Rigidbody::CreateBoxBody(2.0f, 2.0f, glm::vec2(0.0f, 0.0f), 2.0f, false, 0.5f);
	if (box != nullptr)
	{
		std::cout << "Box created\n";
	}*/
}