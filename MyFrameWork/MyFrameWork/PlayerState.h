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
		float speed = 0.0f;
		switch (pData ->bulletType)
		{
		case BulletTypes::M :
			speed = 4.5f;
			speed *= (pData -> isRapid )? 1.25 : 1; 
			pData ->Bullets.push_back(new MBullet( x ,   y , speed, angle));
			break;
		case BulletTypes::S :
		{
			speed = 3.5f;
			speed *= (pData -> isRapid == true)? 1.25 : 1;
			int maxNumberBullet = 5;
			int numberBullet = pData -> Bullets.size();
			int numberBulletWillbeCreate = min (10 - numberBullet, 5 );
			float offset = M_PI / 18;
			
			float tempAngle = -offset* ((int)(numberBulletWillbeCreate ) / 2 + 1);
			for (int i = 0; i < numberBulletWillbeCreate; i++)
			{
				tempAngle += offset ;
				pData ->Bullets.push_back(new MBullet( x ,  y , speed, tempAngle + angle));
			}
		}
		break;
		case BulletTypes::F:
		{
			speed = 2.0f;
			speed *= (pData -> isRapid )? 1.25 : 1;
			if( pData -> Bullets.size() < 3)
				pData ->Bullets.push_back(new FBullet( x ,   y , speed, angle));
		}
		break;
		case BulletTypes::L:
		{
			speed = 3.0f;
			speed *= (pData -> isRapid )? 1.25 : 1;
			this -> pData ->Bullets.clear();
			this -> pData ->Bullets.push_back(new LBullet( x ,   y , speed, angle));
		}
		break;

		default:
			break;
		}
	}
	virtual void hittableCalculation() 
	{
		if(pData -> isRespawn )
		{
			pData -> hittableCounter++;
			if((pData -> hittableCounter %= pData ->nonHittableFrames) == 0)
			{
				pData -> isHittable = true;
				pData -> isRespawn = false;
			}
		}
	}
	


protected:
	PlayerData* pData;
};