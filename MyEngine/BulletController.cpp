#include "BulletController.h"
#include "TransformComponent.h"
#include "MoveEvent.h"
#include "ShootEvent.h"
#include "MyWindowComponent.h"
#include "CollideEvent.h"
#include "PhysicsComponent.h"
#include "CheckerController.h"
#include "RoulletteComponent.h"
#include <iostream>

extern RollingTabletData* rollingTableData;

namespace Entities
{
	BulletController::BulletController()
	{
	}


	BulletController::~BulletController()
	{
		//printf("");
	}

	bool BulletController::Initialize()
	{
		transform = GetOwner()->FindComponent<TransformComponent>();
		Vector3DSet(&shooterPoint, transform->Coords.x, transform->Coords.y, 0.0f);
		physics = GetOwner()->FindComponent<Entities::PhysicsComponent>();
		return true;
	}

	void BulletController::Update(float deltaTime)
	{
		if (( transform->Coords.x >= mainWindow.wWidth() + 100) ||
			( transform->Coords.y >= mainWindow.wHeight() / 2) ||
			( transform->Coords.y / 2 <= -100) ||
			(transform->Coords.x <= -100))
		{
			Entity* tmp = GetOwner();
			tmp->Alive = false;
		}

	}

	bool BulletController::Serialize(FILE** pfile)
	{
		//scanf_s(*pfile, "\n", &);
		return true;
	}

	void BulletController::HandleEvent(Events::Event* pEvent)
	{
		if (pEvent->Type == Events::EventType::COLLIDE)
		{
			
			Events::CollideEvent* collideEvent = (Events::CollideEvent*)pEvent;
			Entities::Entity* collider = collideEvent->Entity1;
			Entities::Entity* collider2 = collideEvent->Entity2;

			if (collider->ArcheType == Entities::EntityType::CONTROLS_SCREEN ||
				collider->ArcheType == Entities::EntityType::GENERAL)
			{
				Entity* tmp = GetOwner();
				tmp->Alive = false;
			}



			if (collider->ArcheType != Entities::EntityType::BULLET)
			{
				if (collider->ArcheType == Entities::EntityType::ENEMY)
				{
					Entity* tmp = GetOwner();
					tmp->Alive = false;
				}


				if (collider->ArcheType == Entities::EntityType::CHECKER)
				{
					CheckerController* checker = collider->FindComponent<CheckerController>();					

					// Destroy the bullet;
					Entity* tmp = GetOwner();
					tmp->Alive = false;

					// Change checker status;
					if (checker->Status == DataType::EMPTY)
					{
						if (this->Creator->ArcheType == Entities::EntityType::SHOOTER_RIGHT)
						{
							checker->Status = DataType::CIRCLE;
						}
						if (this->Creator->ArcheType == Entities::EntityType::SHOOTER_LEFT)
						{
							checker->Status = DataType::EX;
						}

						//checker->Status = DataType::EX;
						for (size_t i = 0; i < 3; i++)
						{
							for (size_t j = 0; j < 3; j++)
							{
								float collidingCheckerId = rollingTableData->TicTacData[i][j].x;
								if (collidingCheckerId == checker->GetOwner()->Id)
								{
									rollingTableData->TicTacData[i][j].y = (float)checker->Status;
									rollingTableData->TicTacData[i][j].z = (float)this->Creator->Id;
								}

							}
						}
					}
					else if (checker->Status == DataType::EX)
					{
						checker->Status = DataType::CIRCLE;
						for (size_t i = 0; i < 3; i++)
						{
							for (size_t j = 0; j < 3; j++)
							{
								float collidingCheckerId = rollingTableData->TicTacData[i][j].x;
								if (collidingCheckerId == checker->GetOwner()->Id)
								{
									rollingTableData->TicTacData[i][j].y = (float)checker->Status;
									rollingTableData->TicTacData[i][j].z = (float)this->Creator->Id;
								}

							}
						}
					}
					else if (checker->Status == DataType::CIRCLE)
					{
						checker->Status = DataType::EX;
						for (size_t i = 0; i < 3; i++)
						{
							for (size_t j = 0; j < 3; j++)
							{
								float collidingCheckerId = rollingTableData->TicTacData[i][j].x;
								if (collidingCheckerId == checker->GetOwner()->Id)
								{
									rollingTableData->TicTacData[i][j].y = (float)checker->Status;
									rollingTableData->TicTacData[i][j].z = (float)this->Creator->Id;
								}

							}
						}
					}

					// Renderer component changes the color of the checker;
					
				}
			}
		}
	}
}