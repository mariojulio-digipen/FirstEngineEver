#include "CollideEvent.h"

namespace Events
{
	CollideEvent::CollideEvent()
	{
		Entity1 = NULL;
		Entity2 = NULL;
		Type = EventType::COLLIDE;
	}


	CollideEvent::~CollideEvent()
	{
	}
}


