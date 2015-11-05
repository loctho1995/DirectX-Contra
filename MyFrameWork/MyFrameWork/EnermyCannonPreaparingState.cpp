#include "EnermyCannonPreaparingState.h"


EnermyCannonPreaparingState::EnermyCannonPreaparingState(EnermyData* pData)
{
	this->pData = pData;
	this->pData->iCurrentArr = EnermyCannonData::APPEAR;
}


EnermyCannonPreaparingState::~EnermyCannonPreaparingState()
{
}

void EnermyCannonPreaparingState::onUpdate()
{
	if (this->pData->x - this->pData->playerX <= 120)
	{
		transition(new EnermyCannonAppearingState(pData));
	}
}