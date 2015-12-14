#pragma once

#include "SpriteState.h"
#include "PlayerData.h"
#include "Sound.h"

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
		pData -> x = min ( pData -> x, cameraRect.x + cameraRect.width- 20 );
		if( pData -> y > cameraRect.y + cameraRect.height)
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
			speed = 4.0f;
			speed *= (pData -> isRapid )? 1.25 : 1; 
			pData ->Bullets.push_back(new MBullet( x ,   y , speed, angle));
			Sound::getInstance() -> play("shootM", false, 1);
			break;
		case BulletTypes::S :
		{
			speed = 3.0f;
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
			if(numberBulletWillbeCreate > 0 )
			{
				Sound::getInstance() -> play("shootS", false, 1);
			}
		}
		break;
		case BulletTypes::F:
		{
			speed = 1.75f;
			speed *= (pData -> isRapid )? 1.25 : 1;
			if( pData -> Bullets.size() < 3)
			{
				pData ->Bullets.push_back(new FBullet( x ,   y , speed, angle));
				Sound::getInstance() -> play("shootF", false, 1);
			}
				
		}
		break;
		case BulletTypes::L:
		{
			speed = 2.0f;
			speed *= (pData -> isRapid )? 1.25 : 1;
			this -> pData ->Bullets.clear();
			this -> pData ->Bullets.push_back(new LBullet( x ,   y , speed, angle));
			Sound::getInstance() -> play("shootL", false, 1);
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
			if((pData -> hittableCounter >= pData ->nonHittableFrames))
			{
				pData -> isHittable = true;
				pData -> isRespawn = false;
			}
		}
	}

	virtual void undyingCalculation() 
	{
		if(pData -> isUndying )
		{
			pData -> undyingCounter++;
			if((pData -> undyingCounter >= pData ->nUndyingFrames))
			{
				pData -> isUndying = false;
				
			}
		}
	}
	



protected:
	PlayerData* pData;
};