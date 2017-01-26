#ifndef COMPONENT_H
#define COMPONENT_H

#include <stdio.h>
#include "EventManager.h"

namespace Entities
{
	class Entity;

	class Component
	{
	private:
		friend class Entity;
		Entity* owner;
		Events::EventManager* eventManager;

	public:

		Component();
		virtual ~Component();

		virtual void Update(float deltaTime) {}
		virtual bool Initialize() { return true; }
		virtual bool ShutDown() { return true; }
		virtual bool Serialize(FILE** pfile) { return true; }
		virtual void HandleEvent(Events::Event* pEvent) {  }
		Entity* GetOwner() const { return owner; }
		Events::EventManager* GetEventManager() { return eventManager; };
		void SetEventManager(Events::EventManager* pEventManager) { eventManager = pEventManager; };
	};

}


#endif