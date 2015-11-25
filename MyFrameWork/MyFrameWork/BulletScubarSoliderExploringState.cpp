#include"BulletScubarSoliderExploringState.h"

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
	pData->ppTextureArrays[pData->iCurrentArr]->update();
	if (pData->ppTextureArrays[pData->iCurrentArr]->isLastTexture())
	{
		pData->isDesTroyed = true;
	}
}