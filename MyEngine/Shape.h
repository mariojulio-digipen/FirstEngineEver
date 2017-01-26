#ifndef Shape_H
#define Shape_H

namespace Entities
{
	class PhysicsComponent;
}

namespace Physics
{
	class Shape
	{
	public:
		enum ShapeType
		{
			CIRCLE,
			RECTANGLE,
			MAX
		};
		ShapeType Type;
		Shape();
		Entities::PhysicsComponent* OwnerBody;
		virtual bool TestPoint(float pointX, float pointY) = 0;
		virtual ~Shape();
	};
}


#endif