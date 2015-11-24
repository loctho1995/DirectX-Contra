#include"BulletScubarSoliderMovingState.h"
#include"BulletScubarSoliderExploringState.h"

BulletScubarSoliderMovingState::BulletScubarSoliderMovingState(SpriteData *data, float vx,int index)
{
	pData = data;
	pData->iCurrentArr = 0;
	pData->vx = vx;
	
	pData->vy = BULLETVYJUMP;
	this->index = index;
}

void BulletScubarSoliderMovingState:: Jumping(bool kind)
{
	pData->vy += BULLETGRAVITY*GAMETIME; // v = v0 + at
	
		pData->y += pData->vy*GAMETIME; // s = s0+vt

		if (kind == true)
		{
			if (pData->vy + 0.3 > 0)
			{
				// tao no
				pData->x += pData->vx*GAMETIME;
			}
		}

		if (kind == false)
		{
			if (pData->vy +0.3> 0)
			{
				onDead(1);
			}
		}
	
}

void BulletScubarSoliderMovingState::onUpdate()
{
	if (index == 1 ||index ==2)
	{
		Jumping(true);
	}
	if (index == 0)
		Jumping(false);
}

void BulletScubarSoliderMovingState::onCollision(CollisionRectF cRect)
{
	// devide into 4 case
	float vx = pData->vx - cRect.vx;
	float vy = pData->vy - cRect.vy;
	float top = pData->getBody().y;
	float left = pData->getBody().x;
	float right = left + pData->getBody().width;
	float bottom = top + pData->getBody().height;


	float topR = cRect.rect.y;
	float leftR = cRect.rect.x;
	float rightR = leftR + cRect.rect.width;
	float bottomR = topR + cRect.rect.height;



	if (vx > 0.0f)
	{
		if (vy > 0.0f)
		{
			float px = right - leftR;
			float py = bottom - topR;
			if (vy * px > vx * py)
			{
				// top collision
				pData->vy = 0.0f;
				pData->y -= py;

				if (cRect.type == "throughable")
				{
					if (pData->cThroughRect.size() == 0)
					{
						//pData->cThroughRect.push_back(cRect);
						onDead(2);
					}
					else
					{				
						//onDead(2);
					}
				}
				else if (cRect.type == "nonthroughable")
				{
					onDead(2);
				}
			}
			
		}
			
	}
	else // vx <= 0.0f
	{
		if (vy > 0.0f)
		{
			float px = rightR - left;
			float py = bottom - topR;
			if (vy * px > (-vx * py))
			{
				// top collisi
				pData->y -= py;
				pData->vy = 0.0f;
				if (cRect.type == "throughable")
				{
					if (pData->cThroughRect.size() == 0)
					{
						//pData->cThroughRect.push_back(cRect);
						onDead(2);
					}
					else
					{
						//onDead(2);
					}
				}
				else if (cRect.type == "nonthroughable")
				{
					onDead(2);
				}

			}
				
		}
		else // vy <= 0.0f
		{
			
		}
	}
}

void BulletScubarSoliderMovingState::onDead(int index)
{
	transition(new BulletScubarSoliderExploringState(pData, index));
}