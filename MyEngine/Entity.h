#ifndef ENTITY_H
#define ENTITY_H


#include <string>

#include "EventManager.h"

namespace Entities
{
	enum EntityType
	{
		SHOOTER_LEFT,
		SHOOTER_RIGHT,
		CHECKER,
		BULLET,
		CONTROLS_SCREEN,
		ENEMY,
		ENEMY_ALIEN,
		DUST,
		ORB,
		GENERAL,

		Max
	};

	class Component;
	class Entity
	{
	private:
		static const int NUM_MAX_COMPONENTS = 10;
		static const int NUM_MAX_EVENTS = 10;
		Component* components[NUM_MAX_COMPONENTS];
		Events::Event* events[NUM_MAX_EVENTS];

	public:

		bool Alive;
		int Id;

		//TransformComponent transform;
		std::string Name;
		std::string GraphicType;
		EntityType ArcheType;
		//float direction;
		Entity();
		//~Entity();
		bool Initialize();
		bool ShutDown();
		void AddComponent(Component* component);
		void Update(float deltaTime);
		Component** GetAllComponents();
		void HandleEvent(Events::Event* pEvent);

		template<class T>
		T* FindComponent() const;

		int NumComponents;
		int Siblings;

	};

	template<class T>
	T* Entity::FindComponent() const
	{
		for (int i = 0; i < NumComponents; i++)
		{
			T* ret = dynamic_cast<T*>(components[i]);
			if(ret != 0)
				return ret;
		}
		return 0;
	}

}

#endif


