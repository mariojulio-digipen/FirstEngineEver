#ifndef CONTROLLERCOMPONENT_H
#define CONTROLLERCOMPONENT_H

#include "Component.h"
#include "PhysicsComponent.h"
#include "MoveEvent.h"

namespace Entities
{

	class ControllerComponent : public Component
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
		void Update(float deltaTime);
		bool ShutDown();
		bool Serialize(FILE** pfile);
		void HandleEvent(Events::Event* pEvent);
	};

}

#endif