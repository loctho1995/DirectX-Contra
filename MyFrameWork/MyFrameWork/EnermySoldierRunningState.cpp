#include "EnermySoldierRunningState.h"
#include "EnermySoldierData.h"

EnermySoldierRunningState::EnermySoldierRunningState(EnermyData *pData)
{
    this->pData = pData;
    this->pData->iCurrentArr = EnermySoldierData::RUN;
    this->pData->vx = -1.1f;
}


EnermySoldierRunningState::~EnermySoldierRunningState()
{
}

void EnermySoldierRunningState::onUpdate()
{
    EnermyState::onUpdate();

    pData->x += pData->vx;
    pData->y += pData->vy;
}

void EnermySoldierRunningState::onCollision()
{

}