#ifndef PhysicsComponent_H
#define PhysicsComponent_H

#include "Component.h"
#include "TransformComponent.h"
#include "Shape.h"


namespace Entities
{
	class Component;
	class TransformComponent;

	class PhysicsComponent : public Component
	{
	private:


	public:
		
		TransformComponent* Position;
		Physics::Shape* attachedShape;

		//char Switch[3];
		int Velocity;
		int VelocityY;
		float Gravity;
		//float PosX;
		//float PosY;

		float PrevPosX;
		float PrevPosY;

		float AccX;
		float AccY;

		float VelX;
		float VelY;

		float TotalForceX;
		float TotalForceY;

		float Mass;
		float InvMass;

		float DirectionX;
		float DirectionY;

		

		PhysicsComponent();
		~PhysicsComponent();
		bool Initialize();
		bool ShutDown();
		void Integrate(float deltaTime);
		void Update(float deltaTime);
		bool Serialize(FILE ** pfile);
		void HandleEvent(Events::Event* pEvent);
	};

}


#endif
