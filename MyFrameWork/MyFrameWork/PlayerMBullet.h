#pragma once

#include "BulletSprite.h"


class PlayerMBullet : public BulletSprite
{
public:

	PlayerMBullet( float x, float y ,bool  isBoosting, float angle  );
	virtual void draw(Camera* cam);
	virtual void update();
};