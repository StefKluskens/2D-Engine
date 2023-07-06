#pragma once
#include "Observer.h"
#include <vector>

namespace Engine
{
	class Subject final
	{
	public:
		Subject() = default;
		~Subject() = default;
		void AddObserver(Observer* pObserver);
		void RemoveObserver(Observer* pObserver);
		void Notify(Event event);

	private:
		std::vector<Observer*> m_pObservers;
	};
}