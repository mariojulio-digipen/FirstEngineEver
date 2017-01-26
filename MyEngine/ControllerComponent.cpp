#include "ControllerComponent.h"
#include "InputManager.h"
#include "MoveActions.h"
#include "Entity.h"
#include "SARendererComponent.h"
#include "CollideEvent.h"
#include "PlayerHitEvent.h"
#include "ShootEvent.h"
#include "ResourceManager.h"
#include <iostream>


extern Assets::ResourceManager* resources;
extern InputManager* sdlInput;

namespace Entities
{
	bool ControllerComponent::Initialize()
	{
		physics = GetOwner()->FindComponent<PhysicsComponent>(); 
		TurboShoot = false;
		tmpTimer = 0.0f;
		behCtrl = 0;
		return (physics != 0);
	}

	bool ControllerComponent::ShutDown()
	{
		return true;
	}

	bool ControllerComponent::Serialize(FILE** pfile)
	{
		return true;
	}

	void shootBullet(ControllerComponent* thisComponent)
	{
		Events::ShootEvent shootEvent;
		shootEvent.Entity = thisComponent->GetOwner();
		shootEvent.ProjectileOn = true;
		shootEvent.Entity->HandleEvent(&shootEvent);
	}

	void ControllerComponent::Update(float frameRate)
	{
		this->framerate = frameRate;

		Entity* owner = this->GetOwner();
		TransformComponent* ownerTrans = owner->FindComponent<TransformComponent>();

		float* angle = &ownerTrans->OrientationAngle;
		//std::cout << *angle;
		if (*angle >= 225)
			*angle = 225;
		if (*angle <= 135)
			*angle = 135;

		float* posY = &ownerTrans->Coords.y;
		if (*posY > mainWindow.wHeight() / 2)
			*posY = mainWindow.wHeight() / 2;
		if (*posY < 0)
			*posY = 0;


		Events::MoveEvent moveEvent;
		moveEvent.Entity = owner;

		if (sdlInput->IsKeyDown(SDL_SCANCODE_UP))
		{
			moveEvent.MoveUp = true;
			moveEvent.Entity->HandleEvent(&moveEvent);
		}
		else
		{
			moveEvent.MoveUp = false;
			moveEvent.Entity->HandleEvent(&moveEvent);
		}

		bool tt = sdlInput->IsKeyDown(SDL_SCANCODE_DOWN);
		if (tt)
		{
			moveEvent.MoveDown = true;
			moveEvent.Entity->HandleEvent(&moveEvent);
		}
		else
		{
			moveEvent.MoveDown = false;
			moveEvent.Entity->HandleEvent(&moveEvent);
		}

		if (sdlInput->IsKeyDown(SDL_SCANCODE_LEFT))
		{
			moveEvent.MoveLeft = true;
			moveEvent.Entity->HandleEvent(&moveEvent);
		}
		else
		{
			moveEvent.MoveLeft = false;
			moveEvent.Entity->HandleEvent(&moveEvent);
		}

		if (sdlInput->IsKeyDown(SDL_SCANCODE_RIGHT))
		{
			moveEvent.MoveRight = true;
			moveEvent.Entity->HandleEvent(&moveEvent);
		}
		else
		{
			moveEvent.MoveRight = false;
			moveEvent.Entity->HandleEvent(&moveEvent);
		}
		if (!sdlInput->IsKeyDown(SDL_SCANCODE_UP) &&
			!sdlInput->IsKeyDown(SDL_SCANCODE_DOWN) &&
			!sdlInput->IsKeyDown(SDL_SCANCODE_LEFT) &&
			!sdlInput->IsKeyDown(SDL_SCANCODE_RIGHT))
		{
			moveEvent.Idle = true;
			moveEvent.Entity->HandleEvent(&moveEvent);
		}
		else
		{
			moveEvent.Idle = false;
			moveEvent.Entity->HandleEvent(&moveEvent);
		}


		// shoot with RIGHT CONTROL key!
		

		// Stress Testing
		
		if (TurboShoot)
		{
			physics->VelocityY = 6; 
			if (sdlInput->IsKeyDown(SDL_SCANCODE_RCTRL))		// for testing, can be switched to other IsKey functions 
				shootBullet(this);
			tmpTimer += frameRate;
			if (tmpTimer > 0)
			{
				behCtrl = (int)tmpTimer % 5;
				printf("SECONDS THAT THE POWERUP LASTS--------------->%i\n", behCtrl);
				//printf("==============================\n");
				if (behCtrl == 4)
				{
					TurboShoot = false;
					physics->VelocityY = 1;
					tmpTimer = 0;
					resources->CreateNewOrb();
				}
			}

			

		}
		else
		{
			if (sdlInput->IsKeyPressed(SDL_SCANCODE_RCTRL))
				shootBullet(this);
		}

	}



	void ControllerComponent::HandleEvent(Events::Event* pEvent)
	{
		
	}

}