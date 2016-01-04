#include "EnemySniperDyingState.h"


EnemySniperDyingState::EnemySniperDyingState(EnermyData* pData)
{
    this->pData = pData;
    this->pData->iCurrentArr = EnemySniperData::DYING;
	this->pData->isHittable = false;
    pData->vy = -2.7f;
    acc = 0.2f;
}


EnemySniperDyingState::~EnemySniperDyingState()
{
}

void EnemySniperDyingState::onUpdate()
{
    pData->vy += acc;
    pData->y += pData->vy;

    if (pData->vy >= 0)
    {
        this->pData->pState = new EnemySniperDeadState(this->pData);
    }
}
