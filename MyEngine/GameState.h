#ifndef GameState_H
#define GameState_H

class GameState
{
public:
	GameState();
	~GameState();

	virtual void Init() = 0;
	virtual void Clear() = 0;
	virtual void Pause() = 0;
	virtual void Resume() = 0;

	//virtual void HandleEvents();
};

#endif