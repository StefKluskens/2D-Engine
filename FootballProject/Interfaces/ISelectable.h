#pragma once

namespace Engine
{
	class GameObject;
}

namespace FP
{
	class ISelectable
	{
	public:
		virtual void OnSelect() = 0;
		virtual void OnDeselect() = 0;

		Engine::GameObject* GetOwner() const { return m_pOwner; }
	private:
		Engine::GameObject* m_pOwner;
	};
}