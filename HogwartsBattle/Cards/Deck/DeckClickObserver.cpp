#include "DeckClickObserver.h"
#include "Deck.h"
#include "Input/InputManager.h"
#include "SceneGraph/GameObject.h"
#include <iostream>

HB::DeckClickObserver::DeckClickObserver(Engine::GameObject* pObject)
	: Engine::BaseComponent(pObject)
	, m_InputManager(Engine::InputManager::GetInstance())
{
	m_InputManager.AddObserver(this);
}

void HB::DeckClickObserver::Start()
{
	m_pDeckComponent = m_pOwner->GetComponent<Deck>();
}

void HB::DeckClickObserver::Notify(Engine::Event event)
{
	glm::vec2 mousePos = { m_InputManager.GetMouseX(), m_InputManager.GetMouseY() };

	switch (event)
	{
	case Engine::Event::LeftMouseDown:
		if (m_pDeckComponent->IsPointInDeck(mousePos))
		{
			m_pDeckComponent->DeckClicked();
		}
		break;
	case Engine::Event::LeftMouseUp:
		break;
	case Engine::Event::RightMouseDown:
		break;
	case Engine::Event::RightMouseUp:
		break;
	default:
		break;
	}
}
