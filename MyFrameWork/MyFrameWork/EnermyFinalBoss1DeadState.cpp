#include "EnermyFinalBoss1DeadState.h"


EnermyFinalBoss1DeadState::EnermyFinalBoss1DeadState(EnermyData* data)
{
	pData  = data;
	pData -> iCurrentArr = 1;
	pData -> isHittable = false;
	nHoldFrames = 48;
	count = 0;
}



EnermyFinalBoss1DeadState::~EnermyFinalBoss1DeadState(void)
{
}

void EnermyFinalBoss1DeadState :: onUpdate() 
{
	pData ->ppTextureArrays[ pData ->iCurrentArr ] ->update();
	count ++;
	count %= nHoldFrames;
	if( count == 0)
	{
		pData -> isDesTroyed = true;
	}
}


