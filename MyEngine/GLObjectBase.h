#ifndef GLObjectBase_H
#define GLObjectBase_H

#include "MyWindowComponent.h"
#include <string>

class Shader;
class GLModelBase;
namespace Entities {
	class TransformComponent;
}

class GLObjectBase
{
private:

	GLuint glVertexPos3DLocation = -1;
	Shader* objectShader;
	GLModelBase* objectModel;

	Entities::TransformComponent* transform;

public:
	GLObjectBase();
	virtual ~GLObjectBase();

	virtual void Init(GLfloat* verts, int numVerts, std::string texturePath) = 0;
	virtual void SetTransform(Entities::TransformComponent* transform) = 0;
	virtual Entities::TransformComponent* GetTransform() = 0;
	virtual void Render(float deltaTime) = 0;
	virtual void Update() = 0;
	virtual void Close() = 0;
};

#endif