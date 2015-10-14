#pragma once
#include "EnermyState.h"
class EnermyFinalBoss1StandingState : public EnermyState
{
public:
	EnermyFinalBoss1StandingState(EnermyData* data);
	~EnermyFinalBoss1StandingState();
	virtual void onUpdate() ;
	virtual void onDead();
};

