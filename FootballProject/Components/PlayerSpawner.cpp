#include "PlayerSpawner.h"
#include "SceneGraph/Scene.h"
#include "SceneGraph/GameObject.h"
#include "Player.h"
#include "Input/InputManager.h"
#include "imgui.h"

FP::PlayerSpawner::PlayerSpawner(Engine::GameObject* pObject)
	: Engine::BaseComponent(pObject)
	, m_InputManager(Engine::InputManager::GetInstance())
{
	m_InputManager.AddObserver(this);
}

void FP::PlayerSpawner::Render() const
{
	ImGuiWindowFlags_NoResize;
	ImGui::Begin("Player Spawner", nullptr, ImGuiWindowFlags_NoMove);

	ImVec2 window_pos = ImGui::GetWindowPos();
	ImVec2 window_size = ImGui::GetWindowSize();
	m_minBoundsWindow = { window_pos.x, window_pos.y };
	m_maxBoundsWindow = { window_pos.x + window_size.x, window_pos.y + window_size.y };

	if (ImGui::Button("Spawn Player"))
	{
		m_SpawnPlayer = !m_SpawnPlayer;
	}

	m_SpawnPlayer? ImGui::Text("Click to spawn player") : ImGui::Text("Click player to select");

	ImGui::End();
}

void FP::PlayerSpawner::Notify(Engine::Event event)
{
	switch (event)
	{
		case Engine::Event::LeftMouseDown:
		{
			m_MousePos = m_InputManager.GetMousePos();

			if (PointInWindow(m_minBoundsWindow, m_maxBoundsWindow))
			{
				break;
			}

			if (!m_SpawnPlayer)
			{
				break;
			}
			auto scene = GetGameObject()->GetScene();
			auto playerGo = std::make_shared<Engine::GameObject>("Player", scene);
			scene->AddObject(playerGo);
			auto mousePos = m_InputManager.GetMousePos();
			playerGo->GetTransform()->SetLocalPosition(mousePos.x, mousePos.y);

			auto playerComponent = std::make_unique<Player>(playerGo.get());
			playerGo->AddComponent(std::move(playerComponent));
			break;
		}
	}
}

bool FP::PlayerSpawner::PointInWindow(glm::vec2 minBounds, glm::vec2 maxBounds) const
{
	return m_MousePos.x > minBounds.x && m_MousePos.x < maxBounds.x && m_MousePos.y > minBounds.y && m_MousePos.y < maxBounds.y;
}
