#include"EnermyTankData.h"

EnermyTankData::EnermyTankData(std::vector<BulletSprite*>& bulletsVector)
	:EnermyData(bulletsVector)
{
	this->isHittable = true;
	this->isThrougable = false;

	this->isDesTroyed = false;
	this->HP = 50;
	this->botName = "tank";
	this->score = 5000;
}

EnermyTankData::~EnermyTankData()
{

}