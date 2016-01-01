#pragma once

#include "EnermyState.h"
#include "EnermyData.h"
#include "EnemySniperStandingState.h"


class EnemySniperTurningState : public EnermyState
{
public:
	EnemySniperTurningState(EnermyData* pData);
	~EnemySniperTurningState();
	virtual void onUpdate();
	virtual void onDead();
private:
	int count;
	int nFiringDelayTime;
	int nHoldFrames;
	int listAngle[6];
	int getIndex();
	int iCurrent; // xac dinh sprite hien tai
	float fAngle; // xac dinh goc hien tai
	float getAngle();
	float getDistance();
	int temp;
	float directPlayerX, directPlayerY;
};