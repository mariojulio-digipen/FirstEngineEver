#ifndef GLModelBase_H
#define GLModelBase_H

#include "MyWindowComponent.h"

class GLModelBase
{

private:
	GLuint glVBO;
	GLuint glIBO;
	GLuint glTBO; //if transform feedback is implemented
	bool debugMode;

public:
	GLModelBase();
	virtual ~GLModelBase();

	virtual void SetVertexData(GLfloat* vertexData, int numVerts) {};
	virtual void DefineModel() {};
	virtual void DrawModel(int glVertexPos3DLocation, int numVerts) {};
	virtual void Update() {};
};

#endif