#include "EnermyGunBoss1StandingState.h"
#include "EnermyGunBoss1FiringState.h"
#include "EnermyGunBoss1DeadState.h"

EnermyGunBoss1StandingState::EnermyGunBoss1StandingState( EnermyData* data)
{
	pData = data;
	pData ->iCurrentArr = 0;
	nHoldFrames = 20;
	count = 0;
}


void EnermyGunBoss1StandingState :: onUpdate()
{
	pData ->ppTextureArrays[ pData ->iCurrentArr ] ->update();
	count ++;
	count %= nHoldFrames;
	if( count == 0)
	{
		transition(new EnermyGunBoss1FiringState(pData));
	}
}

void EnermyGunBoss1StandingState :: onDead()
{
	transition(new EnermyGunBoss1DeadState(pData));
}

