#include "PlayerStandingState.h"
#include "PlayerJumpingState.h"
#include "PlayerRunningState.h"
#include "PlayerDeadState.h"

PlayerStandingState :: PlayerStandingState(PlayerData* data)
{
		this->pData = data;
		if( pData -> verticalDir.isDown())
		{
			pData -> iCurrentArr = PlayerData :: STANDDOWN;
		}
		
		else if( pData -> verticalDir.isUp())
		{
			pData -> iCurrentArr = PlayerData :: STANDUP;
		}
		else
			pData -> iCurrentArr = PlayerData :: STAND;
		pData -> vy = 0.0f;

		
		
}

void PlayerStandingState::onMovePressed(Direction d)
{
	pData -> dir = d;
	transition(new PlayerRunningState(pData));
}

void PlayerStandingState:: onJumpPressed()
{
	if(!pData -> verticalDir.isDown() || pData ->cSupportRect.type != "throughable")
	{
		transition(new PlayerJumpingState(pData));
	}
	else
	{
		pData ->cThroughRect.push_back( pData ->cSupportRect );
		pData -> y += 1;
		//pData -> ly += 1;
		transition( new PlayerJumpingState(pData, false, 0.0f));
	}
	
}

void PlayerStandingState:: onUpdate()
{
	pData -> ppTextureArrays[ pData ->iCurrentArr ] -> update();
	if( pData ->isFiring )
	{
		pData ->count ++;
		pData ->count %= pData ->nFiringHoldFrames;
		if(pData ->count == 0)
		{
			pData ->isFiring = false;
			pData ->iCurrentArr = PlayerData::STAND;
		}
	}
}
void PlayerStandingState:: onFirePressed()
{
	if( pData -> verticalDir.isDown())
	{
		pData -> iCurrentArr = PlayerData :: STANDDOWN;
	}

	else if( pData -> verticalDir.isUp())
	{
		pData -> iCurrentArr = PlayerData :: STANDUPNFIRE;
	}
	else
		pData ->iCurrentArr = PlayerData::STANDNFIRE;
	
	pData ->isFiring = true;
	pData ->count = 0;
	if(pData -> dir.isRight())
	{
		pData ->Bullets.push_back(new RockMansBullet(pData -> ppTextureArrays[ pData ->iCurrentArr] ->getWidth() / 2 + pData -> x,  pData -> y - pData -> ppTextureArrays[ pData ->iCurrentArr] ->getHeight() / 2 , pData -> dir));
	}
	else
	{
		pData ->Bullets.push_back(new RockMansBullet( - pData -> ppTextureArrays[ pData ->iCurrentArr] ->getWidth() / 2 + pData -> x,  pData -> y - pData -> ppTextureArrays[ pData ->iCurrentArr] ->getHeight() / 2 , pData -> dir));
	}
}

void PlayerStandingState :: onVeticalDirectionPressed(Direction d)
{
	pData ->verticalDir = d;
	if(d.isDown())
	{
		pData ->iCurrentArr = PlayerData ::STANDDOWN;
	}
	else
	{
		pData ->iCurrentArr = PlayerData :: STANDUP;
	}
}

void PlayerStandingState :: onVeticalDirectionReleased()
{
	pData ->verticalDir = Direction::createNone();
	pData ->iCurrentArr = pData ->STAND;
}
void PlayerStandingState :: onDead()
{
	transition(new PlayerDeadState(pData));
}