#pragma once

#include "BulletState.h"

class PlayerFBulletMovingState : public BulletState
{
private:
	float speed;
	float cx;
	float cy;
	float radius;
	float rotationAngle;
public:
	PlayerFBulletMovingState( SpriteData * data , float speed, float angle )
	{
		pData = data;

		pData -> iCurrentArr = 0;

		this -> speed = speed;
		radius = 13.0f;
		cx = cos(angle) * radius + pData -> x;
		cy = sin(angle) * radius + pData -> y;
		
		pData -> vx = cos(angle) * speed;
		pData -> vy = sin(angle) * speed;

		if( pData -> vx >=0 ) 
		{
			rotationAngle = M_PI / 8;
		}
		else
		{
			rotationAngle = -M_PI / 8;
		}

		
	}
	virtual void onUpdate()
	{
		pData ->ppTextureArrays[pData -> iCurrentArr ] ->update();

		cx += pData -> vx;

		cy += pData -> vy;

		float x = pData -> x;

		float y = pData -> y;

		x -= cx;
		
		y -= cy;

		float cosA = cos(rotationAngle);

		float sinA = sin(rotationAngle);

		float xRotation = x* cosA - y* sinA;
		float yRotation = x * sinA + y * cosA;

		x = xRotation + cx;

		y = yRotation + cy;

		pData -> x = x;
		
		pData -> y = y;


	}

};