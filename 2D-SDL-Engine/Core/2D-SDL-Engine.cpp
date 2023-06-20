#include <iostream>
#include "2D-SDL-Engine.h"
#include "SDL.h"
#include "Renderer.h"
#include "FileManager.h"
#include "InputManager.h"

Engine::SDLEngine::SDLEngine(const std::string& dataPath)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	//turn into variable, probably global
	SDL_Window* pWindow = SDL_CreateWindow("Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1300, 987, SDL_WINDOW_OPENGL);

	Renderer::GetInstance().CreateRenderer(pWindow);
	FileManager::GetInstance().CreateFileManager(dataPath);
}

Engine::SDLEngine::~SDLEngine()
{
	Renderer::GetInstance().Destroy();
}

void Engine::SDLEngine::Run(const std::function<void()>& load)
{
	load();

	auto& input = InputManager::GetInstance();
	auto& renderer = Renderer::GetInstance();

	bool doContinue = true;

	while (doContinue)
	{
		doContinue = input.ProcessInput();

		
		renderer.Render();
	}
}
