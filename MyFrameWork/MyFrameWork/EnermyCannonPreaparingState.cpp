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
	switch (this->pData->getPlayerIndexToExcute())
	{
	case 1:
		directPlayerX = this->pData->playerX;
		break;
	case 2:
		directPlayerX = this->pData->player2X;
		break;
	default:
		break;
	}
	if (this->pData->x - directPlayerX <= 100)
	{
		transition(new EnermyCannonAppearingState(pData));
	}
}