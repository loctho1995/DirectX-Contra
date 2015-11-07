#pragma once

#include "SpriteData.h"
#include "MBullet.h"
#include "FBullet.h"
#include "LBullet.h"
#include "CollisionRect.h"
#include "Define.h"
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
		STANDDOWNNFIRE,
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
	virtual void setiCurrentArray(int index)
	{
		iCurrentArr = index;
		body = bodyRects[index];
	}
	RectF* bodyRects;
	bool isFiring;
	std::vector<BulletSprite *> Bullets;
	int nFiringHoldFrames;
	int count;
	RectF cameraRect;
	BulletTypes bulletType;
	int hittableCounter;
	int nonHittableFrames;
};