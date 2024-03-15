#include "InputManager.h"
#include "SDL.h"
#include "../Observer/Observer.h"
#include <backends/imgui_impl_sdl2.h>

Engine::InputManager::InputManager()
	: m_pMouseSubject(std::make_unique<Subject>())
	, m_MouseX(0)
	, m_MouseY(0)
{
}

bool Engine::InputManager::ProcessInput()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		ImGui_ImplSDL2_ProcessEvent(&event);

		if (event.type == SDL_QUIT)
		{
			return false;
		}

		if (event.type == SDL_MOUSEBUTTONDOWN)
		{
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				SDL_GetMouseState(&m_MouseX, &m_MouseY);
				m_pMouseSubject->Notify(Event::LeftMouseDown);
			}
		}
	}

	return true;
}

void Engine::InputManager::AddObserver(Observer* pObserver)
{
	m_pMouseSubject->AddObserver(pObserver);
}

void Engine::InputManager::RemoveObserver(Observer* pObserver)
{
	m_pMouseSubject->RemoveObserver(pObserver);
}
