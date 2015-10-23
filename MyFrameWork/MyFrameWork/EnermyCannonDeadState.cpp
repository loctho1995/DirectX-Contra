#include "EnermyCannonDeadState.h"
#include "EnermyCannonData.h"

EnermyCannonDeadState::EnermyCannonDeadState(EnermyData* pData)
{
	this->pData = pData;
	this->pData->iCurrentArr = EnermyCannonData::DEAD;
	pData->isHittable = false;
	nHoldFrames = 24;
	count = 0;
}


EnermyCannonDeadState::~EnermyCannonDeadState()
{
}

void EnermyCannonDeadState::onUpdate()
{
	pData->ppTextureArrays[pData->iCurrentArr]->update();
	count++;
	count %= nHoldFrames;
	if (count == 0)
	{
		pData->isDesTroyed = true;
	}
}
