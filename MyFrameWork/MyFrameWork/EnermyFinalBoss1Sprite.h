#pragma once
#include "EnermySprite.h"
class EnermyFinalBoss1Sprite : public EnermySprite
{
public:
	~EnermyFinalBoss1Sprite();
	EnermyFinalBoss1Sprite(int respawnX, int respawnY);
	virtual void playBeShootedEffect();
	static void loadResources();
};

