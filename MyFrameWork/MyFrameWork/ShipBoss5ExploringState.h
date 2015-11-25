#pragma once
#include "BulletState.h"
#include "ShipBoss5.h"

class ShipBoss5ExploringState :
	public BulletState
{
public:
	ShipBoss5ExploringState(SpriteData * data);
	~ShipBoss5ExploringState();
	virtual void onUpdate();
};

