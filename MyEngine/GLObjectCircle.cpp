#include "GLObjectCircle.h"
#include "GLObjectCircle.h"
#include "iostream"
#include "Shader.h"
#include "GLModelCircle.h"
#include "Matrix3D.h"
#include "TransformComponent.h"
#include "Camera.h"
#include <glm\glm\glm.hpp>
#include <glm\glm\gtc\matrix_transform.hpp>
#include <glm\glm\gtc\type_ptr.hpp>

extern Shader* circleShader;

#define CHECKERROR {int err = glGetError(); if (err) { fprintf(stderr, "OpenGL error in GLObjectCircle.cpp at line %d: %s\n", __LINE__, gluErrorString(err)); getchar(); exit(-1);} }

GLObjectCircle::GLObjectCircle() : GLObjectBase()
{
	objectShader = circleShader;
	objectModel = new GLModelCircle;
	Color[0] = Color[1] = Color[2] = 1.0f;
}


GLObjectCircle::~GLObjectCircle()
{
	delete objectShader;
	delete objectModel;
}


void GLObjectCircle::Init(GLfloat * verts, int numVerts, std::string texturePath)
{
	nVerts = numVerts;

	if (!mainWindow.OpenGLIsActive())
	{
		return;
	}

	objectModel->SetVertexData(verts, numVerts);

	/*objectShader->CreateProgram();
	objectShader->CreateShader("DebugCircle.vertex", GL_VERTEX_SHADER);
	objectShader->CreateShader("DebugCircle.fragment", GL_FRAGMENT_SHADER);
	objectShader->LinkProgram();
	CHECKERROR;*/

	objectModel->DefineCircle();

	glVertexPos3DLocation = glGetAttribLocation(objectShader->Program, "LVertexPos3D");
	if (glVertexPos3DLocation == -1)
	{
		std::cout << "LVertexPos3D is not a valid glsl program variable!";
		getchar();
		exit(-1);
	}

	CHECKERROR;

}


void GLObjectCircle::SetTransform(Entities::TransformComponent * transform)
{
	this->transform = transform;
}

Entities::TransformComponent * GLObjectCircle::GetTransform()
{
	return this->transform;
}

void GLObjectCircle::Render(float deltaTime)
{
	if (!mainWindow.OpenGLIsActive())
	{
		return;
	}

	glViewport(0, 0, mainWindow.wWidth(), mainWindow.wHeight());
	objectShader->Use();

	GLuint location;
	Matrix3D modelMatrix = this->transform->GetModelMatrix();

	glm::mat4 viewMatrix = mainCamera.GetViewMatrix();
	glm::mat4 projMatrix = mainCamera.GetProjMatrix();

	location = glGetUniformLocation(objectShader->Program, "ModelMatrix");
	glUniformMatrix4fv(location, 1, GL_TRUE, &(modelMatrix.m[0][0]));
	CHECKERROR;

	location = glGetUniformLocation(objectShader->Program, "ViewMatrix");
	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(viewMatrix));
	CHECKERROR;

	location = glGetUniformLocation(objectShader->Program, "ProjectionMatrix");
	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(projMatrix));
	CHECKERROR;//Color

	//Color[0] = 0.0f; Color[2] = 0.0;
	location = glGetUniformLocation(objectShader->Program, "CircleColor");
	glUniform3fv(location, 1, &Color[0]);
	CHECKERROR;

	objectModel->DrawCircle(glVertexPos3DLocation, nVerts);
	objectShader->Unuse();

}


void GLObjectCircle::Update()
{
	if (!mainWindow.OpenGLIsActive())
	{
		return;
	}
}

void GLObjectCircle::Close()
{
	/*if (!mainWindow.OpenGLIsActive())
	{
		return;
	}
	glDeleteProgram(objectShader->Program);
	CHECKERROR;*/
}