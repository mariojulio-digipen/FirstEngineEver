#ifndef ShootEvent_H
#define ShootEvent_H

#include "EventManager.h"


namespace Entities
{
	class Entity;
}


namespace Events
{

	class ShootEvent : public Event
	{
	public:

		bool MoveUp;
		bool MoveDown;
		bool MoveRight;
		bool MoveLeft;

		bool ProjectileOn;

		Entities::Entity* Entity;

		ShootEvent();
		~ShootEvent();


	};

}
#endif