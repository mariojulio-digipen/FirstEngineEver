#include "Game.h"

#define CHECKERROR {int err = glGetError(); if (err) { fprintf(stderr, "OpenGL error in Game.cpp at line %d: %s\n", __LINE__, gluErrorString(err)); getchar(); exit(-1);} }


Assets::ResourceManager* resources;
Utils::FramerateController* framerateController;
Physics::PhysicsManager* physicsManager;
Physics::CollisionManager* collisionManager;
Events::EventManager* eventManager;
InputManager* sdlInput;

RollingTabletData* rollingTableData;

Shader* circleShader;
Shader* squareShader;

//GLObject* glObjectSquare;


//bool loadMedia();
float angle = 0.0f;
int LevelStatus = 1;
std::vector<Entities::Entity*> levelEntities;
extern int Reset;
extern bool Paused;

Game::Game()
{
	srand(time(NULL));

	quit = false;
	float maxFrameRate = 60.0f;



	resources = new Assets::ResourceManager;
	framerateController = new Utils::FramerateController(maxFrameRate);
	physicsManager = new Physics::PhysicsManager;
	collisionManager = new Physics::CollisionManager;
	eventManager = new Events::EventManager;
	sdlInput = new InputManager;
	rollingTableData = new RollingTabletData;

	circleShader = new Shader;
	squareShader = new Shader;

	circleShader->CreateCircleProgram();
	squareShader->CreateSquareProgram();

	resources->InitializeAssets("Level1.txt");
	levelEntities = resources->LevelEntities;

	physicsManager->ManagesThisEntities(levelEntities);
	physicsManager->SetUpCollisionManager(collisionManager);

	eventManager->BroadcastTo(levelEntities);

	for (auto entity : resources->LevelEntities)
	{
		if (entity->ArcheType == Entities::EntityType::SHOOTER_LEFT)
			rollingTableData->Player1Id = entity->Id;
		if (entity->ArcheType == Entities::EntityType::SHOOTER_RIGHT)
			rollingTableData->Player2Id = entity->Id;
	}
}


Game::~Game()
{
	Close();
}


int Game::RunLevel()
{

	while (!quit)
	{
		framerateController->FrameStart();

		SDL_Event e;
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			else if (e.type == SDL_KEYDOWN)
			{
				if (e.key.keysym.sym == SDLK_ESCAPE)
				{
					quit = true;
				}
			}
		}
		glClear(GL_COLOR_BUFFER_BIT);

		float deltaTime = framerateController->GetFrameTime();
		deltaTime /= 1000.0f;

		if (LevelStatus == 0)
		{
			//printf("continue!!!!!!");
			//resources->ResetGame();
			if (sdlInput->IsKeyDown(SDL_SCANCODE_RETURN))
			{
				//printf("ENTER!!!!");
				//Close();
				Reset = 1;
				return 0;
			}
			continue;
		}
		


		physicsManager->Update(deltaTime);

		//mainCamera.RotationAngle = 1.0f;
		mainCamera.Update(deltaTime);

		if (!mainWindow.OpenGLIsActive())
		{
			SDL_FillRect(mainWindow.GetMyWindowSurface(), NULL, 0x00000000);

		}
		//std::cout << "=============DRAWING============================================\n";
		sdlInput->UpdateKeyStates();
		for (size_t i = 0; i < resources->LevelEntities.size(); i++)
		{
			Entities::Entity* tmp = resources->LevelEntities.at(i);
			if (tmp)
			{
				if (!tmp->Alive)
				{
					tmp->ShutDown();
					delete tmp;
					resources->LevelEntities.erase(resources->LevelEntities.begin() + i);
					levelEntities.clear();
					levelEntities = resources->LevelEntities;
					physicsManager->ManagesThisEntities(levelEntities);
					eventManager->BroadcastTo(levelEntities);
				}
				else
				{
					tmp->Update(deltaTime);
				}
				rollingTableData->Update();
				
			}



		}
		/*for (size_t i = 0; i < 3; i++)
		{
			for (size_t j = 0; j < 3; j++)
			{
				if (rollingTableData->TicTacData[i][j].y == 0) std::cout << "  00   ";
				if (rollingTableData->TicTacData[i][j].y == 1) std::cout << "  EX   ";
				if (rollingTableData->TicTacData[i][j].y == 2) std::cout << "CIRCLE ";
			}
			std::cout << std::endl;
		}*/
		eventManager->Update(deltaTime);
		framerateController->FrameEnd();
		mainWindow.Update();

	}
	levelEntities.clear();
	if (quit)
		return 1;
	return 0;
}

void Game::Close()
{
	size_t g = resources->LevelEntities.size();
	for (size_t i = 0; i < g; i++)
	{
		Entities::Entity* tmp = resources->LevelEntities.at(i);
		tmp->ShutDown();
		delete tmp;
	}

	resources->LevelEntities.clear();
	glDeleteProgram(circleShader->Program);
	glDeleteProgram(squareShader->Program);
	CHECKERROR;
	delete resources;
	delete framerateController;
	delete physicsManager;
	delete collisionManager;
	delete eventManager;
	delete sdlInput;
	delete rollingTableData;

}