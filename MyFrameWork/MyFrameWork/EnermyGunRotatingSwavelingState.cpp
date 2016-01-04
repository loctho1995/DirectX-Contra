#include"EnermyGunRotatingSwavelingState.h"
#include"EnermyWhiteBullet.h"
#include"EnermyGunRotatingDieState.h"
#include"Sound.h"

EnermyGunRotatingSwavelingState::EnermyGunRotatingSwavelingState(EnermyData *pData)
{
	this->pData = pData;
	iFrame = 0;
	iCurentIndex = -1;
	distanceX = 95;
	distanceY = 50;
	temp = 0;
	iCurentIndex = 10;
	isTheFirst = true;
}
EnermyGunRotatingSwavelingState::~EnermyGunRotatingSwavelingState()
{

}

bool flag;

void EnermyGunRotatingSwavelingState::onUpdate()
{
	if (isTheFirst == true)
	{
		SwavelingAndShoot(-1, 0, 15);
	}
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

	if (getDistanceToClose() == true)
	{
		pData->iCurrentArr = EnermyGunRotatingData::CLOSE;
		pData->isHittable = false;
		pData->ppTextureArrays[pData->iCurrentArr]->update();
		return;
	}

	index = getIndex() + 1;

	if (iCurentIndex == index)// co shoot hay khong
		flag = true;
	else
		flag = false;

	if (iFrame == 50)
	{
		if (iCurentIndex < index)
		{
			if (index - iCurentIndex > 6)
			{
				iCurentIndex--;
				if (iCurentIndex<1)
					iCurentIndex = 12;
			}
			else
			{
				iCurentIndex++;
				if (iCurentIndex >12)
					iCurentIndex = 1;
			}
		}

		if (iCurentIndex > index)
		{
			if (iCurentIndex - index > 6)
			{
				iCurentIndex++;
				if (iCurentIndex >12)
					iCurentIndex = 1;
			}
			else
			{
				iCurentIndex--;
				if (iCurentIndex<1)
					iCurentIndex = 12;
			}
		}

		//fAngle = listAngle[iCurentIndex - 1];
	}

	iFrame++;

	if (isTheFirst == false)
		SwavelingAndShoot(50, 55, 65);

	/*if (isTheFirst == false && pData->stage == 3)
	SwavelingAndShoot(60, 75);*/
}

