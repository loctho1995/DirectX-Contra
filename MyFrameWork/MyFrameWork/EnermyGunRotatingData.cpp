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
	this->isGun = true; // gun stage1
	this->score = 300;
}
EnermyGunRotatingData::~EnermyGunRotatingData()
{

}