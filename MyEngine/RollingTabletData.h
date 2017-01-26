#ifndef RollingTabletData_H
#define RollingTabletData_H

#include <vector>
#include "Vector3D.h"
#include "Entity.h"

enum DataType
{
	EMPTY,
	EX,
	CIRCLE,

	MAX
};


class RollingTabletData
{
private:
	Entities::EntityType winner;
	
public:

	// x = id, y = status, z = user data
	Vector3D TicTacData[3][3];
	int Player1Id;
	int Player2Id;

	Entities::EntityType GetWinner();

	RollingTabletData();
	~RollingTabletData();
	void Update();
	void AddDataToCell(float anglePos, Vector3D data);

	int EnemyLeftData;
	int EnemyLeftData2;
	int EnemyLeftData3;

	int EnemyRightData;
	int EnemyRightData2;
	int EnemyRightData3;
	int GameLogicCounterController;
};

#endif