#include "EnemyController.h"
#include "Entity.h"
#include "TransformComponent.h"
#include "PhysicsComponent.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include "FramerateController.h"
#include "RollingTabletData.h"
#include "ShootEventP2.h"
#include <algorithm>

extern InputManager* sdlInput;
extern Utils::FramerateController* framerateController;
extern Assets::ResourceManager* resources;
extern RollingTabletData* rollingTableData;

namespace Entities
{
	struct GetAlien
	{
		Entities::Entity** alien;
		GetAlien() {};
		GetAlien(Entities::Entity** alien) : alien(alien) {};
		void operator() (Entities::Entity* entity)
		{
			if (entity->ArcheType == Entities::EntityType::ENEMY_ALIEN)
				(*alien) = entity;
		}
	};


	EnemyController::EnemyController()
	{
	}


	EnemyController::~EnemyController()
	{
	}

	bool EnemyController::Initialize()
	{
		owner = GetOwner();
		thisEnemytransform = owner->FindComponent<TransformComponent>();
		
		controlAngle = 0.0f;
		timer = 0.0f;
		oscilationRange = 150.0f;
		counterController = rollingTableData->GameLogicCounterController;
		return true;
	}

	void EnemyController::Update(float deltaTime)
	{
		int rand;
		int rand2;
		int rand3;

		controlAngle += 100 * deltaTime;
		timer += deltaTime;

		

		if ((owner->Name.compare("Enemy1Bottom") == 0) || (owner->Name.compare("Enemy1Top") == 0))
		{
			thisEnemytransform->Coords.y = oscilationRange * sinf(controlAngle * (float)(3.14159265 / 180)) - offset;
			thisEnemytransform->Coords.x = 25 * cosf(controlAngle * (float)(3.14159265 / 180)) + 150;

			//printf("%f\n", timer);
			behaviorController = (int)timer % 20;


			rand = rollingTableData->EnemyLeftData;
			rand2 = rollingTableData->EnemyLeftData2;
			rand3 = rollingTableData->EnemyLeftData3;

			if (behaviorController == 19)
			{
				if(oscilationRange < 150)
					oscilationRange += counterController + rand;
				return;
			}
			
			if (behaviorController == 0 || behaviorController == 1)
			{
				oscilationRange += counterController + rand;// 3;

			}
			else if (behaviorController == 2 || behaviorController == 3)
			{
				oscilationRange -= counterController + rand;// + 1;

			}
			else if (behaviorController == 4 || behaviorController == 5)
			{
				oscilationRange += counterController + rand2;// + 1;

			}
			else if (behaviorController == 6 || behaviorController == 7)
			{
				oscilationRange -= counterController + rand2;// + 2;

			}
			else if (behaviorController == 8 || behaviorController == 9)
			{
				oscilationRange += counterController + rand3;// + 2;

			}
			else if (behaviorController == 10 || behaviorController == 11)
			{
				oscilationRange -= counterController + rand3;//;

			}
			else if (behaviorController >= 12)
			{
				if (oscilationRange > 0)
				{
					oscilationRange -= counterController + rand;
					Events::ShootEventP2 alienEvent;
					/*if (alienEvent.Entity)
					{*/
						GetAlien myalien(&alienEvent.Entity);
						alienEvent.ProjectileOn = true;
						if (oscilationRange <= 1)
						{
							std::for_each(resources->LevelEntities.begin(), resources->LevelEntities.end(), myalien);
							if (alienEvent.Entity)
							{
								alienEvent.Entity->HandleEvent(&alienEvent);
							}
						}
					
					
					
				}

			}

			//printf("%f degrees\n", oscilationRange);
		}
		
		if ((owner->Name.compare("Enemy1BottomRight") == 0) || (owner->Name.compare("Enemy1TopRight") == 0))
		{
			thisEnemytransform->Coords.y = -oscilationRange * sinf(controlAngle * (float)(3.14159265 / 180)) - offset;
			thisEnemytransform->Coords.x = 25 * cosf(controlAngle * (float)(3.14159265 / 180)) + 750;

			//printf("%f\n", timer);
			behaviorController = (int)timer % 20;


			rand = rollingTableData->EnemyRightData;
			rand2 = rollingTableData->EnemyRightData2;
			rand3 = rollingTableData->EnemyRightData3;

			if (behaviorController == 19)
			{
				if (oscilationRange < 150)
					oscilationRange += counterController + rand;
				return;
			}

			if (behaviorController == 0 || behaviorController == 1)
			{
				oscilationRange += counterController + rand;// 3;

			}
			else if (behaviorController == 2 || behaviorController == 3)
			{
				oscilationRange -= counterController + rand;// + 1;

			}
			else if (behaviorController == 4 || behaviorController == 5)
			{
				oscilationRange += counterController + rand2;// + 1;

			}
			else if (behaviorController == 6 || behaviorController == 7)
			{
				oscilationRange -= counterController + rand2;// + 2;

			}
			else if (behaviorController == 8 || behaviorController == 9)
			{
				oscilationRange += counterController + rand3;// + 2;

			}
			else if (behaviorController == 10 || behaviorController == 11)
			{
				oscilationRange -= counterController + rand3;//;

			}
			else if (behaviorController >= 12)
			{
				if (oscilationRange > 0)
					oscilationRange -= counterController + rand;
			}

			//printf("%f degrees\n", oscilationRange);
		}
		
	}

	bool EnemyController::Serialize(FILE** pfile)
	{
		fscanf_s(*pfile, "%i\n", &offset);
		return true;
	}
	void EnemyController::HandleEvent(Events::Event* pEvent)

	{

	}

}