#include "EnermyFinalBoss5WaitingState.h"

EnermyFinalBoss5WaitingState::EnermyFinalBoss5WaitingState(EnermyData* data)
{
	pData = data;
	pData->iCurrentArr = 2;
	pData->isHittable = true;
	count = 0;
	nHoldFrames = 240;
	nCycleBullet = 0;
	nCycleShip = 0;
	typeLeft = true;
	bulletX = pData->x;
	bulletY = pData->y;
}


EnermyFinalBoss5WaitingState::~EnermyFinalBoss5WaitingState()
{
}

void EnermyFinalBoss5WaitingState::onUpdate()
{
	pData->ppTextureArrays[pData->iCurrentArr]->update();
	count++;
	nCycleBullet++;
	nCycleShip++;
	count %= nHoldFrames;

	if (nCycleBullet==30)
	{
		nCycleBullet = 0;
		pData->bulletsVector.push_back(new GunBoss5Bullet(bulletX,bulletY));
	}

	if (nCycleShip==40)
	{
		nCycleShip = 0;
		switch (typeLeft)
		{
		case true:
			pData->bulletsVector.push_back(new ShipBoss5(bulletX-20, bulletY-10, typeLeft));
			break;
		case false:
			pData->bulletsVector.push_back(new ShipBoss5(bulletX+20, bulletY-10, typeLeft));
			break;
		}
		typeLeft = (!typeLeft);
	}

	if (count == 0)
	{
		transition(new EnermyFinalBoss5DisappearingState(pData));
	}
}

void EnermyFinalBoss5WaitingState::onDead()
{
	transition(new EnermyFinalBoss5DeadState(pData));
}