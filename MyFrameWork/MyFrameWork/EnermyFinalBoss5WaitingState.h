#pragma once
#include "EnermyState.h"
#include "EnermyFinalBoss5Sprite.h"

class EnermyFinalBoss5WaitingState :
	public EnermyState
{
public:
	EnermyFinalBoss5WaitingState(EnermyData* data);
	~EnermyFinalBoss5WaitingState();
	virtual void onUpdate();
	virtual void onDead();
private:
	int count;
	int nHoldFrames;
	int nCycleBullet;
	int nCycleShip;
	bool typeLeft;
	float bulletX;
	float bulletY;
};

