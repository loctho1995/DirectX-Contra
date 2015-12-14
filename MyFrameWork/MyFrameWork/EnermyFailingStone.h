#pragma once
#include "EnermySprite.h"
#include "EnermyFailingStoneData.h"
#include "EnermyFailingStoneAppearingState.h"
#include "EnermyFailingStoneDroppingState.h"
#include "EnermyFailingStoneDeadState.h"
#include "Sound.h"

class EnermyFailingStone :
	public EnermySprite
{
public:
	EnermyFailingStone(float respawnX, float respawnY);
	~EnermyFailingStone();

	static void loadResources();
	virtual void update();
	virtual void draw(Camera *cam);
	virtual void playBeShootedEffect();
};

