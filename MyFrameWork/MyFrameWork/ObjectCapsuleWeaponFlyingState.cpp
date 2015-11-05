#include "ObjectCapsuleWeaponFlyingState.h"

ObjectCapsuleWeaponFlyingState::ObjectCapsuleWeaponFlyingState(ObjectData* pData)
{
	this->pData = pData;
	this->pData->iCurrentArr = ObjectCapsuleWeaponData::FLY;
	this->pData->vx = 2.0f;
	nHoldFrames = 1;
	count = 0;
	crow = 0.0f;
}


ObjectCapsuleWeaponFlyingState::~ObjectCapsuleWeaponFlyingState()
{
}


void ObjectCapsuleWeaponFlyingState::onUpdate()
{
	pData->ppTextureArrays[pData->iCurrentArr]->update();
	count++;
	crow += M_PI/30;
	count %= nHoldFrames;
	if (count == 0)
	{
		pData->x += pData->vx;
		pData->y += 2.8f * sin(crow);
	}
}

void ObjectCapsuleWeaponFlyingState::onDead()
{
	pData->isAffectble = false;
	transition(new ObjectCapsuleWeaponDropState(pData));
}

