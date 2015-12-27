#include "EnemySniperDeadState.h"
#include "EnemySniperData.h"


EnemySniperDeadState::EnemySniperDeadState(EnermyData* data)
{
	pData = data;
    pData->iCurrentArr = EnemySniperData::DEAD;
	pData->isHittable = false;
	pData->isThrougable = false;
}

EnemySniperDeadState::~EnemySniperDeadState(void)
{
}

void EnemySniperDeadState::onUpdate()
{
    EnermyState::onUpdate();

    if (pData->ppTextureArrays[pData->iCurrentArr]->isLastTexture())
    {
        pData->isDesTroyed = true;
    }
}