#pragma once
#include "EnermyState.h"
#include "EnermyData.h"
#include "EnermyCannonTurningState.h"
#include "EnermyCannonDeadState.h"
#include "EnermyCannonData.h"
#include "EnermyWhiteBullet.h"

class EnermyCannonFiringState : public EnermyState
{
public:
	EnermyCannonFiringState(EnermyData* pData);
	~EnermyCannonFiringState();
	virtual void onUpdate(); 
	virtual void onDead();
private:
	int count;
	int nShootCycle;
	float angle;
	float bulletX;
	float bulletY;
};
