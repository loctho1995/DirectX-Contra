#pragma once

#include "BulletSprite.h"


class EnermyWhiteBullet : public BulletSprite
{
public:

	EnermyWhiteBullet(float x, float y, bool  isBoosting, float angle);
	virtual void draw(Camera* cam);
	virtual void update();
};