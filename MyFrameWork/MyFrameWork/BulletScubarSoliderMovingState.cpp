#include"BulletScubarSoliderMovingState.h"
#include"BulletScubarSoliderExploringState.h"

BulletScubarSoliderMovingState::BulletScubarSoliderMovingState(SpriteData *data, float vx,int index, int kindScubar)
{
	pData = data;
	pData->iCurrentArr = 0;
	pData->vx = vx;
	
	if (kindScubar == 2)
		pData->vy = BULLETVYJUMP2;
	else
		pData->vy = BULLETVYJUMP13;

	this->index = index;
	
	this->kindScubar = kindScubar;
	dem = 0;
	flag == false;
}

void BulletScubarSoliderMovingState:: Jumping(bool kind)
{
	pData->vy += BULLETGRAVITY*GAMETIME; // v = v0 + at

	pData->y += pData->vy*GAMETIME; // s = s0+vt

	if (kind == true)
	{
		if (  pData->vy +0.3 > 0)
		{
			// tao no
			if (index == 1 || index == 3)
				pData->y += 0.3;
			pData->x -= pData->vx*GAMETIME;
		}
	}

	if (kind == false)
	{

		if (pData->vy + 0.3> 0)
		{
			onDead(1);
		}
	}
}

void BulletScubarSoliderMovingState::onUpdate()
{
	if (index == 1 || index ==2 ||index ==3)
	{
		Jumping(true);
	}
	if (index == 0)
	{
		Jumping(false);
	}
}

void BulletScubarSoliderMovingState::onCollision(CollisionRectF cRect)
{

	/* if (pData->vy > 0)
	 {
	 pData->vy = 0;
	 onDead(2);

	 }*/
	// devide into 4 case 
	float vx = pData->vx - cRect.vx;
	float vy = pData->vy - cRect.vy;
	float top = pData->getBody().y;
	float left = pData-> getBody().x;
	float right = left + pData->body.width;
	float bottom = top + pData->body.height;


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
				//pData->vy = 0.15;
				//pData->y -= py;

				if (cRect.type == "throughable")
				{
					if (pData->cThroughRect.size() == 0)
					{					
						if (kindScubar == 1)
						{
							if (index == 2 || index == 3)
								pData->cThroughRect.push_back(cRect);
							else
								if (index == 1)
									onDead(2);
						}

						if (kindScubar == 2)
						{
							if (index == 2 )
								onDead(2);
							else
								if (index == 1 || index == 3)
									pData->cThroughRect.push_back(cRect);
						}

						if (kindScubar == 3)
						{
							onDead(2);
						}

					}
					else
					{
						onDead(2);
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
			if (vy * px >= (-vx * py))
			{
				// top collisi
				//pData->vy = 0.15f; // dong nay co van de a 
				//pData->y -= py;

				if (cRect.type == "throughable")
				{
					if (pData->cThroughRect.size() == 0)
					{
						if (kindScubar == 1)
						{
							if (index == 2 || index == 3)
								pData->cThroughRect.push_back(cRect);
							else
								if (index == 1)
									onDead(2);
						}

						if (kindScubar == 2)
						{
							if (index == 2)
							{
								std::cout << kindScubar << index;
								onDead(2);
							}
								
							else
								if (index == 1 || index == 3)
									pData->cThroughRect.push_back(cRect);
						}

						if (kindScubar == 3)
						{
							onDead(2);
						}

					}
					else if (pData->cThroughRect.size() >= 0)
					{
						onDead(2);
					}
				}
				else if (cRect.type == "nonthroughable")
				{
					onDead(2);
				}

			}
		}
	}
}

void BulletScubarSoliderMovingState::onDead(int index)
{
	pData->body.width *= 4; // thay doi body de khoang no Player cham cung chet
	pData->body.height *= 4;
	pData->body.x = -pData->body.width / 2;
	pData->body.y = -pData->body.height / 2;
	
	transition(new BulletScubarSoliderExploringState(pData, index));
}