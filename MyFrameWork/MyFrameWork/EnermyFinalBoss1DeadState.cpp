#include "EnermyFinalBoss1DeadState.h"


EnermyFinalBoss1DeadState::EnermyFinalBoss1DeadState(EnermyData* data)
{
	pData  = data;
	pData -> iCurrentArr = 1;
	pData -> isHittable = false;
}



EnermyFinalBoss1DeadState::~EnermyFinalBoss1DeadState(void)
{
}

void EnermyFinalBoss1DeadState :: onUpdate() 
{
	pData ->ppTextureArrays[ pData ->iCurrentArr ] ->update();
	if(pData ->ppTextureArrays[ pData ->iCurrentArr ] ->isLastTexture())
	{
		pData -> isDesTroyed = true;
	}
}


