/*
***********************************************************************
\file Matrix3D.c
\author Mariojulio Zaldivar, mariojulio.zaldivar, 60002515
\par Email1: zaldivar.alvarez@gmail.com
\par Email2: mariojulio.zaldivar@digipen.edu
\date Sep 12, 2015
\brief
Copyright (C) 2015 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the
prior written consent of DigiPen Institute of Technology is prohibited.
***********************************************************************/

#include "Matrix3D.h"
#include "MyWindowComponent.h"


/*
This function sets the matrix Result to the identity matrix
*/
void Matrix3DIdentity(Matrix3D *pResult)
{
	pResult->m[0][0] = 1.f;	pResult->m[0][1] = 0.f;	pResult->m[0][2] = 0.f; pResult->m[0][3] = 0.f;
	pResult->m[1][0] = 0.f;	pResult->m[1][1] = 1.f;	pResult->m[1][2] = 0.f; pResult->m[1][3] = 0.f;
	pResult->m[2][0] = 0.f;	pResult->m[2][1] = 0.f;	pResult->m[2][2] = 1.f; pResult->m[2][3] = 0.f;
	pResult->m[3][0] = 0.f;	pResult->m[3][1] = 0.f;	pResult->m[3][2] = 0.f; pResult->m[3][3] = 1.f;
}

// ---------------------------------------------------------------------------

/*
This functions calculated the transpose matrix of Mtx and saves it in Result
*/
void Matrix3DTranspose(Matrix3D* pResult, Matrix3D* pMtx)
{
	Matrix3D newMatrix0 = *pMtx;

	pResult->m[0][0] = newMatrix0.m[0][0]; // j=0; i=0
	pResult->m[1][0] = newMatrix0.m[0][1]; // j=1; i=0
	pResult->m[2][0] = newMatrix0.m[0][2]; // j=2; i=0
	pResult->m[3][0] = newMatrix0.m[0][3]; // j=2; i=0

	pResult->m[0][1] = newMatrix0.m[1][0]; // j=0; i=1
	pResult->m[1][1] = newMatrix0.m[1][1]; // j=1; i=1
	pResult->m[2][1] = newMatrix0.m[1][2]; // j=2; i=1
	pResult->m[3][1] = newMatrix0.m[1][3]; // j=2; i=1

	pResult->m[0][2] = newMatrix0.m[2][0]; // j=0; i=2
	pResult->m[1][2] = newMatrix0.m[2][1]; // j=1; i=2
	pResult->m[2][2] = newMatrix0.m[2][2]; // j=2; i=2
	pResult->m[3][2] = newMatrix0.m[2][3]; // j=2; i=2

	pResult->m[0][3] = newMatrix0.m[3][0]; // j=0; i=3
	pResult->m[1][3] = newMatrix0.m[3][1]; // j=1; i=3
	pResult->m[2][3] = newMatrix0.m[3][2]; // j=2; i=3
	pResult->m[3][3] = newMatrix0.m[3][3]; // j=2; i=3
}

// ---------------------------------------------------------------------------

