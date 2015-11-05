#pragma once
#include "ObjectState.h"
#include "ObjectCapsuleWeaponData.h"
class ObjectCapsuleWeaponDropState :
	public ObjectState
{
public:
	ObjectCapsuleWeaponDropState(ObjectData *pData);
	~ObjectCapsuleWeaponDropState();
	void onUpdate();
	void onCollision(CollisionRectF rect);
	void onCameraCollision(RectF rect);
private:
	float accelemeter;
};

