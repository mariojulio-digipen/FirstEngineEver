#include "EnemyAlienController.h"
#include "TransformComponent.h"
#include "Entity.h"
#include "ResourceManager.h"

extern Assets::ResourceManager* resources;

namespace Entities
{
	int getRand(int min, int max)
	{
		int r = (rand() % max) + min;
		return r;
	}

	EnemyAlienController::EnemyAlienController()
	{

	}


	EnemyAlienController::~EnemyAlienController()
	{
	}


	void EnemyAlienController::Update(float deltaTime)
	{
		
		transform = owner->FindComponent<TransformComponent>();

		if (Status == 0)
		{
			/*transform->Coords.x = 650.0f;
			transform->Coords.y = -50.0f;
			radius = 200.0f;
			offset.x = 450.0f;
			offset.y = -50.0f;*/

			transform->Coords.x = defaultCoords.x;
			transform->Coords.y = defaultCoords.y;
			radius = defaultRadius;
			offset.x = defaultOffsets.x;
			offset.y = defaultOffsets.y;


		}
		else
		{
			/*printf("transform->Coords.x: %f\n", transform->Coords.x);
			printf("transform->Coords.y: %f\n", transform->Coords.y);
			printf("radius: %f\n", radius);
			printf("offset.x: %f\n", offset.x);
			printf("offset.y: %f\n", offset.y);
			printf("=========================================================================\n");*/
			if (deltaTime > 0.0f)
			{
				// shoot dust:
				resources->DynamicCreation = true;
				if (transform->Coords.y >= -50) {
					resources->CreateDust("Dust", "DustParticle", 
						transform->Coords.x + getRand(1,10), transform->Coords.y + getRand(1, 10), owner);
					resources->CreateDust("Dust", "DustParticle",
						transform->Coords.x + getRand(1, 10), transform->Coords.y + getRand(1, 10), owner);
					resources->CreateDust("Dust", "DustParticle",
						transform->Coords.x + getRand(1, 10), transform->Coords.y + getRand(1, 10), owner);
				}
					


				transform->Coords.x = radius * cosf(angle * (float)(3.14159265 / 180)) + offset.x;
				transform->Coords.y = radius * sinf(angle * (float)(3.14159265 / 180)) + offset.y;
				angle += 100 * deltaTime;
				if (angle >= 360)
				{
					
					angle = 0.0f;
					Status = 0;		// idle mode!
				}
			}
		}
		
		
	}

	bool EnemyAlienController::Initialize()
	{
		owner = GetOwner();
		Status = 0;		// 0 = idle , 1 = attack

		transform = owner->FindComponent<TransformComponent>();
		Vector3DSet(&defaultCoords, transform->Coords.x, transform->Coords.y, 0.0f);
		return true;
	}

	bool EnemyAlienController::Serialize(FILE** pfile)
	{
		fscanf_s(*pfile, "%f %f %f %f\n", &offset.x, &offset.y, &radius, &angle);
		Vector3DSet(&defaultOffsets, offset.x, offset.y, 0.0f);
		defaultRadius = radius;

		return true;
	}

	void EnemyAlienController::HandleEvent(Events::Event* pEvent)
	{
		if (pEvent->Type == Events::EventType::SHOOT_P2)
		{
			Status = 1;		// Attack mode!
		}

	}

	bool EnemyAlienController::ShutDown()
	{
		return true;
	}

}
