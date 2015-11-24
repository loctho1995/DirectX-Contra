#include "EnermyFinalBoss5PreparingState.h"


EnermyFinalBoss5PreparingState::EnermyFinalBoss5PreparingState(EnermyData* data)
{
	pData = data;
	pData->iCurrentArr = 0;
	count = 0;
	nHoldFrames = 120;
	appearX = DurexX + rand() % 150;// + this->pData->body.width / 2
	appearY = DurexY + rand() % 50;// + this->pData->body.height / 2
}

EnermyFinalBoss5PreparingState::~EnermyFinalBoss5PreparingState()
{
}

void EnermyFinalBoss5PreparingState::onUpdate()
{
	pData->ppTextureArrays[pData->iCurrentArr]->update();
	count++;
	count %= nHoldFrames;
	if (count == 0)
	{
		transition(new EnermyFinalBoss5AppearingState(pData, appearX, appearY));
	}
}