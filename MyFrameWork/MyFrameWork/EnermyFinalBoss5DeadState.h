#pragma once
#include "EnermyState.h"
#include "EnermyFinalBoss5Sprite.h"

class EnermyFinalBoss5DeadState :
	public EnermyState
{
public:
	EnermyFinalBoss5DeadState(EnermyData* data);
	~EnermyFinalBoss5DeadState(); 
	virtual void onUpdate();
};

