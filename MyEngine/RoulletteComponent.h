#ifndef RoulletteComponent_H
#define RoulletteComponent_H

#include "Component.h"

#include "Vector3D.h"

namespace Entities
{
	class TransformComponent;
	class RoulletteComponent : public Component
	{
	private:
		TransformComponent* transform;
		Vector3D offset;

	public:
		RoulletteComponent();
		~RoulletteComponent();

		
		float angle;
		float rotationSpeed;
		float radius;

		bool Initialize();
		void Update(float deltaTime);
		bool Serialize(FILE** pfile);

		void SetNewEntityOffsets(float offsetX, float offsetY, float radius, float startingAngle);
		void SetCheckerData();
	};
}



#endif