#pragma once

#include "EnermyState.h"
#include "EnermyInkStandingState.h"
class EnermyInkJumpingState : public EnermyState
{
private:
	float acceleration;
	int nJumpingFrames;
	int count;

public:
	EnermyInkJumpingState(EnermyData* pData);
	virtual void onCollision(RectF rect);
	virtual void onUpdate();

};

