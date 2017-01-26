#include "Camera.h"
#include "MyWindowComponent.h"

Camera Camera::instance;

Camera& Camera::getInstance()
{
	return instance;
}

Camera::Camera()
{

}


Camera::~Camera()
{
}

void Camera::buildViewMatrix()
{
	// Building the view matrix
	float X = 0.0f;//(float) mainWindow.wWidth() / 2.0f;
	float Y = 0.0f;//(float) mainWindow.wHeight() / 2.0f;
	eyeView = glm::vec3(X, Y, 1.0f);
	eyeDir = glm::vec3(X, Y, 0.0f);
	eyeUp = glm::vec3(0.0f, 1.0f, 0.0f);
	viewMatrix = glm::lookAt(eyeView, eyeDir, eyeUp);
	viewMatrix = glm::translate(viewMatrix, glm::vec3(OffsetX, OffsetY, 0));
}

void Camera::buildProjectionMatrix()
{
	// Building the projection matrix
	//float aspectRatio = (float)mainWindow.wWidth() / (float)mainWindow.wHeight();
	//projMatrix = glm::perspective(glm::radians(45.0f), aspectRatio, -1.0f, 10.0f);
	float maxWinX = static_cast<float>(mainWindow.wWidth());
	float maxWinY = static_cast<float>(mainWindow.wHeight());
	projMatrix = glm::ortho(0.0f, maxWinX, maxWinY, 0.0f, -1.0f, 1.0f);
}


bool Camera::Initialize()
{
	buildViewMatrix();
	buildProjectionMatrix();
	return true;
}

void Camera::Update(float deltaTime)
{
	//RotationAngle = RotationAngle*deltaTime;
	viewMatrix = glm::rotate(viewMatrix, RotationAngle, glm::vec3(0.0f, 0.0f, 1.0f));
	//viewMatrix = glm::translate(viewMatrix, glm::vec3(OffsetX, OffsetY, 0));
	//viewMatrix = glm::lookAt(eyeView, eyeDir, eyeUp);
}

glm::mat4 Camera::GetProjMatrix()
{
	return projMatrix;
}

glm::mat4 Camera::GetViewMatrix()
{
	return viewMatrix;
}