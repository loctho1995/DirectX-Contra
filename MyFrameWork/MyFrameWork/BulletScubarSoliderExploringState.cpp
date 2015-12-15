#include"BulletScubarSoliderExploringState.h"
#include"Sound.h"

BulletScubarSoliderExploringState::BulletScubarSoliderExploringState(SpriteData * data, int index)
{
	pData = data;
	pData->iCurrentArr = index;

	pData->vx = 0.0f;
	pData->vy = 0.0f;
}
BulletScubarSoliderExploringState::~BulletScubarSoliderExploringState()
{

}
void BulletScubarSoliderExploringState::onUpdate()
{
	Sound::getInstance()->play("exbullet", false, 1);
	pData->ppTextureArrays[pData->iCurrentArr]->update();
	if (pData->ppTextureArrays[pData->iCurrentArr]->isLastTexture())
	{
		pData->isDesTroyed = true;
	}
}
void BulletScubarSoliderExploringState::onCollision(CollisionRectF cRect)
{
	
}