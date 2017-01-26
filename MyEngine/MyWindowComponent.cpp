#include "MyWindowComponent.h"
#include <iostream>

#define WIDTH 900
#define HEIGHT 900 // difference of 380 (+420)

MyWindowComponent MyWindowComponent::instance;


bool MyWindowComponent::OpenGLIsActive()
{
	return useOpenGL;
}

void MyWindowComponent::initGraphicsAccelerationSetup()
{
	useOpenGL = true;
	/*char settingsFileName[256] = { "Settings.txt" };
	FILE *fp;
	fopen_s(&fp, settingsFileName, "r");
	if (!fp)
	{
		std::cout << "SDL could not initialize Software Accelerated graphics! SDL_Error:\n" << SDL_GetError();
		std::cout << "Press any key to finish the program...";
		getchar();
		exit(0);
	}
	while (!feof(fp))
	{
		char openGLSwitch[256];
		memset(openGLSwitch, 0, 256 * sizeof(char));
		fscanf_s(fp, "%s\n", openGLSwitch, sizeof(openGLSwitch));
		if (strcmp(openGLSwitch,"OpenGL_Off") == 0)
		{
			useOpenGL = false;
		}
		if (strcmp(openGLSwitch, "OpenGL_On") == 0)
		{
			useOpenGL = true;
		}
	}
	fclose(fp);*/
}

MyWindowComponent& MyWindowComponent::getInstance()
{
	return instance;
}

MyWindowComponent::MyWindowComponent()
{
	x = SDL_WINDOWPOS_UNDEFINED;
	y = SDL_WINDOWPOS_UNDEFINED;
	width = WIDTH;//640;
	height = HEIGHT;//480;
	useOpenGL = true;
	glContext = NULL;
	DebugMode = false;
	init();
}


MyWindowComponent::MyWindowComponent(int width, int height)
{
	x = SDL_WINDOWPOS_UNDEFINED;
	y = SDL_WINDOWPOS_UNDEFINED;
	this->width = width;
	this->height = height;
	useOpenGL = true;
	glContext = NULL;
	init();
}

MyWindowComponent::MyWindowComponent(int width, int height, int x, int y)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	useOpenGL = true;
	glContext = NULL;
	init();
}

void MyWindowComponent::init()
{
	initGraphicsAccelerationSetup();
	if (useOpenGL)
	{
		// init openGL
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			printf("SDL could not initialize OpenGL! SDL Error: %s\n", SDL_GetError());
			getchar();
			exit(0);
		}

		// Setup the opengl context and attempt to create the window
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
		myWindow = SDL_CreateWindow("OpenGL Window", x, y, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
		if (myWindow == NULL)
		{
			std::cout << "Window could not be created! SDL_Error:\n" << SDL_GetError();
			getchar();
			exit(0);
		}

		// Create Context if windows is successfully created
		glContext = SDL_GL_CreateContext(myWindow);
		if (glContext == NULL)
		{
			printf("OpenGL context could not be created! SDL Error: %s\n", SDL_GetError());
			getchar();
			exit(0);
		}
		
		// Initialize extensions through GLEW only if a context was successfuly created
		glewExperimental = GL_FALSE;
		GLenum glewError = glewInit();
		if (glewError != GLEW_OK)
		{
			printf("Error initializing GLEW! %s\n", glewGetErrorString(glewError));
			getchar();
			exit(0);
		}
		

		// If GLEW was successfully initialized, start using vsync
		if (SDL_GL_SetSwapInterval(1) < 0)
		{
			printf("Warning: Unable to set VSync! SDL Error: %s\n", SDL_GetError());
		}

	}
	else
	{
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			std::cout << "SDL could not initialize! SDL_Error:\n" << SDL_GetError();
			getchar();
			exit(0);
		}
		myWindow = SDL_CreateWindow("SDL Window", x, y, width, height, SDL_WINDOW_SHOWN);
		if (myWindow == NULL)
		{
			std::cout << "Window could not be created! SDL_Error:\n" << SDL_GetError();
			getchar();
			exit(0);
		}
		myWindowSurface = SDL_GetWindowSurface(myWindow);
	}

	
}


void MyWindowComponent::Update()
{
	if (mainWindow.OpenGLIsActive())
	{
		SDL_GL_SwapWindow(myWindow);
	}
	else
	{
		SDL_UpdateWindowSurface(myWindow);
	}

	
}

SDL_Window* MyWindowComponent::GetMyWindow()
{
	return myWindow;
}

SDL_Surface* MyWindowComponent::GetMyWindowSurface()
{
	return myWindowSurface;
}

int MyWindowComponent::wWidth()
{
	return width;
}

int MyWindowComponent::wHeight()
{
	return height;
}

int MyWindowComponent::wX()
{
	return x;
}


int MyWindowComponent::wY()
{
	return y;
}

MyWindowComponent::~MyWindowComponent()
{
	SDL_DestroyWindow(myWindow);
	myWindow= NULL;

	SDL_Quit();
}