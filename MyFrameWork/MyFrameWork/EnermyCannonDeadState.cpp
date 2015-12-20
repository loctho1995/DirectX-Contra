#include "EnermyCannonDeadState.h"
#include "EnermyCannonData.h"
#include "Sound.h"

EnermyCannonDeadState::EnermyCannonDeadState(EnermyData* pData)
{
	this->pData = pData;
	this->pData->iCurrentArr = EnermyCannonData::DEAD;
	pData->isHittable = false;

	Sound::getInstance()->play("qexplode", false, 1);
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
