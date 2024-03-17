#include "Subject.h"

void Engine::Subject::AddObserver(Observer* pObserver)
{
	m_pObservers.push_back(pObserver);
}

void Engine::Subject::RemoveObserver(Observer* pObserver)
{
	for (size_t i = 0; i < m_pObservers.size(); ++i)
	{
		if (m_pObservers[i] == pObserver)
		{
			m_pObservers.erase(std::remove(m_pObservers.begin(), m_pObservers.end(), pObserver));
			break;
		}
	}
}

void Engine::Subject::Notify(Event event)
{
	for (int i = 0; i < m_pObservers.size(); ++i)
	{
		m_pObservers[i]->Notify(event);
	}
}
