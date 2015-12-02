#include"EnermyScubarSoliderShootState.h"
#include"EnermyScubarSoliderHidingState.h"
#include"EnermyScubarSoliderData.h"

EnermyScubarSoliderHidingState::EnermyScubarSoliderHidingState(EnermyData *pData, bool isFirst)
 {
	this->pData = pData;
	this->pData->iCurrentArr = 0;
	iFrame = 0;
	pData->isHittable = false;

	this->isFirst = isFirst;
}

EnermyScubarSoliderHidingState::~EnermyScubarSoliderHidingState()
{

}

void EnermyScubarSoliderHidingState::onUpdate()
{
	pData->ppTextureArrays[pData->iCurrentArr]->update();
	if (isFirst == false)
	{
		if (pData->y > pData->playerY)
			iFrame++;
	}
		else
			iFrame++;
	if (iFrame == 200)
		transition(new EnermyScubarSoliderShootState(pData));
}