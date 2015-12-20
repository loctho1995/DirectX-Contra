#include "GunBoss5BulletExploringState.h"


GunBoss5BulletExploringState::GunBoss5BulletExploringState(SpriteData * data)
{
	pData = data;
	this->pData->iCurrentArr = 1;
	Sound::getInstance()->play("qexplode", false, 1);
}


GunBoss5BulletExploringState::~GunBoss5BulletExploringState()
{
}

void GunBoss5BulletExploringState::onUpdate()
{
	pData->ppTextureArrays[pData->iCurrentArr]->update();
	if (pData->ppTextureArrays[pData->iCurrentArr]->isLastTexture())
	{
		pData->isDesTroyed = true;
	}
}