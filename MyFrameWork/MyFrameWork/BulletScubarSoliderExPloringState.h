#pragma once

#include"BulletState.h"

class BulletScubarSoliderExploringState : public BulletState
{
public:
	BulletScubarSoliderExploringState(SpriteData * data, int index);
	~BulletScubarSoliderExploringState();
	virtual void onUpdate();
private:
	int nHoldFrames;
	int count;
};