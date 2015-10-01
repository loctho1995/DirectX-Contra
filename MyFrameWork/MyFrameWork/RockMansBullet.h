#pragma once

#include "BulletSprite.h"

class RockMansBullet : public BulletSprite
{
public:

	RockMansBullet( float x, float y , Direction dir);
	virtual void draw(Camera* cam);
	virtual void update();
};