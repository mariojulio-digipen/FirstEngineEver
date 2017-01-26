/*
***********************************************************************
\file Math2d.h
\author Mariojulio Zaldivar, mariojulio.zaldivar, 60002515
\par Email1: zaldivar.alvarez@gmail.com
\par Email2: mariojulio.zaldivar@digipen.edu
\date Sep 12, 2015
\brief
Copyright (C) 2015 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the
prior written consent of DigiPen Institute of Technology is prohibited.
***********************************************************************/

#ifndef MATH2D_H
#define MATH2D_H


#include "Vector3D.h"

/*
This function checks if the point P is colliding with the circle whose
center is "Center" and radius is "Radius"
*/
int StaticPointToStaticCircle(Vector3D *pP, Vector3D *pCenter, float Radius);


/*
This function checks if the point Pos is colliding with the rectangle
whose center is Rect, width is "Width" and height is Height
*/
int StaticPointToStaticRect(Vector3D *pPos, Vector3D *pRect, float Width, float Height);

/*
This function checks for collision between 2 circles.
Circle0: Center is Center0, radius is "Radius0"
Circle1: Center is Center1, radius is "Radius1"
*/
int StaticCircleToStaticCircle(Vector3D *pCenter0, float Radius0, Vector3D *pCenter1, float Radius1);

/*
This functions checks if 2 rectangles are colliding
Rectangle0: Center is pRect0, width is "Width0" and height is "Height0"
Rectangle1: Center is pRect1, width is "Width1" and height is "Height1"
*/
int StaticRectToStaticRect(Vector3D *pRect0, float Width0, float Height0, Vector3D *pRect1, float Width1, float Height1);

/*
This functions checks if 1 circle is colliding with 1 rectangle
Circle: Center is pCircle, with radius radius
Rectangle: Center is pRect1, width is "Width0" and height is "Height0"
*/
int StaticCircleToRect(Vector3D *pCircle, float radius, Vector3D *pRect0, float Width0, float Height0);

#endif