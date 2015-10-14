#pragma once

#include "EnermyState.h"


class EnermyGunBoss1StandingState : public EnermyState
{
public:
	EnermyGunBoss1StandingState( EnermyData* data);
	virtual void onUpdate() ;
	virtual void onDead();
private:
	int count;
	int nHoldFrames;
};