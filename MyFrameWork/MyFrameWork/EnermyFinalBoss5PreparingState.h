#pragma once
#include "EnermyState.h"
#include "EnermyFinalBoss5Sprite.h"

const float DurexX = 4900.0f;
const float DurexY = 35.0f;

class EnermyFinalBoss5PreparingState :
	public EnermyState
{
public:
	EnermyFinalBoss5PreparingState(EnermyData* data);
	~EnermyFinalBoss5PreparingState();
	virtual void onUpdate();
private:
	int count;
	int nHoldFrames;
	int appearX;
	int appearY;
};