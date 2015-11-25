#pragma once
#include "EnermySprite.h"
#include "ObjectCapsuleWeaponData.h"
#include "Camera.h"
#include "ObjectSprite.h"
#include "Define.h"

class ObjectCapsuleWeapon : public ObjectSprite
{
public:
	ObjectCapsuleWeapon(int respawnX, int respawnY, int isStage, BulletTypes bulletType);
	~ObjectCapsuleWeapon();

	virtual void update();
	virtual void draw(Camera *cam);
	virtual bool isDesTroyed();
	virtual void onCameraCollision(RectF rect);
	BulletTypes getBulletType();
};

