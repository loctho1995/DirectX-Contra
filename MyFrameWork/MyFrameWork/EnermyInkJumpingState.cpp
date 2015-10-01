#include "EnermyInkJumpingState.h"
#include "EnermyInkStandingState.h"

EnermyInkJumpingState::EnermyInkJumpingState(EnermyData* pData)
{
	this -> pData = pData;
	this -> pData -> iCurrentArr = 1;
	nJumpingFrames = 40;

	acceleration = 0.7;

	pData -> vy = (pData -> playerY - pData ->y - 0.5 * acceleration * nJumpingFrames * nJumpingFrames ) / nJumpingFrames;



	if(pData -> x > pData ->playerX )
	{
		pData -> dir = Direction::createLeft();
		pData -> vx = pData ->transform( pData -> x - pData ->playerX ) / nJumpingFrames;
	}
	else
	{
		pData -> dir = Direction::createRight();
		pData -> vx = pData ->transform( pData ->playerX - pData -> x ) / nJumpingFrames;
	}
}
void EnermyInkJumpingState:: onUpdate()
{
	pData ->ppTextureArrays[ pData ->iCurrentArr ] ->update();
	pData -> x += pData	 -> vx;
	pData -> y += pData -> vy;
	pData -> vy += acceleration;
}


void EnermyInkJumpingState::onCollision(RectF rect)
{
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
				
				transition(new EnermyInkStandingState( pData ));

			}
			else
			{
				// side collision
				pData -> x -= px;
				//pData -> vx = 0.0f;
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
				//pData -> vx = 0.0f;
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

				transition(new EnermyInkStandingState( pData ));
			}
			else
			{
				// side collision
				pData -> x += px;
				//pData -> vx = 0.0f;
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
				//pData -> vx = 0.0f;
			}
		}
	}
}