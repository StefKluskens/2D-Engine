#pragma once
#include <glm/vec2.hpp>

struct SDL_Texture;

namespace Engine
{
	class Texture final
	{
	public:
		explicit Texture(SDL_Texture* pTexture);
		~Texture();

		SDL_Texture* GetTexture() const;
		glm::ivec2 GetSize() const;

		Texture(const Texture&) = delete;
		Texture(Texture&&) = delete;
		Texture& operator= (const Texture&) = delete;
		Texture& operator= (const Texture&&) = delete;

	private:
		SDL_Texture* m_pTexture;
	};
}