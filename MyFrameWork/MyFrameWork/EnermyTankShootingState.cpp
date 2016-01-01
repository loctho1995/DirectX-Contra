#include"EnermyTankShootingState.h"
#include"EnermyTankStartingState.h"
#include"EnermyWhiteBullet.h"
#include"EnermyTankExploring.h"
#include"Sound.h"

EnermyTankShootingState::EnermyTankShootingState(EnermyData *pData, int index)
{
	this->pData = pData;
	iFrames = 0;
	this->index = index;
	count = 0;
	iLastIndex = -1;
	this->pData->isHittable = true;
}

EnermyTankShootingState::~EnermyTankShootingState()
{

}

void EnermyTankShootingState::getSprite()
{
	if (pData->HP >80)
		pData->iCurrentArr = 0;
	else
		if (pData->HP > 60)
			pData->iCurrentArr = 3;
		else
			if (pData->HP > 40)
				pData->iCurrentArr = 6;
			else
				if (pData->HP > 20)
					pData->iCurrentArr = 9;

	if (directPlayerY <= 165 - 16)
	{
		pData->iCurrentArr += index;
	}

	else
		if (directPlayerY >= 165 && (directPlayerX >2410 && directPlayerX < 3300) || (directPlayerX >3355))
		{
			pData->iCurrentArr += index + 2;
		}

		else
		{
			pData->iCurrentArr += index + 1;
		}

	iLastIndex = pData->iCurrentArr % 3;
}

void EnermyTankShootingState::Shoot()
{
	switch (this->pData->getPlayerIndexToExcute())
	{
	case 1:
		directPlayerX = this->pData->playerX;
		directPlayerY = this->pData->playerY;
		break;
	case 2:
		directPlayerX = this->pData->player2X;
		directPlayerY = this->pData->player2Y;
		break;
	default:
		break;
	}
	Sound::getInstance()->play("shootM", false, 1);
	//pData->x -= 4;
	if (iLastIndex == 0)
	{
		pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x - pData->body.width * 1 / 10, pData->y - pData->body.height + pData->body.height * 3 / 20, true, PI, 1));

	}

	if (iLastIndex == 1)
	{
		pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x - pData->body.width * 1 / 10 + 5, pData->y - pData->body.height + 20, true, PI - PI / 6, 1));

	}

	if (iLastIndex == 2)
	{
		pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x - pData->body.width * 1 / 10 + 9, pData->y - pData->body.height + 27, true, PI - PI / 3, 1));
	}


	pData->ppTextureArrays[pData->iCurrentArr]->update();

	count++;
}

void EnermyTankShootingState::onUpdate()
{
	bool flag = false;

	iFrames++;


	if (iFrames == 10)
	{
		getSprite();
	}

	pData->ppTextureArrays[pData->iCurrentArr]->update();


	if (iFrames == 30)
	{
		Shoot();
	}
	if (iFrames == 50)
	{
		Shoot();
	}
	if (iFrames == 70)
	{
		Shoot();
	}

	if (iFrames == 100)
	{
		iFrames = 0;
	}



	if (pData->HP <= 0)
		transition(new EnermyTankExploring(pData, index));

	if (count == 15)
		transition(new EnermyTankStartingState(pData, 100));
}


