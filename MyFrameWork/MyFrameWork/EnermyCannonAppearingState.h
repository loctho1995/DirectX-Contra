#pragma once
#include "EnermyState.h"
#include "EnermyData.h"
#include "EnermyCannonData.h"
#include "EnermyCannonTurningState.h"

class EnermyCannonAppearingState : public EnermyState
{
public:
	EnermyCannonAppearingState(EnermyData* pData);
	~EnermyCannonAppearingState();
	virtual void onUpdate();
private:
	int count;
	int nHoldFrames;
};