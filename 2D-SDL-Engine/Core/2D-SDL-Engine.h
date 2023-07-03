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

		const std::string& GetWindowTitle() const { return m_WindowName; };
		const int GetWindowWidth() const { return m_WindowWidth; };
		const int GetWindowHeight() const { return m_WindowHeight; };

		//static SDL_Window* g_Window;

	private:
		const std::string m_WindowName{};
		const int m_WindowWidth{};
		const int m_WindowHeight{};
	};
}