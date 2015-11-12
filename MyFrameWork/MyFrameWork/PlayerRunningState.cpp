#include "PlayerRunningState.h"
#include "PlayerStandingState.h"
#include "PlayerJumpingState.h"
#include "PlayerDeadState.h"

PlayerRunningState :: PlayerRunningState(PlayerData* data)
{	
		this ->pData = data;
		if( pData -> verticalDir.isDown())
		{
			pData ->setiCurrentArray( PlayerData :: RUNDOWN);
		}
		
		else if( pData -> verticalDir.isUp())
		{
			pData ->setiCurrentArray( PlayerData :: RUNUP);
		}
		else
			pData ->setiCurrentArray( PlayerData :: RUN);
		
		pData -> vy = 0.0f;
		speed = 1;
}

void PlayerRunningState:: onMovePressed( Direction d )
{
		pData -> dir = d;
}

void PlayerRunningState :: onMoveReleased ( Direction d)
{
	transition(new PlayerStandingState(pData));
}

void PlayerRunningState :: onUpdate()
{
		hittableCalculation();
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

				pData ->setiCurrentArray(PlayerData::RUN);
			}
		}
}

void PlayerRunningState:: onJumpPressed()
{
	transition(new PlayerJumpingState(pData, true, -5.0f));
}

void PlayerRunningState :: onCollision(RectF rect )
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

void PlayerRunningState :: onCollision(CollisionRectF cRect )
{
	if( cRect.type != "throughable")
	{
		if( pData -> vx > 0 )
		{
			pData -> x -= pData -> getBody().x + pData -> getBody().width - cRect.rect.x;
			pData -> vx = 0;
		}
		else
		{
			pData -> x += cRect.rect.x + cRect.rect.width - pData->getBody().x;
			pData -> vx = 0;
		}
	}
	else
		pData -> cThroughRect.push_back(cRect);
	
}

void PlayerRunningState :: onFall()
{
	transition(new PlayerJumpingState(pData, true,0.0f));
}

void PlayerRunningState:: onFirePressed()
{
	if( pData -> verticalDir.isDown())
	{
		pData ->setiCurrentArray( PlayerData :: RUNDOWN);
	}

	else if( pData -> verticalDir.isUp())
	{
		pData ->setiCurrentArray( PlayerData :: RUNUP);
	}
	else
		pData ->setiCurrentArray( PlayerData :: RUNNFIRE);
	
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

	if( pData -> verticalDir.isDown() )
	{
		bulletY = pData -> y ;
	}
	else if ( pData -> verticalDir.isUp() )
	{
		bulletY = pData -> y - pData -> ppTextureArrays[ pData ->iCurrentArr] ->getHeight();
	}
	else
	{
		bulletY = pData -> y - pData -> ppTextureArrays[ pData ->iCurrentArr] ->getHeight() / 2 + 3;
	}


	if(pData -> dir.isRight())
	{
		if( pData -> verticalDir.isDown() )
		{
			angle = M_PI_4;
		}
		else if ( pData -> verticalDir.isUp() )
		{
			angle = -M_PI_4;
		}
		else
		{
			angle = 0.0f;
		}
	}
	else
	{
		if( pData -> verticalDir.isDown() )
		{
			angle = M_PI_4 + M_PI_2;
		}
		else if ( pData -> verticalDir.isUp() )
		{
			angle = -M_PI_4 - M_PI_2;
		}
		else
		{
			angle = M_PI;
		}

	}
	createBullet(bulletX, bulletY, angle );
}


void PlayerRunningState :: onVeticalDirectionPressed( Direction d)
{
	pData ->verticalDir = d;
	if(d.isDown())
	{
		pData ->setiCurrentArray( PlayerData :: RUNDOWN);
	}
	else
	{
		pData ->setiCurrentArray( PlayerData :: RUNUP);
	}
}
void PlayerRunningState :: onVeticalDirectionReleased()
{
	pData -> verticalDir = Direction :: createNone();
	pData ->setiCurrentArray( PlayerData :: RUN);
}

void PlayerRunningState :: onDead()
{
	transition(new PlayerDeadState(pData));
}
