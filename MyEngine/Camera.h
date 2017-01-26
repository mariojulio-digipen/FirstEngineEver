#ifndef Camera_H
#define Camera_H

#include <glm\glm\glm.hpp>
#include <glm\glm\gtc\matrix_transform.hpp>
#include <glm\glm\gtc\type_ptr.hpp>

class Camera
{

private:
	glm::mat4 viewMatrix;
	glm::mat4 viewRot, viewScale, viewTrans;
	glm::vec3 eyeView, eyeDir, eyeUp;

	glm::mat4 projMatrix;

	static Camera instance;

	Camera();
	Camera(const Camera&);
	
	void buildViewMatrix();
	void buildProjectionMatrix();

public:
	~Camera();

	float OffsetX = 0.0f;// -static_cast<float>(mainWindow.wWidth()) / 2;
	float OffsetY = 0.0f;// -static_cast<float>(mainWindow.wHeight()) / 2;
	float RotationAngle = 0.0f;

	bool Initialize();
	void Update(float deltaTime);

	glm::mat4 GetViewMatrix();
	glm::mat4 GetProjMatrix();

	static Camera& getInstance();
};

#define mainCamera Camera::getInstance()

#endif