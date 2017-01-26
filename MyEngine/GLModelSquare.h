#ifndef GLModel_H
#define GLModel_H

#include "MyWindowComponent.h"
#include "Vector3D.h"
#include "GLModelBase.h"

class GLModelSquare : public GLModelBase
{
private:
	GLuint glVBO;
	GLuint glIBO;
	GLfloat modelVertexData[4*8];
	GLfloat positionFeedback[2];
	Vector3D modelFeedback;
	bool debugMode;

public:
	GLModelSquare();
	virtual ~GLModelSquare();


	

	void SetVertexData(GLfloat* vertexData, int numVerts);
	void DefineBox();
	void DrawBox(int glVertexPos2DLocation, int glColorLocation, int glTextureCoords);
	void Update();


};

#endif