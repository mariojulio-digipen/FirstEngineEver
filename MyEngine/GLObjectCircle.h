#ifndef GLObject_NEW_Circle_H
#define GLObject_NEW_Circle_H


#include "MyWindowComponent.h"
#include "GLObjectBase.h"
#include "Vector3D.h"

class Shader;
class GLModelCircle;
namespace Entities {
	class TransformComponent;
}


class GLObjectCircle : public GLObjectBase
{

private:

	GLuint glVertexPos3DLocation = -1;

	Shader* objectShader;
	GLModelCircle* objectModel;

	Entities::TransformComponent* transform;

	int nVerts;

public:


	GLfloat Color[3];

	GLObjectCircle();
	~GLObjectCircle();

	void Init(GLfloat* verts, int numVerts, std::string texturePath);
	void SetTransform(Entities::TransformComponent* transform);
	Entities::TransformComponent* GetTransform();
	void Render(float deltaTime);
	void Update();
	void Close();

};

#endif