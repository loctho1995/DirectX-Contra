#pragma once

#include "EnermyState.h"


class EnermyGunBoss1FiringState : public EnermyState
{
public:
	EnermyGunBoss1FiringState( EnermyData* data);
	virtual void onUpdate() ;
	virtual void onDead();
private:
	int count;
	int nHoldFrames;
};