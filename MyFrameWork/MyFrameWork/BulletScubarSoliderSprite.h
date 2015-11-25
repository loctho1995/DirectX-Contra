#pragma once

#include"BulletSprite.h"

class BulletScubarSoliderSprite : public BulletSprite
{
public:
	BulletScubarSoliderSprite(float x, float y, int index = 0, float vx = 0.0f);
	~BulletScubarSoliderSprite();
	virtual void draw(Camera *cam);
	virtual void update();
	virtual void die();

private:
	int iFrame;
	int index;
};