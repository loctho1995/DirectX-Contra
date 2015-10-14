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
    std::string botName; //add by Tho
    bool isDone; //enermy da chet cmn chua ?
    bool isHittable; //co hiep dc con enermy nay khong ?
	int HP;
	std:: vector < BulletSprite* > Bullets;
	std::string name;
};