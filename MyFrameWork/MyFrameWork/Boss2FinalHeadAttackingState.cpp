#include "Boss2FinalHeadAttackingState.h"


Boss2FinalHeadAttackingState::Boss2FinalHeadAttackingState(EnermyData *pData)
{
    this->pData = pData;
    this->pData->iCurrentArr = Boss2FinalData::ArrayIndex::OPEN;
    frameAttack = 25;
}


Boss2FinalHeadAttackingState::~Boss2FinalHeadAttackingState()
{
}

void Boss2FinalHeadAttackingState::onUpdate()
{
    frameAttack--;

    if (frameAttack >= 0)
    {
        if (frameAttack == 0)
        {
            this->pData->bulletsVector.push_back(new Boss2FinalBullet(this->pData->x, this->pData->y + 50, 1.5f, D3DXToRadian(90)));
            this->pData->bulletsVector.push_back(new Boss2FinalBullet(this->pData->x, this->pData->y + 50, 1.5f, D3DXToRadian(60)));
            this->pData->bulletsVector.push_back(new Boss2FinalBullet(this->pData->x, this->pData->y + 50, 1.5f, D3DXToRadian(120)));           
        }
    }
    else
    {
        this->pData->ppTextureArrays[pData->iCurrentArr]->resetIndex();
        transition(new Boss2FinalHeadShuttingState(this->pData));
        return;
    }
}