#ifndef Enemy1Controller_H
#define Enemy1Controller_H

#include "Component.h"

namespace Entities
{
	class TransformComponent;
	class EnemyController : public Component
	{
	private:
		Entity* owner;
		float controlAngle;
		//int enemySide;
		int offset;
		float timer;
		int behaviorController;
		float oscilationRange;
		int counterController;
		TransformComponent* playerTrans;
		TransformComponent* thisEnemytransform;

	public:
		EnemyController();
		~EnemyController();

		bool Initialize();
		void Update(float deltaTime);
		bool Serialize(FILE** pfile);
		void HandleEvent(Events::Event* pEvent);
	};
}


#endif