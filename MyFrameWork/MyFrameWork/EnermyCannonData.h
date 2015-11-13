#pragma once
#include "EnermyData.h"

class EnermyCannonData : public EnermyData
{
public:
	EnermyCannonData(std::vector < BulletSprite* >& bulletsVector = std::vector <BulletSprite* >());
	~EnermyCannonData();

	enum EnermyCannonArrayIndex
	{
		APPEAR,
		TURN0,
		TURN30,
		TURN60,
		FIRE,
		DEAD,
		PREPARE,
		COUNT
	};
};