void EnermyGunRotatingSwavelingState::SwavelingAndShoot(int iFrameSwaveling, int iFramebet, int iFrameShoot)
{

	if (pData->stage == 1)
	{
		if (iFrame > iFrameSwaveling)
		{

			switch (iCurentIndex)
			{
			case 1:this->pData->iCurrentArr = EnermyGunRotatingData::SWAVEL1; break;
			case 2:this->pData->iCurrentArr = EnermyGunRotatingData::SWAVEL2; break;
			case 3:this->pData->iCurrentArr = EnermyGunRotatingData::SWAVEL3; break;
			case 4:this->pData->iCurrentArr = EnermyGunRotatingData::SWAVEL4; break;
			case 5:this->pData->iCurrentArr = EnermyGunRotatingData::SWAVEL5; break;
			case 6:this->pData->iCurrentArr = EnermyGunRotatingData::SWAVEL6; break;
			case 7:this->pData->iCurrentArr = EnermyGunRotatingData::SWAVEL7; break;
			case 8:this->pData->iCurrentArr = EnermyGunRotatingData::SWAVEL8; break;
			case 9:this->pData->iCurrentArr = EnermyGunRotatingData::SWAVEL9; break;
			case 10:this->pData->iCurrentArr = EnermyGunRotatingData::SWAVEL10; break;
			case 11:this->pData->iCurrentArr = EnermyGunRotatingData::SWAVEL11; break;
			case 12:this->pData->iCurrentArr = EnermyGunRotatingData::SWAVEL12; break;
			}

			pData->ppTextureArrays[pData->iCurrentArr]->update();
			fAngle = listAngle[iCurentIndex - 1];
		}
		if (iFrame >iFrameShoot)
		{

			if (flag == true)
			{
				Sound::getInstance()->play("shootM", false, 1);
				switch (iCurentIndex)
				{
				case 1: pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x, pData->y - pData->body.height / 2, true, fAngle)); break;
				case 2: pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x + pData->body.width * 1 / 4, pData->y - pData->body.height / 2, true, fAngle)); break;
				case 3:pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x + pData->body.width * 1 / 2, pData->y - pData->body.height * 1 / 4, true, fAngle)); break;
				case 4: pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x + pData->body.width / 2, pData->y, true, fAngle)); break;
				case 5:pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x + pData->body.width / 2, pData->y + pData->body.height * 1 / 4, true, fAngle)); break;
				case 6:pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x + pData->body.width * 1 / 4, pData->y + pData->body.height / 2, true, fAngle)); break;
				case 7:pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x, pData->y + pData->body.height / 2, true, fAngle)); break;
				case 8:pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x - pData->body.width * 1 / 4, pData->y + pData->body.height / 2, true, fAngle)); break;
				case 9:pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x - pData->body.width * 1 / 2, pData->y + pData->body.height * 1 / 4, true, fAngle)); break;
				case 10:pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x - pData->body.width * 1 / 2, pData->y, true, fAngle)); break;
				case 11:pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x - pData->body.width / 2, pData->y - pData->body.height * 1 / 4, true, fAngle)); break;
				case 12:pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x - pData->body.width * 1 / 4, pData->y - pData->body.height / 2, true, fAngle)); break;
				default:
					break;
				}
			}

			pData->ppTextureArrays[pData->iCurrentArr]->update();
			if (isTheFirst == true)
				isTheFirst = false;
			if (isTheFirst == false)
				iFrame = 0;
		}
	}

	if (pData->stage == 3)
	{
		if (iFrame > iFrameSwaveling)
		{

			switch (iCurentIndex)
			{
			case 1:this->pData->iCurrentArr = EnermyGunRotatingData::SWAVEL1; break;
			case 2:this->pData->iCurrentArr = EnermyGunRotatingData::SWAVEL2; break;
			case 3:this->pData->iCurrentArr = EnermyGunRotatingData::SWAVEL3; break;
			case 4:this->pData->iCurrentArr = EnermyGunRotatingData::SWAVEL4; break;
			case 5:this->pData->iCurrentArr = EnermyGunRotatingData::SWAVEL5; break;
			case 6:this->pData->iCurrentArr = EnermyGunRotatingData::SWAVEL6; break;
			case 7:this->pData->iCurrentArr = EnermyGunRotatingData::SWAVEL7; break;
			case 8:this->pData->iCurrentArr = EnermyGunRotatingData::SWAVEL8; break;
			case 9:this->pData->iCurrentArr = EnermyGunRotatingData::SWAVEL9; break;
			case 10:this->pData->iCurrentArr = EnermyGunRotatingData::SWAVEL10; break;
			case 11:this->pData->iCurrentArr = EnermyGunRotatingData::SWAVEL11; break;
			case 12:this->pData->iCurrentArr = EnermyGunRotatingData::SWAVEL12; break;
			}

			if (isTheFirst == false)
				pData->ppTextureArrays[pData->iCurrentArr]->update();
			fAngle = listAngle[iCurentIndex - 1];
		}

		if (iFrame == iFramebet)
		{

			if (flag == true)
			{

				switch (iCurentIndex)
				{
				case 1: pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x, pData->y - pData->body.height / 2, true, fAngle)); break;
				case 2: pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x + pData->body.width * 1 / 4, pData->y - pData->body.height / 2, true, fAngle)); break;
				case 3:pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x + pData->body.width * 1 / 2, pData->y - pData->body.height * 1 / 4, true, fAngle)); break;
				case 4: pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x + pData->body.width / 2, pData->y, true, fAngle)); break;
				case 5:pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x + pData->body.width / 2, pData->y + pData->body.height * 1 / 4, true, fAngle)); break;
				case 6:pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x + pData->body.width * 1 / 4, pData->y + pData->body.height / 2, true, fAngle)); break;
				case 7:pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x, pData->y + pData->body.height / 2, true, fAngle)); break;
				case 8:pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x - pData->body.width * 1 / 4, pData->y + pData->body.height / 2, true, fAngle)); break;
				case 9:pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x - pData->body.width * 1 / 2, pData->y + pData->body.height * 1 / 4, true, fAngle)); break;
				case 10:pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x - pData->body.width * 1 / 2, pData->y, true, fAngle)); break;
				case 11:pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x - pData->body.width / 2, pData->y - pData->body.height * 1 / 4, true, fAngle)); break;
				case 12:pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x - pData->body.width * 1 / 4, pData->y - pData->body.height / 2, true, fAngle)); break;
				default:
					break;
				}
			}

			pData->ppTextureArrays[pData->iCurrentArr]->update();
		}

		if (iFrame >iFrameShoot)
		{
			if (flag == true)
			{
				Sound::getInstance()->play("shootM", false, 1);
				switch (iCurentIndex)
				{
				case 1: pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x, pData->y - pData->body.height / 2, true, fAngle)); break;
				case 2: pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x + pData->body.width * 1 / 4, pData->y - pData->body.height / 2, true, fAngle)); break;
				case 3:pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x + pData->body.width * 1 / 2, pData->y - pData->body.height * 1 / 4, true, fAngle)); break;
				case 4: pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x + pData->body.width / 2, pData->y, true, fAngle)); break;
				case 5:pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x + pData->body.width / 2, pData->y + pData->body.height * 1 / 4, true, fAngle)); break;
				case 6:pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x + pData->body.width * 1 / 4, pData->y + pData->body.height / 2, true, fAngle)); break;
				case 7:pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x, pData->y + pData->body.height / 2, true, fAngle)); break;
				case 8:pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x - pData->body.width * 1 / 4, pData->y + pData->body.height / 2, true, fAngle)); break;
				case 9:pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x - pData->body.width * 1 / 2, pData->y + pData->body.height * 1 / 4, true, fAngle)); break;
				case 10:pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x - pData->body.width * 1 / 2, pData->y, true, fAngle)); break;
				case 11:pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x - pData->body.width / 2, pData->y - pData->body.height * 1 / 4, true, fAngle)); break;
				case 12:pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x - pData->body.width * 1 / 4, pData->y - pData->body.height / 2, true, fAngle)); break;
				default:
					break;
				}
			}


			pData->ppTextureArrays[pData->iCurrentArr]->update();

			if (isTheFirst == true)
				isTheFirst = false;
			if (isTheFirst == false)
				iFrame = 0;
		}
	}

}

