#include "GLObjectFactory.h"
#include "GLObjectSquare.h"
#include "GLObjectCircle.h"



GLObjectFactory::GLObjectFactory()
{
}


GLObjectFactory::~GLObjectFactory()
{
}


GLObjectBase* GLObjectFactory::GLObject(std::string graphicType, int textureUnit)
{
	if (graphicType.compare("AABB") == 0)
	{
		GLObjectSquare* obj = new GLObjectSquare();
		obj->SetTextureUnit(textureUnit);
		glObject = dynamic_cast<GLObjectSquare*>(obj);
		vertexes = std::vector<float>();
		GLfloat squareVerts[] =
		{
			-1.0f, -1.0f, 0.0f,		1.0f, 0.0f, 0.0f,   1.0f,  0.0f,
			1.0f, -1.0f, 0.0f,		0.0f, 1.0f, 0.0f,	0.0f,  0.0f,
			1.0f,  1.0f, 0.0f,		0.0f, 0.0f, 1.0f,	0.0f,  1.0f,
			-1.0f,  1.0f, 0.0f,		1.0f, 0.0f, 0.0f,	1.0f,  1.0f
		};
		for (size_t i = 0; i < 32; i++)   //i < 24
			vertexes.push_back(squareVerts[i]);	
		numVerts = 4;
		//delete squareVerts;
	}

	if (graphicType.compare("CIRCLE") == 0)
	{
		GLObjectCircle* obj = new GLObjectCircle;
		glObject = dynamic_cast<GLObjectCircle*>(obj);
		float numSegments = 12.0f;
		vertexes = std::vector<float>();


		float PI = 3.14159265f;
		float angleStep = PI / numSegments;
		float radius = 0.5f;

		for (float i = 0.0f; i < numSegments; ++i)
		{
			vertexes.push_back(0.0f); vertexes.push_back(0.0f); vertexes.push_back(0.0f);
			angleStep = (2.0f * PI * i) / numSegments;
			vertexes.push_back(0.5f*cosf(angleStep)); vertexes.push_back(0.5f*sinf(angleStep)); vertexes.push_back(0.0f);
			angleStep = (2.0f * PI * (i + 1)) / numSegments;
			vertexes.push_back(0.5f*cosf(angleStep)); vertexes.push_back(0.5f*sinf(angleStep)); vertexes.push_back(0.0f);
		}

		size_t si = vertexes.size();
		numVerts = si / 3;
	}
	return glObject;
}

void GLObjectFactory::InitVers(std::string texturePath)
{
	glObject->Init(&vertexes[0], numVerts, texturePath);
}