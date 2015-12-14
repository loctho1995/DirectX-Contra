#include "PlayerJumpingState.h"
#include "PlayerRunningState.h"
#include "PlayerStandingState.h"
#include "PlayerDivingState.h"
#include "PlayerSwimmingState.h"
#include "PlayerDeadState.h"

PlayerJumpingState:: PlayerJumpingState(PlayerData* data, bool isMoving, float vy)
{
	this -> pData = data;
	
	speedX = 1;
	pData -> vy = vy;
	acceleration = 0.2f;

	this-> isMoving = isMoving;
	if(vy != -0.21f && vy != 0.0f)
	{
		
		pData ->setiCurrentArray(PlayerData::JUMP);
		isJumpingPress = true;
	}
		
	else
	{
		pData ->setiCurrentArray(PlayerData::FALL);
		isJumpingPress = false;
	}
	pData ->isFiring = false;
	if(isMoving )
	tempDir = pData -> dir;
		
	
}
void PlayerJumpingState:: onMovePressed(Direction dir )
{
	pData -> dir = dir ;
	tempDir = (tempDir | dir );
	isMoving = true;
}

void PlayerJumpingState :: onMoveReleased(Direction dir )
{
	
	tempDir = tempDir ^ dir;
	if(!tempDir.isNone())
	{
		pData -> dir = tempDir;
	}
	else 
		isMoving = false;
}

void PlayerJumpingState :: onUpdate()
{

	hittableCalculation();
	undyingCalculation();
	pData -> ppTextureArrays [ pData ->iCurrentArr] ->update();


	if(isMoving)
	{
		pData -> vx = pData->transform(speedX);
	}
	else
	{
		pData -> vx = 0.0f;
	}
		pData -> vy  += acceleration;

		pData -> x += (pData -> vx + pData -> cSupportRect.vx);
		pData -> y += (pData -> vy + pData -> cSupportRect.vy);
	
	if( pData ->isFiring )
	{
		pData ->count ++;
		pData ->count %= pData ->nFiringHoldFrames;
		if(pData ->count == 0)
		{
			pData ->isFiring = false;
		}
	}


}

void PlayerJumpingState:: onCollision( RectF rect) 
{
	
	// devide into 4 case
	float vx = pData -> vx;
	float vy = pData -> vy;
	float top = pData ->getBody().y;
	float left = pData -> getBody().x;
	float right =  left + pData-> getBody().width;
	float bottom = top + pData ->getBody().height;


	float topR = rect.y;
	float leftR = rect.x;
	float rightR =  leftR + rect.width;
	float bottomR = topR + rect.height;

	if( vx > 0.0f)
	{
		if(vy > 0.0f)
		{
			float px = right - leftR;
			float py = bottom - topR;
			if( vy * px > vx * py )
			{
				// top collision
				pData -> vy = 0.0f;
				pData -> y -= py;
				

				if(isMoving)
				{
					transition(new PlayerRunningState( pData));
				}
				else
				{
					transition( new PlayerStandingState( pData));
				}
			}
			else
			{
				// side collision
				pData -> x -= px;
				pData -> vx = 0.0f;
			}
		}
		else // vy <= 0.0f
		{
			float px = right - leftR;
			float py = bottomR - top;
			if( (- vy * px ) > vx * py)
			{
				// top collision
				pData -> y += py;
				pData -> vy = 0.0f;
			}
			else
			{
				// side collision
				pData -> x -= px;
				pData -> vx = 0.0f;
			}
		}
	}
	else // vx <= 0.0f
	{
		if(vy > 0.0f)
		{
			float px = rightR - left;
			float py = bottom - topR;
			if( vy * px > (-vx * py) )
			{
				// top collision
				
				pData -> y -= py;
				pData -> vy = 0.0f;
				if(isMoving)
				{
					transition(new PlayerRunningState( pData));
				}
				else
				{
					transition( new PlayerStandingState( pData));
				}
			}
			else
			{
				// side collision
				pData -> x += px;
				pData -> vx = 0.0f;
			}
		}
		else // vy <= 0.0f
		{
			float px = rightR - left;
			float py = bottomR - top;
			if( (- vy * px ) > (-vx * py))
			{
				// top collision
				pData -> y += py;
				pData -> vy = 0.0f;
			}
			else
			{
				// side collision
				pData -> x += px;
				pData -> vx = 0.0f;
			}
		}
	}
		
}

