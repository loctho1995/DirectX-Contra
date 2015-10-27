#pragma once
#include"EnermyData.h"

class EnermyGunRotatingData : public EnermyData
{
public:
	EnermyGunRotatingData();
	~EnermyGunRotatingData();

	enum EnermyGunRotatingArrayIndex
	{
		CLOSE,
		OPEN,
		SWAVEL1,
		SWAVEL2,
		SWAVEL3,
		SWAVEL4,
		SWAVEL5,
		SWAVEL6,
		SWAVEL7,
		SWAVEL8,
		SWAVEL9,
		SWAVEL10,
		SWAVEL11,
		SWAVEL12,
		DIE,
		COUNT
	};
};