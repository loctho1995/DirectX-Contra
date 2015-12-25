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
		nonHittableFrames = 150;
		nFiringHoldFrames = 15;
		nUndyingFrames = 600;
		undyingCounter = 0;
		isOver = false;
		isRapid = false;
		isRespawn = true;
		isDead = false;
		isUndying = false;
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
		FALL,
		DIVE,
		DIVEDOWN,
		DIVENFIRE,
		DIVEUP,
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
	void reset()
	{
		this ->x = cameraRect.x + 20;
		if(movedir.isRight())
		{
			this -> y = cameraRect.y + 20;
		}
		else
			this ->y = cameraRect.y + cameraRect.height / 2;
		this ->isRespawn = true;
		this -> isUndying = false;
		this -> bulletType = BulletTypes::S;
		this -> isDead = false;
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
	int nUndyingFrames;
	int undyingCounter;
	int index;
	bool isOver;
	bool isRapid;
	bool isRespawn;
	bool isUndying;
	Direction movedir;
};