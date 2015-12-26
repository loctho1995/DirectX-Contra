#pragma once
#include"EnermyState.h"
class EnermyScubarSoliderDeadState : public EnermyState
{
public:
	EnermyScubarSoliderDeadState(EnermyData *pData);
	~EnermyScubarSoliderDeadState();
	void onUpdate();

private:
	int iFrames;
};

