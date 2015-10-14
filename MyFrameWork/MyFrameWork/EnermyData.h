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
	}
	float playerX;
	float playerY;
	int HP;
	std:: vector < BulletSprite* > Bullets;
	std::string name;
};