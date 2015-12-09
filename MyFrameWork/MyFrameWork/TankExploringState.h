#pragma once

#include"BulletState.h"

class TankExploringState : public BulletState
{
public:
	TankExploringState(SpriteData * data);
	~TankExploringState();
	virtual void onUpdate();
};