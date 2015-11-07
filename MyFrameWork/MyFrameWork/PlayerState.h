#pragma once

#include "SpriteState.h"
#include "PlayerData.h"


class PlayerState : public SpriteState
{
public:
	PlayerState() {}
	virtual void transition(PlayerState* state) 
	{
		pData -> pState = state; 
		delete this;
	}
	virtual void onCameraCollision(RectF cameraRect)
	{
		pData -> x = max(pData -> x, cameraRect.x + 20);
		if( pData -> y >= cameraRect.y + cameraRect.height)
		{
			pData -> y = cameraRect.y + cameraRect.height;
			onDead();
		}
	}
	virtual void createBullet(float x, float y, float angle) 
	{
		switch (pData ->bulletType)
		{
		case BulletTypes::M :
			pData ->Bullets.push_back(new MBullet( x ,   y , 4.5f, angle));
			break;
		case BulletTypes::S :
		{
			int maxNumberBullet = 5;
			int numberBullet = pData -> Bullets.size();
			int numberBulletWillbeCreate = min (10 - numberBullet, 5 );
			float offset = M_PI / 18;
			
			float tempAngle = -offset* ((int)(numberBulletWillbeCreate ) / 2 + 1);
			for (int i = 0; i < numberBulletWillbeCreate; i++)
			{
				tempAngle += offset ;
				pData ->Bullets.push_back(new MBullet( x ,  y , 3.5f, tempAngle + angle));
			}
		}
		break;
		case BulletTypes::F:
		{
			if( pData -> Bullets.size() < 3)
				pData ->Bullets.push_back(new FBullet( x ,   y , 2.0f, angle));
		}
		break;
		case BulletTypes::L:
		{
			this -> pData ->Bullets.clear();
			this -> pData ->Bullets.push_back(new LBullet( x ,   y , 3.0f, angle));
		}
		break;

		default:
			break;
		}
	}
	virtual void hittableCalculation() 
	{
		if(!pData -> isHittable )
		{
			pData -> hittableCounter++;
			if((pData -> hittableCounter %= pData ->nonHittableFrames) ==0)
			{
				pData -> isHittable = true;
			}
		}
	}
	


protected:
	PlayerData* pData;
};