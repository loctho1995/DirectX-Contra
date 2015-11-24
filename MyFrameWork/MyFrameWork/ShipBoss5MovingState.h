#pragma once
#include "BulletState.h"
#include "ShipBoss5.h"

const float wallLeft = 4870;
const float wallRight = 5100;
const float wallBottom = 155;

class ShipBoss5MovingState :
	public BulletState
{
public:
	ShipBoss5MovingState(SpriteData * data, bool isLeft);
	~ShipBoss5MovingState();
	virtual void onUpdate();
	virtual void onDead();
private:
	bool isLeftAppear;
	float speed;
};