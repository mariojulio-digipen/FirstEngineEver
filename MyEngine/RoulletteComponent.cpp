#include "RoulletteComponent.h"
#include "TransformComponent.h"
#include "ControllerComponent.h"
#include "Entity.h"
#include "KeyInput.h"
#include "MoveActions.h"
#include "RollingTabletData.h"

extern RollingTabletData* rollingTableData;

namespace Entities
{
	RoulletteComponent::RoulletteComponent()
	{
	}


	RoulletteComponent::~RoulletteComponent()
	{
	}

	bool RoulletteComponent::Initialize()
	{
		Entity* owner = GetOwner();
		transform = owner->FindComponent<TransformComponent>();

		return true;
	}

	void RoulletteComponent::SetCheckerData()
	{
		Vector3D ticTacData;
		Vector3DSet(&ticTacData, (float)GetOwner()->Id, 0.0f, 0.0f);

		rollingTableData->AddDataToCell(this->angle, ticTacData);
	}

	void RoulletteComponent::Update(float deltaTime)
	{
		//rollingTableData->Update();
		if (deltaTime > 0.0f)
		{
			transform->Coords.x = radius * cosf(angle * (float)(3.14159265 / 180)) + offset.x;
			transform->Coords.y = radius * sinf(angle * (float)(3.14159265 / 180)) + offset.y;
			angle += rotationSpeed * deltaTime;
			if (angle == 360)
			{
				angle = 0.0f;
			}

		}
	}

	void RoulletteComponent::SetNewEntityOffsets(float offsetX, float offsetY, float radius, float startingAngle)
	{
		offset.x = offsetX;
		offset.y = offsetY;
		this->radius = radius;
		this->angle = startingAngle;
	}

	bool RoulletteComponent::Serialize(FILE ** pfile)
	{
		//Vector3DSet(&offset, 0.0f, 0.0f, 0.0f);
		fscanf_s(*pfile, "%f %f %f %f %f\n", &offset.x, &offset.y, &radius, &angle, &rotationSpeed);
		transform = NULL;
		return true;
	}
}