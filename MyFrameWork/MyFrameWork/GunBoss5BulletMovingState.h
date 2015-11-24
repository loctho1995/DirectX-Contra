#pragma once
#include "BulletState.h"
#include "GunBoss5Bullet.h"
class GunBoss5BulletMovingState :
	public BulletState
{
public:
	GunBoss5BulletMovingState(SpriteData * data);
	~GunBoss5BulletMovingState(); 
	virtual void onUpdate();
	virtual void onCollision(CollisionRectF rect);
	virtual void onDead();
};

