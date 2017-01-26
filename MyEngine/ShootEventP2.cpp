#include "ShootEventP2.h"
#include "EventManager.h"
#include "Entity.h"

namespace Events
{


	ShootEventP2::ShootEventP2()
	{
		Entity = NULL;
		Type = EventType::SHOOT_P2;

		MoveDown = false;
		MoveUp = false;
		MoveRight = false;
		MoveLeft = false;
		ProjectileOn = false;
	}


	ShootEventP2::~ShootEventP2()
	{
	}

}