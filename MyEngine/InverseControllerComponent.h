#ifndef InverseControllerComponent_H
#define InverseControllerComponent_H

#include "Component.h"
#include "PhysicsComponent.h"
#include "MoveEvent.h"

namespace Entities
{

	class InverseControllerComponent : public Component
	{
	private:
		PhysicsComponent* physics;
		float framerate;

		float tmpTimer;
		int behCtrl;

	public:

		bool MoveUp;
		bool MoveDown;
		bool MoveRight;
		bool MoveLeft;
		bool Idle;
		bool TurboShoot;

		bool Initialize();
		bool ShutDown();
		void Update(float deltaTime);
		void HandleEvent(Events::Event* pEvent);
	};

}

#endif