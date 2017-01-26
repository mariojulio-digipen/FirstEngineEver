#include "ResourceManager.h"
#include "Camera.h"
#include "EventManager.h"
#include "PhysicsManager.h"
#include "RollingTabletData.h"
#include "EnemyController.h"
#include "EnemyAlienController.h"
#include "DustController.h"
#include "OrbController.h"

extern Events::EventManager* eventManager;
extern Physics::PhysicsManager* physicsManager;
extern RollingTabletData* rollingTableData;

namespace Assets
{
	

	ResourceManager::ResourceManager() : idCounter(0)
	{
	}

	ResourceManager::~ResourceManager()
	{

	}


	bool ResourceManager::InitializeAssets(const char* levelFileName)
	{
		FILE *fp;
		fopen_s(&fp, levelFileName, "r");
		if (fp)
		{
			while (!feof(fp))
			{
				char entityName[256];
				memset(entityName, 0, 256 * sizeof(char));
				
				fscanf_s(fp, "%s\n", entityName, sizeof(entityName));
				if (strcmp(entityName, "Camera") != 0)
				{
					if (strcmp(entityName, "Checker") == 0)
					{
						createLevelCheckers();
					}
					else
					{
						Entities::Entity* pEntity = loadEntity(entityName);
						std::cout << "Initializing entity \"" << pEntity->Name << "\" and its components...\n";
						pEntity->Initialize();
						Entities::RoulletteComponent* roullette = pEntity->FindComponent<Entities::RoulletteComponent>();
						if (roullette)
							roullette->SetCheckerData();
						LevelEntities.push_back(pEntity);
					}
					
				}else
				{
					std::cout << "Initializing camera parameters...\n";
					memset(entityName, 0, 256 * sizeof(char));
					fscanf_s(fp, "%f %f %f\n", &mainCamera.OffsetX, &mainCamera.OffsetY, &mainCamera.RotationAngle);
					float x = mainCamera.OffsetX;
					float y = mainCamera.OffsetY;
					float rot = mainCamera.RotationAngle;
					mainCamera.Initialize();
				}


			}
		}
		
		int entities_num = LevelEntities.size();			//It's for debugging purposes
		
		mainCamera.Initialize();
		std::cout << "Initializing entities succeed!" << std::endl;

		return true;
	}
	bool ResourceManager::DisposeAssets()
	{
		for (unsigned i = 0; i < LevelEntities.size(); i++)
		{
			assert(LevelEntities.at(i) == NULL);
			LevelEntities.at(i)->ShutDown();
		}
		return true;
	}

	

