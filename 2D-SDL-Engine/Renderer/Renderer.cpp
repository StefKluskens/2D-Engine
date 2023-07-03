#include "Renderer.h"
#include "../FileTypes/Texture.h"
#include "../Core/SceneManager.h"

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
	const auto& color = GetBackgroundColor();
	SDL_SetRenderDrawColor(m_pRenderer, color.r, color.g, color.b, color.a);
	SDL_RenderClear(m_pRenderer);

	SceneManager::GetInstance().Render();

	SDL_RenderPresent(m_pRenderer);
}

void Engine::Renderer::Destroy()
{
	if (m_pRenderer)
	{
		SDL_DestroyRenderer(m_pRenderer);
		m_pRenderer = nullptr;
	}
}

void Engine::Renderer::RenderTexture(const Texture& texture, float x, float y) const
{
	SDL_Rect dst{};
	dst.x = static_cast<int>(x);
	dst.y = static_cast<int>(y);
	SDL_QueryTexture(texture.GetTexture(), nullptr, nullptr, &dst.w, &dst.h);
	SDL_RenderCopy(GetRenderer(), texture.GetTexture(), nullptr, &dst);
}

void Engine::Renderer::RenderTexture(const Texture& texture, glm::vec2 position) const
{
	RenderTexture(texture, position.x, position.y);
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
