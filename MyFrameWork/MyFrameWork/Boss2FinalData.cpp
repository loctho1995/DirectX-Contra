#include "Boss2FinalData.h"

Boss2FinalData::Boss2FinalData(std::vector < BulletSprite* >& bulletsVector) : EnermyData(bulletsVector)
{
    botName = "boss2final";
    armLength = 16.0f * 5;
    isDesTroyed = false;
    isHittable = true;
    HP = 10;
    isThrougable = true;
    dir = Direction::createRight();
    //appearDir = Direction::createRight();
}


Boss2FinalData::~Boss2FinalData()
{

}
