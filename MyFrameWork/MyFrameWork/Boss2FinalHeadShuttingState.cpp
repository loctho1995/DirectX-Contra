#include "Boss2FinalHeadShuttingState.h"


Boss2FinalHeadShuttingState::Boss2FinalHeadShuttingState(EnermyData *pData)
{
    this->pData = pData;
    this->pData->iCurrentArr = Boss2FinalData::ArrayIndex::SHUT;
    frameCountOpen = 265;
    isStartChange = false;
}

Boss2FinalHeadShuttingState::~Boss2FinalHeadShuttingState()
{
}

void Boss2FinalHeadShuttingState::onUpdate()
{
    EnermyState::onUpdate();

    if (frameCountOpen >= 0)
    {
        frameCountOpen--;
    }
    else
    {
        transition(new Boss2FinalHeadOpeningState(this->pData));
        return;
    }
}


