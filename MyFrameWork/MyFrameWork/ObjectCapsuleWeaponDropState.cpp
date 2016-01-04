#include "ObjectCapsuleWeaponDropState.h"


ObjectCapsuleWeaponDropState::ObjectCapsuleWeaponDropState(ObjectData *pData)
{
	this->pData = pData;
	this->pData->iCurrentArr = ObjectCapsuleWeaponData::DROP;
	this->pData->isPlayerCollisionable = true;
	this->pData->isAffectble = false;
	this->pData->isHittable = false;
	this->pData->body = RectF(-8.0f, -6.5f, 16.0f, 13.0f);
	this->pData->vx = 0.8f;
	this->pData->vy = -3.8f;
	accelemeter = 0.1f;

	Sound::getInstance()->play("qexplode", false, 1);
}


ObjectCapsuleWeaponDropState::~ObjectCapsuleWeaponDropState()
{
}

void ObjectCapsuleWeaponDropState::onUpdate()
{
	ObjectState::onUpdate();

	this->pData->x = this->pData->x + this->pData->vx;
	this->pData->y = this->pData->y + this->pData->vy;
	this->pData->vy += accelemeter;
}

void ObjectCapsuleWeaponDropState::onCollision(CollisionRectF cRect)
{
	// devide into 4 case
	float vx = pData -> vx - cRect.vx;
	float vy = pData -> vy - cRect.vy;
	float top = pData ->getBody().y;
	float left = pData -> getBody().x;
	float right =  left + pData-> getBody().width;
	float bottom = top + pData ->getBody().height;


	float topR = cRect.rect.y;
	float leftR = cRect.rect.x;
	float rightR =  leftR + cRect.rect.width;
	float bottomR = topR + cRect.rect.height;
	

	
		if( vx > 0.0f)
		{
			if(vy > 0.0f)
			{
				float px = right - leftR;
				float py = bottom - topR;
				if( vy * px > vx * py )
				{
					// top collision
					pData -> vy = 0.0f;
					pData -> vx = 0.0f;
					pData -> y -= py;

				}
			}
		}
		else // vx <= 0.0f
		{
			if(vy > 0.0f)
			{
				float px = rightR - left;
				float py = bottom - topR;
				if( vy * px > (-vx * py) )
				{
					pData -> vy = 0.0f;
					pData -> vx = 0.0f;
					pData -> y -= py;
				}

			}
		}
}

void ObjectCapsuleWeaponDropState::onCameraCollision(RectF rect)
{
	if ((rect.x + rect.width) - this->pData->x <= 15)
	{
		this->pData->vx = -this->pData->vx;
	}
}

void ObjectCapsuleWeaponDropState::onDead()
{
	this->pData->isDesTroyed = true;
}

