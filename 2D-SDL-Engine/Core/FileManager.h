#pragma once
#include "Singleton.h"
#include <string>
#include <memory>

namespace Engine
{
	class Texture;

	class FileManager final : public Singleton<FileManager>
	{
	public:
		void CreateFileManager(std::string dataPath);

		//std::shared_ptr<Texture> LoadTexture(const std::string filePath) const;
		std::unique_ptr<Texture> LoadTexture(const std::string filePath) const;

	private:
		friend class Singleton<FileManager>;
		FileManager() = default;

		std::string m_DataPath{};
	};
}