/*
This function multiplies Mtx0 with Mtx1 and saves the result in Result
Result = Mtx0*Mtx1
*/
void Matrix3DConcat(Matrix3D *pResult, Matrix3D *pMtx0, Matrix3D *pMtx1)
{
	Matrix3D newMatrix0 = *pMtx0;	// Saves the value of the targeted
	Matrix3D newMatrix1 = *pMtx1;	// address in a new variable.
									// Useful when dev wants to 
									// override a matrix that will
									// multiply another, 
									// like in "test Matrix3DConcat"
									// in Main.x
	
	// Reset pResult since we need a fresh 
	// matrix in which we can store results.
	pResult->m[0][0] = newMatrix0.m[0][0] * newMatrix1.m[0][0] + newMatrix0.m[0][1] * newMatrix1.m[1][0] + newMatrix0.m[0][2] * newMatrix1.m[2][0] + newMatrix0.m[0][3] * newMatrix1.m[3][0];
	pResult->m[0][1] = newMatrix0.m[0][0] * newMatrix1.m[0][1] + newMatrix0.m[0][1] * newMatrix1.m[1][1] + newMatrix0.m[0][2] * newMatrix1.m[2][1] + newMatrix0.m[0][3] * newMatrix1.m[3][1];
	pResult->m[0][2] = newMatrix0.m[0][0] * newMatrix1.m[0][2] + newMatrix0.m[0][1] * newMatrix1.m[1][2] + newMatrix0.m[0][2] * newMatrix1.m[2][2] + newMatrix0.m[0][3] * newMatrix1.m[3][2];
	pResult->m[0][3] = newMatrix0.m[0][0] * newMatrix1.m[0][3] + newMatrix0.m[0][1] * newMatrix1.m[1][3] + newMatrix0.m[0][2] * newMatrix1.m[2][3] + newMatrix0.m[0][3] * newMatrix1.m[3][3];

	pResult->m[1][0] = newMatrix0.m[1][0] * newMatrix1.m[0][0] + newMatrix0.m[1][1] * newMatrix1.m[1][0] + newMatrix0.m[1][2] * newMatrix1.m[2][0] + newMatrix0.m[1][3] * newMatrix1.m[3][0];
	pResult->m[1][1] = newMatrix0.m[1][0] * newMatrix1.m[0][1] + newMatrix0.m[1][1] * newMatrix1.m[1][1] + newMatrix0.m[1][2] * newMatrix1.m[2][1] + newMatrix0.m[1][3] * newMatrix1.m[3][1];
	pResult->m[1][2] = newMatrix0.m[1][0] * newMatrix1.m[0][2] + newMatrix0.m[1][1] * newMatrix1.m[1][2] + newMatrix0.m[1][2] * newMatrix1.m[2][2] + newMatrix0.m[1][3] * newMatrix1.m[3][2];
	pResult->m[1][3] = newMatrix0.m[1][0] * newMatrix1.m[0][3] + newMatrix0.m[1][1] * newMatrix1.m[1][3] + newMatrix0.m[1][2] * newMatrix1.m[2][3] + newMatrix0.m[1][3] * newMatrix1.m[3][3];

	pResult->m[2][0] = newMatrix0.m[2][0] * newMatrix1.m[0][0] + newMatrix0.m[2][1] * newMatrix1.m[1][0] + newMatrix0.m[2][2] * newMatrix1.m[2][0] + newMatrix0.m[2][3] * newMatrix1.m[3][0];
	pResult->m[2][1] = newMatrix0.m[2][0] * newMatrix1.m[0][1] + newMatrix0.m[2][1] * newMatrix1.m[1][1] + newMatrix0.m[2][2] * newMatrix1.m[2][1] + newMatrix0.m[2][3] * newMatrix1.m[3][1];
	pResult->m[2][2] = newMatrix0.m[2][0] * newMatrix1.m[0][2] + newMatrix0.m[2][1] * newMatrix1.m[1][2] + newMatrix0.m[2][2] * newMatrix1.m[2][2] + newMatrix0.m[2][3] * newMatrix1.m[3][2];
	pResult->m[2][3] = newMatrix0.m[2][0] * newMatrix1.m[0][3] + newMatrix0.m[2][1] * newMatrix1.m[1][3] + newMatrix0.m[2][2] * newMatrix1.m[2][3] + newMatrix0.m[2][3] * newMatrix1.m[3][3];

	pResult->m[3][0] = newMatrix0.m[3][0] * newMatrix1.m[0][0] + newMatrix0.m[3][1] * newMatrix1.m[1][0] + newMatrix0.m[3][2] * newMatrix1.m[2][0] + newMatrix0.m[3][3] * newMatrix1.m[3][0];
	pResult->m[3][1] = newMatrix0.m[3][0] * newMatrix1.m[0][1] + newMatrix0.m[3][1] * newMatrix1.m[1][1] + newMatrix0.m[3][2] * newMatrix1.m[2][1] + newMatrix0.m[3][3] * newMatrix1.m[3][1];
	pResult->m[3][2] = newMatrix0.m[3][0] * newMatrix1.m[0][2] + newMatrix0.m[3][1] * newMatrix1.m[1][2] + newMatrix0.m[3][2] * newMatrix1.m[2][2] + newMatrix0.m[3][3] * newMatrix1.m[3][2];
	pResult->m[3][3] = newMatrix0.m[3][0] * newMatrix1.m[0][3] + newMatrix0.m[3][1] * newMatrix1.m[1][3] + newMatrix0.m[3][2] * newMatrix1.m[2][3] + newMatrix0.m[3][3] * newMatrix1.m[3][3];


}

