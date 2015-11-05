#include "EnermyCannonTurningState.h"


EnermyCannonTurningState::EnermyCannonTurningState(EnermyData* pData)
{
	this->pData = pData;
	tanalpha = 0;
	if (this->pData->x == this->pData->playerX)
	{
		tanalpha = 2.0f;
	}
	else
	{
		tanalpha = (float)((this->pData->y-this->pData->body.height/2) - this->pData->body.height / 2 - this->pData->playerY) / (this->pData->x - this->pData->playerX);
	}
  	if (tanalpha < 0.24f)
	{
		this->pData->iCurrentArr = EnermyCannonData::TURN0;
	}
	else
	{
		if (tanalpha < 1.45f)
		{
			this->pData->iCurrentArr = EnermyCannonData::TURN30;
		}
		else
		{
			this->pData->iCurrentArr = EnermyCannonData::TURN60;
		}
	}
	nHoldFrames = 9;
	count = 0;
}


EnermyCannonTurningState::~EnermyCannonTurningState()
{

}

void EnermyCannonTurningState::onUpdate()
{
	pData->ppTextureArrays[pData->iCurrentArr]->update();
	count++;
	count %= nHoldFrames;
	if (count == 0)
	{
		if (pData->playerX<pData->x && pData->playerY<pData->y)
		{

			transition(new EnermyCannonFiringState(pData));
		}
		else
		{
			transition(new EnermyCannonTurningState(pData));
		}
	}
}

void EnermyCannonTurningState::onDead()
{
	transition(new EnermyCannonDeadState(pData));
}

