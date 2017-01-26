#include "FramerateController.h"
#include <iostream>
namespace Utils
{
	FramerateController::FramerateController(float maxRate)
	{
		ticksPerFrame = 1000 / maxRate;
		frameTime = 0.0f;
	}

	void FramerateController::FrameStart()
	{
		tickStart = (float)SDL_GetTicks();
	}

	void FramerateController::FrameEnd()
	{
		tickEnd = (float)SDL_GetTicks();

		while ((tickEnd - tickStart) < ticksPerFrame)
			tickEnd = (float)SDL_GetTicks();
		frameTime = tickEnd - tickStart;
	}

	float FramerateController::GetFrameTime()
	{
		if(frameTime > 0.0f)
			std::cout << "Printing at: " << 1000 / frameTime << std::endl;
		return frameTime;
	}

	int Utils::FramerateController::GetTicks()
	{
		return (int)SDL_GetTicks();
	}

	FramerateController::~FramerateController()
	{
		//delete this;
	}

}
