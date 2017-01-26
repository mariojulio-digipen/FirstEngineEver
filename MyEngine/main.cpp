#include <iostream>
#include <string>

#include "MyWindowComponent.h"
#include "FramerateController.h"
#include "KeyBoardInputComponent.h"
#include "Entity.h"
#include "SARendererComponent.h"
#include "TransformComponent.h"
#include "PhysicsComponent.h"
#include "MoveActions.h"
#include "ControllerComponent.h"
#include "InverseControllerComponent.h"
#include "Game.h"


Game* game;


int Reset = 0;
bool Paused = false;
extern int LevelStatus;
int main(int argc, char* argv[])
{
	int quit = 0;
	game = new Game;
	while (1)
	{
		quit = game->RunLevel();
		
		
		if (Reset == 1)
		{
			if(game)
				delete game;
			LevelStatus = 1;
			game = new Game;
			game->RunLevel();
			Reset = 0;
		}
		if (quit == 1)
		{
			break;
		}
			
	}
	
	delete game;
	return 0;
}

