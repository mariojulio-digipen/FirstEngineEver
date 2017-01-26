#ifndef FramerateController_H
#define FramerateController_H

#include <SDL.h>

namespace Utils
{
	class FramerateController
	{
		float tickStart;
		float tickEnd;
		float ticksPerFrame;			//(1000/maxRAte)
		float frameTime;


	public:
		FramerateController(float maxRate);
		~FramerateController();

		void FrameStart();
		void FrameEnd();
		float GetFrameTime();
		int GetTicks();



	};
}



#endif 



