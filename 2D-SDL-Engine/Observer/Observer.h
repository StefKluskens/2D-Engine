#pragma once
namespace Engine
{
	enum class Event
	{
		LeftMouseDown,
		LeftMouseUp,
		RightMouseDown,
		RightMouseUp
	};

	class Observer
	{
	public:
		~Observer() = default;
		virtual void Notify(Event event) = 0;
	};
}