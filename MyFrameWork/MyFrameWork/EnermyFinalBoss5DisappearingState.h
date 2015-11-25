#pragma once
#include "EnermyState.h"
#include "EnermyFinalBoss5Sprite.h"

class EnermyFinalBoss5DisappearingState :
	public EnermyState
{
public:
	EnermyFinalBoss5DisappearingState(EnermyData* data);
	~EnermyFinalBoss5DisappearingState();
	virtual void onUpdate();
};

