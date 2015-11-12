#include "GunBoss1BulletExploringState.h"


GunBoss1BulletExploringState::GunBoss1BulletExploringState(SpriteData * data)
{
	pData = data;
	pData -> iCurrentArr = 1;

	pData -> vx = 0.0f;
	pData -> vy =  0.0f;
}


GunBoss1BulletExploringState::~GunBoss1BulletExploringState()
{

}
void GunBoss1BulletExploringState::onUpdate()
{

	pData -> ppTextureArrays[pData -> iCurrentArr ] ->update();
	if(pData -> ppTextureArrays[pData -> iCurrentArr ] -> isLastTexture())
	{
		pData -> isDesTroyed = true;
	}
}
