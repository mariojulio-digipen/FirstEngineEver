#ifndef OrbController_H
#define OrbController_H

#include "Component.h"

namespace Entities
{ 
	class TransformComponent;
	class OrbController : public Component
	{
	private:
		TransformComponent* transform;
		float rotationVelocity;
		float moveVelocity;
		float xLimiteft, xLimitRight, yLimitTop, yLimitBottom;

		enum STATE
		{
			RIGHT,
			DOWNWARDS,
			LEFT,
			UPWARDS,
			MAX
		};

		STATE state;

	public:
		OrbController();
		~OrbController();

		bool Initialize();
		void Update(float deltaTime);
		bool Serialize(FILE** pfile);
		void HandleEvent(Events::Event* pEvent);
	};
}
#endif