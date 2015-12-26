#include "EnermyScubarSoliderDeadState.h"


EnermyScubarSoliderDeadState::EnermyScubarSoliderDeadState(EnermyData *pData)
{
	this->pData = pData;
	iFrames = 0;
	pData->iCurrentArr = 2;
	pData->isHittable = false;
	Sound::getInstance()->play("qexplode", false, 1);
}


EnermyScubarSoliderDeadState::~EnermyScubarSoliderDeadState()
{

}

void EnermyScubarSoliderDeadState::onUpdate()
{
	pData->ppTextureArrays[pData->iCurrentArr]->update();
	iFrames++;
	if (iFrames == 10)
	{
		pData->isDesTroyed = true;
	}
}