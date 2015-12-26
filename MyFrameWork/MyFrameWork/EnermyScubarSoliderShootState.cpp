#include"EnermyScubarSoliderShootState.h"
#include"BulletScubarSoliderSprite.h"
#include"EnermyScubarSoliderData.h"
#include"EnermyScubarSoliderHidingState.h"
#include"EnermyScubarSoliderDeadState.h"

EnermyScubarSoliderShootState::EnermyScubarSoliderShootState(EnermyData *pData)
{
	this->pData = pData;
	iFrames = 0;
	pData->iCurrentArr = 1;
	flag = false;
	pData->isHittable = true;
}

EnermyScubarSoliderShootState::~EnermyScubarSoliderShootState()
{

}

void EnermyScubarSoliderShootState::onUpdate()
{

	pData->ppTextureArrays[pData->iCurrentArr]->update();
	iFrames++;

	if (iFrames == 20)
	{

		pData->bulletsVector.push_back(new BulletScubarSoliderSprite(pData->x + pData->body.width / 3, pData->y - pData->body.height * 3 / 4, 0, 0, pData->stage));
		pData->bulletsVector.push_back(new BulletScubarSoliderSprite(pData->x + pData->body.width / 3, pData->y - pData->body.height * 3 / 4, 3, 0.08, pData->stage));
		pData->bulletsVector.push_back(new BulletScubarSoliderSprite(pData->x + pData->body.width / 3, pData->y - pData->body.height * 3 / 4, 1, -0.08, pData->stage));
		pData->bulletsVector.push_back(new BulletScubarSoliderSprite(pData->x + pData->body.width / 3, pData->y - pData->body.height * 3 / 4, 2, 0, pData->stage));

		transition(new EnermyScubarSoliderHidingState(pData, true));
	}
}

void EnermyScubarSoliderShootState::onDead()
{
	transition(new EnermyScubarSoliderDeadState(pData));
}