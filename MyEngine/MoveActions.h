#ifndef MoveActions_H
#define MoveActions_H

namespace Input
{

	enum MoveActions
	{
		MOVE_LEFT  =	0x00000001,	//2^0
		MOVE_RIGHT =	0x00000002,	//2^1
		MOVE_UP	   =	0x00000004,	//2^2
		MOVE_DOWN  =	0x00000008,	//2^3
		MOVE_A	   =	0x00000010,	//2^4
		MOVE_D	   =	0x00000020,	//2^5
		MOVE_W     =	0x00000040,	//2^6
		MOVE_S     =	0x00000080,	//2^7
		SHOOT_P1   =	0x00000100,	//2^8
		SHOOT_P2   =	0x00000200,	//2^9

		MAX		   =	0x00000400	//2^10
	};

}

#endif