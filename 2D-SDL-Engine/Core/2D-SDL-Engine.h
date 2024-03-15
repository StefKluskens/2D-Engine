#pragma once
#include <string>
#include <functional>
namespace Engine
{
	class SDLEngine final
	{
	public:
		explicit SDLEngine(const std::string& dataPath, const std::string& windowTitle);

		~SDLEngine();
		void Run(const std::function<void()>& load);

		SDLEngine(const SDLEngine& other) = delete;
		SDLEngine(SDLEngine&& other) = delete;
		SDLEngine& operator=(const SDLEngine& other) = delete;
		SDLEngine& operator=(SDLEngine&& other) = delete;

		/*const std::string& GetWindowTitle() const { return m_WindowName; };*/

	private:
		//const std::string m_WindowName{};
	};
}