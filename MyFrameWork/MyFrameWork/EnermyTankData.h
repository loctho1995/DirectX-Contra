#pragma once
#include"EnermyData.h"

class EnermyTankData : public EnermyData
{
public:
	EnermyTankData ( std::vector<BulletSprite*>& bulletsVector = std::vector<BulletSprite*>());
	~EnermyTankData();
};