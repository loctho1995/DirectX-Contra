#pragma once
#include "EnermySprite.h"
#include "EnermyCannonData.h"
#include "Camera.h"
#include "PlayerSprite.h"
#include "EnermyCannonPreaparingState.h"
#include "EnermyCannonAppearingState.h"
#include "EnermyCannonTurningState.h"

class EnermyCannon : public EnermySprite
{
private:
public:
	EnermyCannon(int respawnX, int respawnY, int isStage, std::vector < BulletSprite*>& bulletSpriteVector);
	~EnermyCannon();

	virtual void playBeShootedEffect();
	static void loadResources();
	virtual void update();
	virtual void draw(Camera *cam);
};