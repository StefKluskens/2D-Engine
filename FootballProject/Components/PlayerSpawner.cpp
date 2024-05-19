#include "PlayerSpawner.h"
#include "SceneGraph/Scene.h"
#include "SceneGraph/GameObject.h"
#include "Player.h"
#include "Input/InputManager.h"
#include "imgui.h"

FP::PlayerSpawner::PlayerSpawner(Engine::GameObject* pObject)
	: Engine::BaseComponent(pObject)
{
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
			m_MousePos = Engine::InputManager::GetInstance().GetMousePos();

			if (PointInWindow(m_minBoundsWindow, m_maxBoundsWindow))
			{
				break;
			}

			if (!m_SpawnPlayer)
			{
				SetPlayersSelectable(true);
				break;
			}
			else
			{
				SetPlayersSelectable(false);
			}

			auto scene = m_pOwner->GetScene();
			auto playerGo = std::make_shared<Engine::GameObject>("Player " + std::to_string(m_pPlayers.size()), scene);
			scene->AddObject(playerGo);
			auto mousePos = Engine::InputManager::GetInstance().GetMousePos();
			playerGo->GetTransform()->SetLocalPosition(mousePos.x, mousePos.y);

			auto playerComponent = std::make_unique<Player>(playerGo.get());
			Engine::InputManager::GetInstance().AddObserver(playerComponent.get());
			m_pPlayers.push_back(playerComponent.get());
			playerGo->AddComponent(std::move(playerComponent));
			break;
		}
	}
}

bool FP::PlayerSpawner::PointInWindow(glm::vec2 minBounds, glm::vec2 maxBounds) const
{
	return m_MousePos.x > minBounds.x && m_MousePos.x < maxBounds.x && m_MousePos.y > minBounds.y && m_MousePos.y < maxBounds.y;
}

void FP::PlayerSpawner::SetPlayersSelectable(bool selectable)
{
	for (int i = 0; i < m_pPlayers.size(); ++i)
	{
		m_pPlayers[i]->m_CanBeSelected = selectable;
	}
}
