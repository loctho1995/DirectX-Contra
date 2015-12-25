#include "PlayerDeadState.h"
#include "PlayerJumpingState.h"

PlayerDeadState:: PlayerDeadState(PlayerData* data)
{
	this -> pData = data;
	pData -> isDead = true;
	speedX = 1.0f;
	pData -> vy = -4.0f;
	acceleration = 0.2f;
	pData ->setiCurrentArray(PlayerData::DEAD);
	count = 0;
	nHoldFrames = 150;
	isMoving = false;
	pData -> vx = -pData->transform(speedX);
	pData ->isHittable = false;
	pData -> hittableCounter = 0;
	pData -> isRapid = false;
	tempDir = pData -> dir;
	UIComponents::getInstance() ->descreaseLifes(pData -> index);
	Sound::getInstance() -> play("playerdie", false, 1);
	
}

void PlayerDeadState :: onUpdate()
{
	hittableCalculation();
	undyingCalculation();
	pData -> ppTextureArrays [ pData ->iCurrentArr] ->update();

	pData -> vy  += acceleration;

	pData -> x += pData -> vx;
	pData -> y += pData -> vy;

	count++;
	if(count == nHoldFrames )
	{
		if( UIComponents::getInstance()->getLifes(pData -> index) >= 1 )
		{
			pData -> reset();
			pData -> dir = tempDir;
			transition(new PlayerJumpingState(pData, isMoving, 0.0f) );
		}
		else 
		{
			pData -> isOver = true;
		}
		
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
					pData ->setiCurrentArray(PlayerData::LIE);
					

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
					pData ->setiCurrentArray(PlayerData::LIE);
					
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
	tempDir = dir;
	isMoving = true;
}
void PlayerDeadState :: onMoveReleased( Direction dir)
{
	tempDir = dir;
	isMoving = false;
}

void PlayerDeadState ::  onCameraCollision( RectF cameraRect)
{
	pData -> x = max(pData -> x, cameraRect.x + 20);
	if( pData -> y > cameraRect.y + cameraRect.height)
	{
		pData ->setiCurrentArray(PlayerData::LIE);
		pData -> y = cameraRect.y + cameraRect.height;
		pData -> vy = 0.0f;
		speedX = 0.0f;
		pData -> vx = 0.0f;
		acceleration = 0.0f;
		
	}
}

void PlayerDeadState :: onVeticalDirectionReleased()
{
	pData -> verticalDir = Direction::createNone();
}