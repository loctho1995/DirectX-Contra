#pragma once
#include "EnermySprite.h"
#include "EnermyFinalBoss5PreparingState.h"
#include "EnermyFinalBoss5AppearingState.h"
#include "EnermyFinalBoss5WaitingState.h"
#include "EnermyFinalBoss5DisappearingState.h"
#include "EnermyFinalBoss5DeadState.h"
#include "GunBoss5Bullet.h"
#include "ShipBoss5.h"

class EnermyFinalBoss5Sprite :
	public EnermySprite
{
public:
	EnermyFinalBoss5Sprite(float respawnX, float respawnY, std::vector < BulletSprite*>& bulletSpriteVector);
	~EnermyFinalBoss5Sprite();
	static void loadResources();
	virtual void playBeShootedEffect();
};

