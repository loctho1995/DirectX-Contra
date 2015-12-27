#pragma once
#include "EnermyData.h"


class EnemySniperData : public EnermyData
{
public:
	EnemySniperData(std::vector < BulletSprite*>& bulletSpriteVector);
	~EnemySniperData();

	enum EnemySniperArrayIndex
	{
		STAND1,
		STAND2,
		STAND3,
		STAND4,
		STAND5,
		STAND6,
		FIRE1,
		FIRE2,
		FIRE3,
		FIRE4,
		FIRE5,
		FIRE6,
        HIDING,
        SHOWING,
		DEAD,
        DYING,
		COUNT
	};

    bool isHiding;
};