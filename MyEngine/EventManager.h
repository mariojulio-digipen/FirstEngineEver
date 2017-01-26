#ifndef Event_H
#define Event_H

#include <list>
#include <vector>

namespace Entities
{
	class Entity;
}

namespace Events
{
	enum EventType
	{
		MOVE,
		COLLIDE,
		PLAYERHIT,
		SHOOT_P1,
		SHOOT_P2,
		Max
	};

	class Event
	{

	public:
		Event();
		virtual ~Event();

		EventType Type;
		float Timer;
	};

	class EventManager
	{
	public:
		EventManager();
		~EventManager();

		std::vector<Entities::Entity*> ClientEntities;
		void BroadcastTo(std::vector<Entities::Entity*> thisClientEvents);	// Used to initialize Events' clients (the entities)
		void DispatchEvent(Event* pEvent);
		void AddTimedEvent(Event* pEvent);
		void Update(float deltaTime);
		void UpdateClientEntitiesToBroadCast(Entities::Entity* newEntity);
		std::list<Event*> TimedEvents;		//for timed events ??

	};

}


#endif

