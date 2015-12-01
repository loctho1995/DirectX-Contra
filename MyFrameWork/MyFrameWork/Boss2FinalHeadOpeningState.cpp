#include "Boss2FinalHeadOpeningState.h"


Boss2FinalHeadOpeningState::Boss2FinalHeadOpeningState(EnermyData *pData)
{
    this->pData = pData;
    this->pData->iCurrentArr = Boss2FinalData::ArrayIndex::OPEN;
    this->pData->ppTextureArrays[pData->iCurrentArr]->resetIndex();
    frameChange = 150;
}

Boss2FinalHeadOpeningState::~Boss2FinalHeadOpeningState()
{
}

void Boss2FinalHeadOpeningState::onUpdate()
{
    EnermyState::onUpdate();

    if (pData->ppTextureArrays[pData->iCurrentArr]->isLastTexture())
    {
        //for (size_t i = 0; i < 24; i++)
        //{
        //    EnermyState::onUpdate();
        //}

        transition(new Boss2FinalHeadAttackingState(this->pData));
        return;
    }
}
