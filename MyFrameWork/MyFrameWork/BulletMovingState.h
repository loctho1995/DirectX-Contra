#pragma once

#include "BulletState.h"

class BulletMovingState : public BulletState
{
private:
	float speed;
public:
	BulletMovingState( SpriteData * data , float speed, float angle , int iCurrentArray)
	{
		pData = data;
		pData -> iCurrentArr = iCurrentArray;
		this -> speed = speed;
		
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