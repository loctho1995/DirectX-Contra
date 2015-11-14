#pragma once

#include "EnermySprite.h"
#include "EnermyGunBoss1Sprite.h"
class EnermyGunBoss1Sprite : public EnermySprite
{
public:
	EnermyGunBoss1Sprite(int respawnX, int respawnY, std::vector < BulletSprite*>& bulletSpriteVector);
	virtual void draw( Camera* cam) ;
	virtual void update();
	static void loadResources();
};