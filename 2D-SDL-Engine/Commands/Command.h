#pragma once
#include "../Core/Singleton.h"

namespace Engine
{
	class Scene;

	class Command : public Singleton<Command>
	{
	public:
		enum class ButtonState
		{
			IsDown,
			IsUp,
			IsPressed,
			None
		};

		explicit Command(Scene* pScene) : m_pScene(pScene) {};
		virtual ~Command() {};
		virtual void Execute(float deltaTime) = 0;
		virtual ButtonState GetButtonState() = 0;

		Scene* GetScene() const { return m_pScene; };
		void SetScene(Scene* pScene) { m_pScene = pScene; }

	private:
		Scene* m_pScene{};
	};
}