#include "Shader.h"
#include "Debug.h"
#include <fstream>
#include <iostream>
#include <sstream>

// Reads a specified file into a string and returns the string.
std::string ReadFile(const char* name)
{

	std::ifstream ifile(name);
	std::string filetext;

	while (ifile.good()) {
		std::string line;
		std::getline(ifile, line);
		filetext.append(line + "\n");
	}

	ifile.close();
	return filetext;
}

Shader::Shader()
{
}


Shader::~Shader()
{
}


void Shader::CreateSquareProgram()
{
	CreateProgram();
	CreateShader("DebugSquare.vertex", GL_VERTEX_SHADER);
	CreateShader("DebugSquare.fragment", GL_FRAGMENT_SHADER);
	LinkProgram();
	CHECKERROR;
}


void Shader::CreateCircleProgram()
{
	CreateProgram();
	CreateShader("DebugCircle.vertex", GL_VERTEX_SHADER);
	CreateShader("DebugCircle.fragment", GL_FRAGMENT_SHADER);
	LinkProgram();
	CHECKERROR;
}

void Shader::CreateProgram()
{
	Program = glCreateProgram();
}

void Shader::CreateShader(const char* fileName, const int type)
{
	// Read the source from the named file
	std::string src = ReadFile(fileName);
	//const char* psrc[1] = { src };

	// Create a shader and attach, hand it the source, and compile it.
	int shader = glCreateShader(type);
	//glShaderSource(shader, 1, psrc, NULL);
	//const char* c_str = src.c_str();

	GLchar const *shader_source = src.c_str();
	GLint const shader_length = src.size();

	glShaderSource(shader, 1, &shader_source, &shader_length);
	glCompileShader(shader);
	//delete[] src;

	// Get the compilation status
	int status;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);

	// If compilation status is not OK, get and print the log message.
	if (status != 1) {
		int length;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
		char* buffer = new char[length];
		glGetShaderInfoLog(shader, length, NULL, buffer);
		printf("Compile log for %s:\n%s\n", fileName, buffer);
		delete buffer;
		getchar();
		exit(-1);
	}

	glAttachShader(Program, shader);
	CHECKERROR;

	// test transform feedback feature. (I'll need this for my rotations)
	//const GLchar* feedbackVaryings[] = { "PosX", "PosY" };
	//glTransformFeedbackVaryings(Program, 2, feedbackVaryings, GL_INTERLEAVED_ATTRIBS);
	//CHECKERROR;

}

void Shader::LinkProgram()
{
	// Link program and check the status
	glLinkProgram(Program);
	int status;
	glGetProgramiv(Program, GL_LINK_STATUS, &status);

	// If link failed, get and print log
	if (status != 1) {
		int length;
		glGetProgramiv(Program, GL_INFO_LOG_LENGTH, &length);
		char* buffer = new char[length];
		glGetProgramInfoLog(Program, length, NULL, buffer);
		printf("Link log:\n%s\n", buffer);
		delete buffer;
		getchar();
		std::cout << "Press any key to finish the program..." << std::endl;
		exit(-1);
	}
}

void Shader::Use()
{
	glUseProgram(Program);
}

void Shader::Unuse()
{
	glUseProgram(NULL);
}


