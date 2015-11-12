#include "GunBoss1BulletMovingState.h"
#include <stdlib.h>
#include "GunBoss1BulletExploringState.h"
GunBoss1BulletMovingState :: GunBoss1BulletMovingState( SpriteData * data  )
{
	
	pData = data;
	pData -> iCurrentArr = 0;
	nFallingFrames = 20;
	acceleration = 0.2f;

	float maxRange = 3.0f * 16;
	float maxHigh = 1.5f * 16;
	float minHigh = 16.0f;
	float minRange = 16.0f;
	
	collisionLineY = 215;
	float range = std::rand()% (int)(maxRange - minRange) + minRange;
	float high = std::rand()% (int)maxHigh + minHigh;
	float speedX = (float) range / nFallingFrames;
	float speedY = ( -  0.5 * acceleration * nFallingFrames * nFallingFrames ) / nFallingFrames;

	pData -> vx = - speedX;
	pData -> vy =  speedY;
}
void GunBoss1BulletMovingState :: onUpdate()
{
	pData ->ppTextureArrays[pData -> iCurrentArr ] ->update();
	
	pData -> vy += acceleration;

	pData -> x += pData -> vx;

	pData -> y += pData -> vy;

	onCollision();
}
void GunBoss1BulletMovingState :: onCollision()
{
	if( pData -> y >= collisionLineY )
	{
		pData -> y = collisionLineY;
		pData ->vx = 0.0f;
		onDead();
	}
}

void GunBoss1BulletMovingState :: onDead() 
{
	transition(new GunBoss1BulletExploringState(pData ) );
}