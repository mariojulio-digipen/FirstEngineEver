#include "Circle.h"
#include "PhysicsComponent.h"
#include "Shape.h"

namespace Physics
{
	Circle::Circle() : Shape()
	{
		Type = ShapeType::CIRCLE;
		Radius = 0.0f;
	}


	Circle::~Circle()
	{
	}

	bool Circle::TestPoint(float pointX, float pointY)
	{
		float sqDistance = (pointX - OwnerBody->Position->Coords.x) * (pointX - OwnerBody->Position->Coords.x) +
			(pointY - OwnerBody->Position->Coords.y) * (pointY - OwnerBody->Position->Coords.y);
		if (sqDistance > (Radius * Radius))
		{
			return false;
		}
		return true;
	}

}

