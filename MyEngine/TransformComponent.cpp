#include "TransformComponent.h"
#include "Camera.h"
#include "MoveEvent.h"
#include "ShootEvent.h"
#include "ShootEventP2.h"
#include "ResourceManager.h"

extern Assets::ResourceManager* resources;

namespace Entities
{
	TransformComponent::TransformComponent(void) : x(0.0f), y(0.0f), w(0.0f), h(0.0f),
		isRotating(false), rotDir(0)
	{
		Coords = { x, y };
		Scale = { w, h };
	}

	bool Entities::TransformComponent::Initialize()
	{
		owner = GetOwner();
		// build the model matrix
		Matrix3DIdentity(&modelMatrix);
		Matrix3DRotDeg(&modelRot, OrientationAngle);
		Matrix3DScale(&modelScale, Scale.x, Scale.y);
		Matrix3DTranslate(&modelTrans, Coords.x, Coords.y);
		return true;
	}

	void TransformComponent::Update(float deltaTime)
	{		

		if (isRotating)
		{
			OrientationAngle = OrientationAngle + rotDir;
		}

		
		if (owner->ArcheType == EntityType::CONTROLS_SCREEN)
		{
			if (Scale.y < 220.0f)
			{
				Scale.y += 10;
				Coords.y -= 10;
			}
		}

		if ((owner->Name.compare("Pipe2") == 0) || (owner->Name.compare("Pipe4") == 0))
		{
			if (Coords.y > 470.0f)
			{
				Coords.y -= 20;
			}
		}

		if (OrientationAngle >= 360)
			OrientationAngle = 0;

		if (rotationAxis) // over its own axis
		{
			Matrix3DIdentity(&modelMatrix);
			Matrix3DRotDeg(&modelRot, OrientationAngle);
			Matrix3DScale(&modelScale, Scale.x, Scale.y);
			Matrix3DTranslate(&modelTrans, Coords.x, Coords.y);

			Matrix3DConcat(&modelMatrix, &modelScale, &modelMatrix);
			Matrix3DConcat(&modelMatrix, &modelRot, &modelMatrix);
			Matrix3DConcat(&modelMatrix, &modelTrans, &modelMatrix);

		}
		else // over the world axis
		{
			Matrix3DIdentity(&modelMatrix);
			Matrix3DScale(&modelScale, Scale.x, Scale.y);
			Matrix3DTranslate(&modelTrans, Coords.x, Coords.y);
			Matrix3DRotDeg(&modelRot, OrientationAngle);

			Matrix3DConcat(&modelMatrix, &modelTrans, &modelScale);
			Matrix3DConcat(&modelMatrix, &modelMatrix, &modelRot);
		}
		
	}

	void Entities::TransformComponent::HandleEvent(Events::Event * pEvent)
	{
		// TODO: change to another class (maybe controller component?)
		if (pEvent->Type == Events::EventType::SHOOT_P1)
		{
			resources->DynamicCreation = true;

			float dirAngle = OrientationAngle;


			Events::ShootEvent* shootEvent = dynamic_cast<Events::ShootEvent*>(pEvent);
			float shooterRadius;
			float newPosX;
			float newPosY;
			shooterRadius = Scale.x + Scale.x / 2;
			newPosX = shooterRadius * cosf(OrientationAngle * (float)(3.14159265 / 180)) + Coords.x;
			newPosY = shooterRadius * sinf(OrientationAngle * (float)(3.14159265 / 180)) + Coords.y;

			char objActualName[30];
			std::string tmp;
			if (shootEvent->Entity->ArcheType == Entities::EntityType::SHOOTER_LEFT)
				tmp = "Bullet1";
			if (shootEvent->Entity->ArcheType == Entities::EntityType::SHOOTER_RIGHT)
				tmp = "Bullet2";
			strcpy(objActualName, tmp.c_str());

			resources->CreateNewBullet(objActualName, "ShootBullet", true, newPosX, newPosY, OrientationAngle, shootEvent->Entity);
		}

		


		if (pEvent->Type == Events::EventType::MOVE)
		{
			Events::MoveEvent* pMoveEvent = dynamic_cast<Events::MoveEvent*>(pEvent);

			PhysicsComponent* phy = owner->FindComponent<PhysicsComponent>();
			if (pMoveEvent->MoveRight)
			{
				isRotating = true;
				if (phy->VelocityY == 6)
					rotDir = 6;
				if (phy->VelocityY == 1)
					rotDir = 1;
			}

			if (pMoveEvent->MoveLeft)
			{
				isRotating = true;
				if (phy->VelocityY == 6)
					rotDir = -6;
				if (phy->VelocityY == 1)
					rotDir = -1;
			}

			if (pMoveEvent->Idle)
			{
				isRotating = false;
				rotDir = 0;
			}

		}
	}

	void TransformComponent::RotateWorld()
	{
		rotationAxis = false;
	}

	void TransformComponent::RotateAxis()
	{
		rotationAxis = true; // means a rotation over the world axis
	}

	bool TransformComponent::Serialize(FILE ** pfile)
	{
		fscanf_s(*pfile, "%f %f %f %f %f\n", &x, &y, &w, &h, &OrientationAngle);
		/*x = x - w/2;
		y = y - h/2;
		
		w = w / 2;
		h = h / 2;
		*/
		Vector3DSet(&Coords, x, y, 0);
		Vector3DSet(&Scale, w, h, 0);
		rotationAxis = true;
		return true;		//validate errors later.
	}

	Matrix3D Entities::TransformComponent::GetModelMatrix()
	{
		return modelMatrix;
	}

	TransformComponent::~TransformComponent(void)
	{

	}

	void TransformComponent::InitializeNewEntityCoords(float x, float y)
	{
		Vector3DSet(&Coords, x, y, 0);
	}
}