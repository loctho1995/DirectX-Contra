#pragma once

#include "EnermyState.h"
#include "EnermyData.h"
#include "EnemySniperDeadState.h"

class EnemySniperStandingState : public EnermyState
{
public:
	EnemySniperStandingState(EnermyData* data);
	~EnemySniperStandingState();

	virtual void onUpdate();
	virtual void onDead();
private:
	int count;
	int nHoldFrames;
};