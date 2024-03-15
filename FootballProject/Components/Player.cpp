#include "Player.h"
#include "imgui.h"
#include <iostream>

FP::Player::Player(Engine::GameObject* pObject)
	: Engine::BaseComponent(pObject)
{
}

void FP::Player::Render() const
{
	if (m_IsSelected)
	{
		ImGui::Begin("Player");
		ImGui::Text("Player Text");

		if (ImGui::Button("Show Position"))
		{
			std::cout << "Player position: Central Midfielder\n";
		}

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
