#include "Texture.h"
#include "SOIL.h"
#include <iostream>

#define CHECKERROR {int err = glGetError(); if (err) { fprintf(stderr, "OpenGL error in Texture.cpp at line %d: %s\n", __LINE__, gluErrorString(err)); getchar(); exit(-1);} }

Texture::Texture()
{
}


Texture::~Texture()
{
	glDeleteTextures(1, &textureId);
}

void Texture::Create(int program, GLuint* tetCoords)
{
	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);

	int width, height;
	unsigned char* image = SOIL_load_image(this->texturePath.c_str(), &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);

	*tetCoords = glGetAttribLocation(program, "texturePos");
	if (*tetCoords == -1)
	{
		std::cout << "texturePos is not a valid glsl program variable!";
		getchar();
		exit(-1);
	}

	
	glBindTexture(GL_TEXTURE_2D, 0);
}


void Texture::SetTexturePath(std::string texturePath)
{
	this->texturePath = texturePath;
}