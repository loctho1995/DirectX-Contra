#pragma once
#include"EnermySprite.h"
class EnermyTankSprite : public EnermySprite
{
public:
	EnermyTankSprite(int respawnX, int respawnY, std::vector<BulletSprite*>& bulletSpriteVector);
	~EnermyTankSprite();
	static void loadResources();
	void update();
	void draw(Camera*);
	virtual void playBeShootedEffect();
};