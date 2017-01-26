#ifndef AABB_H
#define AABB_H



#include "Shape.h"

namespace Physics
{
	class AABB : public Shape
	{
	public:
		AABB();
		~AABB();

		float Left, Right;
		float Top, Bottom;
		bool TestPoint(float pointX, float pointY);

	};
}

#endif