/*
***********************************************************************
\file Vector3D.h
\author Mariojulio Zaldivar, mariojulio.zaldivar, 60002515
\par Email1: zaldivar.alvarez@gmail.com
\par Email2: mariojulio.zaldivar@digipen.edu
\date Sep 12, 2015
\brief
Copyright (C) 2015 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the
prior written consent of DigiPen Institute of Technology is prohibited.
***********************************************************************/

#ifndef VECTOR3_H
#define VECTOR3_H

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include "math.h"



typedef struct Vector3D
{
	float x, y, z;

}Vector3D;




/*
This function sets the coordinates of the 2D vector (pResult) to 0
*/
void Vector3DZero(Vector3D *pResult);

/*
This function sets the coordinates of the 2D vector (pResult) to x &y
*/
void Vector3DSet(Vector3D *pResult, float x, float y, float z);

/*
In this function, pResult will be set to the opposite of pVec0
*/
void Vector3DNeg(Vector3D *pResult, Vector3D *pVec0);

/*
In this function, pResult will be the sum of pVec0 and pVec1
*/
void Vector3DAdd(Vector3D *pResult, Vector3D *pVec0, Vector3D *pVec1);

/*
In this function, pResult will be the difference between pVec0 *pVec1: pVec0 - pVec1
*/
void Vector3DSub(Vector3D *pResult, Vector3D *pVec0, Vector3D *pVec1);

/*
In this function, pResult will be the unit vector of pVec0
*/
void Vector3DNormalize(Vector3D *pResult, Vector3D *pVec0);

/*
In this function, pResult will be the vector pVec0 scaled by the value c
*/
void Vector3DScale(Vector3D *pResult, Vector3D *pVec0, float c);

/*
In this function, pResult will be the vector pVec0 scaled by c and added to pVec1
*/
void Vector3DScaleAdd(Vector3D *pResult, Vector3D *pVec0, Vector3D *pVec1, float c);

/*
In this function, pResult will be the vector pVec0 scaled by c and pVec1 will be subtracted from it
*/
void Vector3DScaleSub(Vector3D *pResult, Vector3D *pVec0, Vector3D *pVec1, float c);

/*
This function returns the length of the vector pVec0
*/
float Vector3DLength(Vector3D *pVec0);

/*
This function returns the square of pVec0's length. Avoid the square root 
*/
float Vector3DSquareLength(Vector3D *pVec0);

/*
In this function, pVec0 and pVec1 are considered as 2D points.
The distance between these 2 2D points is returned
*/
float Vector3DDistance(Vector3D *pVec0, Vector3D *pVec1);

/*
In this function, pVec0 and pVec1 are considered as 2D points.
The squared distance between these 2 2D points is returned. Avoid the square root 
*/
float Vector3DSquareDistance(Vector3D *pVec0, Vector3D *pVec1);

/*
This function returns the dot product between pVec0 and pVec1
*/
float Vector3DDotProduct(Vector3D *pVec0, Vector3D *pVec1);

/*
This function computes the coordinates of the vector represented by the angle "angle", which is in Degrees
*/
void Vector3DFromAngleDeg(Vector3D *pResult, float angle);

/*
This function computes the coordinates of the vector represented by the angle "angle", which is in Radian
*/
void Vector3DFromAngleRad(Vector3D *pResult, float angle);

#endif