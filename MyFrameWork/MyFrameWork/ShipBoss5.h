#pragma once
#include "BulletSprite.h"
#include "ShipBoss5MovingState.h"
#include "ShipBoss5ExploringState.h"

class ShipBoss5 :
	public BulletSprite
{
public:
	ShipBoss5(float x, float y, bool isLeft);
	~ShipBoss5();
	virtual void draw(Camera* cam);
	virtual void update();
	virtual void die();
};

