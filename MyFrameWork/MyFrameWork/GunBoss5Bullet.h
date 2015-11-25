#pragma once
#include "BulletSprite.h"
#include "BulletMovingState.h"
#include "GunBoss5BulletMovingState.h"
#include "GunBoss5BulletExploringState.h"

class GunBoss5Bullet :
	public BulletSprite
{
public:
	GunBoss5Bullet(float x, float y);
	~GunBoss5Bullet();
	virtual void draw(Camera* cam);
	virtual void update();
	virtual void die();
};

