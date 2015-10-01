#pragma once

#include "BulletState.h"

class BulletMovingState : public BulletState
{
private:
	int speedX;
	int speedY;
public:
	BulletMovingState( SpriteData * data )
	{
		pData = data;
		pData -> iCurrentArr = 0;
		speedY = 0;
		speedX = 10;
		pData -> vx = pData ->transform( speedX );
		pData -> vy = pData ->transform( speedY );
	}
	virtual void onUpdate()
	{
		pData ->ppTextureArrays[pData -> iCurrentArr ] ->update();
		
		pData -> x += pData -> vx;

		pData -> y += pData -> vy;
	}
};