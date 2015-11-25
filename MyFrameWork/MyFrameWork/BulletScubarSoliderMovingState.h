#pragma once

#include "BulletState.h"
#include"BulletScubarSoliderExploringState.h"

#define BULLETGRAVITY 0.001
#define GAMETIME 5
#define BULLETVYJUMP -0.58

// index: index of bullet way: bullet bump :0, bullet traight, bullet right: 1, bullet left: 2

class BulletScubarSoliderMovingState : public BulletState
{
private:
	float collisionLineY;
	void Jumping(bool);
	int index;
	public:
	BulletScubarSoliderMovingState(SpriteData * data, float vx, int index);
	virtual void onUpdate();
	void onCollision(CollisionRectF recF);
	virtual void onDead(int index);
};