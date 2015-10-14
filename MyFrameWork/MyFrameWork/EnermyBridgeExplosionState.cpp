#include "EnermyBridgeExplosionState.h"


EnermyBridgeExplosionState::EnermyBridgeExplosionState(EnermyData *pData)
{
    this->pData = pData;
    this->pData->iCurrentArr = EnermyBridgeData::EXPLOSION;
}

void EnermyBridgeExplosionState::onUpdate()
{
    if (this->pData->isDone)
        return;

    EnermyState::onUpdate();

    if (this->pData->ppTextureArrays[EnermyBridgeData::EXPLOSION]->isLastTexture())
        this->pData->isDone = true;
}

EnermyBridgeExplosionState::~EnermyBridgeExplosionState()
{
}
