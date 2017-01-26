#include "InputController.h"
#include <iostream>

InputController::InputController(void)
{
	moveUp = false;
	moveDown = false;
	moveLeft = false;
	moveRight = false;
	stop = true;
}

void InputController::HandleEvent()
{

	if(Event.type == SDL_KEYDOWN)
	{
		switch (Event.key.keysym.sym)
		{
		case SDLK_UP:
			moveUp = true;
			break;
		case SDLK_DOWN:
			moveDown = true;
			break;
		case SDLK_LEFT:
			moveLeft = true;
			break;
		case SDLK_RIGHT:
			moveRight = true;
			break;
		default:
			stop = false;
			break;
		}
	}

	if(Event.type == SDL_KEYUP)
	{
		switch (Event.key.keysym.sym)
		{
		case SDLK_UP:
			moveUp = false;
			break;
		case SDLK_DOWN:
			moveDown = false;
			break;
		case SDLK_LEFT:
			moveLeft = false;
			break;
		case SDLK_RIGHT:
			moveRight = false;
			break;
		default:
			stop = true;
			break;
		}
	}
}

/*SDL_Event InputController::Event()
{
	if(!myEvent)
	{
		std::cout << "EVent not initialized SDL_Error:\n" << SDL_GetError();
		getchar();
		exit(0);
	}
	SDL_Event* pEvent = myEvent;
	return *pEvent;					//dereference the pointer to event to return an event
}*/

bool InputController::IsPollingEvent()
{
	return (SDL_PollEvent( &Event ) != 0);
}

bool InputController::MoveUp()
{
	return moveUp;
}

bool InputController::MoveDown()
{
	return moveDown;
}

bool InputController::MoveLeft()
{
	return moveLeft;
}

bool InputController::MoveRight()
{
	return moveRight;
}

bool InputController::Stopped()
{
	return stop;
}

InputController::~InputController(void)
{
	//delete myEvent;
}
