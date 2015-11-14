#include "EnermySoldierFallingState.h"


EnermySoldierFallingState::EnermySoldierFallingState(EnermyData *pData)
{
    this->pData = pData;
    this->pData->iCurrentArr = EnermySoldierData::FALL;
    acceleration = 0.1f;
    this->pData->vx = 0;
    this->pData->vy = 1.3f;
}


EnermySoldierFallingState::~EnermySoldierFallingState()
{
}

void EnermySoldierFallingState::onUpdate()
{
    EnermyState::onUpdate();

    this->pData->y += this->pData->vy;
    this->pData->vy += acceleration;

    if (!(this->pData->cSupportRect == CollisionRectF()))
    {
        transition(new EnermySoldierRunningState(this->pData));
    }
}

void EnermySoldierFallingState::onCollision(CollisionRectF rect)
{
    if (rect.type == "water")
    {
        transition(new EnemySoldierDrowningState(this->pData));
    }
}