#include"EnermyGunRotatingOpeningState.h"
#include"EnermyGunRotatingSwavelingState.h"

EnermyGunRotatingOpeningState::EnermyGunRotatingOpeningState(EnermyData *pData)
{
	this->pData = pData;
	this->pData->iCurrentArr = EnermyGunRotatingData::OPEN;
	iFrame = 0;
}

EnermyGunRotatingOpeningState::~EnermyGunRotatingOpeningState()
{

}

void EnermyGunRotatingOpeningState::onUpdate()
{
	pData->ppTextureArrays[pData->iCurrentArr]->update();
	iFrame++;
	if (iFrame == 2)
		transition(new EnermyGunRotatingSwavelingState(pData));
}