#ifndef EnemyAlienController_H
#define EnemyAlienController_H

#include "Component.h"
#include "Vector3D.h"

namespace Entities
{
	class TransformComponent;
	class EnemyAlienController : public Component
	{
	private:
		Entity* owner;
		int Status;
		float radius;
		float angle;
		Vector3D offset;

		Vector3D defaultCoords;
		Vector3D defaultOffsets;
		float defaultRadius;

		TransformComponent* transform;


	public:
		EnemyAlienController();
		~EnemyAlienController();

		void Update(float deltaTime);
		bool Initialize();
		bool Serialize(FILE** pfile);
		void HandleEvent(Events::Event* pEvent);
		bool ShutDown();
	};
}
#endif