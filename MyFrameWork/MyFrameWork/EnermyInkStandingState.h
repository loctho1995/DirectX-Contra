#pragma once

#include "EnermyState.h"


class EnermyInkStandingState : public EnermyState
{
public:
	EnermyInkStandingState( EnermyData* data);
	virtual void onUpdate() ;
private:
	int count;
	int nHoldFrame;
};