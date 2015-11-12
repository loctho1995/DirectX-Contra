#include "EnermyCannonPreaparingState.h"


EnermyCannonPreaparingState::EnermyCannonPreaparingState(EnermyData* pData)
{
	this->pData = pData;
	this->pData->iCurrentArr = EnermyCannonData::PREPARE;
}


EnermyCannonPreaparingState::~EnermyCannonPreaparingState()
{
}

void EnermyCannonPreaparingState::onUpdate()
{
	if (this->pData->x - this->pData->playerX <= 100)
	{
		transition(new EnermyCannonAppearingState(pData));
	}
}