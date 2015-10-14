#pragma once

#include "SpriteData.h"
#include "PlayerMBullet.h"
#include "PlayerFBullet.h"
#include "PlayerLBullet.h"
#include "CollisionRect.h"
class PlayerData : public SpriteData
{
public:
	PlayerData() 
	{
		hittableCounter = 0;
		nonHittableFrames = 300;
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
	enum BulletType
	{
		F,
		L,
		M,
		R,
		S
	};
	bool isFiring;
	std::vector<BulletSprite *> Bullets;
	int nFiringHoldFrames;
	int count;
	RectF cameraRect;
	BulletType bulletType;
	int hittableCounter;
	int nonHittableFrames;
};