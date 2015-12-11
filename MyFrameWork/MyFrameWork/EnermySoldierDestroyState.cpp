#include "EnermySoldierDestroyState.h"


EnermySoldierDestroyState::EnermySoldierDestroyState(EnermyData *pData)
{
    this->pData = pData;
    this->pData->iCurrentArr = EnermySoldierData::DESTROY;

    Sound::getInstance()->play("enemydead.wav", false, 1);
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
