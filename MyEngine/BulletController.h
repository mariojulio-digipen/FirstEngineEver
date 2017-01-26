#ifndef BulletController_H
#define BulletController_H

#include "Component.h"
#include "Vector3D.h"

namespace Entities
{
	class TransformComponent;
	class PhysicsComponent;

	class BulletController : public Component
	{
	private:
		TransformComponent* transform;
		Entities::PhysicsComponent* physics;

		Vector3D shooterPoint;
		Vector3D shooterScale;
		float framerate;
		bool alive;
		
	public:
		BulletController();
		~BulletController();

		bool MoveUp;
		bool MoveDown;
		bool MoveRight;
		bool MoveLeft;


		bool Initialize();
		void Update(float deltaTime);
		bool Serialize(FILE** pfile);
		void HandleEvent(Events::Event* pEvent);

		Entity* Creator;
	};
}


#endif