#include"EnermyGunRotatingDieState.h"

EnermyGunRotatingDieState::EnermyGunRotatingDieState(EnermyData *pData)
{
	this->pData = pData;
	this->pData->iCurrentArr = EnermyGunRotatingData::DIE;
	iFrame = 0;
	pData->isHittable = false;
	Sound::getInstance()->play("qexplode", false, 1);
}

EnermyGunRotatingDieState::~EnermyGunRotatingDieState()
{

}
void EnermyGunRotatingDieState::onUpdate()
{
	pData->ppTextureArrays[pData->iCurrentArr]->update();
	iFrame++;
	if (iFrame == 10)
	{
		pData->isDesTroyed = true;
	}
}