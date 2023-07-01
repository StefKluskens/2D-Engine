#pragma once
#include <SDL.h>
#include "../Core/Singleton.h"
#include <memory>

namespace Engine
{
	class Renderer final : public Singleton<Renderer>
	{
	public:
		void CreateRenderer(SDL_Window* pWindow);
		void Render() const;
		void Destroy();

		SDL_Renderer* GetRenderer() const { return m_pRenderer; }

	private:
		int GetOpenGlIndex();

		SDL_Window* m_pWindow{};
		SDL_Color* m_pBackGroundColour{};
		SDL_Renderer* m_pRenderer{};
	};
}