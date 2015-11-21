#include "PlayerSwimmingState.h"
#include "PlayerDivingState.h"
#include "PlayerStandingState.h"
#include "PlayerClimbingState.h"
#include "PlayerDeadState.h"

PlayerSwimmingState :: PlayerSwimmingState(PlayerData* data)
{	
		this ->pData = data;
		if( pData -> verticalDir.isDown())
		{
			pData ->setiCurrentArray (PlayerData :: DIVEDOWN);
		}
		
		else if( pData -> verticalDir.isUp())
		{
			pData ->setiCurrentArray (PlayerData :: SWIMUP);
		}
		else
			pData ->setiCurrentArray (PlayerData :: DIVE);
		
		pData -> vy = 0.0f;
		speed = 1;
		tempDir = pData -> dir;
}

void PlayerSwimmingState:: onMovePressed( Direction d )
{
		pData -> dir = d;
		tempDir = (tempDir | d);
}

void PlayerSwimmingState :: onMoveReleased ( Direction d)
{
	tempDir = tempDir ^ d;
	if(!tempDir.isNone())
	{
		pData -> dir = tempDir;
	}
	else
	transition(new PlayerDivingState(pData));

}

void PlayerSwimmingState :: onUpdate()
{
		hittableCalculation();
		undyingCalculation();
		pData -> ppTextureArrays [ pData ->iCurrentArr] ->update();
		pData -> vx = pData->transform(speed);
		pData -> x += pData -> vx;
		if( pData ->isFiring )
		{
			pData ->count ++;
			pData ->count %= pData ->nFiringHoldFrames;
			if(pData ->count == 0)
			{
				pData ->isFiring = false;
				if( pData -> verticalDir.isDown())
				{
					pData ->setiCurrentArray (PlayerData :: DIVEDOWN);
				}

				else if( pData -> verticalDir.isUp())
				{
					pData ->setiCurrentArray (PlayerData :: SWIMUP);
				}
				else
					pData ->setiCurrentArray (PlayerData :: DIVE);
			}
		}
}


void PlayerSwimmingState :: onCollision(RectF rect )
{
	if( pData -> vx > 0 )
	{
		pData -> x -= pData -> getBody().x + pData -> getBody().width - rect.x;
		pData -> vx = 0;
	}
	else
	{
		pData -> x += rect.x + rect.width - pData->getBody().x;
		pData -> vx = 0;
	}
}

void PlayerSwimmingState :: onCollision(CollisionRectF cRect )
{
	if( cRect.type != "water")
	{
		if( pData -> vx > 0 )
		{
			pData -> y = cRect.rect.y;
			pData -> x +=  pData -> getBody().width / 2;

			pData -> vx = 0;

		}
		else
		{
			pData -> y = cRect.rect.y;
			pData -> x -=  pData -> getBody().width / 2;
			pData -> vx = 0;

		}
		transition(new PlayerClimbingState(pData ));
	}
	
}


void PlayerSwimmingState:: onFirePressed()
{
	if( pData -> verticalDir.isDown())
	{
		pData ->setiCurrentArray (PlayerData :: DIVEDOWN);
	}

	else if( pData -> verticalDir.isUp())
	{
		pData ->setiCurrentArray (PlayerData :: SWIMUP);
	}
	else
		pData ->setiCurrentArray (PlayerData :: DIVENFIRE);

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

	if ( pData -> verticalDir.isUp())
	{
		bulletY = pData -> y - pData -> ppTextureArrays[ pData ->iCurrentArr] ->getHeight();
	}
	else if ( pData -> verticalDir.isNone())
	{
		bulletY = pData -> y - pData -> ppTextureArrays[ pData ->iCurrentArr] ->getHeight() / 2;
	}


	if(pData -> dir.isRight())
	{

		if ( pData -> verticalDir.isUp() )
		{
			angle = -M_PI_4;
		}
		else if (pData -> verticalDir.isNone()) 
		{
			angle = 0.0f;
		}
	}
	else
	{

		if ( pData -> verticalDir.isUp() )
		{
			angle = -M_PI_4 - M_PI_2;
		}
		else if (pData -> verticalDir.isNone()) 
		{
			angle = M_PI;
		}

	}


	if( !pData ->verticalDir.isDown())
		
			createBullet(bulletX, bulletY, angle );
}


void PlayerSwimmingState :: onVeticalDirectionPressed( Direction d)
{
	pData ->verticalDir = d;
	if(d.isDown())
	{
		//pData ->iCurrentArr = PlayerData :: RUNDOWN;
		transition(new PlayerDivingState(pData));
	}
	else
	{
		pData ->setiCurrentArray (PlayerData :: SWIMUP) ;
	}
}
void PlayerSwimmingState :: onVeticalDirectionReleased()
{
	pData -> verticalDir = Direction :: createNone();
	pData ->setiCurrentArray (PlayerData :: DIVE) ;
}

void PlayerSwimmingState :: onDead()
{
	transition(new PlayerDeadState(pData));
}