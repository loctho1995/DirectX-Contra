#include "EnermyFailingStoneDeadState.h"


EnermyFailingStoneDeadState::EnermyFailingStoneDeadState(EnermyData* pData)
{
	this->pData = pData;
	this->pData->iCurrentArr = EnermyFailingStoneData::DEAD;
	pData->isHittable = false;
	nHoldFrames = 22;
	count = 0;
}


EnermyFailingStoneDeadState::~EnermyFailingStoneDeadState()
{
}

void EnermyFailingStoneDeadState::onUpdate()
{
	pData->ppTextureArrays[pData->iCurrentArr]->update();
	count++;
	count %= nHoldFrames;
	if (count == 0)
	{
		pData->isDesTroyed = true;
	}
}
