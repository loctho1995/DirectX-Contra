#include"EnermyTankExploring.h"
#include"TankExploringSprite.h"

EnermyTankExploring::EnermyTankExploring(EnermyData *pData, int index)
{
	pData->iCurrentArr = 16;
	this->pData = pData;
	this->index = index;
	pData->vx = pData->vy = 0.0f;
	Sound::getInstance()->play("exbullet", false, 1);
}

EnermyTankExploring::~EnermyTankExploring()
{

}

void EnermyTankExploring::onUpdate()
{
	pData->bulletsVector.push_back(new TankExploringSprite(pData->x - pData->body.width / 4 + pData->body.width * 2 / 10, pData->y - pData->body.height / 2));
	pData->bulletsVector.push_back(new TankExploringSprite(pData->x + pData->body.width * 2 / 10, pData->y - pData->body.height / 2));
	pData->bulletsVector.push_back(new TankExploringSprite(pData->x + pData->body.width * 1 / 4 + pData->body.width * 2 / 10, pData->y - pData->body.height / 2));
	pData->bulletsVector.push_back(new TankExploringSprite(pData->x - pData->body.width / 4 + pData->body.width * 2 / 10, pData->y));
	pData->bulletsVector.push_back(new TankExploringSprite(pData->x + pData->body.width * 2 / 10, pData->y));
	pData->bulletsVector.push_back(new TankExploringSprite(pData->x + pData->body.width * 1 / 4 + pData->body.width * 2 / 10, pData->y));

	//pData->ppTextureArrays[pData->iCurrentArr]->update();
	pData->isDesTroyed = true;
}
