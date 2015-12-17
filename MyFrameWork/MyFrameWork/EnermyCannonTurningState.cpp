#include "EnermyCannonTurningState.h"


EnermyCannonTurningState::EnermyCannonTurningState(EnermyData* pData)
{
	this->pData = pData;
	this->pData->isHittable = true;
	this->getIndex();
	count = 0; 
	nShootCycle = 150;
}


EnermyCannonTurningState::~EnermyCannonTurningState()
{

}

void EnermyCannonTurningState::onUpdate()
{
	this->getIndex();
	if ((count == 0 || count == 25 || count == 50) && pData->playerX<pData->x && pData->playerY<pData->y)
	{
		pData->bulletsVector.push_back(new EnermyWhiteBullet(bulletX, bulletY, true, angle));
	}
	pData->ppTextureArrays[pData->iCurrentArr]->update();
	count++;
	count %= nShootCycle;
	if (count == 0)
	{
		transition(new EnermyCannonTurningState(pData));
	}
}

void EnermyCannonTurningState::onDead()
{
	transition(new EnermyCannonDeadState(pData));
}

void EnermyCannonTurningState::getIndex()
{
	if (this->pData->x == this->pData->playerX)
	{
		tanalpha = 2.0f;
	}
	else
	{
		tanalpha = (float)((this->pData->y - this->pData->body.height / 2) - this->pData->body.height / 2 - this->pData->playerY) / (this->pData->x - this->pData->playerX);
	}
	if (tanalpha < 0.24f)
	{
		this->pData->iCurrentArr = EnermyCannonData::TURN0;
		angle = M_PI;
		bulletX = pData->x - pData->body.width / 2;
		bulletY = pData->y - pData->body.height / 2;
	}
	else
	{
		if (tanalpha < 1.45f)
		{
			this->pData->iCurrentArr = EnermyCannonData::TURN30;
			angle = M_PI * 7 / 6;
			bulletX = pData->x - pData->body.width / 2;
			bulletY = pData->y - pData->body.height * 3 / 4;
		}
		else
		{
			this->pData->iCurrentArr = EnermyCannonData::TURN60;
			angle = M_PI * 4 / 3;
			bulletX = pData->x - pData->body.width * 1 / 4;
			bulletY = pData->y - pData->body.height;
		}
	}
}