#pragma once
#include "../Core/Singleton.h"

namespace Engine
{
	class InputManager final : public Singleton<InputManager>
	{
	public:
		InputManager();
		bool ProcessInput();

	private:
	};
}


