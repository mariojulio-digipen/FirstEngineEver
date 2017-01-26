#include "CheckerController.h"

namespace Entities
{

	CheckerController::CheckerController()
	{
	}


	CheckerController::~CheckerController()
	{
	}

	bool CheckerController::Initialize()
	{
		return true;

	}

	void CheckerController::Update(float deltaTime)
	{

	}

	bool CheckerController::Serialize(FILE** pfile)
	{
		fscanf_s(*pfile, "%i\n", &Status);
		return true;
	}

	void CheckerController::HandleEvent(Events::Event* pEvent)
	{

	}

	bool CheckerController::ShutDown()
	{
		return true;
	}


}