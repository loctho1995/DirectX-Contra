#include "EnermySoldierJumpingState.h"


EnermySoldierJumpingState::EnermySoldierJumpingState(EnermyData *pData)
{
    this->pData = pData;
    this->pData->iCurrentArr = EnermySoldierData::JUMP;
    acceleration = 0.2f;
    pData->vy = -4.2f;
    pData->vx = 1.3f;
}


EnermySoldierJumpingState::~EnermySoldierJumpingState()
{
}


void EnermySoldierJumpingState::onUpdate()
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
    pData->vy += acceleration;
}

void EnermySoldierJumpingState::onCollision(RectF rect)
{
    if (pData->vy > 0)
    {
        pData->pState = new EnermySoldierRunningState(pData);
    }
}

void EnermySoldierJumpingState::onCollision(CollisionRectF rect)
{

}