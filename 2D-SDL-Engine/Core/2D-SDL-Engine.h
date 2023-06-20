#pragma once
#include <string>
#include <functional>

namespace Engine
{
	class SDLEngine final
	{
	public:
		explicit SDLEngine(const std::string& dataPath);
		~SDLEngine();
		void Run(const std::function<void()>& load);

		SDLEngine(const SDLEngine& other) = delete;
		SDLEngine(SDLEngine&& other) = delete;
		SDLEngine& operator=(const SDLEngine& other) = delete;
		SDLEngine& operator=(SDLEngine&& other) = delete;
	};
}