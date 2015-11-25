#include "EnermyFinalBoss5DisappearingState.h"


EnermyFinalBoss5DisappearingState::EnermyFinalBoss5DisappearingState(EnermyData* data)
{
	pData = data;
	pData->isHittable = false;
	pData->iCurrentArr = 3;
}

EnermyFinalBoss5DisappearingState::~EnermyFinalBoss5DisappearingState()
{
}

void EnermyFinalBoss5DisappearingState::onUpdate()
{
	pData->ppTextureArrays[pData->iCurrentArr]->update();
	if (pData->ppTextureArrays[pData->iCurrentArr]->isLastTexture())
	{
		transition(new EnermyFinalBoss5PreparingState(pData));
	}
}