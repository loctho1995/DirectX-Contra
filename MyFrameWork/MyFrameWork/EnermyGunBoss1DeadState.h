#pragma once
#include "EnermyState.h"
class EnermyGunBoss1DeadState : public EnermyState
{
public:
public:
	EnermyGunBoss1DeadState( EnermyData* data);
	~EnermyGunBoss1DeadState(void);
	virtual void onUpdate() ;
private:
	int count;
	int nHoldFrames;
	
};

