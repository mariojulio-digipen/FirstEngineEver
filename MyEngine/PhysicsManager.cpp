#include "PhysicsManager.h"
#include "CollideEvent.h"


namespace Physics
{

	PhysicsManager::PhysicsManager()
	{
	}


	PhysicsManager::~PhysicsManager()
	{
	}

	void PhysicsManager::ManagesThisEntities(std::vector<Entities::Entity*>  & pLevelEntities)
	{
		this->ManagedEntities = pLevelEntities;
	}

	void PhysicsManager::SetUpCollisionManager(CollisionManager* collisionManager)
	{
		this->Collisions = collisionManager;
	}

	void PhysicsManager::Update(float deltaTime)
	{


		for (size_t i = 0; i < ManagedEntities.size(); i++)
		{
			Entities::PhysicsComponent* pBody =
				ManagedEntities.at(i)->FindComponent<Entities::PhysicsComponent>();
			if (pBody)
			{
				pBody->Integrate(deltaTime);
			}
		}

		Collisions->Reset();

		if (ManagedEntities.size() > 1)
		{
			std::vector<Entities::Entity*>::iterator iterBegin;// firstEntity; = ManagedEntities.begin();
			iterBegin = ManagedEntities.begin();
			
			std::vector<Entities::Entity*>::iterator iterLast;// firstEntity; = ManagedEntities.begin();
			iterLast = ManagedEntities.end();
			--iterLast;

			Entities::PhysicsComponent* body1;
			Entities::PhysicsComponent* body2;

			if (ManagedEntities.size() == 2)
			{
				body1 = (*iterBegin)->FindComponent<Entities::PhysicsComponent>();
				body2 = (*iterLast)->FindComponent<Entities::PhysicsComponent>();
				if (body1 && body2)
				{
					Collisions->CheckCollisionAndGenerateContacts(
						body1->attachedShape, body1->Position->Coords.x, body1->Position->Coords.y,
						body2->attachedShape, body2->Position->Coords.x, body2->Position->Coords.y);
				}
				
				
			}
			else
			{
				for (; iterBegin != iterLast; ++iterBegin)
				{
					body1 = (*iterBegin)->FindComponent<Entities::PhysicsComponent>();
					if (!body1)
						continue;

					std::vector<Entities::Entity*>::iterator iterNext;
					iterNext = iterBegin + 1;

					while (iterNext != (iterLast + 1))
					{
						body2 = (*iterNext)->FindComponent<Entities::PhysicsComponent>();
						if (!body2)
						{
							iterNext++;
							continue;
						}
							

						// Check for collision
						Collisions->CheckCollisionAndGenerateContacts(
							body1->attachedShape, body1->Position->Coords.x, body1->Position->Coords.y,
							body2->attachedShape, body2->Position->Coords.x, body2->Position->Coords.y);

						iterNext++;
					}


				}
			}

		}
		
		// send events
		//int num_contacts = Collisions->Contacts.size();
		//std::cout << "Number of contacts: " << num_contacts << std::endl;
		//std::cout << "\xd";
		for (Physics::Contact* contact: Collisions->Contacts)
		{
			Events::CollideEvent collideEvent;

			collideEvent.Entity1 = contact->Bodies[0]->GetOwner();
			collideEvent.Entity2 = contact->Bodies[1]->GetOwner();

			collideEvent.Entity1->HandleEvent(&collideEvent);
			collideEvent.Entity2->HandleEvent(&collideEvent);
		}



	}
}

