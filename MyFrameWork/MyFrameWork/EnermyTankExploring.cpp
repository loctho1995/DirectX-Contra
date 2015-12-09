#include"EnermyTankExploring.h"
#include"TankExploringSprite.h"

EnermyTankExploring::EnermyTankExploring(EnermyData *pData, int index)
{
	pData->iCurrentArr = 12;
	this->pData = pData;
	this->index = index;
}

EnermyTankExploring::~EnermyTankExploring()
{
	
}

void EnermyTankExploring::onUpdate()
{
	pData->bulletsVector.push_back(new TankExploringSprite(pData->x - pData->body.width / 4, pData->y - pData->body.height / 2));
	pData->bulletsVector.push_back(new TankExploringSprite(pData->x, pData->y - pData->body.height / 2));
	pData->bulletsVector.push_back(new TankExploringSprite(pData->x + pData->body.width * 1 / 4, pData->y - pData->body.height / 2));
	pData->bulletsVector.push_back(new TankExploringSprite(pData->x - pData->body.width / 4, pData->y));
	pData->bulletsVector.push_back(new TankExploringSprite(pData->x, pData->y ));
	pData->bulletsVector.push_back(new TankExploringSprite(pData->x + pData->body.width * 1 / 4, pData->y));

	pData->ppTextureArrays[pData->iCurrentArr]->update();
	pData->isDesTroyed = true;
}
