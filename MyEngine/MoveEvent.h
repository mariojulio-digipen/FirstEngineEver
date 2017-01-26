#ifndef Events_H
#define Events_H

#include "EventManager.h"
#include "Entity.h"

namespace Events
{
	class MoveEvent : public Event
	{

	public:

		bool MoveUp;
		bool MoveDown;
		bool MoveRight;
		bool MoveLeft;
		bool Idle;

		MoveEvent();
		~MoveEvent();
		Entities::Entity* Entity;

	};

}

#endif

