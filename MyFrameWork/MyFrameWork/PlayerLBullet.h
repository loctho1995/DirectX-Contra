#pragma once

#include "BulletSprite.h"


class PlayerLBullet : public BulletSprite
{
public:

	PlayerLBullet( float x, float y ,bool  isBoosting, float angle  );
	virtual void draw(Camera* cam);
	virtual void update();
};