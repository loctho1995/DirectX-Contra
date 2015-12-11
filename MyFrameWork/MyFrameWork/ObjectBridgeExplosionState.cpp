#include "ObjectBridgeExplosionState.h"


ObjectBridgeExplosionState::ObjectBridgeExplosionState(ObjectData *pData)
{
    this->pData = pData;
    this->pData->iCurrentArr = ObjectBridgeData::EXPLOSION;
    ((ObjectBridgeData*)this->pData)->isDestroying = true;

    Sound::getInstance()->play("bridgeexplosion.wav", false, 1);
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

    ((ObjectBridgeData*)this->pData)->isDestroying = false;
}

ObjectBridgeExplosionState::~ObjectBridgeExplosionState()
{
}
