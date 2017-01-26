#ifndef CollideEvent_H
#define CollideEvent_H

#include "EventManager.h"
#include "Entity.h"

namespace Entities
{
	class Entity;
}


namespace Events
{
	class CollideEvent : public Event
	{
	public:
		CollideEvent();
		~CollideEvent();

		Entities::Entity* Entity1;
		Entities::Entity* Entity2;
	};
}


#endif