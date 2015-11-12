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
        this->pData->pState = new EnermySoldierRunningState(this->pData);
    }
}

void EnermySoldierFallingState::onCollision(CollisionRectF rect)
{

}

void EnermySoldierFallingState::onCameraCollision(RectF camera)
{
    if (this->pData->y >= (camera.y + camera.height))
    {
        this->pData->isDesTroyed = true;
    }
}
