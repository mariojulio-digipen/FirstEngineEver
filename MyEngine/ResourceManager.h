#ifndef ResourceManager_H
#define ResourceManager_H

#include <cassert>
#include <vector>
#include <string>
#include <map>

#include "Component.h"
#include "Entity.h"
#include "EntityTypes.h"
#include "SARendererComponent.h"
#include "TransformComponent.h"
#include "PhysicsComponent.h"
#include "ControllerComponent.h"
#include "InverseControllerComponent.h"
#include "ComponentsList.h"
#include "Camera.h"
#include "RoulletteComponent.h"
#include "BulletController.h"
#include "CheckerController.h"




namespace Assets
{
	class ResourceManager
	{
	private:

		int idCounter;
		Entities::Entity* loadEntity(char *pFileName);
		std::map<std::string, Entities::Entity*> LevelEntitiesMap; 
		bool createNewChecker(char* entityName, char* logicName,
			float x, float y,
			float offsetX = 0.0f, float offsetY = 0.0f, float radius = 0.0f,
			float startingAngle = 0.0f);
		void createLevelCheckers();

	public:

		ResourceManager();
		~ResourceManager();


		std::vector<Entities::Entity*>  LevelEntities;
		bool DynamicCreation;
		bool InitializeAssets(const char* levelFileName);
		bool DisposeAssets();

		Entities::TransformComponent* GetEntityTransform(char* entityName);
		Entities::RoulletteComponent* GetEntityRoullete(char* entityName);
		bool CreateNewBullet(char* entityName, char* logicName, bool p1,
			float x = 0.0f, float y = 0.0f, float dirAngle = 0.0f, Entities::Entity* creator = NULL);
		bool CreateDust(char* entityName, char* logicName, float x, float y, Entities::Entity* creator);
		void CreateNewOrb();
	};
}



#endif