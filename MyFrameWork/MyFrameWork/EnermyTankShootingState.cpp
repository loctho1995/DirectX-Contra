#include"EnermyTankShootingState.h"
#include"EnermyTankStartingState.h"
#include"EnermyWhiteBullet.h"
#include"EnermyTankExploring.h"

EnermyTankShootingState::EnermyTankShootingState(EnermyData *pData, int index)
{
	this->pData = pData;
	iFrames = 0;
	this->index = index;
	count = 0;
	iLastIndex = -1;
}

EnermyTankShootingState::~EnermyTankShootingState()
{

}

 void EnermyTankShootingState::onUpdate()
{
	bool flag = false;
	
	iFrames++;

	
	if (iFrames == 10)  
	{
		if (pData->HP >30)
			pData->iCurrentArr = 0;
		else
			if (pData->HP > 20)
				pData->iCurrentArr = 3;
			else
				if (pData->HP > 10)
					pData->iCurrentArr = 6;
				else
					if (pData->HP > 0)
						pData->iCurrentArr = 9;

		

			if (pData->playerY <= 165 - 16)
			{
				pData->iCurrentArr = index;
			}
				
			else
				if (pData->playerY >= 165 && pData->playerX >2410 )
				{
					pData->iCurrentArr = index + 2;
				}
					
				else
				{
					pData->iCurrentArr = index + 1;
				}	

			iLastIndex = pData->iCurrentArr % 3;
		}
	
	pData->ppTextureArrays[pData->iCurrentArr]->update();


	if (iFrames == 30)
	{
			if (iLastIndex == 0)
			{
				pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x - pData->body.width * 1 / 10, pData->y - pData->body.height + pData->body.height*3/20 , true, PI, 1));

			}

			if (iLastIndex == 1)
			{
				pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x - pData->body.width * 1 / 10 + 5, pData->y - pData->body.height + 20, true, PI - PI / 6, 1));

			}

			if (iLastIndex == 2)
			{
				pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x - pData->body.width * 1 / 10 + 9, pData->y - pData->body.height + 27, true, PI - PI / 3, 1));
			}


			pData->ppTextureArrays[pData->iCurrentArr]->update();

		count++;
		
	}
	if (iFrames == 50)
	{
			if (iLastIndex == 0)
			{
				pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x - pData->body.width * 1 / 10, pData->y - pData->body.height + pData->body.height * 3 / 20, true, PI, 1));

			}

			if (iLastIndex == 1)
			{
				pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x - pData->body.width * 1 / 10 + 5, pData->y - pData->body.height + 20, true, PI - PI / 6, 1));

			}

			if (iLastIndex == 2)
			{
				pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x - pData->body.width * 1 / 10 + 9, pData->y - pData->body.height + 27, true, PI - PI / 3, 1));
			}

			pData->ppTextureArrays[pData->iCurrentArr]->update();
			count++;
	}
  	if (iFrames == 70)
	{
			if (iLastIndex == 0)
			{
				pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x - pData->body.width * 1 / 10, pData->y - pData->body.height + pData->body.height * 3 / 20, true, PI, 1));
			
			}

			if (iLastIndex == 1)
			{
				pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x - pData->body.width * 1 / 10 + 5, pData->y - pData->body.height + 20, true, PI - PI / 6,1));
				
			}

			if (iLastIndex == 2)
			{
				pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x - pData->body.width * 1 / 10 + 9, pData->y - pData->body.height + 27, true, PI - PI / 3,1));
			}

			pData->ppTextureArrays[pData->iCurrentArr]->update();
			count++;
	}
	
	if (iFrames == 100)
	{
		iFrames = 0;
	}

	

	if (pData->HP <= 0)
		transition(new EnermyTankExploring(pData, index));

	if (count == 15)
		transition(new EnermyTankStartingState(pData, pData->iCurrentArr,100));
}


