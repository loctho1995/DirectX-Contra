#include "EnermySoldierDestroyState.h"


EnermySoldierDestroyState::EnermySoldierDestroyState(EnermyData *pData)
{
    this->pData = pData;
    this->pData->iCurrentArr = EnermySoldierData::DESTROY;
}

EnermySoldierDestroyState::~EnermySoldierDestroyState()
{

}

void EnermySoldierDestroyState::onUpdate()
{
    if (this->pData->isDesTroyed)
        return;

    if (this->pData->ppTextureArrays[EnermySoldierData::DESTROY]->isLastTexture())
    {
        this->pData->isDesTroyed = true;
    }
        

    EnermyState::onUpdate();
}
