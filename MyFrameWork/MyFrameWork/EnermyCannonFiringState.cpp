#include "EnermyCannonFiringState.h"
#include "EnermyCannonTurningState.h"
#include "EnermyCannonDeadState.h"
#include "EnermyCannonData.h"
#include "PlayerMBullet.h"

EnermyCannonFiringState::EnermyCannonFiringState(EnermyData* pData)
{
	this->pData = pData;
	this->pData->iCurrentArr = pData->iCurrentArr;
	nHoldFrames = 24;
	count = 0;
	switch (this->pData->iCurrentArr)
	{
	case 2:
		angle = M_PI * 7 / 6;
		break;
	case 3:
		angle = M_PI * 4 / 3;
		break;
	default:
		angle = M_PI;
		break;
	}
	if (!(this->pData->playerX <= this->pData->body.x&&this->pData->playerY <= pData->body.y))
	{
		//transition(new EnermyCannonTurningState(pData));
	}
}


EnermyCannonFiringState::~EnermyCannonFiringState()
{
}

void EnermyCannonFiringState::onUpdate()
{
	if (count == 0)
	{
		switch (this->pData->iCurrentArr)
		{
		case 1:
			pData->Bullets.push_back(new PlayerMBullet(pData->x - pData->body.width / 2, pData->y - pData->body.height / 2, true, angle));
			break;
		case 2:
			pData->Bullets.push_back(new PlayerMBullet(pData->x - pData->body.width / 2, pData->y - pData->body.height * 3 / 4, true, angle));
			break;
		case 3:
			pData->Bullets.push_back(new PlayerMBullet(pData->x - pData->body.width * 1 / 4, pData->y - pData->body.height, true, angle));
		default:
			break;
		}
	}
	pData->ppTextureArrays[pData->iCurrentArr]->update();
	count++;
	count %= nHoldFrames;
	if (count == 0)
	{
		transition(new EnermyCannonTurningState(pData));
	}
}

void EnermyCannonFiringState::onDead()
{
	transition(new EnermyCannonDeadState(pData));
}