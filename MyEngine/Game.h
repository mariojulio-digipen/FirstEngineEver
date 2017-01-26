#ifndef Game_H
#define Game_H

//#include <vector>

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
#include "ResourceManager.h"
#include "PhysicsManager.h"
#include "CollisionManager.h"
#include "Camera.h"
#include "InputManager.h"
#include "RollingTabletData.h"
#include "Shader.h"
#include <time.h>
#include <vector>

#include <functional>

class Game
{
private:
	bool quit;
	//std::vector<Entities::Entity*> levelEntities;

public:
	Game();
	~Game();

	int RunLevel();
	void Close();
};


#endif