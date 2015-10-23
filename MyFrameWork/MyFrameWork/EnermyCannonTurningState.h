#pragma once
#include "EnermyState.h"
#include "EnermyData.h"
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
};

