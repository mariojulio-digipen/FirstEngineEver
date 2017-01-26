#ifndef Shader_H
#define Shader_H

#include <SDL.h>
#include <GL\glew.h>
#include <GL\GLU.h>

class Shader
{
public:
	Shader();
	~Shader();


	GLuint Program;

	void CreateProgram();
	void CreateShader(const char* fileName, const int type);
	void LinkProgram();
	void Use();
	void Unuse();

	void CreateSquareProgram();
	void CreateCircleProgram();

};

#endif