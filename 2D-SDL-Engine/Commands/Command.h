#pragma once
namespace Engine
{
	class GameObject;

	class Command
	{
	public:
		enum class ButtonState
		{
			IsDown,
			IsUp,
			IsPressed,
			None
		};

		Command(GameObject* pObject);
		virtual ~Command() {};
		virtual void Execute() = 0;
		//virtual ButtonState GetButtonState() = 0;

		const Engine::GameObject* GetObject() const { return m_pObject; }

	protected:
			GameObject* m_pObject;
	};
}