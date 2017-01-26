#include "AABB.h"
#include "PhysicsComponent.h"

namespace Physics
{
	AABB::AABB() : Shape()
	{
		Type = ShapeType::RECTANGLE;
		Top = Bottom = Right = Left = 0.0f;
		/*Left = x - width / 2;
		Right = x + width / 2;
		Top = y - height / 2;
		Bottom = y + height / 2;*/
	}


	AABB::~AABB()
	{
	}

	bool AABB::TestPoint(float pointX, float pointY)
	{
		float left, right, top, bottom;
		left = OwnerBody->Position->Scale.x + Left;
		right = OwnerBody->Position->Scale.x + Right;
		top = OwnerBody->Position->Scale.y + Top;
		bottom = OwnerBody->Position->Scale.y + Bottom;

		if ((pointX >= left) && (pointX <= right) &&
			(pointY >= top) && (pointY <= bottom)) {
			return true;
		}
		return false;

		/*float left, right, top, bottom;
		left = OwnerBody->Position->X + Left;
		right = OwnerBody->Position->X + Right;
		top = OwnerBody->Position->Y + Top;
		bottom = OwnerBody->Position->Y + Bottom;

		if (pointX < left ||
			pointX > right ||
			pointY < top ||
			pointY > bottom)
			return false;
		
		return true;*/
	}
}

