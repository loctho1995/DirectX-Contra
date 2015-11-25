#include "Boss2FinalData.h"

Boss2FinalData::Boss2FinalData(std::vector < BulletSprite* >& bulletsVector)
{
    this->bulletsVector = bulletsVector;
    this->botName = "boss2final";
    armLength = 16.0f * 5;
    isDesTroyed = false;
    isHittable = true;
    HP = 1000;
    isHittable = true;
    isThrougable = true;
    dir = Direction::createRight();
    //appearDir = Direction::createRight();
}


Boss2FinalData::~Boss2FinalData()
{

}
