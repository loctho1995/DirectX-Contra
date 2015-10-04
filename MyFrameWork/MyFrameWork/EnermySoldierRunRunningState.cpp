#include "EnermySoldierRunRunningState.h"
#include "EnermySoldierRunData.h"

EnermySoldierRunRunningState::EnermySoldierRunRunningState(EnermyData *pData)
{
    this->pData = pData;
    this->pData->iCurrentArr = EnermySoldierRunData::RUN;
    this->pData->vx = -1.1f;
}


EnermySoldierRunRunningState::~EnermySoldierRunRunningState()
{
}

void EnermySoldierRunRunningState::onUpdate()
{
    EnermyState::onUpdate();

    pData->x += pData->vx;
    pData->y += pData->vy;
}

void EnermySoldierRunRunningState::onCollision()
{

}