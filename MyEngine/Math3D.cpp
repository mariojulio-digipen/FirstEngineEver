/*
***********************************************************************
\file Math2D.c
\author Mariojulio Zaldivar, mariojulio.zaldivar, 60002515
\par Email1: zaldivar.alvarez@gmail.com
\par Email2: mariojulio.zaldivar@digipen.edu
\date Sep 12, 2015
\brief
Copyright (C) 2015 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the
prior written consent of DigiPen Institute of Technology is prohibited.

Since the game will be in 2D, we will just use the 2D calculations with Z = 0;
***********************************************************************/

#include "Math3D.h"
#include "stdio.h"

/*
This function checks if the point P is colliding with the circle whose
center is "Center" and radius is "Radius"
*/
int StaticPointToStaticCircle(Vector3D *pP, Vector3D *pCenter, float Radius)
{
	float sq_distance = Vector3DSquareDistance(pP, pCenter);
	if (sq_distance <= Radius*Radius) {
		return 1;
	}
	return 0;
}


/*
This function checks if the point Pos is colliding with the rectangle
whose center is Rect, width is "Width" and height is Height
*/
int StaticPointToStaticRect(Vector3D *pPos, Vector3D *pRect, float Width, float Height)
{
	if ((pPos->x >= pRect->x - Width/2) && (pPos->x <= pRect->x + Width/2) && 
		(pPos->y >= pRect->y - Height/2) && (pPos->y <= pRect->y + Height/2)) {
		return 1;
	}
	return 0;
}

/*
This function checks for collision between 2 circles.
Circle0: Center is Center0, radius is "Radius0"
Circle1: Center is Center1, radius is "Radius1"
*/
int StaticCircleToStaticCircle(Vector3D *pCenter0, float Radius0, Vector3D *pCenter1, float Radius1)
{
	float sq_distance = Vector3DSquareDistance(pCenter0, pCenter1);
	float radius_sum = Radius0 + Radius1;
	if (sq_distance <= radius_sum*radius_sum) {
		return 1;
	}

  return 0;
}

/*
This functions checks if 2 rectangles are colliding
Rectangle0: Center is pRect0, width is "Width0" and height is "Height0"
Rectangle1: Center is pRect1, width is "Width1" and height is "Height1"
*/
int StaticRectToStaticRect(Vector3D *pRect0, float Width0, float Height0, Vector3D *pRect1, float Width1, float Height1)
{
	float rect0CenterX = pRect0->x;
	float rect0CenterY = pRect0->y;
	float rect0Left = rect0CenterX - Width0 / 2;
	float rect0Rigth = rect0CenterX + Width0 / 2;
	float rect0Top = rect0CenterY + Width0 / 2;
	float rect0Bottom = rect0CenterY - Width0 / 2;

	float rect1CenterX = pRect1->x;
	float rect1CenterY = pRect1->y;
	float rect1Left = rect1CenterX - Width1 / 2;
	float rect1Rigth = rect1CenterX + Width1 / 2;
	float rect1Top = rect1CenterY + Width1 / 2;
	float rect1Bottom = rect1CenterY - Width1 / 2;


	if ((rect0Left <= rect1Rigth) && (rect0Rigth >= rect1Left) &&
		(rect0Top >= rect1Bottom) && (rect0Bottom <= rect1Top)) {
		return 1;
	}
  return 0;
}


/*
This functions checks if 1 circle is colliding with 1 rectangle
Circle: Center is pCircle, with radius radius
Rectangle: Center is pRect1, width is "Width0" and height is "Height0"
*/
int StaticCircleToRect(Vector3D *pCircle, float radius, Vector3D *pRect0, float Width0, float Height0)
{
	float circleCenterX = pCircle->x;
	float circleCenterY = pCircle->y;
	

	float rect0CenterX = pRect0->x;
	float rect0CenterY = pRect0->y;

	float rect0Left = rect0CenterX - Width0 / 2;
	float rect0Rigth = rect0CenterX + Width0 / 2;
	float rect0Top = rect0CenterY + Width0 / 2;
	float rect0Bottom = rect0CenterY - Width0 / 2;

	Vector3D recNearestPointToCircle;
	Vector3DSet(&recNearestPointToCircle, 0 ,0, 0);

	float distance = 0;

	float offsetX = 0.5f;
	float offsetY = 0.5f;
	if (circleCenterX < rect0Left)
	{
		recNearestPointToCircle.x = rect0Left;
	}
	else if (circleCenterX > rect0Rigth)
	{
		recNearestPointToCircle.x = rect0Rigth;
	}
	else
	{
		recNearestPointToCircle.x = circleCenterX;
	}

	if (circleCenterY > rect0Top)
	{
		recNearestPointToCircle.y = rect0Top;
	}
	else if (circleCenterY < rect0Bottom)
	{
		recNearestPointToCircle.y = rect0Bottom;
	}
	else
	{
		recNearestPointToCircle.y = circleCenterY;
	}

	distance = Vector3DDistance(&recNearestPointToCircle, pCircle);

	if (distance < radius - 0.6f)
		return 1;

	return 0;
}
