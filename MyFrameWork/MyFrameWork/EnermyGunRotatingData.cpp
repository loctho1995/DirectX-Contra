#include"EnermyGunRotatingData.h"

EnermyGunRotatingData::EnermyGunRotatingData(std::vector < BulletSprite* >& bulletsVector)
	:
	EnermyData(bulletsVector)
{
	this->botName = "gunrotating";
	this->isHittable = false;
	this->isThrougable = true;
	this->isDesTroyed = false;
	this->HP = 10;
	this->appearDir = Direction::createRight();
}
EnermyGunRotatingData::~EnermyGunRotatingData()
{

}