void PlayerJumpingState:: onCollision( CollisionRectF cRect) 
{
	
	// devide into 4 case
	float vx = pData -> vx - cRect.vx;
	float vy = pData -> vy - cRect.vy;
	float top = pData ->getBody().y;
	float left = pData -> getBody().x;
	float right =  left + pData-> getBody().width;
	float bottom = top + pData ->getBody().height;


	float topR = cRect.rect.y;
	float leftR = cRect.rect.x;
	float rightR =  leftR + cRect.rect.width;
	float bottomR = topR + cRect.rect.height;
	

	
		if( vx > 0.0f)
		{
			if(vy > 0.0f)
			{
				float px = right - leftR;
				float py = bottom - topR;
				if( vy * px > vx * py )
				{
					// top collision
					pData -> vy = 0.0f;
					pData -> y -= py;

					if(cRect.type != "water")
					{
						Sound::getInstance() -> play("landing", false, 1);
						if(isMoving)
						{
							transition(new PlayerRunningState( pData));
						}
						else
						{
							transition( new PlayerStandingState( pData));
						}
					}
					else
					{
						if(isMoving)
						{
							transition( new PlayerSwimmingState( pData));
							
						}
						else
						{
							transition( new PlayerDivingState( pData));
						}
					}
				}
				else
				{
					// side collision
					if(cRect.type != "throughable")
					{
						pData -> x -= px;
						pData -> vx = 0.0f;
					}
					else
					{
						pData -> cThroughRect.push_back(cRect);
					}
					
				}
			}
			else // vy <= 0.0f
			{
				float px = right - leftR;
				float py = bottomR - top;
				if( (- vy * px ) > vx * py)
				{
					// top collision
				
					if(cRect.type != "throughable")
					{
						pData -> y += py;
						pData -> vy = 0.0f;
					}
					else
					{
						pData -> cThroughRect.push_back(cRect);
					}

				}
				else
				{
					// side collision
					if(cRect.type != "throughable")
					{
						pData -> x -= px;
						pData -> vx = 0.0f;
					}
					else
					{
						pData -> cThroughRect.push_back(cRect);
					}
				}
			}
		}
		else // vx <= 0.0f
		{
			if(vy > 0.0f)
			{
				float px = rightR - left;
				float py = bottom - topR;
				if( vy * px > (-vx * py) )
				{
					// top collision
					
					pData -> y -= py;
					pData -> vy = 0.0f;
					if(cRect.type != "water")
					{
						Sound::getInstance() -> play("landing", false, 1);
						if(isMoving)
						{
							
							transition( new PlayerRunningState( pData));
						}
						else
						{
							transition(new PlayerStandingState( pData));
						}
					}
					else
					{
						if(isMoving)
						{
							transition( new PlayerSwimmingState( pData));
							
						}
						else
						{
							transition( new PlayerDivingState( pData));
						}
						
					}
					
				}
				else
				{
					// side collision
					if(cRect.type != "throughable")
					{
						pData -> x += px;
						pData -> vx = 0.0f;
					}
					else
					{
						pData -> cThroughRect.push_back(cRect);
					}
				}
			}
			else // vy <= 0.0f
			{
				float px = rightR - left;
				float py = bottomR - top;
				if( (- vy * px ) > (-vx * py))
				{
					// top collision
					if(cRect.type != "throughable")
					{
						pData -> y += py;
						pData -> vy = 0.0f;
					}
					else
					{
						pData -> cThroughRect.push_back(cRect);
					}
				}
				else
				{
					// side collision
					if(cRect.type != "throughable")
					{
						pData -> x += px;
						pData -> vx = 0.0f;
					}
					else
					{
						pData -> cThroughRect.push_back(cRect);
					}
				}
			}
		}
	



	
		
}

