#ifndef DustController_H
#define DustController_H

#include "Component.h"

namespace Entities 
{

	class TransformComponent;
	class DustController : public Component
	{
	private:
		TransformComponent* transform;

	public:
		DustController();
		~DustController();

		bool Initialize();
		void Update(float deltaTime);
		bool Serialize(FILE** pfile);
		void HandleEvent(Events::Event* pEvent);

		Entity* Creator;
	};
}
#endif