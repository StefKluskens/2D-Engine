#include "InputManager.h"
#include "SDL.h"

Engine::InputManager::InputManager()
{
}

bool Engine::InputManager::ProcessInput()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			return false;
		}
	}

	return true;
}
