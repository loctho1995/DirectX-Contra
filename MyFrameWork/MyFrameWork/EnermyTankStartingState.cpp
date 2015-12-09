#include"EnermyTankShootingState.h"
#include"EnermyTankStartingState.h"
#include"EnermyTankExploring.h"

EnermyTankStartingState::EnermyTankStartingState(EnermyData *pData, int index, int s)
{
	this->pData = pData;
	this->pData->iCurrentArr = index;
	iFrames = 0;
	this->s = s;
	s0 = 0;
}

EnermyTankStartingState::~EnermyTankStartingState()
{

}

void EnermyTankStartingState::onUpdate()
{
	pData->ppTextureArrays[pData->iCurrentArr]->update();
	iFrames++;
	if (iFrames == 10)
	{
		pData->x -= 4;
		s0 += 2;
		if (s0 < s)
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
			iFrames = 0;
		}
		else
			iFrames = 70;
	}
		
			if (iFrames ==70)
		{
			transition(new EnermyTankShootingState(pData, pData->iCurrentArr));
		}

}