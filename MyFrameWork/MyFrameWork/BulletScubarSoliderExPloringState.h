#pragma once

#include"BulletState.h"

class BulletScubarSoliderExploringState : public BulletState
{
public:
	BulletScubarSoliderExploringState(SpriteData * data, int index);
	~BulletScubarSoliderExploringState();
	virtual void onUpdate();
	void onCollision(CollisionRectF cRect);
private:
	int nHoldFrames;
	int count;
};