#include "FileManager.h"
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "Renderer.h"
#include "../FileTypes/Texture.h"

void Engine::FileManager::CreateFileManager(std::string dataPath)
{
	m_DataPath = dataPath;

	TTF_Init();
}

std::shared_ptr<Engine::Texture> Engine::FileManager::LoadTexture(const std::string filePath) const
{
	const auto path = m_DataPath + filePath;
	auto texture = IMG_LoadTexture(Renderer::GetInstance().GetRenderer(), path.c_str());

	if (!texture)
	{
		//handle error
		return nullptr;
	}

	return std::make_shared<Texture>(texture);
}
