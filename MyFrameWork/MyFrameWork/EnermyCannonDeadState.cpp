#include "EnermyCannonDeadState.h"
#include "EnermyCannonData.h"

EnermyCannonDeadState::EnermyCannonDeadState(EnermyData* pData)
{
	this->pData = pData;
	this->pData->iCurrentArr = EnermyCannonData::DEAD;
	pData->isHittable = false;
}


EnermyCannonDeadState::~EnermyCannonDeadState()
{
}

void EnermyCannonDeadState::onUpdate()
{
	pData->ppTextureArrays[pData->iCurrentArr]->update();
	if (pData->ppTextureArrays[pData->iCurrentArr]->isLastTexture())
	{
		pData->isDesTroyed = true;
	}
}
