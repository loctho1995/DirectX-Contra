#pragma once
#include "EnermyState.h"
#include "EnermyData.h"

class EnermyCannonFiringState : public EnermyState
{
public:
	EnermyCannonFiringState(EnermyData* pData);
	~EnermyCannonFiringState();
	virtual void onUpdate(); 
	virtual void onDead();
private:
	int count;
	int nHoldFrames;
	float angle;
};
