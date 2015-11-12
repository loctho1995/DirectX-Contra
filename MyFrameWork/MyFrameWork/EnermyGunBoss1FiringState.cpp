#include "EnermyGunBoss1FiringState.h"
#include "EnermyGunBoss1StandingState.h"
#include "EnermyGunBoss1DeadState.h"
#include "GunBoss1Bullet.h"
EnermyGunBoss1FiringState::EnermyGunBoss1FiringState( EnermyData* data)
{
	pData = data;
	pData ->iCurrentArr = 1;
	nHoldFrames = 30;
	count = 0;
}


void EnermyGunBoss1FiringState :: onUpdate()
{
	if( count == 0)
	{
		pData -> bulletsVector.push_back( new GunBoss1Bullet(pData -> x - pData ->ppTextureArrays[ pData ->iCurrentArr ] -> getWidth() / 2, pData -> y ));
	}
	pData ->ppTextureArrays[ pData ->iCurrentArr ] ->update();
	count ++;
	count %= nHoldFrames;
	if( count == 0)
	{
		transition(new EnermyGunBoss1StandingState(pData));
	}
}

void EnermyGunBoss1FiringState :: onDead()
{
	transition(new EnermyGunBoss1DeadState(pData));
}

