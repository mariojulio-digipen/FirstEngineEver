#include "ShootEvent.h"
#include "EventManager.h"
#include "Entity.h"

namespace Events
{


	ShootEvent::ShootEvent()
	{
		Entity = NULL;
		Type = EventType::SHOOT_P1;

		MoveDown = false;
		MoveUp = false;
		MoveRight = false;
		MoveLeft = false;
		ProjectileOn = false;
	}


	ShootEvent::~ShootEvent()
	{
	}

}