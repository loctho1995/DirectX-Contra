#pragma once
#include "BulletState.h"

class GunBoss1BulletExploringState : public BulletState
{
public:
	GunBoss1BulletExploringState(SpriteData * data);
	~GunBoss1BulletExploringState();
	virtual void onUpdate();
private:
	int nHoldFrames;
	int count;
};

