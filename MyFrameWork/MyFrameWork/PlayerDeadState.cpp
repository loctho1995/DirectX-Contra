#include "PlayerDeadState.h"
#include "PlayerJumpingState.h"

PlayerDeadState:: PlayerDeadState(PlayerData* data)
{
	this -> pData = data;
	
	speedX = 1.0f;
	pData -> vy = -4.0f;
	acceleration = 0.2f;
	pData -> iCurrentArr  =  PlayerData :: DEAD;
	count = 0;
	nHoldFrames = 150;
	isMoving = false;
	pData -> vx = -pData->transform(speedX);
	
}

void PlayerDeadState :: onUpdate()
{
	pData -> ppTextureArrays [ pData ->iCurrentArr] ->update();

	pData -> vy  += acceleration;

	pData -> x += pData -> vx;
	pData -> y += pData -> vy;

	count++;
	if(count == nHoldFrames)
	{
		pData -> x = pData -> cameraRect.x + 20;
		pData -> y = pData -> cameraRect.y + 50;
		transition(new PlayerJumpingState(pData, isMoving, 0.0f) );
	}

}

void PlayerDeadState:: onCollision( CollisionRectF cRect) 
{
	
	// devide into 4 case
	float vx = pData -> vx;
	float vy = pData -> vy;
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
					pData -> vx = 0.0f;
					speedX = 0.0f;
					acceleration = 0.0f;
					pData ->iCurrentArr = PlayerData::LIE;
					

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
					pData -> vx = 0.0f;
					speedX = 0.0f;
					acceleration = 0.0f;
					pData ->iCurrentArr = PlayerData::LIE;
					
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

void PlayerDeadState :: onMovePressed(Direction dir)
{
	pData ->dir = dir;
	isMoving = true;
}
void PlayerDeadState :: onMoveReleased( Direction dir)
{
	pData ->dir = dir;
	isMoving = false;
}

void PlayerDeadState ::  onCameraCollision( RectF cameraRect)
{
	pData -> x = max(pData -> x, cameraRect.x + 20);
	if( pData -> y >= cameraRect.y + cameraRect.height)
	{
		pData -> y = cameraRect.y + cameraRect.height;
		pData -> vy = 0.0f;
		speedX = 0.0f;
		pData -> vx = 0.0f;
		acceleration = 0.0f;
		pData ->iCurrentArr = PlayerData::LIE;
	}
}