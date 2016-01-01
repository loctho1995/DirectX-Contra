#include"EnermyTankShootingState.h"
#include"EnermyTankStartingState.h"
#include"EnermyTankExploring.h"
#include"Sound.h"

EnermyTankStartingState::EnermyTankStartingState(EnermyData *pData, int s)
{
	this->pData = pData;
	getSprite();
	iFrames = 0;
	this->s = s;
	s0 = 0;
	this->pData->isHittable = false;
}

EnermyTankStartingState::~EnermyTankStartingState()
{

}

void EnermyTankStartingState::getSprite()
{
	if (pData->HP >30)
		pData->iCurrentArr = 13;
	else
		if (pData->HP > 20)
			pData->iCurrentArr = 14;
		else
			if (pData->HP > 10)
				pData->iCurrentArr = 15;
			else
				if (pData->HP > 0)
					pData->iCurrentArr = 16;
}

void EnermyTankStartingState::onUpdate()
{
	pData->ppTextureArrays[pData->iCurrentArr]->update();
	iFrames++;
	if (iFrames == 10)
	{
		Sound::getInstance()->play("tank", false, 1);
		pData->x -= 4;
		s0 += 2;
		if (s0 < s)
		{

			getSprite();
			iFrames = 0;
		}
		else
			iFrames = 70;
	}

	if (iFrames == 70)
	{
		int index;
		if (pData->iCurrentArr == 13)
			index = 0;
		else
			if (pData->iCurrentArr == 14)
				index = 3;
			else
				if (pData->iCurrentArr == 15)
					index = 6;
				else
					index = 9;
		transition(new EnermyTankShootingState(pData, index));
	}

}