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
	EnermyCannon(int respawnX, int respawnY);
	~EnermyCannon();

	virtual void update();
	virtual void draw(Camera *cam);
};