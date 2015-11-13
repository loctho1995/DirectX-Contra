#include "EnermyCannonData.h"

EnermyCannonData::EnermyCannonData(std::vector < BulletSprite* >& bulletsVector )
	:
	EnermyData(bulletsVector)
{
	this->botName = "cannon";
	this->isHittable = true;
	this->isThrougable = true;
	this->isDesTroyed = false;
}

EnermyCannonData::~EnermyCannonData()
{
}