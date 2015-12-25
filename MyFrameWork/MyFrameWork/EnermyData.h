#pragma once

#include "SpriteData.h"
#include "BulletSprite.h"
#include "UIComponents.h"
class EnermyData : public SpriteData
{
public :
	EnermyData(std:: vector < BulletSprite* >& bulletsVector = std :: vector <BulletSprite* >())
		:
		bulletsVector(bulletsVector)
	{
		killBy = 1;
		isDesTroyed = false;
		isHittable  = true;
		appearDir = Direction::createRight();
		isDead = false;
		score = 0;
	}
	virtual int getPlayerIndexToExcute()
	{
		// return 0 : both are dead.
		// return 1 : player 1
		// return 2 : player 2
		float centerY = ( y - ppTextureArrays[iCurrentArr] -> getHeight() * ppTextureArrays[iCurrentArr] -> getAnchorPoint().y) + ppTextureArrays[iCurrentArr] -> getHeight() / 2;
		float centerX = ( x - ppTextureArrays[iCurrentArr] -> getWidth() * ppTextureArrays[iCurrentArr] -> getAnchorPoint().x) + ppTextureArrays[iCurrentArr] -> getWidth() / 2;

		if(UIComponents::getInstance() -> getNumberPlayer() == 1 )
		{
			if(isPlayerDead)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}

		if(isPlayerDead && isPlayer2Dead)
		{
			return 0;
		}
		else if(!isPlayerDead && isPlayer2Dead)
		{
			return 1;
		}
		else if(isPlayerDead && !isPlayer2Dead)
		{
			return 2;
		}
		else if(!isPlayerDead && !isPlayer2Dead)
		{
			float lengthsq1 = pow((playerX - centerX), 2)+ pow((playerY - centerY), 2);
			float lengthsp2 = pow((player2X - centerX), 2)+ pow((player2Y - centerY), 2);
			if(lengthsq1 < lengthsp2)
			{
				return 1;
			}
			else return 2;
		}
	}
	float playerX;
	float playerY;
	float player2X;
	float player2Y;
	int killBy;
	bool isPlayerDead;
	bool isPlayer2Dead;
    std::string botName; //add by Tho
	int HP;
	bool isThrougable;
	std:: vector < BulletSprite* >& bulletsVector;
	int score;
	Direction appearDir;
	int stage; // add by Hang
	float respawnX;
	float respawnY;
};