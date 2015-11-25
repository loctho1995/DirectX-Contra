#pragma once
#include "EnermyData.h"
class EnermyFailingStoneData :
	public EnermyData
{
public:
	EnermyFailingStoneData();
	~EnermyFailingStoneData();

	enum EnermyFailingStoneArrayIndex
	{
		PREPARE,
		APPEAR,
		DROP,
		DEAD,
		COUNT
	};
};

