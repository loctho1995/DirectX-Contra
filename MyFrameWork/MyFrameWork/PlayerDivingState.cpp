#include "PlayerDivingState.h"
#include "PlayerStandingState.h"
#include "PlayerRunningState.h"
#include "PlayerSwimmingState.h"
#include "PlayerDeadState.h"

PlayerDivingState :: PlayerDivingState(PlayerData* data)
{	
		this ->pData = data;
		if( pData -> verticalDir.isDown())
		{
			pData -> iCurrentArr = PlayerData :: DIVEDOWN;
		}
		
		else if( pData -> verticalDir.isUp())
		{
			pData -> iCurrentArr = PlayerData :: DIVEUP;
		}
		else
			pData ->iCurrentArr = PlayerData :: DIVE;
		
		pData -> vy = 0.0f;
}

void PlayerDivingState::onMovePressed(Direction d)
{
	pData -> dir = d;
	transition(new PlayerSwimmingState(pData));
}


void PlayerDivingState:: onUpdate()
{
	hittableCalculation();
	pData -> ppTextureArrays[ pData ->iCurrentArr ] -> update();
	if( pData ->isFiring )
	{
		pData ->count ++;
		pData ->count %= pData ->nFiringHoldFrames;
		if(pData ->count == 0)
		{
			pData ->isFiring = false;
			pData ->iCurrentArr = PlayerData::DIVE;
		}
	}
}
void PlayerDivingState:: onFirePressed()
{
	if( pData -> verticalDir.isDown())
	{
		pData -> iCurrentArr = PlayerData :: DIVEDOWN;
	}

	else if( pData -> verticalDir.isUp())
	{
		pData -> iCurrentArr = PlayerData :: DIVEUP;
	}
	else
		pData ->iCurrentArr = PlayerData::DIVENFIRE;
	
	pData ->isFiring = true;
	pData ->count = 0;

	float bulletX;
	float bulletY;
	float angle;

	if(pData -> dir.isRight())
	{
		bulletX = pData -> ppTextureArrays[ pData ->iCurrentArr] ->getWidth() / 2 + pData -> x;
	}
	else
	{
		bulletX = -pData -> ppTextureArrays[ pData ->iCurrentArr] ->getWidth() / 2 + pData -> x;
		
	}

	if( pData -> verticalDir.isNone())
	{
		bulletY = pData -> y - pData -> ppTextureArrays[ pData ->iCurrentArr] ->getHeight() / 2;
	}
	else if ( pData -> verticalDir.isUp())
	{
		bulletY = pData -> y - pData -> ppTextureArrays[ pData ->iCurrentArr] ->getHeight();
		bulletX = pData -> x;
	}

	if(pData -> dir.isRight())
	{
		if( pData -> verticalDir.isNone())
		{
			angle = 0.0f;
		}
		else if( pData -> verticalDir.isUp())
			angle = M_PI_2;
	}
	else
	{
		if( pData -> verticalDir.isNone())
		{
			angle = M_PI;
		}
		else
		{
			angle = M_PI_2;
		}

	}

	if( !pData -> verticalDir.isDown())
		createBullet(bulletX, bulletY, angle );
}

void PlayerDivingState :: onVeticalDirectionPressed(Direction d)
{
	pData ->verticalDir = d;
	if(d.isDown())
	{
		pData ->iCurrentArr = PlayerData ::DIVEDOWN;
	}
	else
	{
		pData ->iCurrentArr = PlayerData :: DIVEUP;
	}
}

void PlayerDivingState :: onVeticalDirectionReleased()
{
	pData ->verticalDir = Direction::createNone();
	pData ->iCurrentArr = pData ->DIVE;
}


void PlayerDivingState :: onDead()
{
	transition(new PlayerDeadState(pData));
}


