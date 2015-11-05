#pragma once
#include "EnermyState.h"
#include "EnermyData.h"
#include "EnermyCannonFiringState.h"
#include "EnermyCannonDeadState.h"
#include "EnermyCannonData.h"
#include "PlayerMBullet.h"

class EnermyCannonTurningState : public EnermyState
{
public:
	EnermyCannonTurningState(EnermyData* pData);
	~EnermyCannonTurningState();
	virtual void onUpdate();
	virtual void onDead();
private:
	int count;
	int nHoldFrames; 
	float tanalpha; //goc ban
};

