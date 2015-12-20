#include "EnermyFailingStoneDeadState.h"


EnermyFailingStoneDeadState::EnermyFailingStoneDeadState(EnermyData* pData)
{
	this->pData = pData;
	this->pData->iCurrentArr = EnermyFailingStoneData::DEAD;
	pData->isHittable = false;

	Sound::getInstance()->play("qexplode", false, 1);
}


EnermyFailingStoneDeadState::~EnermyFailingStoneDeadState()
{
}

void EnermyFailingStoneDeadState::onUpdate()
{
	pData->ppTextureArrays[pData->iCurrentArr]->update();
	if (pData->ppTextureArrays[pData->iCurrentArr]->isLastTexture())
	{
		pData->isDesTroyed = true;
	}
}
