#pragma once
#include "EnermyData.h"


class EnemySniperData : public EnermyData
{
public:
	EnemySniperData(std::vector < BulletSprite*>& bulletSpriteVector);
	~EnemySniperData();

	enum EnemySniperArrayIndex
	{
		STAND0,
		STAND1,
		STAND2,
		STAND3,
		STAND4,
		STAND5,
        HIDING,
		HIDING2,
        SHOWING,
		DEAD,
        DYING,
		COUNT
	};

    int isHiding;
};