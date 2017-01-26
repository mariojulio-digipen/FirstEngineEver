#ifndef KeyInput_H
#define KeyInput_H


#include "IKeyManager.h"
#include "SDL.h"

namespace Input
{
	class KeyInput
	{
	private:
		/*IKeyManager* keyManager;
		int maxActionValue;
		int actionsThisFrame;*/

		SDL_Event e;
		const Uint8 *currentKeyStates;
		Uint8* previousKeyStates;
		int length;

		//will define a singleton pattern here
		/*static KeyInput instance;*/
		
		

	public:

		KeyInput();
		~KeyInput();
		//KeyInput(const KeyInput&);
		//KeyInput& operator=(const KeyInput&);

		void UpdateKeyStates();
		bool IsKeyDown(int key);
		bool IsKeyUp(int key);
		bool IsKeyPressed(int key);
		bool IsKeyRelease(int key);
		/*int GetActionsThisFrame() { return actionsThisFrame;}*/
		/*bool ActionHotThisFrame(int actions);*/
		/*bool ActionKeyTriggered(int actions);*/
		//for singleton:
		/*static KeyInput& getInstance();*/

	};
	/*#define sdlInput Input::KeyInput::getInstance()*/

}

#endif