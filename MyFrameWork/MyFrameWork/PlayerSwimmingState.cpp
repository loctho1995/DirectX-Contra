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
			pData -> iCurrentArr = PlayerData :: DIVEDOWN;
		}
		
		else if( pData -> verticalDir.isUp())
		{
			pData -> iCurrentArr = PlayerData :: DIVEUP;
		}
		else
			pData ->iCurrentArr = PlayerData :: DIVE;
		
		pData -> vy = 0.0f;
		speed = 1;
}

void PlayerSwimmingState:: onMovePressed( Direction d )
{
		pData -> dir = d;
}

void PlayerSwimmingState :: onMoveReleased ( Direction d)
{
	transition(new PlayerDivingState(pData));
}

void PlayerSwimmingState :: onUpdate()
{
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
				pData ->iCurrentArr = PlayerData::DIVE;
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
	if(pData -> dir.isRight())
	{
		//pData ->Bullets.push_back(new RockMansBullet(pData -> ppTextureArrays[ pData ->iCurrentArr] ->getWidth() / 2 + pData -> x,  pData -> y - pData -> ppTextureArrays[ pData ->iCurrentArr] ->getHeight() / 2 , pData -> dir));
	}
	else
	{
		//pData ->Bullets.push_back(new RockMansBullet( - pData -> ppTextureArrays[ pData ->iCurrentArr] ->getWidth() / 2 + pData -> x,  pData -> y - pData -> ppTextureArrays[ pData ->iCurrentArr] ->getHeight() / 2 , pData -> dir));
	}
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
		pData ->iCurrentArr = PlayerData :: DIVEUP;
	}
}
void PlayerSwimmingState :: onVeticalDirectionReleased()
{
	pData -> verticalDir = Direction :: createNone();
	pData -> iCurrentArr = PlayerData :: DIVE;
}

void PlayerSwimmingState :: onDead()
{
	transition(new PlayerDeadState(pData));
}