#pragma once
#include "Commands/Command.h"

namespace Engine
{
	class GameObject;
}

namespace SB
{
	class MoveCommand final : public Engine::Command
	{
	public:
		MoveCommand(Engine::GameObject* pObject);
		void Execute() override;
	};
}