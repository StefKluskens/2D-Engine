#include "CardClickObserver.h"
#include "CardComponent.h"
#include "Input/InputManager.h"
#include <iostream>
#include <glm/glm.hpp>
#include "SceneGraph/GameObject.h"

HB::CardClickObserver::CardClickObserver(Engine::GameObject* pObject)
	: Engine::BaseComponent(pObject)
	, m_InputManager(Engine::InputManager::GetInstance())
{
	m_InputManager.AddObserver(this);
	m_CardComponent = pObject->GetComponent<CardComponent>();
}

void HB::CardClickObserver::Notify(Engine::Event event)
{
	glm::vec2 mousePos = { m_InputManager.GetMouseX(), m_InputManager.GetMouseY() };

	switch (event)
	{
	case Engine::Event::LeftMouseDown:
	{
		//check if click is inside of card rect
		std::cout << "mouse pos x: " << mousePos.x << ", mouse pos y: " << mousePos.y << '\n';
		m_CardComponent->CardClicked();
		break;
	}
	default:
		break;
	}
}
