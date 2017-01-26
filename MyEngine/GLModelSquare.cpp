#include "GLModelSquare.h"
#include "ResourceManager.h"
#include <iostream>
#include <iterator>

#define CHECKERROR {int err = glGetError(); if (err) { fprintf(stderr, "OpenGL error in GLModelSquare.cpp at line %d: %s\n", __LINE__, gluErrorString(err)); getchar(); exit(-1);} }


extern Assets::ResourceManager* resources;

GLModelSquare::GLModelSquare() : GLModelBase()
{

}


GLModelSquare::~GLModelSquare()
{
	glDeleteBuffers(1, &glVBO);
	glDeleteBuffers(1, &glIBO);
}

void GLModelSquare::SetVertexData(GLfloat* vertexData, int numVerts)
{
	memcpy_s(modelVertexData, sizeof(modelVertexData), vertexData, 8 * numVerts * sizeof(float));	//6 * numVerts
}

void GLModelSquare::DefineBox()
{
	// Initialize color
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// VBO - Vertex Buffer Object
	glGenBuffers(1, &glVBO);
	glBindBuffer(GL_ARRAY_BUFFER, glVBO);
	//glDeleteBuffers(1,)

	/*size_t sizeofModelVerteData = sizeof(modelVertexData);
	size_t otherSize = (sizeof(modelVertexData) / sizeof(*modelVertexData))*sizeof(GLfloat);*/

	glBufferData(GL_ARRAY_BUFFER, sizeof(modelVertexData), modelVertexData, GL_STATIC_DRAW);

	// IBO - Index Buffer Object, data for triangles
	GLushort triagIndexData[] = { 0, 1, 2, 2, 3, 0 };	// This is for triangle, the order in which
	glGenBuffers(1, &glIBO);							// verteces will be read
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, glIBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(triagIndexData), triagIndexData, GL_STATIC_DRAW);


}



void GLModelSquare::DrawBox(int glVertexPos3DLocation, int glColorLocation, int glTextureCoords)
{

	if (mainWindow.DebugMode == true)
		glDisableVertexAttribArray(glTextureCoords);

	glEnableVertexAttribArray(glVertexPos3DLocation);

	glBindBuffer(GL_ARRAY_BUFFER, glVBO);
	int positionsThatRepresentOneVertexVBO = 3;
	glVertexAttribPointer(glVertexPos3DLocation, positionsThatRepresentOneVertexVBO,
		GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)0);

	glEnableVertexAttribArray(glTextureCoords);
	int positionsThatRepresentOneTextureVertex = 2;
	glVertexAttribPointer(glTextureCoords, positionsThatRepresentOneTextureVertex,
	GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)(sizeof(float) * 6));
		

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, glIBO);

	if (mainWindow.DebugMode == true)
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, NULL);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	else
	{
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, NULL);
	}

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDisableVertexAttribArray(glTextureCoords);
	glDisableVertexAttribArray(glVertexPos3DLocation);
	CHECKERROR;

		
}


void GLModelSquare::Update()
{
	//glGetBufferSubData(GL_TRANSFORM_FEEDBACK_BUFFER, 0, sizeof(positionFeedback), positionFeedback);
}

//Vector3D GLModelSquare::GetModelFeedback()
//{
//	/*Vector3DSet(&modelFeedback, positionFeedback[0], positionFeedback[1], 0);
//	return modelFeedback;*/
//}