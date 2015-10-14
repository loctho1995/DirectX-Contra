#include "EnermyBridgeAliveState.h"


EnermyBridgeAliveState::EnermyBridgeAliveState(EnermyData *pData)
{
    this->pData = pData;
    this->pData->iCurrentArr = EnermyBridgeData::ALIVE;
    isAlloDestroy = false;
}


EnermyBridgeAliveState::~EnermyBridgeAliveState()
{
}

void EnermyBridgeAliveState::onUpdate()
{
    EnermyState::onUpdate();

    if (isAlloDestroy)
    {
        if (frameDelay > 0)
            frameDelay--;
        else
            this->pData->pState = new EnermyBridgeExplosionState(this->pData);
    }
}

void EnermyBridgeAliveState::onCollision(RectF rect)
{
    this->pData->pState = new EnermyBridgeExplosionState(pData);
}

void EnermyBridgeAliveState::onCollision(CollisionRectF rect)
{

}

void EnermyBridgeAliveState::destroy(int frameDelay)
{
    this->frameDelay = frameDelay;
    isAlloDestroy = true;
}
