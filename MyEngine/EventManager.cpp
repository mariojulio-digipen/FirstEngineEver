#include "EventManager.h"
#include "Entity.h"
#include "Component.h"

namespace Events
{
	Event::Event()
	{
		Timer = 0;
	}


	Event::~Event()
	{

	}

	EventManager::EventManager()
	{

	}


	EventManager::~EventManager()
	{
		for (auto i:TimedEvents)
			delete i;
		TimedEvents.clear();
	}

	void EventManager::BroadcastTo(std::vector<Entities::Entity*> thisClientEvents)
	{
		this->ClientEntities = thisClientEvents;
		for (Entities::Entity* entities : ClientEntities)
		{
			Entities::Component** comp = entities->GetAllComponents();
			Entities::Component* next = NULL;
			for (int i = 0; i < entities->NumComponents; i++)
			{
				next = comp[i];
				next->SetEventManager(this);
			}
		}
	}

	void EventManager::UpdateClientEntitiesToBroadCast(Entities::Entity* newEntity)
	{
		Entities::Component** comp = newEntity->GetAllComponents();
		Entities::Component* next = NULL;
		for (int i = 0; i < newEntity->NumComponents; i++)
		{
			next = comp[i];
			next->SetEventManager(this);
		}
	}

	void EventManager::DispatchEvent(Event * pEvent)
	{
		for (Entities::Entity* entities: ClientEntities)
		{
			entities->HandleEvent(pEvent);
		}
	}

	void EventManager::AddTimedEvent(Event * pEvent)
	{
		TimedEvents.push_back(pEvent);
	}

	void EventManager::Update(float deltaTime)
	{
		// Update the timer of every event

		// If timer is <=0, broadcast event
		if (TimedEvents.size() <= 0)
		{
			return;
		}

		std::list<Event*>::iterator itNext, itTemp, itEnd;
		itNext = TimedEvents.begin();
		itEnd = TimedEvents.end();
		while (itNext != itEnd)
		{
			Event* pEvent = *itNext;

			pEvent->Timer -= deltaTime;
			if (pEvent->Timer <= 0.0f)
			{
				DispatchEvent(pEvent);
				delete pEvent;
				itTemp = itNext;
				++itTemp;
				TimedEvents.erase(itNext);	//memory leak when using vectors
				itNext = itTemp;
			}
			else
			{
				++itNext;
			}

		}


	}


}

