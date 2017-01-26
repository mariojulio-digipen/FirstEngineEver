#ifndef ShootEventP2_H
#define ShootEventP2_H

#include "EventManager.h"


namespace Entities
{
	class Entity;
}


namespace Events
{

	class ShootEventP2 : public Event
	{
	public:

		bool MoveUp;
		bool MoveDown;
		bool MoveRight;
		bool MoveLeft;

		bool ProjectileOn;

		Entities::Entity* Entity;

		ShootEventP2();
		~ShootEventP2();


	};

}
#endif