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
	if ((count == 0 || count == 25 || count == 50) && directPlayerX < pData->x && directPlayerY < pData->y)
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

	if (this->pData->playerX < this->pData->x && this->pData->player2X < this->pData->x)
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
	}
	else {
		if (this->pData->playerX > this->pData->x)
		{
			directPlayerX = this->pData->player2X;
			directPlayerY = this->pData->player2Y;
		}
		if (this->pData->player2X > this->pData->x)
		{
			directPlayerX = this->pData->playerX;
			directPlayerY = this->pData->playerY;
		}
	}
	/*if (this->pData->isPlayer2Dead)
	{
	directPlayerX = this->pData->playerX;
	directPlayerY = this->pData->playerY;
	}
	else if (this->pData->isPlayerDead)
	{
	directPlayerX = this->pData->player2X;
	directPlayerY = this->pData->player2Y;
	}
	else
	{
	distancePlayer1 = sqrt(pow(this->pData->playerX - (this->pData->x - this->pData->body.width / 2), 2) + pow(this->pData->playerY - (this->pData->y - this->pData->body.height / 2), 2));
	distancePlayer2 = sqrt(pow(this->pData->player2X - (this->pData->x - this->pData->body.width / 2), 2) + pow(this->pData->player2Y - (this->pData->y - this->pData->body.height / 2), 2));
	if (distancePlayer1 < distancePlayer2)
	{
	directPlayerX = this->pData->playerX;
	directPlayerY = this->pData->playerY;
	}
	else
	{
	directPlayerX = this->pData->player2X;
	directPlayerY = this->pData->player2Y;
	}
	}*/

	if (this->pData->x == this->directPlayerX)
	{
		tanalpha = 2.0f;
	}
	else
	{
		tanalpha = (float)((this->pData->y - this->pData->body.height / 2) - directPlayerY) / (this->pData->x - directPlayerX);
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