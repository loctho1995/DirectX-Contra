#include "EnemySniperTurningState.h"
#include "EnemySniperDeadState.h"
#include "EnemySniperData.h"
#include "EnermyWhiteBullet.h"


EnemySniperTurningState::EnemySniperTurningState(EnermyData* pData)
{
	this->pData = pData;

	iCurrent = 0;
	fAngle = getAngle();

	nFiringDelayTime = 30;
	nHoldFrames = 90;
	count = 0;
}

EnemySniperTurningState::~EnemySniperTurningState()
{
}

void EnemySniperTurningState::onUpdate()
{
	count++;
	count %= nHoldFrames;

	switch (getIndex())
	{
	case 0:
		pData->iCurrentArr = EnemySniperData::STAND5;
		break;
	case 1:
		pData->iCurrentArr = EnemySniperData::STAND6;
		break;
	case 2:
		pData->iCurrentArr = EnemySniperData::STAND1;
		break;
	case 3:
		pData->iCurrentArr = EnemySniperData::STAND2;
		break;
	case 4:
		pData->iCurrentArr = EnemySniperData::STAND3;
		break;
	case 5:
		pData->iCurrentArr = EnemySniperData::STAND4;
		break;
	}

	if (count % nFiringDelayTime == 0)
	{
		switch (getIndex())
		{
		case 0:
			pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x + pData->body.width / 2 + 6, pData->y - pData->body.height * 28 / 32, true, getAngle()));
			break;
		case 1:
			pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x + pData->body.width / 2 + 5, pData->y - pData->body.height * 13 / 32 + 1, true, getAngle()));
			break;
		case 2:
			pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x - pData->body.width / 2 - 5, pData->y - pData->body.height * 13 / 32 + 1, true, getAngle()));
			break;
		case 3:
			pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x - pData->body.width / 2 - 5, pData->y - pData->body.height * 28 / 32, true, getAngle()));
			break;
		case 4:
			pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x - pData->body.width / 2 - 3, pData->y - pData->body.height - 8, true, getAngle()));
			break;
		case 5:
			pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x + pData->body.width / 2 + 4, pData->y - pData->body.height - 8, true, getAngle()));
			break;
		}

		pData->iCurrentArr += 6;
		pData->ppTextureArrays[pData->iCurrentArr]->update();
	}

	if (count == 0)
	{
		transition(new EnemySniperStandingState(pData));
	}
}

void EnemySniperTurningState::onDead()
{
	transition(new EnemySniperDeadState(pData));
}


float EnemySniperTurningState::getDistance()
{
	return sqrt((float)((pData->playerX + 9 - pData->x) * (pData->playerX + 9 - pData->x) + (pData->playerY + 17 - pData->y + pData->body.width / 2) * (pData->playerY + 17 - pData->y + pData->body.width / 2)));
}



float EnemySniperTurningState::getAngle()
{
	float angle;

	if (getDistance() == 0.0)
		return M_PI;

	int x1 = pData->playerX + 9;
	int x2 = pData->x;
	angle = (float)acos((x1 - x2) / getDistance());

	//delete 2k*pi
	if (pData->playerY < pData->y && pData->playerX < pData->x)
		angle = 2 * (M_PI - angle) + angle;
	if (pData->playerY < pData->y &&  pData->playerX > pData->x)
		angle = 2 * M_PI - angle;

	return angle;
}

int EnemySniperTurningState::getIndex()
{
	if (getAngle() > 0 && getAngle() < M_PI / 4)
		if (getAngle() < 0 + M_PI / 8)
			return 0;
		else
			return 1;

	if (getAngle() > M_PI / 4 && getAngle() < 3 * M_PI / 4)
		if (getAngle() < M_PI / 4 + M_PI / 4)
			return 1;
		else
			return 2;

	if (getAngle() > 3 * M_PI / 4 && getAngle() < M_PI)
		if (getAngle() < (3 * M_PI / 4) + M_PI / 8)
			return 2;
		else
			return 3;

	if (getAngle() >= M_PI && getAngle() <= 5 * M_PI / 4)
		if (getAngle() < M_PI + M_PI / 8)
			return 3;
		else
			return 4;

	if (getAngle() > 5 * M_PI / 4 && getAngle() < 7 * M_PI / 4)
		if (getAngle() < 5 * M_PI / 4 + M_PI / 4)
			return 4;
		else
			return 5;
	return 0;
}