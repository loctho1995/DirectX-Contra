#pragma once
#include "ObjectState.h"
#include "ObjectCapsuleWeaponData.h"
#include "Sound.h"

class ObjectCapsuleWeaponDropState :
	public ObjectState
{
public:
	ObjectCapsuleWeaponDropState(ObjectData *pData);
	~ObjectCapsuleWeaponDropState();
	void onUpdate();
	void onCollision(CollisionRectF rect);
	void onCameraCollision(RectF rect);
	void onDead();
private:
	float accelemeter;
};

