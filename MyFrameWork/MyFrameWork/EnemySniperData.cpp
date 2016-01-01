#include "EnemySniperData.h"


EnemySniperData::EnemySniperData(std::vector < BulletSprite*>& bulletSpriteVector)
	:
	EnermyData(bulletSpriteVector)
{
	this->botName = "sniper";
	this->isHittable = true;
	this->isThrougable = true;
	this->HP = 1;
	this->score = 500;
}

EnemySniperData::~EnemySniperData()
{
}