#include "EnermyCannonData.h"

EnermyCannonData::EnermyCannonData(std::vector < BulletSprite* >& bulletsVector )
	:
	EnermyData(bulletsVector)
{
	this->botName = "cannon";
	this->isHittable = false;
	this->isThrougable = true;
	this->isDesTroyed = false;
	this->HP = 8;
	this->score = 500;
}

EnermyCannonData::~EnermyCannonData()
{
}