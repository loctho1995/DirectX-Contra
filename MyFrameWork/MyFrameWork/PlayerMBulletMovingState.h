#pragma once

#include "BulletState.h"

class PlayerMBulletMovingState : public BulletState
{
private:
	float speed;
public:
	PlayerMBulletMovingState( SpriteData * data , float angle )
	{
		pData = data;
		pData -> iCurrentArr = 0;
		speed = 3.0f;
		
		pData -> vy = sin(angle) * speed;
		pData -> vx = cos(angle) * speed;
		
	}
	virtual void onUpdate()
	{
		pData ->ppTextureArrays[pData -> iCurrentArr ] ->update();
		
		pData -> x += pData -> vx;

		pData -> y += pData -> vy;
	}
};