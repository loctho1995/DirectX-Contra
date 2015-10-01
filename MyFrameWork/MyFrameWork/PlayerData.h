#pragma once

#include "SpriteData.h"
#include "RockMansBullet.h"
#include "CollisionRect.h"
class PlayerData : public SpriteData
{
public:
	PlayerData() 
	{
		
		nFiringHoldFrames = 15;
		
	}
	enum SpriteArrayIndex
	{
		STAND,
		STANDNFIRE,
		STANDUP,
		STANDUPNFIRE,
		STANDDOWN,
		RUN,
		RUNNFIRE,
		RUNUP,
		RUNDOWN,
		JUMP,
		JUMPNFIRE,
		FALL,
		DIVE,
		DIVEDOWN,
		DIVENFIRE,
		DIVEUP,
		SWIM,
		SWIMUP,
		CLIMP,
		DEAD,
		LIE,
		COUNT
	};
	bool isFiring;
	std::vector<BulletSprite *> Bullets;
	int nFiringHoldFrames;
	int count;
	RectF cameraRect;
	
};