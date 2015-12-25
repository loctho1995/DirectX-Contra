#pragma once
#include "EnermyState.h"
#include "EnermyData.h"
#include "EnermyWhiteBullet.h"
#include "EnermyCannonDeadState.h"
#include "EnermyCannonData.h"
#include "MBullet.h"

class EnermyCannonTurningState : public EnermyState
{
public:
	EnermyCannonTurningState(EnermyData* pData);
	~EnermyCannonTurningState();
	void getIndex();
	virtual void onUpdate();
	virtual void onDead();
private:
	int count;
	int nShootCycle;
	float tanalpha; //goc ban
	float angle;
	float bulletX;
	float bulletY;
	float directPlayerX;
	float directPlayerY;
};