	Entities::Entity* ResourceManager::loadEntity(char* pFileName)
	{
		Entities::Entity* pNewEntity = NULL;
		std::string pName(pFileName);
		pName.append(".txt");
		//std::strcat(pFileName,".txt");
		FILE *fp;
		const char* finalName = pName.c_str();
		fopen_s(&fp, finalName, "r");
		if (fp)
		{
			pNewEntity = new Entities::Entity;
			char entityName[256]; 
			memset(entityName, 0, 256 * sizeof(char));
			fscanf_s(fp, "%s\n", entityName, sizeof(entityName));

			pNewEntity->Name = entityName;
			pNewEntity->Id = idCounter++;

			// Building arquetypes
			std::string eName(entityName);
			if (eName.find("ShooterLeft") != -1)
				pNewEntity->ArcheType = Entities::EntityType::SHOOTER_LEFT;
			else if (eName.find("ShooterRight") != -1)
				pNewEntity->ArcheType = Entities::EntityType::SHOOTER_RIGHT;
			else if (eName.find("Checker") != -1)
				pNewEntity->ArcheType = Entities::EntityType::CHECKER;
			else if (eName.find("Bullet") != -1)
				pNewEntity->ArcheType = Entities::EntityType::BULLET;
			else if (eName.find("ControlsScreen") != -1)
				pNewEntity->ArcheType = Entities::EntityType::CONTROLS_SCREEN;
			else if (eName.find("Enemy") != -1)
				pNewEntity->ArcheType = Entities::EntityType::ENEMY;
			else if (eName.find("Enem2Alien") != -1)
				pNewEntity->ArcheType = Entities::EntityType::ENEMY_ALIEN;
			else if (eName.find("Dust") != -1)
				pNewEntity->ArcheType = Entities::EntityType::DUST;
			else if (eName.find("Orb") != -1)
				pNewEntity->ArcheType = Entities::EntityType::ORB;
			else
				pNewEntity->ArcheType = Entities::EntityType::GENERAL;

			//
			while (!feof(fp))
			{
				char componentName[256];
				memset(componentName, 0, 256 * sizeof(char));
				
				fscanf_s(fp,"%s\n",componentName, sizeof(componentName));
				if (strcmp(componentName, "Renderer") == 0)
				{
					Entities::SARendererComponent* rendererComponent = new Entities::SARendererComponent;
					pNewEntity->AddComponent(rendererComponent);
					rendererComponent->Serialize(&fp);
				}
				if (strcmp(componentName, "Transform") == 0)
				{
					Entities::TransformComponent* transform = new Entities::TransformComponent;
					pNewEntity->AddComponent(transform);
					transform->Serialize(&fp);
				}
				if (strcmp(componentName, "Physics") == 0)
				{
					Entities::PhysicsComponent* physics = new Entities::PhysicsComponent;
					pNewEntity->AddComponent(physics);
					physics->Serialize(&fp);
				}
				if (strcmp(componentName, "StandardController") == 0)
				{
					Entities::ControllerComponent* standardController = new Entities::ControllerComponent;
					pNewEntity->AddComponent(standardController);
				}
				if (strcmp(componentName, "InverseController") == 0)
				{
					Entities::InverseControllerComponent* inverseController = new Entities::InverseControllerComponent;
					pNewEntity->AddComponent(inverseController);
				}
				if (strcmp(componentName, "BulletController") == 0)
				{
					if (DynamicCreation)
					{
						Entities::BulletController* bulletController = new Entities::BulletController;
						pNewEntity->AddComponent(bulletController);
					}
				}
				if (strcmp(componentName, "CheckerController") == 0)
				{
					Entities::CheckerController* checkerController = new Entities::CheckerController;
					pNewEntity->AddComponent(checkerController);
					checkerController->Serialize(&fp);
				}
				if (strcmp(componentName, "Roullette") == 0)
				{
					Entities::RoulletteComponent* roullette = new Entities::RoulletteComponent;
					pNewEntity->AddComponent(roullette);
					roullette->Serialize(&fp);
				}
				if (strcmp(componentName, "EnemyController") == 0)
				{
					Entities::EnemyController* enemy = new Entities::EnemyController;
					pNewEntity->AddComponent(enemy);
					enemy->Serialize(&fp);
				}
				if (strcmp(componentName, "Enem2Alien") == 0)
				{
					Entities::EnemyAlienController* enemy = new Entities::EnemyAlienController;
					pNewEntity->AddComponent(enemy);
					enemy->Serialize(&fp);
				}
				if (strcmp(componentName, "DustController") == 0)
				{
					if (DynamicCreation)
					{
						Entities::DustController* bulletController = new Entities::DustController;
						pNewEntity->AddComponent(bulletController);
					}
				}
				if (strcmp(componentName, "OrbController") == 0)
				{
					Entities::OrbController* orb = new Entities::OrbController;
					pNewEntity->AddComponent(orb);
					orb->Serialize(&fp);
				}

			}
			fclose(fp);
		}
		return pNewEntity;
	}

	
	Entities::TransformComponent* ResourceManager::GetEntityTransform(char* entityName)
	{
		for (unsigned i = 0; i < LevelEntities.size(); i++)
		{
			//assert(LevelEntities.at(i) == NULL);
			LevelEntitiesMap[LevelEntities.at(i)->Name] = LevelEntities.at(i);
		}

		Entities::Entity* entity = LevelEntitiesMap[entityName];
		Entities::TransformComponent* entityTrans = entity->FindComponent<Entities::TransformComponent>();
		return entityTrans;
	}

	Entities::RoulletteComponent* ResourceManager::GetEntityRoullete(char* entityName)
	{
		for (unsigned i = 0; i < LevelEntities.size(); i++)
		{
			//assert(LevelEntities.at(i) == NULL);
			LevelEntitiesMap[LevelEntities.at(i)->Name] = LevelEntities.at(i);
		}

		Entities::Entity* entity = LevelEntitiesMap[entityName];
		Entities::RoulletteComponent* entityTrans = entity->FindComponent<Entities::RoulletteComponent>();
		return entityTrans;
	}


