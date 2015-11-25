#include "ShipBoss5ExploringState.h"


ShipBoss5ExploringState::ShipBoss5ExploringState(SpriteData * data)
{
	this->pData = data;
	this->pData->iCurrentArr = 1;
}


ShipBoss5ExploringState::~ShipBoss5ExploringState()
{
}

void ShipBoss5ExploringState::onUpdate()
{
	pData->ppTextureArrays[pData->iCurrentArr]->update();
	if (pData->ppTextureArrays[pData->iCurrentArr]->isLastTexture())
	{
		pData->isDesTroyed = true;
	}
}