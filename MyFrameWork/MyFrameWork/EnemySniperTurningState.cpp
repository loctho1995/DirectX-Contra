#include "EnemySniperTurningState.h"
#include "EnemySniperDeadState.h"
#include "EnemySniperData.h"
#include "EnermyWhiteBullet.h"


EnemySniperTurningState::EnemySniperTurningState(EnermyData* pData)
{
	this->pData = pData;

	iCurrent = 0;
	
	nFiringDelayTime = 30;
	nHoldFrames = 0;
	count = 0;
	pData->iCurrentArr = 0;
	
}

EnemySniperTurningState::~EnemySniperTurningState()
{
}

void EnemySniperTurningState::onUpdate()
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

	count++;
	if (count == 70)
	{
		iCurrent = getIndex();
	}
	
	int i;
	iCurrent = getIndex();
	switch (iCurrent)
	{
	case 0:	pData->iCurrentArr = EnemySniperData::STAND0;
		break;
	case 1:
		pData->iCurrentArr = EnemySniperData::STAND1;
		break;
	case 2:
		pData->iCurrentArr = EnemySniperData::STAND2;
		break;
	case 3:
		pData->iCurrentArr = EnemySniperData::STAND3;
		break;
	case 4:
		pData->iCurrentArr = EnemySniperData::STAND4;
		break;
	case 5:
		pData->iCurrentArr = EnemySniperData::STAND5;
		break;
	}

	if (count == 80)
	{
		Sound::getInstance()->play("shootM", false, 1);
		switch (getIndex())
		{
		case 0:
			pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x + pData->body.width / 2 + 6, pData->y - pData->body.height * 28 / 32, true, 0));
			break;
		case 1:
			pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x + pData->body.width / 2 + 5, pData->y - pData->body.height * 13 / 32 + 1, true, fAngle));
			break;
		case 2:
			pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x - pData->body.width / 2 - 5, pData->y - pData->body.height * 13 / 32 + 1, true, fAngle));
			break;
		case 3:
			if (pData->stage == 3)
			{
				if (fAngle > M_PI - M_PI / 24)
					fAngle = M_PI;
				else
					fAngle = M_PI - M_PI /12;
				pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x - pData->body.width / 2 - 5, pData->y - pData->body.height * 28 / 32, true, fAngle));
			}
			else
			pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x - pData->body.width / 2 - 5, pData->y - pData->body.height * 28 / 32, true, M_PI));
			break;
		case 4:
			pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x - pData->body.width / 2 - 3, pData->y - pData->body.height - 8, true, fAngle));
			break;
		case 5:
			pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x + pData->body.width / 2 + 4, pData->y - pData->body.height - 8, true, fAngle));
			break;
		}

		count = 0;
		pData->ppTextureArrays[pData->iCurrentArr]->update();
	}
}

float EnemySniperTurningState::getDistance()
{
	float distance;
	int x1, y1, x2, y2;
	//x1 = directPlayerX + 9;
	//y1 = directPlayerY + 17;
	x1 = directPlayerX;
	y1 = directPlayerY + 17;
	x2 = pData->x;
	y2 = pData->y + pData->body.width / 2;
	distance = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
	return distance;
}

float EnemySniperTurningState::getAngle()
{
	float angle;
	if (getDistance() == 0.0)
		return M_PI;
	int x1 = directPlayerX  ;
	//int x1 = directPlayerX;
	int x2 = pData->x;
	angle = (float)acos((x1 - x2) / getDistance());

	if (directPlayerY < pData->y && directPlayerX < pData->x)
		angle = 2 * (M_PI - angle) + angle;
	if (directPlayerY < pData->y &&  directPlayerX > pData->x)
		angle = 2 * M_PI - angle;

	return angle;
}

int EnemySniperTurningState::getIndex()
{
	int angle0 = 0;
	for (int i = 1; i < 7; i++)
	{
		if (getAngle() < angle0 + M_PI / 3 * i - M_PI / 6)
		{
			if (i - 1 == 5 || i - 1 == 2)
			{
				fAngle = angle0 + M_PI*(i - 1) / 3 + M_PI / 12;
				if (getAngle() > angle0 + M_PI*(i - 1) / 3 )
					fAngle = angle0 + M_PI*(i - 1) / 3 + M_PI/12;
				else
					if (getAngle() > angle0 + M_PI*(i - 1) / 3 - M_PI/24)
						fAngle = angle0 + M_PI*(i - 1) / 3 - M_PI / 12;
				else
					fAngle = angle0 + M_PI*(i - 1) / 3 - 2 * M_PI / 12;
			}
			
			else
			{
				fAngle = angle0 + M_PI*(i - 1) / 3 + M_PI / 12;
				if (getAngle() > angle0 + M_PI*(i - 1) / 3 + M_PI / 12)
					fAngle = angle0 + M_PI*(i - 1) / 3 + 2*M_PI / 12;
				else
					if (getAngle() > angle0 + M_PI*(i - 1) / 3 - M_PI / 24)
						fAngle = angle0 + M_PI*(i - 1) / 3 + M_PI / 12;
				else
					fAngle = angle0 + M_PI*(i - 1) / 3 - 2 * M_PI / 12;
			}
				
			return i - 1;
		}		
	} 
}

void EnemySniperTurningState::onDead()
{
	transition(new EnemySniperDeadState(pData));
}