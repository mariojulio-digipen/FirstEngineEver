#ifndef Texture_H
#define Texture_H


#include <GL\glew.h>
#include <string>

class Texture
{
private:
	std::string texturePath;

public:
	Texture();
	~Texture();

	void SetTexturePath(std::string texturePath);
	void Create(int program, GLuint* tetCoords);

	GLuint textureId;
};

#endif