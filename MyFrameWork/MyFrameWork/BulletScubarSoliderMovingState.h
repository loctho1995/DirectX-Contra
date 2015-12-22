#pragma once

#include "BulletState.h"
#include"BulletScubarSoliderExploringState.h"

#define BULLETGRAVITY 0.001
#define GAMETIME 5
#define BULLETVYJUMP2 - 0.6
#define BULLETVYJUMP13 - 0.615 
#define localY_3 692
#define localY_2_2 800


// index: index of bullet way: bullet bump :0, bullet traight, bullet right: 1, bullet left: 2

class BulletScubarSoliderMovingState : public BulletState

{
private:
	float collisionLineY;
	void Jumping(bool);
	int index;
	int kindScubar;
	int dem;
	bool flag;
	public:
	BulletScubarSoliderMovingState(SpriteData * data, float vx, int index, int kindScubar =0);
	virtual void onUpdate();
	void onCollision(CollisionRectF recF);
	virtual void onDead(int index);
};