#pragma once
#include "EnermyState.h"
#include "EnermyFailingStone.h"

class EnermyFailingStoneDroppingState :
	public EnermyState
{
public:
	EnermyFailingStoneDroppingState(EnermyData* pData);
	~EnermyFailingStoneDroppingState();
	virtual void onUpdate();
	virtual void onDead();
	virtual void onCollision(CollisionRectF rect);
private:
	float acceleration;
	int status;
};