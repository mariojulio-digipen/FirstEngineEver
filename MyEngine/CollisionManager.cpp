#include "CollisionManager.h"
#include "Circle.h"
#include "AABB.h"
#include "Contact.h"
#include "Component.h"
#include <iostream>

//tmp
#include "PhysicsComponent.h"
#include "Entity.h"

namespace Physics
{
	bool CheckCollisionCircleCircle(Shape* circle1Shape, float center1X, float center1Y, Shape* circle2Shape, float center2X, float center2Y, std::vector<Contact*>& contacts)
	{
		float sqDistance;
		float circleRadius1, circleRadius2;
		float radiusSum;

		sqDistance = (center1X - center2X) * (center1X - center2X) + (center1Y - center2Y) * (center1Y - center2Y);
		circleRadius1 = ((Circle*)circle1Shape)->Radius;
		circleRadius2 = ((Circle*)circle2Shape)->Radius;
		radiusSum = circleRadius1 + circleRadius2;

		if (sqDistance <= radiusSum*radiusSum)
		{
			Contact* newContact = new Contact;
			newContact->Bodies[0] = circle1Shape->OwnerBody;
			newContact->Bodies[1] = circle2Shape->OwnerBody;
			contacts.push_back(newContact);

			return true;
		}

		return false;
	}

	bool CheckCollisionAABBAABB(Shape* aabb1Shape, float pos1X, float pos1Y, Shape* aabb2Shape, float pos2X, float pos2Y, std::vector<Contact*>& contacts)
	{

		AABB* aabb1 = (AABB*) aabb1Shape;
		AABB* aabb2 = (AABB*) aabb2Shape;

		float rect1CenterX = pos1X;
		float rect1CenterY = pos1Y;

		float rect2CenterX = pos2X;
		float rect2CenterY = pos2Y;

		float rect1Left = rect1CenterX + aabb1->Left;
		float rect1Rigth = rect1CenterX + aabb1->Right;
		float rect1Top = rect1CenterY + aabb1->Top;
		float rect1Bottom = rect1CenterY + aabb1->Bottom;

		
		float rect2Left = rect2CenterX + aabb2->Left;
		float rect2Rigth = rect2CenterX + aabb2->Right;
		float rect2Top = rect2CenterY + aabb2->Top;
		float rect2Bottom = rect2CenterY + aabb2->Bottom;


		if ((rect1Left <= rect2Rigth) && (rect1Rigth >= rect2Left) &&		// invert < and > signs, because
			(rect1Top <= rect2Bottom) && (rect1Bottom >= rect2Top))			// with SDL, we must validate Y as top down.
		{																	
			Contact* newContact = new Contact;
			newContact->Bodies[0] = aabb1->OwnerBody;
			newContact->Bodies[1] = aabb2->OwnerBody;
			contacts.push_back(newContact);


			return true;
		}
		return false;
	}

	bool CheckCollisionCircleAABB(Shape* circleShape, float pos1X, float pos1Y, Shape* aabbShape, float pos2X, float pos2Y, std::vector<Contact*>& contacts)
	{

		Circle* shapeCircle = (Circle*)circleShape;	
		AABB* shapeAABB = (AABB*)aabbShape;			

		float circleCenterX = pos1X;
		float circleCenterY = pos1Y;


		float rectCenterX = pos2X;
		float rectCenterY = pos2Y;

		float rectLeft = rectCenterX + shapeAABB->Left;
		float rectRigth = rectCenterX + shapeAABB->Right;
		float rectTop = rectCenterY + shapeAABB->Top;
		float rectBottom = rectCenterY + shapeAABB->Bottom;

		float recNearesPointToCircleX, recNearesPointToCircleY = 0;

		float distance = 0;

		if (circleCenterX < rectLeft)
		{
			recNearesPointToCircleX = rectLeft;
		}
		else if (circleCenterX > rectRigth)
		{
			recNearesPointToCircleX = rectRigth;
		}
		else
		{
			recNearesPointToCircleX = circleCenterX;
		}

		if (circleCenterY < rectTop)					
		{												
			recNearesPointToCircleY = rectTop;
		}
		else if (circleCenterY > rectBottom)
		{
			recNearesPointToCircleY = rectBottom;
		}
		else
		{
			recNearesPointToCircleY = circleCenterY;
		}

		float sqDistance =	(recNearesPointToCircleX - circleCenterX) * (recNearesPointToCircleX - circleCenterX) + 
							(recNearesPointToCircleY - circleCenterY) * (recNearesPointToCircleY - circleCenterY);
		distance = sqrt(sqDistance);

		if (distance <= shapeCircle->Radius)
		{
			Contact* newContact = new Contact;
			newContact->Bodies[0] = shapeCircle->OwnerBody;
			newContact->Bodies[1] = shapeAABB->OwnerBody;
			contacts.push_back(newContact);
			return true;
		}
		return false;
	}

	bool CheckCollisionAABBCircle(Shape* aabbShape, float pos1X, float pos1Y, Shape* circleShape, float pos2X, float pos2Y, std::vector<Contact*>& contacts)
	{

		return CheckCollisionCircleAABB(circleShape, pos2X, pos2Y, aabbShape, pos1X, pos1Y, contacts);
	}




	bool CollisionManager::CheckCollisionAndGenerateContacts(Shape * shape1, float posShape1X, float posShape1Y,
																		Shape * shape2, float posShape2X, float posShape2Y)
	{
		return CollisionFunctions[shape1->Type][shape2->Type](shape1, posShape1X, posShape1Y, shape2, posShape2X, posShape2Y, Contacts);
	}


	CollisionManager::CollisionManager()
	{
		CollisionFunctions[Shape::ShapeType::CIRCLE][Shape::ShapeType::CIRCLE] = CheckCollisionCircleCircle;
		CollisionFunctions[Shape::ShapeType::CIRCLE][Shape::ShapeType::RECTANGLE] = CheckCollisionCircleAABB;
		CollisionFunctions[Shape::ShapeType::RECTANGLE][Shape::ShapeType::CIRCLE] = CheckCollisionAABBCircle;
		CollisionFunctions[Shape::ShapeType::RECTANGLE][Shape::ShapeType::RECTANGLE] = CheckCollisionAABBAABB;
	}


	CollisionManager::~CollisionManager()
	{
		Reset();
	}


	void CollisionManager::Reset()
	{
		for (size_t i = 0; i < Contacts.size(); i++)
		{
			Physics::Contact* contactToDelete = Contacts.at(i);
			delete contactToDelete;
		}
		Contacts.clear();
	}


}

