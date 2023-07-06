#pragma once
#include "../Core/Singleton.h"
#include "../Observer/Subject.h"
#include <memory>

namespace Engine
{
	class Observer;
	class InputManager final : public Singleton<InputManager>
	{
	public:
		InputManager();
		bool ProcessInput();

		void AddObserver(Observer* pObserver);
		void RemoveObserver(Observer* pObserver);

		const int GetMouseX() const { return m_MouseX; }
		const int GetMouseY() const { return m_MouseY; }

	private:
		std::unique_ptr<Subject> m_pMouseSubject;

		int m_MouseX;
		int m_MouseY;
	};
}


