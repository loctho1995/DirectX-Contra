#include "EnermySoldierData.h"

EnermySoldierData::EnermySoldierData(std::vector<BulletSprite*>& bullet) : EnermyData(bullet)
{
    this->botName = "soldier";
    this->isHittable = true;
    this->isDesTroyed = false;
    this->isThrougable = false;
    this->isShooted = false;
    this->bulletsVector = bullet;
}


EnermySoldierData::~EnermySoldierData()
{
}
