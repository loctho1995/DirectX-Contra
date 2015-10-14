#include "EnermySoldierRunningState.h"
#include "EnermySoldierData.h"

EnermySoldierRunningState::EnermySoldierRunningState(EnermyData *pData)
{
    this->pData = pData;
    this->pData->iCurrentArr = EnermySoldierData::RUN;
    this->pData->vx = 1.0f;
    this->pData->vy = 0.0f;
}


EnermySoldierRunningState::~EnermySoldierRunningState()
{

}

void EnermySoldierRunningState::onUpdate()
{
    EnermyState::onUpdate();

    if (pData->dir.isLeft())
    {
        pData->x -= pData->vx;
    }
    else if (pData->dir.isRight())
    {
        pData->x += pData->vx;
    }

    pData->y += pData->vy;
}

void EnermySoldierRunningState::onCollision(RectF rect)
{
    if (abs(this->pData->x - rect.x) <= SOLDIER_RANGE_TO_JUMP)
    {
        this->pData->pState = new EnermySoldierJumpingState(this->pData);
    }
}

void EnermySoldierRunningState::onCollision(CollisionRectF rect)
{

}