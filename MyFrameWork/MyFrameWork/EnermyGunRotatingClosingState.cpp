#include"EnermyGunRotatingClosingState.h"
#include"EnermyGunRotatingOpeningState.h"
EnermyGunRotatingClosingState::EnermyGunRotatingClosingState(EnermyData *pData)
{
	this->pData = pData;
	this->pData->iCurrentArr = EnermyGunRotatingData::CLOSE;
	iFrame = 0;
}

EnermyGunRotatingClosingState::~EnermyGunRotatingClosingState()
{

}
void EnermyGunRotatingClosingState::onUpdate()
{
	pData->ppTextureArrays[pData->iCurrentArr]->update();
	
	iFrame++;
	if (iFrame == 2)
	{
		transition(new EnermyGunRotatingOpeningState(pData));
	}

}