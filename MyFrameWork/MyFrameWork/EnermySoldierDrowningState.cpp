#include "EnermySoldierDrowningState.h"


EnemySoldierDrowningState::EnemySoldierDrowningState(EnermyData *pData)
{
    this->pData = pData;
    this->pData->iCurrentArr = EnermySoldierData::DROWNING;
}


EnemySoldierDrowningState::~EnemySoldierDrowningState()
{
}

void EnemySoldierDrowningState::onUpdate()
{
    EnermyState::onUpdate();

    if (this->pData->ppTextureArrays[EnermySoldierData::DROWNING]->isLastTexture())
    {
        this->pData->isDesTroyed = true;
    }
}