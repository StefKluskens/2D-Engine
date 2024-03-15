#include "DarkArtsCardComponent.h"
#include <SDL_render.h>
#include "Renderer/Renderer.h"
#include <iostream>

HB::DarkArtsCardComponent::DarkArtsCardComponent(Engine::GameObject* pObject)
	: CardComponent(pObject)
{
}

void HB::DarkArtsCardComponent::Render() const
{
	/*SDL_SetRenderDrawColor(Engine::Renderer::GetInstance().GetRenderer(), 255, 0, 0, 255);
	SDL_RenderDrawRect(Engine::Renderer::GetInstance().GetRenderer(), &m_CardRect);*/
}

void HB::DarkArtsCardComponent::CardClicked()
{
	std::cout << "Dark Arts Card clicked\n";
}
