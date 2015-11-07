#pragma once

#include "BulletSprite.h"


class FBullet : public BulletSprite
{
public:

	FBullet( float x, float y ,float speed, float angle  );
	virtual void draw(Camera* cam);
	virtual void update();
	
};