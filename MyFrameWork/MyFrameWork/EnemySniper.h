#pragma once
#include "EnermySprite.h"
#include "EnemySniperData.h"
#include "Camera.h"
#include "PlayerSprite.h"
#include "EnemySniperTurningState.h"


class EnemySniper : public EnermySprite
{
public:
	EnemySniper(int respawnX, int respawnY, std::vector < BulletSprite*>& bulletSpriteVector);
	~EnemySniper();

	virtual void update();
	virtual void draw(Camera *cam);
};