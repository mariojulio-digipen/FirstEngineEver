#ifndef MyWindow_H
#define MyWindow_H

#include <SDL.h>
#include <GL\glew.h>
#include <GL\GLU.h>
#include <SDL_opengl.h>

class MyWindowComponent
{
	private:
		// Attribures members
		int width;
		int height;
		int x;
		int y;
		SDL_Window* myWindow;
		SDL_Surface* myWindowSurface;

		// If windows is setup to work with opengl, a context must exist
		SDL_GLContext glContext;
		bool useOpenGL;

		void init();

		static MyWindowComponent instance;

		MyWindowComponent();
		MyWindowComponent(const MyWindowComponent&);
		//MyWindowComponent& operator=(const MyWindowComponent&);
		void initGraphicsAccelerationSetup();



	public:

		bool DebugMode;

		// Constructors list
		MyWindowComponent(int width, int height);
		MyWindowComponent(int width, int height, int x, int y);

		~MyWindowComponent();

		// Function members
		SDL_Window* GetMyWindow();
		SDL_Surface* GetMyWindowSurface();
		int wWidth();
		int wHeight();
		int wX();
		int wY();
		bool OpenGLIsActive();
		void Update();

		static MyWindowComponent& getInstance();
};

#define mainWindow MyWindowComponent::getInstance()

#endif



