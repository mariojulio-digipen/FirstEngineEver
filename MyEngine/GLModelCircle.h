#ifndef GLModelCircle_H
#define GLModelCIrcle_H

#include "MyWindowComponent.h"
#include "GLModelBase.h"

class GLModelCircle : public GLModelBase
{
private:
	GLuint glVBO;
	GLuint glIBO;	
	GLfloat modelVertexData[36*3];
	GLfloat positionFeedback[2];
	bool debugMode;
	GLuint glTBO;		// just for trasnform feedback testing

public:
	GLModelCircle();
	virtual ~GLModelCircle();




	void SetVertexData(GLfloat* vertexData, int numVerts);
	void DefineCircle();
	void DrawCircle(int glVertexPos3DLocation, int numVerts);
	void Update();


};

#endif