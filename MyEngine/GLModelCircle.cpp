#include "GLModelCircle.h"

#include <iostream>
#include <iterator>

GLModelCircle::GLModelCircle() : GLModelBase()
{
}


GLModelCircle::~GLModelCircle()
{
	glDeleteBuffers(1, &glVBO);
	glDeleteBuffers(1, &glIBO);
}

void GLModelCircle::SetVertexData(GLfloat* vertexData, int numVerts)
{
	memcpy_s(modelVertexData, sizeof(modelVertexData), vertexData, 3 * numVerts*sizeof(float));
}

void GLModelCircle::DefineCircle()
{

	// Initialize color
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// VBO - Vertex Buffer Object
	glGenBuffers(1, &glVBO);
	glBindBuffer(GL_ARRAY_BUFFER, glVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(modelVertexData), modelVertexData, GL_STATIC_DRAW);


}

void GLModelCircle::DrawCircle(int glVertexPos3DLocation, int numVerts)
{
	glEnableVertexAttribArray(glVertexPos3DLocation);
	glBindBuffer(GL_ARRAY_BUFFER, glVBO);
	int positionsThatRepresentOneVertex = 3;
	glVertexAttribPointer(glVertexPos3DLocation, positionsThatRepresentOneVertex, 
		GL_FLOAT, GL_FALSE, 0, 0);
	if (mainWindow.DebugMode == false)
	{
		glDrawArrays(GL_TRIANGLES, 0, numVerts*sizeof(float));
	}
	else
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glDrawArrays(GL_TRIANGLES, 0, numVerts*sizeof(float));			// double check this...
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDisableVertexAttribArray(glVertexPos3DLocation);
}

void GLModelCircle::Update()
{
	// nothing for now
}