#pragma once

#include "SpriteData.h"
#include "BulletSprite.h"
class EnermyData : public SpriteData
{
public :
	EnermyData(std:: vector < BulletSprite* >& bulletsVector = std :: vector <BulletSprite* >())
		:
		bulletsVector(bulletsVector)
	{
		isDesTroyed = false;
		isHittable  = true;
		appearDir = Direction::createRight();
	}
	float playerX;
	float playerY;
    std::string botName; //add by Tho
	int HP;
	bool isThrougable;
	std:: vector < BulletSprite* > Bullets;
	std:: vector < BulletSprite* >& bulletsVector;

	Direction appearDir;
};