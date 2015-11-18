#include "PlayerClimbingState.h"
#include "PlayerRunningState.h"
#include "PlayerStandingState.h"
#include "PlayerDeadState.h"

PlayerClimbingState :: PlayerClimbingState(PlayerData* data, bool isMoving )
{
	this->pData = data;
	pData ->setiCurrentArray( PlayerData :: CLIMP);
	pData -> vy = 0.0f;
	count = 0;
	nHoldFrames = 10;
	this -> isMoving = isMoving;
}

void PlayerClimbingState :: onUpdate()
{
	hittableCalculation();
	undyingCalculation();
	count ++;
	if( count == nHoldFrames )
	{
		if(isMoving)
		{
			transition(new PlayerRunningState(pData ));
		}
		else 
		{
			transition(new PlayerStandingState(pData ));
		}
	}
	
}
//virtual void onCollision(RectF rect) {}
void PlayerClimbingState :: onVeticalDirectionPressed( Direction dir)
{
	pData -> verticalDir = dir;
}
void PlayerClimbingState :: onVeticalDirectionReleased()
{
	pData -> verticalDir = Direction::createNone();
}


void PlayerClimbingState :: onMovePressed(Direction d)
{
	pData ->dir = d;
	isMoving = true;
}
void PlayerClimbingState :: onMoveReleased(Direction d)
{
	pData ->dir = d;
	isMoving = false;
}
void PlayerClimbingState :: onDead()
{
	transition(new PlayerDeadState(pData));
}