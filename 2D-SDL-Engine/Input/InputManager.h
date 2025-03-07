#pragma once
#include "../Core/Singleton.h"
#include "../Observer/Subject.h"
#include <memory>
#include <glm/vec2.hpp>
#include <map>
#include <unordered_map>
#include "../Commands/Command.h"
#include <string>
#include <SDL.h>

namespace Engine
{
	class Observer;
	class SceneManager;

	class InputManager final : public Singleton<InputManager>
	{
	public:
		InputManager();
		bool ProcessInput();

		void AddObserver(Observer* pObserver);
		void RemoveObserver(Observer* pObserver);

		const int GetMouseX() const { return m_MouseX; }
		const int GetMouseY() const { return m_MouseY; }
		const glm::vec2 GetMousePos() const;

		void AddCommand(SDL_Scancode key, std::unique_ptr<Command> pCommand);

	private:
		SceneManager* m_pSceneManager{};

		std::unique_ptr<Subject> m_pMouseSubject;

		std::map<SDL_Scancode, std::unique_ptr<Command>> m_pCommands;

		int m_MouseX;
		int m_MouseY;
	};
}