float EnermyGunRotatingSwavelingState::getDistance()
{
	float distance;
	int x1, y1, x2, y2;
	//x1 = directPlayerX + 9;
	//y1 = directPlayerY + 17;
	x1 = directPlayerX;
	y1 = directPlayerY;
	x2 = pData->x;
	y2 = pData->y + pData->body.width / 2;
	distance = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
	return distance;
}

float EnermyGunRotatingSwavelingState::getAngle()
{
	float angle;
	if (getDistance() == 0.0)
		return PI;
	//int x1 = directPlayerX + 9;
	int x1 = directPlayerX;
	int x2 = pData->x;
	angle = (float)acos((x1 - x2) / getDistance());

	if (directPlayerY < pData->y && directPlayerX < pData->x)
		angle = 2 * (PI - angle) + angle;
	if (directPlayerY < pData->y &&  directPlayerX > pData->x)
		angle = 2 * PI - angle;

	return angle;
}

void EnermyGunRotatingSwavelingState::setlistAngle()
{
	listAngle[0] = 3 * PI / 2;
	listAngle[1] = 3 * PI / 2 + PI / 6;
	listAngle[2] = listAngle[1] + PI / 6;
	listAngle[3] = 0;
	for (int i = 4; i < 12; i++)
	{
		listAngle[i] = listAngle[i - 1] + PI / 6;
	}
}


int EnermyGunRotatingSwavelingState::getIndex()
{
	int  j;

	setlistAngle();
	float angle = getAngle();

	for (int i = 3; i < 15; i++)
	{
		j = i % 12;
		if (angle < listAngle[j] + PI / 12)
		{
			fAngle = listAngle[j];
			return (j) % 12;
		}
		if (i == 14 && angle > listAngle[j] + PI / 12)
		{
			return 3;
		}
	}
}

void EnermyGunRotatingSwavelingState::onDead()
{
	transition(new EnermyGunRotatingDieState(pData));
}

bool EnermyGunRotatingSwavelingState::getDistanceToClose()
{
	if (directPlayerX - pData->x > distanceX && pData->stage == 1)
		temp = directPlayerX - pData->x;
	if (temp>distanceX)
		return true;

	if (pData->y - directPlayerY> distanceX && pData->stage == 3)
		temp = pData->y - directPlayerY;
	if (temp>distanceY)
		return true;

	return false;
}

void EnermyGunRotatingSwavelingState::onCameraCollision(RectF cameraRect)
{
	pData->pState->onCameraCollision(cameraRect);
}