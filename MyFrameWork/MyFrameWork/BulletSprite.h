#pragma once
#include "Sprite.h"

class BulletSprite : public Sprite
{
public:
	BulletSprite() {}
	virtual void draw(Camera* cam) = 0;
	virtual void update() = 0;
};