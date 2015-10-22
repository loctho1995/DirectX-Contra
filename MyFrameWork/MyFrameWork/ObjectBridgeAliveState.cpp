#include "ObjectBridgeAliveState.h"


ObjectBridgeAliveState::ObjectBridgeAliveState(ObjectData *pData)
{
    this->pData = pData;
    this->pData->iCurrentArr = ObjectBridgeData::ALIVE;
    isAlloDestroy = false;
}


ObjectBridgeAliveState::~ObjectBridgeAliveState()
{
}

void ObjectBridgeAliveState::onUpdate()
{
    ObjectState::onUpdate();

    if (isAlloDestroy)
    {
        if (frameDelay > 0)
            frameDelay--;
        else
            this->pData->pState = new ObjectBridgeExplosionState(this->pData);
    }
}

void ObjectBridgeAliveState::onCollision(RectF rect)
{
    this->pData->pState = new ObjectBridgeExplosionState(pData);
}

void ObjectBridgeAliveState::onCollision(CollisionRectF rect)
{

}

void ObjectBridgeAliveState::destroy(int frameDelay)
{
    this->frameDelay = frameDelay;
    isAlloDestroy = true;
}
