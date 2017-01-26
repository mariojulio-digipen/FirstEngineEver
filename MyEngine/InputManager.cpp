#include "InputManager.h"
#include <string.h>
#include <iostream>


InputManager::InputManager()
{
	int numkeys;
	currentKeyStates = SDL_GetKeyboardState(&numkeys);
	

	for (size_t i = 0; i < 512; i++)
	{
		isPressed[i] = false;
		isReleased[i] = true;
		isPressedInPreviousFrame[i] = false;
		isReleasedInPreviousFrame[i] = false;
	}
}

InputManager::~InputManager()
{
}

void InputManager::UpdateKeyStates()
{
	for (size_t i = 0; i < 512; i++)
	{
		isPressedInPreviousFrame[i] = isPressed[i];
		isReleasedInPreviousFrame[i] = isReleased[i];

		if (currentKeyStates[i])
		{
			isPressed[i] = true;
			isReleased[i] = false;
		}
		else
		{
			isPressed[i] = false;
			isReleased[i] = true;
		}
	}
}

bool InputManager::IsKeyDown(int key)
{
	bool r = static_cast<bool>(currentKeyStates[key]);
	return r;
}

bool InputManager::IsKeyUp(int key)
{
	return !currentKeyStates[key];
}

bool InputManager::IsKeyPressed(int key)
{

	if (isPressed[key] && !isPressedInPreviousFrame[key])
	{
		return true;
	}
	return false;
}
