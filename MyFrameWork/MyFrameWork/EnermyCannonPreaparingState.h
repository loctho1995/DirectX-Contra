#pragma once
#include "EnermyState.h"
#include "EnermyCannonAppearingState.h"
class EnermyCannonPreaparingState :
	public EnermyState
{
public:
	EnermyCannonPreaparingState(EnermyData* pData);
	~EnermyCannonPreaparingState();
	virtual void onUpdate();
	float directPlayerX;
};

