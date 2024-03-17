#include "Player.h"
#include "imgui.h"
#include <SDL.h>
#include "Renderer/Renderer.h"
#include "SceneGraph/GameObject.h"
#include "Components/TransformComponent.h"
#include "Input/InputManager.h"
#include <iostream>
#include "imgui_internal.h"

FP::Player::Player(Engine::GameObject* pObject)
	: Engine::BaseComponent(pObject)
{
	auto pos = GetGameObject()->GetTransform()->GetWorldPosition();
	m_pCircle = std::make_unique<Circle>(Engine::Renderer::GetInstance().GetRenderer(), (int)pos.x, (int)pos.y, m_PlayerRadius, 255, 0, 0);

	m_ObjectName = GetGameObject()->GetName();

	m_PlayerText = "This is " + m_ObjectName;
}

void FP::Player::Render() const
{
	m_pCircle->Render();

	if (m_CanBeSelected && m_IsSelected)
	{
		ImGui::Begin(m_ObjectName.c_str());
		ImGui::Text(m_PlayerText.c_str());

		ImVec2 window_pos = ImGui::GetWindowPos();
		ImVec2 window_size = ImGui::GetWindowSize();
		m_minBoundsWindow = { window_pos.x, window_pos.y };
		m_maxBoundsWindow = { window_pos.x + window_size.x, window_pos.y + window_size.y };

		/*if (ImGui::Button("Show Position"))
		{
			std::cout << "Player position: Central Midfielder\n";
		}*/

		ImGui::End();
	}
}

void FP::Player::OnSelect()
{
	m_IsSelected = true;
}

void FP::Player::OnDeselect()
{
	m_IsSelected = false;
}

void FP::Player::Notify(Engine::Event event)
{
	switch (event)
	{
	case Engine::Event::LeftMouseDown:
	{
		m_MousePos = Engine::InputManager::GetInstance().GetMousePos();
		if (PointInWindow(m_minBoundsWindow, m_maxBoundsWindow))
		{
			m_IsSelected = true;
			break;
		}
		m_IsSelected = m_pCircle->IsInsideCircle(GetGameObject()->GetTransform()->GetWorldPosition(), (int)m_MousePos.x, (int)m_MousePos.y);

		break;
	}
	case Engine::Event::RightMouseDown:
	{
		//const auto clickedPos = m_InputManager.GetMousePos();
		//std::cout << "Right Mouse Down at position: " << '\n';
		break;
	}
	default:
		break;
	}
}

bool FP::Player::PointInWindow(glm::vec2 minBounds, glm::vec2 maxBounds) const
{
	return m_MousePos.x > minBounds.x && m_MousePos.x < maxBounds.x && m_MousePos.y > minBounds.y && m_MousePos.y < maxBounds.y;
}