#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

namespace Physics
{
	class Circle : public Shape
	{
	public:
		Circle();
		~Circle();

		bool TestPoint(float pointX, float pointY);
		float Radius;

	};
}


#endif