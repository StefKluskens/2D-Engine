#include "Renderer.h"

void Engine::Renderer::CreateRenderer(SDL_Window* pWindow)
{
	m_pWindow = pWindow;

	m_pRenderer = SDL_CreateRenderer(m_pWindow, GetOpenGlIndex(), SDL_RENDERER_ACCELERATED);

	SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);

	SDL_RenderClear(m_pRenderer);

	SDL_RenderPresent(m_pRenderer);
}

void Engine::Renderer::Render() const
{
}

void Engine::Renderer::Destroy()
{
	if (m_pRenderer)
	{
		SDL_DestroyRenderer(m_pRenderer);
		m_pRenderer = nullptr;
	}
}

int Engine::Renderer::GetOpenGlIndex()
{
	auto index = -1;
	const auto driverCount = SDL_GetNumRenderDrivers();
	for (auto i = 0; i < driverCount; ++i)
	{
		SDL_RendererInfo info;
		if (!SDL_GetRenderDriverInfo(i, &info))
		{
			if (!strcmp(info.name, "opengl"))
			{
				index = i;
			}
		}
	}

	return index;
}
