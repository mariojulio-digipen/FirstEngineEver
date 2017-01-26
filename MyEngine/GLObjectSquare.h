#ifndef GLObject_NEW_H
#define GLObject_NEW_H

#include "MyWindowComponent.h"
#include "GLObjectBase.h"
#include "Vector3D.h"

class Shader;
class GLModelSquare;
class Texture;
namespace Entities{
	class TransformComponent;
}

class GLObjectSquare : public GLObjectBase
{
private:

	GLuint glVertexPos3DLocation = -1;
	GLuint glColorLocation = -1;
	GLuint glTextureCoords = -1;

	Shader* objectShader;
	GLModelSquare* objectModel;


	Entities::TransformComponent* transform;

	Texture* texture;
	int textureUnit;



public:
	GLObjectSquare();
	~GLObjectSquare();


	void SetTextureUnit(int textureUnit);

	void Init(GLfloat* verts, int numVertices, std::string texturePath);
	void SetTransform(Entities::TransformComponent* transform);
	Entities::TransformComponent* GetTransform();
	//Vector3D GetCoordsFeedback();
	void Render(float deltaTime);
	void Update();
	void Close();

};

#endif