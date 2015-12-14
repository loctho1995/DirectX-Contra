#include "EnermyFinalBoss5DeadState.h"


EnermyFinalBoss5DeadState::EnermyFinalBoss5DeadState(EnermyData* data)
{
	pData = data;
	pData->iCurrentArr = 4;
	pData->isHittable = false;
	Sound::getInstance()->play("boss2finaldestroy.wav", false, 1);
}


EnermyFinalBoss5DeadState::~EnermyFinalBoss5DeadState()
{
}

void EnermyFinalBoss5DeadState::onUpdate()
{
	pData->ppTextureArrays[pData->iCurrentArr]->update();
	if (pData->ppTextureArrays[pData->iCurrentArr]->isLastTexture())
	{
		pData->isDesTroyed = true;
	}
}
