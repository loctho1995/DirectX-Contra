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
			pData ->setiCurrentArray (PlayerData :: DIVEDOWN);

		}
		
		else if( pData -> verticalDir.isUp())
		{
			pData ->setiCurrentArray (PlayerData :: DIVEUP);
		}
		else
			pData ->setiCurrentArray (PlayerData :: DIVE);
		
		pData -> vy = 0.0f;
}

void PlayerDivingState::onMovePressed(Direction d)
{
	pData -> dir = d;
	if(!pData ->verticalDir.isDown())
	transition(new PlayerSwimmingState(pData));
}


void PlayerDivingState:: onUpdate()
{
	hittableCalculation();
	undyingCalculation();
	pData -> ppTextureArrays[ pData ->iCurrentArr ] -> update();
	if( pData ->isFiring )
	{
		pData ->count ++;
		pData ->count %= pData ->nFiringHoldFrames;
		if(pData ->count == 0)
		{
			pData ->isFiring = false;
			if( pData -> verticalDir.isDown())
			{
				pData ->setiCurrentArray(PlayerData :: DIVEDOWN);
			}

			else if( pData -> verticalDir.isUp())
			{
				pData ->setiCurrentArray(PlayerData :: DIVEUP);
			}
			else
				pData ->setiCurrentArray(PlayerData :: DIVE);
		}
	}

	if( pData -> verticalDir.isDown())
	{
		pData -> isHittable = false;
	}
	else
	{
		pData -> isHittable = true;
	}
}
void PlayerDivingState:: onFirePressed()
{
	if( pData -> verticalDir.isDown())
	{
		pData ->setiCurrentArray(PlayerData :: DIVEDOWN);
	}

	else if( pData -> verticalDir.isUp())
	{
		pData ->setiCurrentArray(PlayerData :: DIVEUP);
	}
	else
		pData ->setiCurrentArray(PlayerData :: DIVENFIRE);
	
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
			angle = -M_PI_2;
	}
	else
	{
		if( pData -> verticalDir.isNone())
		{
			angle = M_PI;
		}
		else if( pData -> verticalDir.isUp())
				angle = -M_PI_2;

	}

	if( !pData -> verticalDir.isDown())
		createBullet(bulletX, bulletY, angle );
}

void PlayerDivingState :: onVeticalDirectionPressed(Direction d)
{
	pData ->verticalDir = d;
	if(d.isDown())
	{
		pData ->setiCurrentArray(PlayerData ::DIVEDOWN);
	}
	else
	{
		pData ->setiCurrentArray(PlayerData ::DIVEUP);
	}
}

void PlayerDivingState :: onVeticalDirectionReleased()
{
	pData ->verticalDir = Direction::createNone();
	pData -> isHittable = true;
	pData ->setiCurrentArray(PlayerData ::DIVE);
}


void PlayerDivingState :: onDead()
{
	transition(new PlayerDeadState(pData));
}


