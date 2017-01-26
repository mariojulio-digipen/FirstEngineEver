#include "MoveEvent.h"

namespace Events
{

	MoveEvent::MoveEvent() : Event() // base class
	{
		Entity = NULL;
		Type = EventType::MOVE;
		MoveDown = false;
		MoveUp = false;
		MoveRight = false;
		MoveLeft = false;
	}


	MoveEvent::~MoveEvent()
	{
	}

}
