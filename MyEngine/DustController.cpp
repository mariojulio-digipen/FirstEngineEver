#include "DustController.h"
#include "CollideEvent.h"
#include "TransformComponent.h"
#include "MyWindowComponent.h"
#include "CheckerController.h"
#include "RoulletteComponent.h"

extern RollingTabletData* rollingTableData;

namespace Entities
{

	DustController::DustController()
	{
	}


	DustController::~DustController()
	{
	}


	bool DustController::Initialize()
	{
		transform = GetOwner()->FindComponent<TransformComponent>();

		return true;
	}
	void DustController::Update(float deltaTime)
	{
		if ((transform->Coords.x >= mainWindow.wWidth() + 100) ||
			(transform->Coords.y >= mainWindow.wHeight() / 2) ||
			(transform->Coords.x <= -100))
		{
			Entity* tmp = GetOwner();
			tmp->Alive = false;
		}
	}

	bool DustController::Serialize(FILE** pfile)
	{
		return true;
	}

	void DustController::HandleEvent(Events::Event* pEvent)
	{
		if (pEvent->Type == Events::EventType::COLLIDE)
		{

			Events::CollideEvent* collideEvent = (Events::CollideEvent*)pEvent;
			Entities::Entity* otherEntity = collideEvent->Entity1;
			Entities::Entity* thisEntity = collideEvent->Entity2;

			if (otherEntity->ArcheType == Entities::EntityType::CHECKER)
			{
				Entity* tmp = GetOwner();
				tmp->Alive = false;

				CheckerController* checker = otherEntity->FindComponent<CheckerController>();
				if (checker->Status == DataType::EX || checker->Status == DataType::CIRCLE)
				{
					checker->Status = DataType::EMPTY;
					for (size_t i = 0; i < 3; i++)
					{
						for (size_t j = 0; j < 3; j++)
						{
							float collidingCheckerId = rollingTableData->TicTacData[i][j].x;
							if (collidingCheckerId == checker->GetOwner()->Id)
							{
								rollingTableData->TicTacData[i][j].y = (float)checker->Status;
							}

						}
					}
				}

			}

			

		}
	}


}