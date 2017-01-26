#include "SARendererComponent.h"
#include "Entity.h"
#include "GLObjectSquare.h"
#include "GLObjectCircle.h"
#include "Vector3D.h"
#include "Matrix3D.h"
#include "GLObjectFactory.h"
#include "GLObjectBase.h"
#include "CheckerController.h"
#include "SDL_ttf.h"
#include "InputManager.h"
#include "RollingTabletData.h"
#include "TextureUnitFactory.h"
#include <SDL.h>
#include <SDL_opengl.h>

#define CHECKERROR {int err = glGetError(); if (err) { fprintf(stderr, "OpenGL error in SARenderer.cpp at line %d: %s\n", __LINE__, gluErrorString(err)); getchar(); exit(-1);} }


extern InputManager* sdlInput;
extern RollingTabletData* rollingTableData;
extern int LevelStatus;

namespace Entities
{



	bool SARendererComponent::Initialize()
	{
		transform = GetOwner()->FindComponent<TransformComponent>();
		
		if (!mainWindow.OpenGLIsActive())
		{
			return true;
		}

		std::string graphicType = GetOwner()->GraphicType;

		TextureUnitFactory* unit = new TextureUnitFactory;
		textureUnit = unit->GetTextureUnit(this);

		glFactory = new GLObjectFactory;
		glObject = glFactory->GLObject(graphicType, textureUnit);

		glFactory->InitVers(texturePath);
		delete unit;
		return true;
	}
	bool SARendererComponent::ShutDown()
	{
		//TODO
		
		return true;
	}

	void SARendererComponent::Update(float deltaTime)
	{
		Entity* owner = GetOwner();
		if (!owner)
			return;
		if ((owner->Name.compare("PlayerLeftWinPic") == 0))
		{
			if (rollingTableData->GetWinner() != EntityType::SHOOTER_LEFT)
			{
				return;
			}
			else
			{
				LevelStatus = 0;
			}
		}

		if ((owner->Name.compare("PlayerRightWinPic") == 0))
		{
			if (rollingTableData->GetWinner() != EntityType::SHOOTER_RIGHT)
			{
				return;
			}
			else
			{
				LevelStatus = 0;
			}
		}
		

		if (sdlInput->IsKeyDown(SDL_SCANCODE_1))
		{
			mainWindow.DebugMode = false;
		}
		else if(sdlInput->IsKeyDown(SDL_SCANCODE_2))
		{
			mainWindow.DebugMode = true;
		}

		bool isOpenGlActive = mainWindow.OpenGLIsActive();
		if (isOpenGlActive)
		{
			glObject->SetTransform(transform);

			GLObjectCircle* checkerShape = dynamic_cast<GLObjectCircle*>(glObject);
			if (checkerShape)
			{
				CheckerController* checkerController = GetOwner()->FindComponent<CheckerController>();
				if (checkerController)
				{
					if (checkerController->Status == DataType::EX)
					{
						checkerShape->Color[0] = 1.0f;
						checkerShape->Color[1] = 0.5f;
						checkerShape->Color[2] = 0.1f;
					}

					if (checkerController->Status == DataType::CIRCLE)
					{
						checkerShape->Color[0] = 0.1f;
						checkerShape->Color[1] = 0.5f;
						checkerShape->Color[2] = 1.0f;
					}

					if (checkerController->Status == DataType::EMPTY)
					{
						checkerShape->Color[0] = 1.0f;
						checkerShape->Color[1] = 1.0f;
						checkerShape->Color[2] = 1.0f;
					}
				}
				
				
			}

			glObject->Render(deltaTime);
			glObject->Update();

			
		}
		else
		{
			SDL_Rect DestR;
			DestR.x = (int)transform->Coords.x;
			DestR.y = (int)transform->Coords.y;
			DestR.w = (int)transform->Scale.x;
			DestR.h = (int)transform->Scale.y;
			SDL_BlitSurface(entitySurface, NULL, mainWindow.GetMyWindowSurface(), &DestR);
		}

	}

	void Entities::SARendererComponent::HandleEvent(Events::Event* pEvent)
	{

	}


	GLObjectBase* SARendererComponent::GetGlObject()
	{
		return glObject;
	}

	bool SARendererComponent::Serialize(FILE ** pfile)
	{
			char imageName[256];
			char fullPath[256] = { "../images/" };
			memset(imageName, 0, 256 * sizeof(char));
			fscanf_s(*pfile, "%255s\n", imageName, sizeof(imageName));
			strcat_s(fullPath, imageName);
			texturePath = fullPath;
			LoadBitmap(fullPath);
			return true;				
		
	}


	void SARendererComponent::LoadBitmap(char* filePathAndName)
	{
		SDL_Surface* img = SDL_LoadBMP(filePathAndName);
		if (img == NULL)
		{
			std::cout << "Unable to load image images! SDL Error:" << SDL_GetError();
			getchar();
			exit(0);
		}
		this->entitySurface = img;
	}

	SARendererComponent::SARendererComponent()
	{
		visible = true;
	}

	SARendererComponent::~SARendererComponent()
	{
		Entity* ent = GetOwner();
		delete glFactory;
		delete glObject;
	}
}