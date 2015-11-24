#include"EnermyScubarSoliderShootState.h"
#include"BulletScubarSoliderSprite.h"
#include"EnermyScubarSoliderData.h"

EnermyScubarSoliderShootState::EnermyScubarSoliderShootState(EnermyData *pData)
{
	this->pData = pData;
	iFrames = 0;
	pData->iCurrentArr = 1;
	flag = false;
}

EnermyScubarSoliderShootState::~EnermyScubarSoliderShootState()
{

}

void EnermyScubarSoliderShootState::onUpdate()
{
	
	pData->ppTextureArrays[pData->iCurrentArr]->update();
	iFrames++;

	if (iFrames ==200)
	{
		
		pData->bulletsVector.push_back(new BulletScubarSoliderSprite(pData->x+pData->body.width/3 , pData->y - pData->body.height*3/4 , 0, 0));
		pData->bulletsVector.push_back(new BulletScubarSoliderSprite(pData->x + pData->body.width / 3, pData->y - pData->body.height *3/ 4, 1, 0.06));
		pData->bulletsVector.push_back(new BulletScubarSoliderSprite(pData->x + pData->body.width / 3, pData->y - pData->body.height *3/ 4, 2, -0.06));
		pData->bulletsVector.push_back(new BulletScubarSoliderSprite(pData->x + pData->body.width / 3, pData->y - pData->body.height*3 / 4, 1, 0));
		iFrames = 0;
	}
}
