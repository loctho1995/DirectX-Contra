#include "ObjectCapsuleWeaponDropState.h"


ObjectCapsuleWeaponDropState::ObjectCapsuleWeaponDropState(ObjectData *pData)
{
	this->pData = pData;
	this->pData->iCurrentArr = ObjectCapsuleWeaponData::DROP;
	this->pData->isPlayerCollisionable = true;
	this->pData->isAffectble = false;
	this->pData->isHittable = false;
	this->pData->vx = 0.8f;
	this->pData->vy = -3.8f;

	this->pData->body = RectF(0.0f, 0.0f, 24.0f, 15.0f);
	accelemeter = 0.1f;
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

void ObjectCapsuleWeaponDropState::onCollision(CollisionRectF rect)
{
	if (this->pData->vy > 0)
	{
		this->pData->vy = 0;
		this->pData->vx = 0;
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
