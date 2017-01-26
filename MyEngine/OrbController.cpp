#include "OrbController.h"
#include "TransformComponent.h"
#include "Entity.h"
#include "CollideEvent.h"
#include "BulletController.h"
#include "ControllerComponent.h"
#include "InverseControllerComponent.h"
#include "PlayerHitEvent.h"


namespace Entities
{ 

	OrbController::OrbController()
	{
		rotationVelocity = 0.0f;
		state = RIGHT;
	}


	OrbController::~OrbController()
	{
	}

	bool OrbController::Initialize()
	{
		transform = GetOwner()->FindComponent<TransformComponent>();
		return true;
	}

	void OrbController::Update(float deltaTime)
	{
		switch (state)
		{
		case Entities::OrbController::RIGHT:
			transform->Coords.x += moveVelocity;
			if (transform->Coords.x >= xLimitRight)
				state = Entities::OrbController::DOWNWARDS;
			break;
		case Entities::OrbController::DOWNWARDS:
			transform->Coords.y += moveVelocity;
			if (transform->Coords.y >= yLimitBottom)
				state = Entities::OrbController::LEFT;
			break;
		case Entities::OrbController::LEFT:
			transform->Coords.x -= moveVelocity;
			if (transform->Coords.x <= xLimiteft)
				state = Entities::OrbController::UPWARDS;
			break;
		case Entities::OrbController::UPWARDS:
			transform->Coords.y -= moveVelocity;
			if (transform->Coords.y <= yLimitTop)
				state = Entities::OrbController::RIGHT;
			break;
		default:
			break;
		}
		
		transform->OrientationAngle += rotationVelocity;
	}

	bool OrbController::Serialize(FILE** pfile)
	{
		fscanf_s(*pfile, "%f %f %f %f %f %f\n", &xLimiteft, &xLimitRight, &yLimitTop, &yLimitBottom, &moveVelocity, &rotationVelocity);
		return true;
	}

	void OrbController::HandleEvent(Events::Event* pEvent)
	{
		if (pEvent->Type == Events::EventType::COLLIDE)
		{
			Events::CollideEvent* collideEvent = (Events::CollideEvent*)pEvent;
			Entities::Entity* collider = collideEvent->Entity1;
			Entities::Entity* collider2 = collideEvent->Entity2;
			if (collider2->ArcheType == Entities::EntityType::BULLET)
			{
				this->GetOwner()->Alive = false;
				collider2->Alive = false;
				Entity* player = collider2->FindComponent<BulletController>()->Creator;

				InverseControllerComponent* left = player->FindComponent<InverseControllerComponent>();
				ControllerComponent* right = player->FindComponent<ControllerComponent>();
				if(left)
					left->TurboShoot = true;
				if(right)
					right->TurboShoot = true;

			}
		}

		
	}


}
