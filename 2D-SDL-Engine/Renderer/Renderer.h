#pragma once
#include <SDL.h>
#include "../Core/Singleton.h"
#include <memory>
#include <glm/glm.hpp>

namespace Engine
{
	class Texture;
	class Renderer final : public Singleton<Renderer>
	{
	public:
		void CreateRenderer(SDL_Window* pWindow);
		void Render() const;
		void Destroy();

		SDL_Renderer* GetRenderer() const { return m_pRenderer; }

		void RenderTexture(const Texture& texture, float x, float y) const;
		void RenderTexture(const Texture& texture, glm::vec2 position) const;

		const SDL_Color& GetBackgroundColor() const { return m_pBackGroundColour; }
		void SetBackgroundColor(const SDL_Color& color) { m_pBackGroundColour = color; }

	private:
		int GetOpenGlIndex();

		SDL_Window* m_pWindow{};
		SDL_Color m_pBackGroundColour{};
		SDL_Renderer* m_pRenderer{};
	};
}