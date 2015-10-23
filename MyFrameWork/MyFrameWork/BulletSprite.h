#pragma once
#include "Sprite.h"
#define _USE_MATH_DEFINES

#include <math.h>
class BulletSprite : public Sprite
{
public:
	BulletSprite() {}
	virtual void draw(Camera* cam) = 0;
	virtual void update() = 0;
	virtual bool isDesTroyed() { return pData ->isDesTroyed;}
	virtual bool isHittable() {return pData -> isHittable;}
	virtual void die() { pData -> isDesTroyed = true;}
};