// ---------------------------------------------------------------------------

/*
This function creates a translation matrix from x *p y and saves it in Result
*/
void Matrix3DTranslate(Matrix3D *pResult, float x, float y)
{
	Matrix3DIdentity(pResult);
	pResult->m[0][3] = x;
	pResult->m[1][3] = y;
	pResult->m[2][3] = 0;
}

// ---------------------------------------------------------------------------

/*
This function creates a scaling matrix from x *p y and saves it in Result
*/
void Matrix3DScale(Matrix3D *pResult, float x, float y)
{
	Matrix3DIdentity(pResult);
	pResult->m[0][0] = x;
	pResult->m[1][1] = y; 
	//pResult->m[2][2] = 0;
}

// ---------------------------------------------------------------------------

/*
This matrix creates a rotation matrix from "Angle" whose value is in degree.
Save the resultant matrix in Result
*/
void Matrix3DRotDeg(Matrix3D *pResult, float Angle)
{
	double rad = (Angle*M_PI) / 180;

	Matrix3DIdentity(pResult);
	pResult->m[0][0] = (float)cos(rad);
	pResult->m[0][1] = (float)sin(rad)*(-1);
	pResult->m[1][0] = (float)sin(rad);
	pResult->m[1][1] = (float)cos(rad);
	pResult->m[2][2] = 1;
}

// ---------------------------------------------------------------------------

/*
This matrix creates a rotation matrix from "Angle" whose value is in radian.
Save the resultant matrix in Result
*/
void Matrix3DRotRad(Matrix3D *pResult, float Angle)
{
	Matrix3DIdentity(pResult);
	pResult->m[0][0] = (float)cos(Angle);
	pResult->m[0][1] = (float)sin(Angle)*(-1);
	pResult->m[1][0] = (float)sin(Angle);
	pResult->m[1][1] = (float)cos(Angle);
	pResult->m[2][2] = 0;
}

// ---------------------------------------------------------------------------

/*
This function multiplies the matrix Mtx with the vector Vec and saves the result in Result
Result = Mtx * Vec
*/
void Matrix3DMultVec(Vector3D *pResult, Matrix3D *pMtx, Vector3D *pVec)
{
	float homogenous_point[4] = { pVec->x, pVec->y, 0.0f, 1.f };	// We need to convert the vector in 
	float res_homogenuous_point[4] = { 0, 0, 0, 0 };			// an homogenous point.
															// That means, an Array of 3 floats.
	res_homogenuous_point[0] += 
		pMtx->m[0][0] * homogenous_point[0] +	//i=0; j=0
		pMtx->m[0][1] * homogenous_point[1] +	//i=0; j=1
		pMtx->m[0][2] * homogenous_point[2] +	//i=0; j=2
		pMtx->m[0][3] * homogenous_point[3];	//i=0; j=3

	res_homogenuous_point[1] +=
		pMtx->m[1][0] * homogenous_point[0] +	//i=1; j=0
		pMtx->m[1][1] * homogenous_point[1] +	//i=1; j=1
		pMtx->m[1][2] * homogenous_point[2] +	//i=1; j=2
		pMtx->m[1][2] * homogenous_point[3];	//i=1; j=3


	pVec->x = res_homogenuous_point[0]; // Finally, assign the resulting values
	pVec->y = res_homogenuous_point[1]; // from the array to the vector.
}

// ---------------------------------------------------------------------------
