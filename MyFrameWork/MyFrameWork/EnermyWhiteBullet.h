#pragma once

#include "BulletSprite.h"


class EnermyWhiteBullet : public BulletSprite
{
public:

	EnermyWhiteBullet(float x, float y, bool  isBoosting, float angle, int  kindBullet = 0);
	virtual void draw(Camera* cam);
	virtual void update();
private:
	int kindBullet;
};