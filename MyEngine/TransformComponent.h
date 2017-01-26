#ifndef Transform_H
#define Transform_H

#include "Component.h"
#include "Vector3D.h"
#include "Matrix3D.h"
#include <string>

namespace Entities
{
	class TransformComponent : public Component
	{
		private:
			float x;
			float y;
			float w;
			float h;

			bool isRotating;
			int rotDir;
			bool rotationAxis;

			Matrix3D modelMatrix;
			Matrix3D modelRot, modelScale, modelTrans;

			Entity* owner;


		public:
			TransformComponent(void);
			~TransformComponent(void);

			bool Initialize();
			void Update(float deltaTime);
			bool Serialize(FILE** pfile);
			void HandleEvent(Events::Event* pEvent);

			void RotateWorld();
			void RotateAxis();

			Matrix3D GetModelMatrix();
			void InitializeNewEntityCoords(float x, float y);
			Vector3D Coords;
			Vector3D Scale;
			float OrientationAngle;
		
	};

}

#endif