#pragma once

#include "BulletSprite.h"


class MBullet : public BulletSprite
{
public:

	MBullet( float x, float y ,float speed, float angle  );
	virtual void draw(Camera* cam);
	virtual void update();
};