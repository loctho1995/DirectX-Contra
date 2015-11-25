#include"EnermyScubarSoliderShootState.h"
#include"EnermyScubarSoliderHidingState.h"
#include"EnermyScubarSoliderData.h"

EnermyScubarSoliderHidingState::EnermyScubarSoliderHidingState(EnermyData *pData)
 {
	this->pData = pData;
	this->pData->iCurrentArr = 0;
	iFrame = 0;
}

EnermyScubarSoliderHidingState::~EnermyScubarSoliderHidingState()
{

}

void EnermyScubarSoliderHidingState::onUpdate()
{
	pData->ppTextureArrays[pData->iCurrentArr]->update();
	iFrame++;
	if (iFrame == 30)
		transition(new EnermyScubarSoliderShootState(pData));
}