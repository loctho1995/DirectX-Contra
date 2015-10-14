#include "EnermyGunBoss1DeadState.h"


EnermyGunBoss1DeadState::EnermyGunBoss1DeadState(EnermyData* data)
{
	pData  = data;
	pData -> iCurrentArr = 2;
	pData -> isHittable = false;
	nHoldFrames = 48;
	count = 0;
}


EnermyGunBoss1DeadState::~EnermyGunBoss1DeadState(void)
{
}

void EnermyGunBoss1DeadState :: onUpdate() 
{
	pData ->ppTextureArrays[ pData ->iCurrentArr ] ->update();
	count ++;
	count %= nHoldFrames;
	if( count == 0)
	{
		pData -> isDesTroyed = true;
	}
}
