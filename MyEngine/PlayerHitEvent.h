#ifndef PlayerHitEvent_H
#define PlayerHitEvent_H

#include "EventManager.h"

namespace Events 
{
	class PlayerHitEvent : public Event
	{
	public:
		PlayerHitEvent();
		~PlayerHitEvent();
	};
}


#endif