#pragma once
#include "EnermyState.h"
class EnermyCannonDeadState : public EnermyState
{
public:
	EnermyCannonDeadState(EnermyData* pData);
	~EnermyCannonDeadState();
	virtual void onUpdate();
private:
	int count;
	int nHoldFrames;
};

