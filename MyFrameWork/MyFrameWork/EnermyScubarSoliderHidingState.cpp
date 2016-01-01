#include"EnermyScubarSoliderShootState.h"
#include"EnermyScubarSoliderHidingState.h"
#include"EnermyScubarSoliderData.h"
#include"EnermyScubarSoliderDeadState.h"

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
	switch (this->pData->getPlayerIndexToExcute())
	{
	case 1:
		directPlayerY = this->pData->playerY;
		break;
	case 2:
		directPlayerY = this->pData->player2Y;
		break;
	default:
		break;
	}

	pData->ppTextureArrays[pData->iCurrentArr]->update();
	if (isFirst == false)
	{
		if (pData->y > directPlayerY)
			iFrame++;
	}
	else
		iFrame++;
	if (iFrame == 200)
		transition(new EnermyScubarSoliderShootState(pData));
}

void EnermyScubarSoliderHidingState::onDead()
{
	transition(new EnermyScubarSoliderDeadState(pData));
}