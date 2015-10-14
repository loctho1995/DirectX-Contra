#pragma once

#include "BulletState.h"

class GunBoss1BulletMovingState : public BulletState
{
private:
	
	float nFallingFrames;
	float acceleration;
	float collisionLineY;
public:
	GunBoss1BulletMovingState( SpriteData * data );
	virtual void onUpdate();
	void onCollision();
	virtual void onDead();
};