#pragma once

#include "BulletSprite.h"


class GunBoss1Bullet : public BulletSprite
{
public:

	GunBoss1Bullet( float x, float y  );
	virtual void draw(Camera* cam);
	virtual void update();
	virtual void die();
};