#ifndef InputController_H
#define InputController_H

#include <SDL.h>

class InputController
{
	bool moveUp;
	bool moveDown;
	bool moveLeft;
	bool moveRight;
	bool stop;
	bool isPolling;
	

	public:
		InputController(void);
		~InputController(void);

		void HandleEvent();
		bool MoveUp();
		bool MoveDown();
		bool MoveLeft();
		bool MoveRight();
		bool Stopped();
		SDL_Event Event;
		bool IsPollingEvent();

};

#endif