#pragma once

#include "BulletSprite.h"


class PlayerFBullet : public BulletSprite
{
public:

	PlayerFBullet( float x, float y ,bool  isBoosting, float angle  );
	virtual void draw(Camera* cam);
	virtual void update();
};