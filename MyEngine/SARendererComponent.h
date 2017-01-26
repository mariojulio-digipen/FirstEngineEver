#ifndef SARendererComponent_H
#define SARendererComponent_H

#include <iostream>
#include <vector>

#include "Component.h"
#include "MyWindowComponent.h"
#include "TransformComponent.h"
#include "FramerateController.h"


//class GLObjectSquare;
//class GLObjectCircle;
class GLObjectFactory;
class GLObjectBase;
namespace Entities
{
	//extern FramerateController* framerateController;

	class SARendererComponent : public Component
	{
		private:
			bool visible;
			SDL_Surface* entitySurface;
			TransformComponent* transform;
			void LoadBitmap(char* filePathAndName);

			/*GLObjectSquare* glObjectSquare;
			GLObjectCircle* glObjectCircle;*/
			GLObjectBase* glObject;
			std::vector<float> circleVerts;
			std::vector<float> squareVerts;

			GLObjectFactory* glFactory;

			std::string texturePath;
			int textureUnit;

		public:
			
			SARendererComponent();
			~SARendererComponent();

			Utils::FramerateController* frameRate;
			//SARendererComponent();
			//void SetData();
			void Update(float deltaTime);
			bool Initialize();
			bool Serialize(FILE** pfile);
			void HandleEvent(Events::Event* pEvent);
			bool ShutDown();

			GLObjectBase* GetGlObject();




	};

}

#endif