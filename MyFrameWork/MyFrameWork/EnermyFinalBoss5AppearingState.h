#pragma once
#include "EnermyState.h"
#include "EnermyFinalBoss5Sprite.h"

class EnermyFinalBoss5AppearingState :
	public EnermyState
{
public:
	//EnermyFinalBoss5AppearingState(EnermyData* data);
	EnermyFinalBoss5AppearingState(EnermyData* data, float x, float y);
	~EnermyFinalBoss5AppearingState();
	virtual void onUpdate();
};

