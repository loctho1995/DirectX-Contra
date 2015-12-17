#include "EnermyCannonAppearingState.h"

EnermyCannonAppearingState::EnermyCannonAppearingState(EnermyData *pData)
{
	this->pData = pData;
	this->pData->iCurrentArr = EnermyCannonData::APPEAR;
}

EnermyCannonAppearingState::~EnermyCannonAppearingState()
{

}

void EnermyCannonAppearingState::onUpdate()
{
	pData->ppTextureArrays[pData->iCurrentArr]->update();
	if (pData->ppTextureArrays[pData->iCurrentArr]->isLastTexture())
	{
		transition(new EnermyCannonTurningState(pData));
	}
}