#include "ObjectBridgeExplosionState.h"


ObjectBridgeExplosionState::ObjectBridgeExplosionState(ObjectData *pData)
{
    this->pData = pData;
    this->pData->iCurrentArr = ObjectBridgeData::EXPLOSION;
}

void ObjectBridgeExplosionState::onUpdate()
{
    if (this->pData->isDesTroyed)
        return;

    ObjectState::onUpdate();

    if (this->pData->ppTextureArrays[ObjectBridgeData::EXPLOSION]->isLastTexture())
    {
        this->pData->isDesTroyed = true;
        this->pData->pState->onDead();
    }
        
}

ObjectBridgeExplosionState::~ObjectBridgeExplosionState()
{
}
