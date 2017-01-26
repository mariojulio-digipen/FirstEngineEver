#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include <vector>
#include "Shape.h"
#include "Contact.h"

namespace Physics
{

	class CollisionManager
	{
		
	public:
		CollisionManager();
		~CollisionManager();

		
		std::vector<Physics::Contact*> Contacts;
		bool CheckCollisionAndGenerateContacts(Shape* shape1, float posShape1X, float posShape1Y,
												Shape* shape2, float posShape2X, float posShape2Y);
		void Reset(void);
		bool (*CollisionFunctions[Shape::ShapeType::MAX][Shape::ShapeType::MAX])(Shape* shape1, float posShape1X, float posShape1Y,
																				Shape* shape2, float posShape2X, float posShape2Y, 
																				std::vector<Contact*>& contacts);

		
	};
}


#endif