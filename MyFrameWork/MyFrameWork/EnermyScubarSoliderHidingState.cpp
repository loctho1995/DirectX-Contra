#include"EnermyScubarSoliderShootState.h"
#include"EnermyScubarSoliderHidingState.h"
#include"EnermyScubarSoliderData.h"

EnermyScubarSoliderHidingState::EnermyScubarSoliderHidingState(EnermyData *pData)
 {
	this->pData = pData;
	this->pData->iCurrentArr = 0;
	iFrame = 0;
	pData->isHittable = false;
}

EnermyScubarSoliderHidingState::~EnermyScubarSoliderHidingState()
{

}

void EnermyScubarSoliderHidingState::onUpdate()
{
	pData->ppTextureArrays[pData->iCurrentArr]->update();
	if (pData->y > pData->playerY)
	iFrame++;
	if (iFrame == 200)
		transition(new EnermyScubarSoliderShootState(pData));
}