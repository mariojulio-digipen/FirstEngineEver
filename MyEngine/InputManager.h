#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <SDL.h>

class InputManager
{
public:
	InputManager();
	~InputManager();
	void UpdateKeyStates();
	bool IsKeyDown(int key);
	bool IsKeyUp(int key);
	bool IsKeyPressed(int key);

private:
	SDL_Event e;
	const Uint8* currentKeyStates;

	bool isPressed[512];
	bool isReleased[512];

	bool isPressedInPreviousFrame[512];
	bool isReleasedInPreviousFrame[512];

	int length;
};

#endif