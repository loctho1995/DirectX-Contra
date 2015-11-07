#pragma once

#include "BulletSprite.h"


class LBullet : public BulletSprite
{
public:

	LBullet( float x, float y ,float speed, float angle  );
	virtual void draw(Camera* cam);
	virtual void update();
};