#ifndef PhysicsManager_H
#define PhysicsManager_H

#include "Entity.h"
#include "PhysicsComponent.h"
#include "CollisionManager.h"
#include <iostream>
#include <vector>



namespace Physics
{
	class PhysicsManager
	{
	public:
		PhysicsManager();
		~PhysicsManager();

		std::vector<Entities::Entity*>  ManagedEntities;
		CollisionManager* Collisions;

		void ManagesThisEntities(std::vector<Entities::Entity*> & pLevelEntities);
		void SetUpCollisionManager(CollisionManager* collisionManager);
		void Update(float deltaTime);
	};
}



#endif