	bool ResourceManager::createNewChecker(char* entityName, char* logicName, 
		float x, float y, 
		float offsetX, float offsetY, float radius,
		float startingAngle)
	{

		Entities::Entity* pEntity = loadEntity(entityName);
		pEntity->Name = logicName;
		//std::cout << "Initializing entity \"" << pEntity->Name << "\" and its components...\n";
		pEntity->Initialize();
		Entities::TransformComponent* trans = pEntity->FindComponent<Entities::TransformComponent>();
		trans->InitializeNewEntityCoords(x, y);

		Entities::RoulletteComponent* roullette = pEntity->FindComponent<Entities::RoulletteComponent>();
		roullette->SetNewEntityOffsets(offsetX, offsetY, radius, startingAngle);
		roullette->SetCheckerData();

		LevelEntities.push_back(pEntity);
		return true;
	}

	bool ResourceManager::CreateNewBullet(char* entityName, char* logicName, bool p1,
		float x, float y, float dirAngle, Entities::Entity* creator)
	{
		Entities::Entity* pEntity = loadEntity(entityName);
		pEntity->Name = logicName;
		pEntity->Initialize();
		Entities::TransformComponent* trans = pEntity->FindComponent<Entities::TransformComponent>();
		trans->InitializeNewEntityCoords(x, y);
		trans->OrientationAngle = dirAngle;
		Entities::BulletController* bullet = pEntity->FindComponent<Entities::BulletController>();
		bullet->Creator = creator;
		LevelEntities.push_back(pEntity);
		physicsManager->ManagedEntities.push_back(pEntity);
		eventManager->BroadcastTo(LevelEntities);
		return true;
	}

	void ResourceManager::createLevelCheckers()
	{
		createNewChecker("Checker", "Checker1", 450.0f, 225.0f, 450.0f, 225.0f, 0, -1);
		createNewChecker("Checker", "Checker2", 450.0f, 225.0f, 450.0f, 225.0f, 100.0f*sqrt(2.0f), -135.0);
		createNewChecker("Checker", "Checker3", 450.0f, 225.0f, 450.0f, 225.0f, 100.0f, -90.0);
		createNewChecker("Checker", "Checker4", 450.0f, 225.0f, 450.0f, 225.0f, 100.0f*sqrt(2.0f), -45.0);
		createNewChecker("Checker", "Checker5", 450.0f, 225.0f, 450.0f, 225.0f, 100.0f, 0.0);
		createNewChecker("Checker", "Checker6", 450.0f, 225.0f, 450.0f, 225.0f, 100.0f*sqrt(2.0f), 45.0);
		createNewChecker("Checker", "Checker7", 450.0f, 225.0f, 450.0f, 225.0f, 100.0f, 90.0);
		createNewChecker("Checker", "Checker8", 450.0f, 225.0f, 450.0f, 225.0f, 100.0f*sqrt(2.0f), 135.0);
		createNewChecker("Checker", "Checker9", 450.0f, 225.0f, 450.0f, 225.0f, 100.0f, 180.0);
	}

	bool ResourceManager::CreateDust(char* entityName, char* logicName, float x, float y, Entities::Entity* creator)
	{
		Entities::Entity* pEntity = loadEntity(entityName);
		pEntity->Name = logicName;
		pEntity->Initialize();
		Entities::TransformComponent* trans = pEntity->FindComponent<Entities::TransformComponent>();
		trans->InitializeNewEntityCoords(x, y);
		Entities::DustController* dust = pEntity->FindComponent<Entities::DustController>();
		dust->Creator = creator;
		LevelEntities.push_back(pEntity);
		physicsManager->ManagedEntities.push_back(pEntity);
		eventManager->BroadcastTo(LevelEntities);
		return true;
	}

	void ResourceManager::CreateNewOrb()
	{
		Entities::Entity* pEntity = loadEntity("Orb");
		pEntity->Name = "Orb";
		pEntity->Initialize();
		Entities::TransformComponent* trans = pEntity->FindComponent<Entities::TransformComponent>();
		trans->InitializeNewEntityCoords(250.0, 40.0); 
		Entities::OrbController* orb = pEntity->FindComponent<Entities::OrbController>();

		LevelEntities.push_back(pEntity);
		physicsManager->ManagedEntities.push_back(pEntity);
		eventManager->BroadcastTo(LevelEntities);
	}


}
