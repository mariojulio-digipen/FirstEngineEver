#include "PhysicsComponent.h"
#include "Entity.h"
#include "TransformComponent.h"
#include "EventManager.h"
#include "MoveEvent.h"
#include "Circle.h"
#include "AABB.h"
#include "Shape.h"
#include "MyWindowComponent.h"
#include <iostream>

namespace Entities
{
	PhysicsComponent::PhysicsComponent()
	{
		VelocityY = 1;
		TotalForceX = 0;
		TotalForceY = 0;
		DirectionX = 0;
		DirectionY = 0;
		PrevPosX = 0.0f;
		PrevPosY = 0.0f;
		AccX = 0;
		AccY = 0;

		attachedShape = NULL;
	}

	PhysicsComponent::~PhysicsComponent()
	{
		delete attachedShape;
	}

	bool PhysicsComponent::Initialize()
	{
		Position = GetOwner()->FindComponent<TransformComponent>();
		if (!Position)
		{
			return false;
		}

		

		return true;
	}

	bool PhysicsComponent::ShutDown()
	{

		return true;
	}


	void PhysicsComponent::Integrate(float deltaTime)
	{
		Entity* owner = GetOwner();

		if (owner->ArcheType == Entities::EntityType::BULLET)
		{
			VelX = 300 * cosf(Position->OrientationAngle * (float)(3.14159265 / 180));
			Position->Coords.x = VelX*deltaTime + Position->Coords.x;

			VelY = 300 * sinf(Position->OrientationAngle * (float)(3.14159265 / 180));
			Position->Coords.y = VelY*deltaTime + Position->Coords.y;

		}
		else
		{
			TotalForceY += Gravity;
			AccY = TotalForceY * InvMass;
			VelY = AccY * deltaTime + VelY;
			if (Gravity != 0)
			{
				Position->Coords.y = VelY*deltaTime + Position->Coords.y;
			}
			else
			{
				Position->Coords.y = VelY*DirectionY*VelocityY*deltaTime + Position->Coords.y;
			}

			TotalForceX += Velocity;
			AccX = TotalForceX * InvMass;
			VelX = AccX * deltaTime + VelX;
			Position->Coords.x = VelX*DirectionX*deltaTime + Position->Coords.x;

			// Clear the force
			TotalForceX = 0;
			TotalForceY = 0;

		}

		
	}

	void PhysicsComponent::Update(float deltaTime)
	{
		
		//Position->X += Velocity;
		//Position->Y += Velocity;
	}

	void PhysicsComponent::HandleEvent(Events::Event* pEvent)
	{
		if (pEvent->Type == Events::EventType::MOVE)
		{
			Events::MoveEvent* pMoveEvent = dynamic_cast<Events::MoveEvent*>(pEvent);
			
			if (pMoveEvent->MoveUp)
			{
				DirectionY = -1;
				DirectionX = 0;
			}
				
			if (pMoveEvent->MoveDown)
			{
				DirectionY = 1;
				DirectionX = 0;
			}
				
			if (pMoveEvent->MoveRight)
			{
				DirectionX = 1;
				DirectionY = 0;
			}
				
			if (pMoveEvent->MoveLeft)
			{
				DirectionX = -1;
				DirectionY = 0;
			}

			if (pMoveEvent->MoveUp && pMoveEvent->MoveRight)
			{
				DirectionY = -1;
				DirectionX = 1;
			}

			if (pMoveEvent->MoveUp && pMoveEvent->MoveLeft)
			{
				DirectionY = -1;
				DirectionX = -1;
			}

			if (pMoveEvent->MoveDown && pMoveEvent->MoveLeft)
			{
				DirectionY = 1;
				DirectionX = -1;
			}

			if (pMoveEvent->MoveDown && pMoveEvent->MoveRight)
			{
				DirectionY = 1;
				DirectionX = 1;
			}

			if (pMoveEvent->Idle)
			{
				DirectionX = 0;
				DirectionY = 0;
			}
		}
	}

	bool PhysicsComponent::Serialize(FILE ** pfile)
	{
		
		//fscanf_s(*pfile, "%s\n", &Switch);
		fscanf_s(*pfile, "%f %f\n", &Gravity, &Velocity);
		fscanf_s(*pfile, "%f %f\n", &VelX, &VelY);
		VelX = VelX * 100;
		VelY = VelY * 100;
		fscanf_s(*pfile, "%f\n", &Mass);
		if (Mass)
			InvMass = 1.0f / Mass;
		else
			InvMass = 0.0f;

		char shapeName[256];
		memset(shapeName, 0, 256 * sizeof(char));
		fscanf_s(*pfile, "%255s\n", shapeName, sizeof(shapeName));
		if (strcmp(shapeName,"CIRCLE") == 0)
		{
			GetOwner()->GraphicType = shapeName;
			attachedShape = new Physics::Circle;
			attachedShape->OwnerBody = this;

			

			Physics::Circle* pCircle = dynamic_cast<Physics::Circle*>(attachedShape);
			fscanf_s(*pfile, "%f\n", &pCircle->Radius);

		}else if (strcmp(shapeName, "AABB") == 0)
		{
			attachedShape = new Physics::AABB;
			attachedShape->OwnerBody = this;
			GetOwner()->GraphicType = shapeName;

			Physics::AABB* pAABB = dynamic_cast<Physics::AABB*>(attachedShape);
			fscanf_s(*pfile, "%f %f %f %f\n", 
				&pAABB->Left, &pAABB->Top, &pAABB->Right, &pAABB->Bottom);

		}

		return true;		//validate errors later.
	}
}