#pragma once
#include "EnermyState.h"
#include "EnermyFailingStone.h"

class EnermyFailingStoneDeadState :
	public EnermyState
{
public:
	EnermyFailingStoneDeadState(EnermyData* pData);
	~EnermyFailingStoneDeadState();
	virtual void onUpdate();
private:
	int count;
	int nHoldFrames;
};

