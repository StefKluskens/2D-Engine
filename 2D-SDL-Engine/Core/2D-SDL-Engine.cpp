#include <iostream>
#include "2D-SDL-Engine.h"
#include "SDL.h"
#include "../Renderer/Renderer.h"
#include "FileManager.h"
#include "../Input/InputManager.h"
#include "SceneManager.h"
#include <chrono>
#include "../Window/WindowManager.h"

SDL_Window* g_Window{};

Engine::SDLEngine::SDLEngine(const std::string& dataPath, const std::string& windowTitle)
	//: m_WindowName("Window")
{
	SDL_Init(SDL_INIT_EVERYTHING);

	g_Window = SDL_CreateWindow(
		windowTitle.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		g_WindowWidth,
		g_WindowHeight,
		SDL_WINDOW_OPENGL);
	//SDL_SetWindowFullscreen(g_Window, SDL_WINDOW_INPUT_FOCUS);

	Renderer::GetInstance().CreateRenderer(g_Window);
	FileManager::GetInstance().CreateFileManager(dataPath);
}

Engine::SDLEngine::~SDLEngine()
{
	Renderer::GetInstance().Destroy();
	SDL_DestroyWindow(g_Window);
	g_Window = nullptr;
	SDL_Quit();
}

void Engine::SDLEngine::Run(const std::function<void()>& load)
{
	load();

	auto& input = InputManager::GetInstance();
	auto& renderer = Renderer::GetInstance();
	auto& sceneManager = SceneManager::GetInstance();

	bool doContinue = true;
	auto lastTime = std::chrono::high_resolution_clock::now();
	int frameTimeMs = 6;
	float lag = 0.f;
	const float fixedTimeStepSec{ 0.02f };

	while (doContinue)
	{
		const auto currentTime = std::chrono::high_resolution_clock::now();
		const float deltaTime = std::chrono::duration<float>(currentTime - lastTime).count();

		lastTime = currentTime;
		lag += deltaTime;

		doContinue = input.ProcessInput();

		while (lag >= fixedTimeStepSec)
		{
			sceneManager.FixedUpdate(fixedTimeStepSec);
			lag -= fixedTimeStepSec;
		}

		sceneManager.Update(deltaTime);
		renderer.Render();

		const auto sleepTime = currentTime + std::chrono::milliseconds(frameTimeMs) - std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(sleepTime);
	}
}
