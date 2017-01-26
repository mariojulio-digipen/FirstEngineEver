/*
***********************************************************************
\file Matrix3D.h
\author Mariojulio Zaldivar, mariojulio.zaldivar, 60002515
\par Email1: zaldivar.alvarez@gmail.com
\par Email2: mariojulio.zaldivar@digipen.edu
\date Sep 12, 2015
\brief
Copyright (C) 2015 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the
prior written consent of DigiPen Institute of Technology is prohibited.
***********************************************************************/

#ifndef Matrix3D_H
#define Matrix3D_H

#ifndef EXIT_FAILURE
#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0
#endif

#include "Vector3D.h"

typedef struct Matrix3D
{
	float m[4][4];
}Matrix3D;


/*
This function sets the matrix Result to the identity matrix - DONE
*/
void Matrix3DIdentity(Matrix3D *pResult);

/*
This functions calculated the transpose matrix of Mtx and saves it in Result - DONE
*/
void Matrix3DTranspose(Matrix3D *pResult, Matrix3D *pMtx); 

/*
This function multiplies Mtx0 with Mtx1 and saves the result in Result - DONE
Result = Mtx0*Mtx1
*/
void Matrix3DConcat(Matrix3D *pResult, Matrix3D *pMtx0, Matrix3D *pMtx1);

/*
This function creates a translation matrix from x *p y and saves it in Result - DONE
*/
void Matrix3DTranslate(Matrix3D *pResult, float x, float y);

/*
This function creates a scaling matrix from x *p y and saves it in Result  - DONE
*/
void Matrix3DScale(Matrix3D *pResult, float x, float y);

/*
This matrix creates a rotation matrix from "Angle" whose value is in degree.
Save the resultant matrix in Result
*/
void Matrix3DRotDeg(Matrix3D *pResult, float Angle);

/*
This matrix creates a rotation matrix from "Angle" whose value is in radian.
Save the resultant matrix in Result
*/
void Matrix3DRotRad(Matrix3D *pResult, float Angle);

/*
This function multiplies the matrix Mtx with the vector Vec and saves the result in Result
Result = Mtx * Vec
*/
void Matrix3DMultVec(Vector3D *pResult, Matrix3D *pMtx, Vector3D *pVec);


#endif