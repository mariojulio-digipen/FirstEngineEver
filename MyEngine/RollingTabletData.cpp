#include "RollingTabletData.h"

int getRand(int min, int max)
{
	int r = (rand() % max) + min;
	return r;
}

RollingTabletData::RollingTabletData()
{
	EnemyLeftData = 0;
	EnemyRightData = 0;
	GameLogicCounterController = getRand(1, 2);
	winner = Entities::EntityType::Max;
	
}


RollingTabletData::~RollingTabletData()
{
}

Entities::EntityType RollingTabletData::GetWinner()
{
	return winner;
}


void RollingTabletData::Update()
{
	EnemyLeftData = getRand(0, 2);
	int tmp = getRand(0, 2);
	while (tmp == EnemyLeftData)
	{
		tmp = getRand(0, 2);
	}
	EnemyRightData = tmp;

	EnemyLeftData2 = getRand(0, 2);
	tmp = getRand(0, 2);
	while (tmp == EnemyLeftData2)
	{
		tmp = getRand(0, 2);
	}
	EnemyRightData2 = tmp;

	EnemyLeftData3 = getRand(0, 2);
	tmp = getRand(0, 2);
	while (tmp == EnemyLeftData3)
	{
		tmp = getRand(0, 2);
	}

	EnemyRightData3 = tmp;

	float counter = 0;
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			counter += TicTacData[i][j].y ;
		}
	}
	if (counter <= 0)
		return;


	if ((TicTacData[0][0].y == 1 && TicTacData[0][1].y == 1 && TicTacData[0][2].y == 1) ||
		(TicTacData[1][0].y == 1 && TicTacData[1][1].y == 1 && TicTacData[1][2].y == 1) ||
		(TicTacData[2][0].y == 1 && TicTacData[2][1].y == 1 && TicTacData[2][2].y == 1) ||

		(TicTacData[0][0].y == 1 && TicTacData[1][0].y == 1 && TicTacData[2][0].y == 1) ||
		(TicTacData[0][1].y == 1 && TicTacData[1][1].y == 1 && TicTacData[2][1].y == 1) ||
		(TicTacData[0][2].y == 1 && TicTacData[1][2].y == 1 && TicTacData[2][2].y == 1) ||
		
		(TicTacData[0][0].y == 1 && TicTacData[1][1].y == 1 && TicTacData[2][2].y == 1) ||
		(TicTacData[0][2].y == 1 && TicTacData[1][1].y == 1 && TicTacData[2][0].y == 1) )
	{
		printf("LEFT SHOOTER WON!!\n");
		winner = Entities::EntityType::SHOOTER_LEFT;
	}
	
	if ((TicTacData[0][0].y == 2 && TicTacData[0][1].y == 2 && TicTacData[0][2].y == 2) ||
		(TicTacData[1][0].y == 2 && TicTacData[1][1].y == 2 && TicTacData[1][2].y == 2) ||
		(TicTacData[2][0].y == 2 && TicTacData[2][1].y == 2 && TicTacData[2][2].y == 2) ||

		(TicTacData[0][0].y == 2 && TicTacData[1][0].y == 2 && TicTacData[2][0].y == 2) ||
		(TicTacData[0][1].y == 2 && TicTacData[1][1].y == 2 && TicTacData[2][1].y == 2) ||
		(TicTacData[0][2].y == 2 && TicTacData[1][2].y == 2 && TicTacData[2][2].y == 2) ||

		(TicTacData[0][0].y == 2 && TicTacData[1][1].y == 2 && TicTacData[2][2].y == 2) ||
		(TicTacData[0][2].y == 2 && TicTacData[1][1].y == 2 && TicTacData[2][0].y == 2))
	{
		printf("RIGHT SHOOTER WON!!\n");
		winner = Entities::EntityType::SHOOTER_RIGHT;
	}
	
}

void RollingTabletData::AddDataToCell(float anglePos, Vector3D data)
{
	if (anglePos == -135)
		TicTacData[2][0] = data;
	if (anglePos == -90)
		TicTacData[2][1] = data;
	if (anglePos == -45)
		TicTacData[2][2] = data;
	if (anglePos == 0)
		TicTacData[1][2] = data;
	if (anglePos == 45)
		TicTacData[0][2] = data;
	if (anglePos == 90)
		TicTacData[0][1] = data;
	if (anglePos == 135)
		TicTacData[0][0] = data;
	if (anglePos == 180)
		TicTacData[1][0] = data;
	if (anglePos == -1)
		TicTacData[1][1] = data;

}
