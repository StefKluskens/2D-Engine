#pragma once
namespace Engine
{
	enum class Event
	{
		LeftMouseDown,
		LeftMouseUp
	};

	class Observer
	{
	public:
		~Observer() = default;
		virtual void Notify(Event event) = 0;
	};
}