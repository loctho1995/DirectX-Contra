#pragma once
#include "EnermySprite.h"
#include "EnermyCannonData.h"
#include "Camera.h"
#include "PlayerSprite.h"

class EnermyCannon : public EnermySprite
{
private:
public:
	EnermyCannon(int respawnX, int respawnY);
	~EnermyCannon();

	virtual void update();
	virtual void draw(Camera *cam);
};