void PlayerJumpingState:: onDynamicObjectCollision(CollisionRectF* cRect)
{
	// devide into 4 case
	float vx = pData -> vx - cRect -> vx;
	float vy = pData -> vy - cRect -> vy;
	float top = pData ->getBody().y;
	float left = pData -> getBody().x;
	float right =  left + pData-> getBody().width;
	float bottom = top + pData ->getBody().height;


	float topR = cRect -> rect.y;
	float leftR = cRect -> rect.x;
	float rightR =  leftR + cRect -> rect.width;
	float bottomR = topR + cRect -> rect.height;
	

	
		if( vx > 0.0f)
		{
			if(vy > 0.0f)
			{
				float px = right - leftR;
				float py = bottom - topR;
				if( vy * px > vx * py )
				{

					// top collision
					pData -> vy = 0.0f;
					pData -> y -= py;

					if(cRect->type != "water")
					{
						Sound::getInstance() -> play("landing", false, 1);
						if(isMoving)
						{
							transition(new PlayerRunningState( pData));
						}
						else
						{
							transition( new PlayerStandingState( pData));
						}
					}
					else
					{
						if(isMoving)
						{
							transition( new PlayerSwimmingState( pData));
							
						}
						else
						{
							transition( new PlayerDivingState( pData));
						}
					}
				}
				else
				{
					// side collision
					if(cRect->type != "throughable")
					{
						pData -> x -= px;
						pData -> vx = 0.0f;
					}
					else
					{
						pData ->dynamicThroughRect.push_back(cRect);
					}
					
				}
			}
			else // vy <= 0.0f
			{
				float px = right - leftR;
				float py = bottomR - top;
				if( (- vy * px ) > vx * py)
				{
					// top collision
				
					if(cRect->type != "throughable")
					{
						pData -> y += py;
						pData -> vy = 0.0f;
					}
					else
					{
						pData -> dynamicThroughRect.push_back(cRect);
					}

				}
				else
				{
					// side collision
					if(cRect->type != "throughable")
					{
						pData -> x -= px;
						pData -> vx = 0.0f;
					}
					else
					{
						pData -> dynamicThroughRect.push_back(cRect);
					}
				}
			}
		}
		else // vx <= 0.0f
		{
			if(vy > 0.0f)
			{
				float px = rightR - left;
				float py = bottom - topR;
				if( vy * px > (-vx * py) )
				{
					// top collision
					pData -> y -= py;
					pData -> vy = 0.0f;
					if(cRect->type != "water")
					{
						Sound::getInstance() -> play("landing", false, 1);
						if(isMoving)
						{
							
							transition( new PlayerRunningState( pData));
						}
						else
						{
							transition(new PlayerStandingState( pData));
						}
					}
					else
					{
						if(isMoving)
						{
							transition( new PlayerSwimmingState( pData));
							
						}
						else
						{
							transition( new PlayerDivingState( pData));
						}
						
					}
					
				}
				else
				{
					// side collision
					if(cRect->type != "throughable")
					{
						pData -> x += px;
						pData -> vx = 0.0f;
					}
					else
					{
						pData -> dynamicThroughRect.push_back(cRect);
					}
				}
			}
			else // vy <= 0.0f
			{
				float px = rightR - left;
				float py = bottomR - top;
				if( (- vy * px ) > (-vx * py))
				{
					// top collision
					if(cRect->type != "throughable")
					{
						pData -> y += py;
						pData -> vy = 0.0f;
					}
					else
					{
						pData -> dynamicThroughRect.push_back(cRect);
					}
				}
				else
				{
					// side collision
					if(cRect->type != "throughable")
					{
						pData -> x += px;
						pData -> vx = 0.0f;
					}
					else
					{
						pData -> dynamicThroughRect.push_back(cRect);
					}
				}
			}
		}
	

}


void PlayerJumpingState:: onJumpRelease()
{
	isJumpingPress = false;
}

void PlayerJumpingState:: onFirePressed()
{
	pData ->isFiring = true;
	pData ->count = 0;
	float bulletX;
	float bulletY;
	float angle;

	if( !isMoving )
	{
		bulletX = pData -> x;
	}
	else
	{
		if(pData -> dir.isRight())
		{
			bulletX = pData -> ppTextureArrays[ pData ->iCurrentArr] ->getWidth() / 2 + pData -> x;
		}
		else
		{
			bulletX = -pData -> ppTextureArrays[ pData ->iCurrentArr] ->getWidth() / 2 + pData -> x;
		
		}
	}
	
	

		if( pData -> verticalDir.isDown() )
		{
			bulletY = pData -> y ;
		}
		else if ( pData -> verticalDir.isUp())
		{
			bulletY = pData -> y - pData -> ppTextureArrays[ pData ->iCurrentArr] ->getHeight();
		}
		else
		{
			bulletY = pData -> y - pData -> ppTextureArrays[ pData ->iCurrentArr] ->getHeight() / 2;
		}

	



	if(pData -> dir.isRight())
	{
		if( pData -> verticalDir.isDown() )
		{
			if(isMoving)
			{
				angle = M_PI_4;
			}
			else
			{
				angle = M_PI_2;
			}

		}
		else if ( pData -> verticalDir.isUp() )
		{
			if(isMoving)
			{
				angle = -M_PI_4;
			}
			else
			{
				angle = -M_PI_2;
			}
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
			if(isMoving)
			{
				angle = M_PI_4 + M_PI_2;
			}
			else
			{
				angle = M_PI_2;
			}
		}
		else if ( pData -> verticalDir.isUp() )
		{
			if(isMoving)
			{
				angle = -M_PI_4 - M_PI_2;
			}
			else
			{
				angle = -M_PI_2;
			}
		}
		else
		{
			angle = M_PI;
		}

	}
	createBullet(bulletX, bulletY, angle);
	
}


void PlayerJumpingState :: onVeticalDirectionPressed( Direction d)
{
	pData ->verticalDir = d;
}
void PlayerJumpingState :: onVeticalDirectionReleased()
{
	pData -> verticalDir = Direction :: createNone();
}

void PlayerJumpingState :: onDead()
{
	transition(new PlayerDeadState(pData));
}
