#include "Entity.h"
#include <cassert>
#include <Component.h>

#include "ResourceManager.h"

extern Assets::ResourceManager* resources;

namespace Entities
{
	Entity::Entity()
	{
		NumComponents = 0;
		Id = 0;
		//Name = NULL;
		for (int i = 0; i < NUM_MAX_COMPONENTS; i++)
		{
			components[i] = NULL;
		}
		//direction = 0;
	}

	/*Entity::~Entity()
	{

	}*/

	bool Entity::Initialize()
	{


		for (int i = 0; i < NumComponents; i++)
		{
			if (!components[i]->Initialize())
			{
				return false;
			}
		}
		Alive = true;
		return true;
	}

	bool Entity::ShutDown()
	{
		for (int i = 0; i < NumComponents; i++)
		{
			if(ArcheType != Entities::EntityType::CHECKER)
				delete components[i];
			components[i] = NULL;
		}
		//delete[] components;
		return true;
	}

	void Entity::AddComponent(Component* component)
	{
		assert(NumComponents != NUM_MAX_COMPONENTS);
		components[NumComponents++] = component;
		component->owner = this;
	}

	Component** Entity::GetAllComponents()
	{
		return components;
	}

	void Entity::Update(float deltaTime)
	{
		for(int i=0; i<NumComponents; i++)
		{
			resources->LevelEntities;
			Component* tmp = components[i];
			if (tmp)
				tmp->Update(deltaTime);
		}
	}


	void Entity::HandleEvent(Events::Event* pEvent)
	{
		for (int i = 0; i<NumComponents; i++)
		{
			components[i]->HandleEvent(pEvent);
		}
	}
}
