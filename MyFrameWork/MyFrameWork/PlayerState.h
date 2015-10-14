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
		case PlayerData::BulletType::M :
			pData ->Bullets.push_back(new PlayerMBullet( x ,   y , false, angle));
			break;
		case PlayerData::BulletType::S :
		{
			float offset = M_PI / 18;
				
			float tempAngle = -M_PI / 9 - offset;
			for (int i = 0; i < 5; i++)
			{
				tempAngle += offset ;
				pData ->Bullets.push_back(new PlayerMBullet( x ,  y , false, tempAngle + angle));
			}
		};
		break;
		case PlayerData::BulletType::F :
		{
			pData ->Bullets.push_back(new PlayerFBullet( x ,   y , false, angle));
		}
		break;
		case PlayerData::BulletType :: L :
		{
			pData ->Bullets.clear();
			pData ->Bullets.push_back(new PlayerLBullet( x ,   y , false, angle));
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