//#pragma once
//
//#include <FInputComponent.h>
//#include <FPhysicsComponent.h>
//#include <FGraphics.h>
//
//class FGameObject
//{
//	private:
//		static const int WALK_ACCELERATION = 1;
//
//		FInputComponent* input;
//		FPhysicsComponent* physics;
//		FGraphics* graphics;
//
//
//	public:
//		int velocity;
//		int x, y;
//
//		FGameObject(FInputComponent* input, FPhysicsComponent* physics, FGraphics* graphics);
//
//		void update(World& world, Graphics& graphics);
//
//		~FGameObject(void);
//};
//


//this code is back up. Don't delete it!
/*inputController->HandleEvent();
		while (inputController->IsPollingEvent())
		{

			if(inputController->MoveUp())
			{
				SDL_FillRect(  mainWindow->GetMyWindowSurface(), 
						& mainWindow->GetMyWindowSurface()->clip_rect, 
						SDL_MapRGB(  mainWindow->GetMyWindowSurface()->format, 
						0xFF, 0xFF, 0xFF ) );
				std::cout << "Printing 0 at " << framerateController->GetFrameTime() << "\n";
				SDL_BlitSurface(loader->GetLevelObject(0), NULL, mainWindow->GetMyWindowSurface(), NULL);
			}

			if(inputController->MoveDown())
			{
				SDL_FillRect(  mainWindow->GetMyWindowSurface(), 
						& mainWindow->GetMyWindowSurface()->clip_rect, 
						SDL_MapRGB(  mainWindow->GetMyWindowSurface()->format, 
						0xFF, 0xFF, 0xFF ) );
				std::cout << "Printing 1 at " << framerateController->GetFrameTime() << "\n";
				SDL_BlitSurface(loader->GetLevelObject(1), NULL, mainWindow->GetMyWindowSurface(), NULL);
			}

			if(inputController->MoveLeft())
			{
				SDL_FillRect(  mainWindow->GetMyWindowSurface(), 
						& mainWindow->GetMyWindowSurface()->clip_rect, 
						SDL_MapRGB(  mainWindow->GetMyWindowSurface()->format, 
						0xFF, 0xFF, 0xFF ) );
				std::cout << "Printing 2 at " << framerateController->GetFrameTime() << "\n";
				SDL_BlitSurface(loader->GetLevelObject(2), NULL, mainWindow->GetMyWindowSurface(), NULL);
			}

			if(inputController->MoveRight())
			{
				SDL_FillRect(  mainWindow->GetMyWindowSurface(), 
						& mainWindow->GetMyWindowSurface()->clip_rect, 
						SDL_MapRGB(  mainWindow->GetMyWindowSurface()->format, 
						0xFF, 0xFF, 0xFF ) );
				std::cout << "Printing 3 at " << framerateController->GetFrameTime() << "\n";
				SDL_BlitSurface(loader->GetLevelObject(3), NULL, mainWindow->GetMyWindowSurface(), NULL);
			}*/

			/*if(inputController->Stopped())
			{
				SDL_FillRect(  mainWindow->GetMyWindowSurface(), 
						& mainWindow->GetMyWindowSurface()->clip_rect, 
						SDL_MapRGB(  mainWindow->GetMyWindowSurface()->format, 
						0xFF, 0xFF, 0xFF ) );
				std::cout << "Printing 0 at " << framerateController->GetFrameTime() << "\n";
				SDL_BlitSurface(loader->GetLevelObject(0), NULL, mainWindow->GetMyWindowSurface(), NULL);
			}*/

			/*if(e.type == SDL_KEYDOWN)
			{
				switch (e.key.keysym.sym)
				{
				case SDLK_UP:
					
					break;
				case SDLK_DOWN:
					
					break;
				case SDLK_LEFT:
					
					break;
				case SDLK_RIGHT:
					
					break;
				default:
					SDL_FillRect(  mainWindow.GetMyWindowSurface(), 
						& mainWindow.GetMyWindowSurface()->clip_rect, 
						SDL_MapRGB(  mainWindow.GetMyWindowSurface()->format, 
						0xFF, 0xFF, 0xFF ) );
					std::cout << "Printing 0 at " << framerateController->GetFrameTime() << "\n";
					SDL_BlitSurface(loader.GetLevelObject(0), NULL, mainWindow.GetMyWindowSurface(), NULL);
					break;
				}
			}

		}*/



/*const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
        if( currentKeyStates[ SDL_SCANCODE_UP ] )
        {
			SDL_FillRect(  mainWindow->GetMyWindowSurface(), 
					&mainWindow->GetMyWindowSurface()->clip_rect, 
					SDL_MapRGB(  mainWindow->GetMyWindowSurface()->format, 
					0xFF, 0xFF, 0xFF ) );
			std::cout << "Printing 0 at " << framerateController->GetFrameTime() << "\n";
			SDL_BlitSurface(loader->GetLevelObject(0), 
				NULL, mainWindow->GetMyWindowSurface(), 
				NULL);
        }
        else if( currentKeyStates[ SDL_SCANCODE_DOWN ] )
        {
			SDL_FillRect(  mainWindow->GetMyWindowSurface(), 
					&mainWindow->GetMyWindowSurface()->clip_rect, 
					SDL_MapRGB(  mainWindow->GetMyWindowSurface()->format, 
					0xFF, 0xFF, 0xFF ) );
			std::cout << "Printing 1 at " << framerateController->GetFrameTime() << "\n";
			SDL_BlitSurface(loader->GetLevelObject(1), 
				NULL, mainWindow->GetMyWindowSurface(), 
				NULL);
        }
        else if( currentKeyStates[ SDL_SCANCODE_LEFT ] )
        {
			SDL_FillRect(  mainWindow->GetMyWindowSurface(), 
					&mainWindow->GetMyWindowSurface()->clip_rect, 
					SDL_MapRGB(  mainWindow->GetMyWindowSurface()->format, 
					0xFF, 0xFF, 0xFF ) );
			std::cout << "Printing 2 at " << framerateController->GetFrameTime() << "\n";
			SDL_BlitSurface(loader->GetLevelObject(2), 
				NULL, mainWindow->GetMyWindowSurface(), 
				NULL);
        }
        else if( currentKeyStates[ SDL_SCANCODE_RIGHT ] )
        {
			SDL_FillRect(  mainWindow->GetMyWindowSurface(), 
					&mainWindow->GetMyWindowSurface()->clip_rect, 
					SDL_MapRGB(  mainWindow->GetMyWindowSurface()->format, 
					0xFF, 0xFF, 0xFF ) );
			std::cout << "Printing 3 at " << framerateController->GetFrameTime() << "\n";
			SDL_BlitSurface(loader->GetLevelObject(3), 
				NULL, mainWindow->GetMyWindowSurface(), 
				NULL);
        }
        else
        {

        }*/