#include"TankExploringState.h"

TankExploringState::TankExploringState(SpriteData * data)
{
	pData = data;

	pData->vx = 0.0f;
	pData->vy = 0.0f;
	pData->iCurrentArr = 0;
}
TankExploringState::~TankExploringState()
{

}
void TankExploringState::onUpdate()
{
	pData->ppTextureArrays[pData->iCurrentArr]->update();
	if (pData->ppTextureArrays[pData->iCurrentArr]->isLastTexture())
	{
		pData->isDesTroyed = true;
	}
}