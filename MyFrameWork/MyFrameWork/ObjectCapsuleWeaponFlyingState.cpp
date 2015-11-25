#include "ObjectCapsuleWeaponFlyingState.h"

ObjectCapsuleWeaponFlyingState::ObjectCapsuleWeaponFlyingState(ObjectData* pData, int isStage)
{
	this->pData = pData;
	this->pData->iCurrentArr = ObjectCapsuleWeaponData::FLY;
	this->pData->vx = this->pData->vy = 2.0f;
	this->pData->isPlayerCollisionable = false;
	this->pData->isAffectble = false;
	nHoldFrames = 1;
	count = 0;
	crow = 0.0f;
	stage = isStage;
}


ObjectCapsuleWeaponFlyingState::~ObjectCapsuleWeaponFlyingState()
{
}


void ObjectCapsuleWeaponFlyingState::onUpdate()
{
	pData->ppTextureArrays[pData->iCurrentArr]->update();
	count++;
	crow += M_PI/30;
	if (crow == 2 * M_PI)
	{
		crow = 0;
	}
	count %= nHoldFrames;
	if (stage==1)
	{
		if (count == 0)
		{
			pData->x += pData->vx;
			pData->y += 2.8f * sin(crow);
		}
	}
	if (stage==3)
	{
		if (count == 0)
		{
			pData->x += 2.8f * sin(crow);
			pData->y -= pData->vy;
		}
	}
}

void ObjectCapsuleWeaponFlyingState::onDead()
{
	transition(new ObjectCapsuleWeaponDropState(pData));
}

