#include "EnermyFinalBoss5AppearingState.h"


EnermyFinalBoss5AppearingState::EnermyFinalBoss5AppearingState(EnermyData* data, float x, float y)
{
	pData = data;
	pData->iCurrentArr = 1;
	pData->x = x;
	pData->y = y;
	pData->isThrougable = false;
}


EnermyFinalBoss5AppearingState::~EnermyFinalBoss5AppearingState()
{
}

void EnermyFinalBoss5AppearingState::onUpdate()
{
	pData->ppTextureArrays[pData->iCurrentArr]->update();
	if (pData->ppTextureArrays[pData->iCurrentArr]->isLastTexture())
	{
		transition(new EnermyFinalBoss5WaitingState(pData));
	}
}