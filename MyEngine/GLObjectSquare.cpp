#include "GLObjectSquare.h"
#include <SDL.h>
#include <GL\glew.h>
#include <GL\GLU.h>
#include <SDL_opengl.h>
#include "iostream"
#include "Shader.h"
#include "GLModelSquare.h"
#include "Matrix3D.h"
#include "TransformComponent.h"
#include "Camera.h"
#include "Texture.h"
#include <glm\glm\glm.hpp>
#include <glm\glm\gtc\matrix_transform.hpp>
#include <glm\glm\gtc\type_ptr.hpp>
#include "SOIL.h"

extern Shader* squareShader;

#define CHECKERROR {int err = glGetError(); if (err) { fprintf(stderr, "OpenGL error in GLObjectSquare.cpp at line %d: %s\n", __LINE__, gluErrorString(err)); getchar(); exit(-1);} }

GLObjectSquare::GLObjectSquare() : GLObjectBase()
{
	objectShader = squareShader; //TODO Use global shader variable
	objectModel = new GLModelSquare;
	texture = new Texture;
}


GLObjectSquare::~GLObjectSquare()
{
	//delete objectShader;
	delete objectModel;
	delete texture;
}


void GLObjectSquare::SetTextureUnit(int textureUnit)
{
	this->textureUnit = textureUnit;
}

void GLObjectSquare::Init(GLfloat* verts, int numVerts, std::string texturePath)
{
	if (!mainWindow.OpenGLIsActive())
	{
		return;
	}

	objectModel->SetVertexData(verts, numVerts);

	/*objectShader->CreateProgram();
	objectShader->CreateShader("DebugSquare.vertex", GL_VERTEX_SHADER);
	objectShader->CreateShader("DebugSquare.fragment", GL_FRAGMENT_SHADER);
	objectShader->LinkProgram();
	CHECKERROR;*/


	objectModel->DefineBox();

	glVertexPos3DLocation = glGetAttribLocation(objectShader->Program, "LVertexPos3D");
	if (glVertexPos3DLocation == -1)
	{
		std::cout << "LVertexPos3D is not a valid glsl program variable!";
		getchar();
		exit(-1);
	}

	texture->SetTexturePath(texturePath);
	texture->Create(objectShader->Program, &glTextureCoords);
	
}



void GLObjectSquare::SetTransform(Entities::TransformComponent * transform)
{
	this->transform = transform;
	
}

Entities::TransformComponent* GLObjectSquare::GetTransform()
{
	return this->transform;
}

void GLObjectSquare::Render(float deltaTime)
{
	if (!mainWindow.OpenGLIsActive())
	{
		return;
	}

	glViewport(0, 0, mainWindow.wWidth(), mainWindow.wHeight());
	objectShader->Use();

	GLuint location;
	Matrix3D modelMatrix = this->transform->GetModelMatrix();
	//std::cout << this->transform->Coords.x << ", " << this->transform->Coords.y << std::endl;
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
	CHECKERROR;

	if (mainWindow.DebugMode == false)
	{
		glActiveTexture(GL_TEXTURE0 + textureUnit);	// activates texture unit depending on the archetype
		glBindTexture(GL_TEXTURE_2D, texture->textureId);
		CHECKERROR;

		location = glGetUniformLocation(objectShader->Program, "customTexture");
		glUniform1i(location, textureUnit);
		CHECKERROR;

		location = glGetUniformLocation(objectShader->Program, "debugMode");
		glUniform1i(location, 0);
		CHECKERROR;
	}
	else
	{

		location = glGetUniformLocation(objectShader->Program, "debugMode");
		glUniform1i(location, 1);
		CHECKERROR;
	}
	

	objectModel->DrawBox(glVertexPos3DLocation, glColorLocation, glTextureCoords);

	if (mainWindow.DebugMode == false)
	{
		glBindTexture(GL_TEXTURE_2D, 0);	// deactivate texture unit 1
		CHECKERROR;
	}
	objectShader->Unuse();
}

void GLObjectSquare::Update()
{
	if (!mainWindow.OpenGLIsActive())
	{
		return;
	}
	objectModel->Update();
	/*Vector3D modelFeedback = objectModel->GetModelFeedback();
	std::cout << modelFeedback.x << " = " << transform->Coords.x << " and " << modelFeedback.y << " = " << transform->Coords.y << std::endl;*/
}

void GLObjectSquare::Close()
{
	/*if (!mainWindow.OpenGLIsActive())
	{
		return;
	}
	glDeleteProgram(objectShader->Program);
	CHECKERROR;*/
}