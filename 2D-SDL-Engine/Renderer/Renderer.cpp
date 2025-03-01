#include "Renderer.h"
#include "../FileTypes/Texture.h"
#include "../Core/SceneManager.h"

#include "imgui.h"
#include <backends/imgui_impl_sdl2.h>
#include <backends/imgui_impl_sdlrenderer.h>

void Engine::Renderer::CreateRenderer(SDL_Window* pWindow)
{
	m_pWindow = pWindow;

	m_pRenderer = SDL_CreateRenderer(m_pWindow, GetOpenGlIndex(), SDL_RENDERER_ACCELERATED);

	SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);

	SDL_RenderClear(m_pRenderer);

	SDL_RenderPresent(m_pRenderer);

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();

	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

	ImGui::StyleColorsDark();

	ImGui_ImplSDL2_InitForSDLRenderer(m_pWindow, m_pRenderer);
	ImGui_ImplSDLRenderer_Init(m_pRenderer);
}

void Engine::Renderer::Render() const
{
	ImGui_ImplSDLRenderer_NewFrame();
	ImGui_ImplSDL2_NewFrame(m_pWindow);
	ImGui::NewFrame();

	const auto& color = GetBackgroundColor();
	SDL_SetRenderDrawColor(m_pRenderer, color.r, color.g, color.b, color.a);
	SDL_RenderClear(m_pRenderer);

	SceneManager::GetInstance().Render();
	SceneManager::GetInstance().OnGuiRender();

	ImGui::Render();

	ImGui_ImplSDLRenderer_RenderDrawData(ImGui::GetDrawData());

	SDL_RenderPresent(m_pRenderer);
}

void Engine::Renderer::Destroy()
{
	if (m_pRenderer)
	{
		ImGui_ImplSDLRenderer_Shutdown();
		ImGui_ImplSDL2_Shutdown();
		ImGui::DestroyContext();

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
