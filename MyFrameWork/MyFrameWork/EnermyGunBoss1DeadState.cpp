#include "EnermyGunBoss1DeadState.h"


EnermyGunBoss1DeadState::EnermyGunBoss1DeadState(EnermyData* data)
{
	pData  = data;
	pData -> iCurrentArr = 2;
	pData -> isHittable = false;
}


EnermyGunBoss1DeadState::~EnermyGunBoss1DeadState(void)
{
}

void EnermyGunBoss1DeadState :: onUpdate() 
{
	pData ->ppTextureArrays[ pData ->iCurrentArr ] ->update();
	if( pData ->ppTextureArrays[ pData ->iCurrentArr ] ->isLastTexture())
	{
		pData -> isDesTroyed = true;
	}
}
