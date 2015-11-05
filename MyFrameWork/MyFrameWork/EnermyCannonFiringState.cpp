#include "EnermyCannonFiringState.h"

EnermyCannonFiringState::EnermyCannonFiringState(EnermyData* pData)
{
	this->pData = pData;
	this->pData->iCurrentArr = pData->iCurrentArr;
	nShootCycle = 72;
	count = 0;
	switch (this->pData->iCurrentArr)
	{
	case 2:
		angle = M_PI * 7 / 6;
		bulletX = pData->x - pData->body.width / 2;
		bulletY = pData->y - pData->body.height * 3 / 4;
		break;
	case 3:
		angle = M_PI * 4 / 3;
		bulletX = pData->x - pData->body.width * 1 / 4;
		bulletY = pData->y - pData->body.height;
		break;
	default:
		angle = M_PI;
		bulletX = pData->x - pData->body.width / 2;
		bulletY = pData->y - pData->body.height / 2;
		break;
	}
}


EnermyCannonFiringState::~EnermyCannonFiringState()
{
}

void EnermyCannonFiringState::onUpdate()
{
	if (count == 0 || count == 12 || count == 24)
	{
		pData->Bullets.push_back(new EnermyWhiteBullet(bulletX, bulletY, true, angle));
	}
	pData->ppTextureArrays[pData->iCurrentArr]->update();
	count++;
	count %= nShootCycle;
	if (count == 0)
	{
		transition(new EnermyCannonTurningState(pData));
	}
}

void EnermyCannonFiringState::onDead()
{
	transition(new EnermyCannonDeadState(pData));
}
