#pragma once

#include "SpriteData.h"
#include "BulletSprite.h"
class EnermyData : public SpriteData
{
public :
	EnermyData() 
	{
		isDesTroyed = false;
		isHittable  = true;
		appearDir = Direction::createRight();
	}
	float playerX;
	float playerY;
    std::string botName; //add by Tho
    bool isHittable; //co hiep dc con enermy nay khong ?
	int HP;
	bool isThrougable;
	std:: vector < BulletSprite* > Bullets;
	Direction appearDir;
};