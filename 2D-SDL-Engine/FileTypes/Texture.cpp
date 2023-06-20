#include "Texture.h"
#include <SDL.h>

Engine::Texture::Texture(SDL_Texture* pTexture)
	: m_pTexture(pTexture)
{
}

Engine::Texture::~Texture()
{
	SDL_DestroyTexture(m_pTexture);
}

SDL_Texture* Engine::Texture::GetTexture()
{
	return m_pTexture;
}

glm::ivec2 Engine::Texture::GetSize() const
{
	SDL_Rect dst;
	SDL_QueryTexture(m_pTexture, nullptr, nullptr, &dst.w, &dst.h);
	return { dst.w,dst.h };
}