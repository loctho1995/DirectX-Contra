#include "Boss2FinalDieState.h"


Boss2FinalDieState::Boss2FinalDieState(Boss2FinalData *pData)
{
    this->pData = pData;    
}


Boss2FinalDieState::~Boss2FinalDieState()
{
}

void Boss2FinalDieState::onUpdate()
{
    EnermyState::onUpdate();
}