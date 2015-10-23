#include "EnermyCannonAppearingState.h"
#include "EnermyCannonData.h"
#include "EnermyCannonTurningState.h"

EnermyCannonAppearingState::EnermyCannonAppearingState(EnermyData *pData)
{
	this->pData = pData;
	this->pData->iCurrentArr = EnermyCannonData::APPEAR;
	nHoldFrames = 24;
	count = 0;
}

EnermyCannonAppearingState::~EnermyCannonAppearingState()
{

}

void EnermyCannonAppearingState::onUpdate()
{
	pData->ppTextureArrays[pData->iCurrentArr]->update();
	count++;
	count %= nHoldFrames;
	if (count == 0)
	{
		transition(new EnermyCannonTurningState(pData));
	}
}