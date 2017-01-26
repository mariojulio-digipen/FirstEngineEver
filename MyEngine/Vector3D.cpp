/*
***********************************************************************
\file Vector3D.c
\author Mariojulio Zaldivar, mariojulio.zaldivar, 60002515
\par Email1: zaldivar.alvarez@gmail.com
\par Email2: mariojulio.zaldivar@digipen.edu
\date Sep 12, 2015
\brief
Copyright (C) 2015 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the
prior written consent of DigiPen Institute of Technology is prohibited.
***********************************************************************/

#include "Vector3D.h"


#define EPSILON 0.0001


// ---------------------------------------------------------------------------

void Vector3DZero(Vector3D *pResult)
{
	pResult->x = 0;
	pResult->y = 0;
	pResult->z = 0;
}

// ---------------------------------------------------------------------------

void Vector3DSet(Vector3D *pResult, float x, float y, float z)
{
	pResult->x = x;
	pResult->y = y;
	pResult->z = z;
}

// ---------------------------------------------------------------------------

void Vector3DNeg(Vector3D *pResult, Vector3D *pVec0)
{
	pResult->x = pVec0->x * (-1);
	pResult->y = pVec0->y * (-1);
	pResult->z = pVec0->z * (-1);
}

// ---------------------------------------------------------------------------

void Vector3DAdd(Vector3D *pResult, Vector3D *pVec0, Vector3D *pVec1)
{
	pResult->x = pVec0->x + pVec1->x;
	pResult->y = pVec0->y + pVec1->y;
	pResult->z = pVec0->z + pVec1->z;
}


// ---------------------------------------------------------------------------

void Vector3DSub(Vector3D *pResult, Vector3D *pVec0, Vector3D *pVec1)
{
	pResult->x = pVec0->x - pVec1->x;
	pResult->y = pVec0->y - pVec1->y;
	pResult->z = pVec0->z - pVec1->z;
}

// ---------------------------------------------------------------------------

void Vector3DNormalize(Vector3D *pResult, Vector3D *pVec0)
{
	float lenght = Vector3DLength(pVec0);
	pResult->x = pVec0->x / lenght;
	pResult->y = pVec0->y / lenght;
	pResult->z = pVec0->z / lenght;
}

// ---------------------------------------------------------------------------

void Vector3DScale(Vector3D *pResult, Vector3D *pVec0, float c)
{
	pResult->x = c * pVec0->x;
	pResult->y = c * pVec0->y;
	pResult->z = c * pVec0->z;
}

// ---------------------------------------------------------------------------

void Vector3DScaleAdd(Vector3D *pResult, Vector3D *pVec0, Vector3D *pVec1, float c)
{
	Vector3DScale(pResult, pVec0, c);
	pResult->x = pResult->x + pVec1->x;
	pResult->y = pResult->y + pVec1->y;
	pResult->z = pResult->z + pVec1->z;
}

// ---------------------------------------------------------------------------

void Vector3DScaleSub(Vector3D *pResult, Vector3D *pVec0, Vector3D *pVec1, float c)
{
	Vector3DScale(pResult, pVec0, c);
	pResult->x = pResult->x - pVec1->x;
	pResult->y = pResult->y - pVec1->y;
	pResult->z = pResult->z - pVec1->z;
}

// ---------------------------------------------------------------------------

float Vector3DLength(Vector3D *pVec0)
{
	return (float)sqrt(Vector3DSquareLength(pVec0));
}

// ---------------------------------------------------------------------------

float Vector3DSquareLength(Vector3D *pVec0)
{
	return (pVec0->x*pVec0->x + pVec0->y*pVec0->y + pVec0->z*pVec0->z);
}

// ---------------------------------------------------------------------------

float Vector3DDistance(Vector3D *pVec0, Vector3D *pVec1)
{
	return (float)sqrt(Vector3DSquareDistance(pVec0, pVec1));
}

// ---------------------------------------------------------------------------

float Vector3DSquareDistance(Vector3D *pVec0, Vector3D *pVec1)
{
	return ((pVec0->x - pVec1->x)*(pVec0->x - pVec1->x) + (pVec0->y - pVec1->y)*(pVec0->y - pVec1->y) + (pVec0->z - pVec1->z)*(pVec0->z - pVec1->z));
}

// ---------------------------------------------------------------------------

float Vector3DDotProduct(Vector3D *pVec0, Vector3D *pVec1)
{
	return (pVec0->x*pVec1->x + pVec0->y*pVec1->y + pVec0->z*pVec1->z);
}

// ---------------------------------------------------------------------------

void Vector3DFromAngleDeg(Vector3D *pResult, float angle)
{
	/*double rad = (angle*M_PI) / 180;
	pResult->x = (float)cos(rad);
	pResult->y = (float)sin(rad);*/
}

// ---------------------------------------------------------------------------

void Vector3DFromAngleRad(Vector3D *pResult, float angle)
{
	/*pResult->x = (float)cos(angle);
	pResult->y = (float)sin(angle);*/
}

// ---------------------------------------------------------------------------
