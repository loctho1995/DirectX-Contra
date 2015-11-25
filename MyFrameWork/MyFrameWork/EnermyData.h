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
		isDead = false;
		score = 0;
	}
	float playerX;
	float playerY;
	bool isPlayerDead;
    std::string botName; //add by Tho
	int HP;
	bool isThrougable;
	std:: vector < BulletSprite* >& bulletsVector;
	int score;
	Direction appearDir;
	int stage; // add by Hang
};