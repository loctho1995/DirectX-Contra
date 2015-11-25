#pragma once
#include "EnermyState.h"
#include "EnermyFailingStone.h"

class EnermyFailingStoneAppearingState :
	public EnermyState
{
public:
	EnermyFailingStoneAppearingState(EnermyData* pData);
	~EnermyFailingStoneAppearingState();
	virtual void onUpdate();
private:
	int count;
	int nHoldFrames;
	float crow;
};