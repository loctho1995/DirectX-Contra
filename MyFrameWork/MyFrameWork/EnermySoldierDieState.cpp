#include "EnermySoldierDieState.h"


EnermySoldierDieState::EnermySoldierDieState(EnermyData *pData)
{
    this->pData = pData;
    this->pData->iCurrentArr = EnermySoldierData::DIE;

    this->pData->vx = 0;
    this->pData->vy = -3.0f;

    acceleration = 0.1f;
}


EnermySoldierDieState::~EnermySoldierDieState()
{
}

void EnermySoldierDieState::onUpdate()
{
    EnermyState::onUpdate();

    this->pData->y += this->pData->vy;
    this->pData->vy += acceleration;

    if (this->pData->vy >= 0)
    {
        //destroy: run animation destroy
        this->pData->pState = new EnermySoldierDestroyState(this->pData);
    }
}

void EnermySoldierDieState::onCollision(RectF rect)
{

}

void EnermySoldierDieState::onCollision(CollisionRectF rect)
{

}