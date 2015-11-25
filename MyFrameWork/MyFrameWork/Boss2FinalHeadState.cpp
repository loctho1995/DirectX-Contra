#include "Boss2FinalHeadState.h"


Boss2FinalHeadState::Boss2FinalHeadState(EnermyData *pData)
{
    this->pData = pData;
    FRAME_COUNT_SHUT = 165;
    frameCountShut = FRAME_COUNT_SHUT;
}


Boss2FinalHeadState::~Boss2FinalHeadState()
{
}

void Boss2FinalHeadState::onUpdate()
{

    this->pData->ppTextureArrays[pData->iCurrentArr]->update();

    if (pData->iCurrentArr == Boss2FinalData::ArrayIndex::SHUT)
    {
        if (frameCountShut >= 0)
        {
            frameCountShut--;
        }
        else
        {
            pData->iCurrentArr = Boss2FinalData::ArrayIndex::OPEN;
        }
    }

    if (pData->iCurrentArr == Boss2FinalData::ArrayIndex::OPEN)
    {
        if (pData->ppTextureArrays[pData->iCurrentArr]->isLastTexture())
        {
            //de dua texture ve index 0
            for (size_t i = 0; i < 15; i++)
            {
                this->pData->ppTextureArrays[pData->iCurrentArr]->update();
            }

            frameCountShut = FRAME_COUNT_SHUT;
            pData->iCurrentArr = Boss2FinalData::ArrayIndex::SHUT;
        }
    }
}

