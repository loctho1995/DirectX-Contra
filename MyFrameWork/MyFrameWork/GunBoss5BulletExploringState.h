#pragma once
#include "BulletState.h"
#include "GunBoss5Bullet.h"
class GunBoss5BulletExploringState :
	public BulletState
{
public:
	GunBoss5BulletExploringState(SpriteData * data);
	~GunBoss5BulletExploringState();
	virtual void onUpdate();
};

