#include "InverseControllerComponent.h"
#include "InputManager.h"
#include "MoveActions.h"
#include "ShootEvent.h"
#include "Entity.h"
#include "SARendererComponent.h"
#include "CollideEvent.h"
#include "ResourceManager.h"
#include <iostream>

extern InputManager* sdlInput;
extern Assets::ResourceManager* resources;

namespace Entities
{
	

	bool InverseControllerComponent::Initialize()
	{
		physics = GetOwner()->FindComponent<PhysicsComponent>();
		TurboShoot = false;
		tmpTimer = 0.0f;
		behCtrl = 0;
		return (physics != 0);
	}

	bool InverseControllerComponent::ShutDown()
	{
		return true;
	}

	void shootBullet(InverseControllerComponent* thisComponent)
	{
		Events::ShootEvent shootEvent;
		shootEvent.Entity = thisComponent->GetOwner();
		shootEvent.ProjectileOn = true;
		shootEvent.Entity->HandleEvent(&shootEvent);
	}

	void InverseControllerComponent::Update(float frameRate)
	{
		this->framerate = frameRate;
		Entity* owner = this->GetOwner();
		TransformComponent* ownerTrans = owner->FindComponent<TransformComponent>();

		float* angle = &ownerTrans->OrientationAngle;
		//std::cout << *angle;
		if (*angle <= -45)
			*angle = -45;
		if (*angle >= 45)
			*angle = 45;

		float* posY = &ownerTrans->Coords.y;
		if (*posY > mainWindow.wHeight() / 2)
			*posY = mainWindow.wHeight() / 2;
		if (*posY < 0)
			*posY = 0;

		Events::MoveEvent moveEvent;
		moveEvent.Entity = owner;

		if (sdlInput->IsKeyDown(SDL_SCANCODE_W))
		{
			//std::cout << "Printing up at " << framerate << "\n";
			moveEvent.MoveUp = true;
			moveEvent.Entity->HandleEvent(&moveEvent);
		}
		else
		{
			moveEvent.MoveUp = false;
			moveEvent.Entity->HandleEvent(&moveEvent);
		}

		if (sdlInput->IsKeyDown(SDL_SCANCODE_S))
		{
			//std::cout << "Printing down at " << framerate << "\n";
			moveEvent.MoveDown = true;
			moveEvent.Entity->HandleEvent(&moveEvent);
		}
		else
		{
			moveEvent.MoveDown = false;
			moveEvent.Entity->HandleEvent(&moveEvent);
		}

		if (sdlInput->IsKeyDown(SDL_SCANCODE_A))
		{
		//	std::cout << "rotating left at " << framerate << "\n";
			moveEvent.MoveLeft = true;
			moveEvent.Entity->HandleEvent(&moveEvent);
		}
		else
		{
			moveEvent.MoveLeft = false;
			moveEvent.Entity->HandleEvent(&moveEvent);
		}

		if (sdlInput->IsKeyDown(SDL_SCANCODE_D))
		{
			//std::cout << "Printing rigth at " << framerate << "\n";
			moveEvent.MoveRight = true;
			moveEvent.Entity->HandleEvent(&moveEvent);
		}
		else
		{
			moveEvent.MoveRight = false;
			moveEvent.Entity->HandleEvent(&moveEvent);
		}

		if (!sdlInput->IsKeyDown(SDL_SCANCODE_D) &&
			!sdlInput->IsKeyDown(SDL_SCANCODE_A) &&
			!sdlInput->IsKeyDown(SDL_SCANCODE_W) &&
			!sdlInput->IsKeyDown(SDL_SCANCODE_S))
		{
			//std::cout << "Stopped at  " << framerate << "\n";
			moveEvent.Idle = true;
			moveEvent.Entity->HandleEvent(&moveEvent);
		}
		else
		{
			moveEvent.Idle = false;
			moveEvent.Entity->HandleEvent(&moveEvent);
		}


		if (TurboShoot)
		{
			physics->VelocityY = 6; 
			if (sdlInput->IsKeyDown(SDL_SCANCODE_LALT) || sdlInput->IsKeyDown(SDL_SCANCODE_Q))
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
			if (sdlInput->IsKeyPressed(SDL_SCANCODE_LALT) || sdlInput->IsKeyPressed(SDL_SCANCODE_Q))
				shootBullet(this);
		}
		

	}

	void InverseControllerComponent::HandleEvent(Events::Event* pEvent)
	{
		
	}

}