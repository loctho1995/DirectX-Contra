#pragma once
#include "EnermyState.h"
#include "ObjectState.h"
#include "ObjectCapsuleWeaponData.h"
#include "ObjectCapsuleWeaponDropState.h"

class ObjectCapsuleWeaponFlyingState : public ObjectState
{
public:
	ObjectCapsuleWeaponFlyingState(ObjectData* pData, int isStage);
	~ObjectCapsuleWeaponFlyingState(); 
	void onUpdate();
	void onDead();
private:
	int count;
	int nHoldFrames;
	float crow;
	int stage;
};

