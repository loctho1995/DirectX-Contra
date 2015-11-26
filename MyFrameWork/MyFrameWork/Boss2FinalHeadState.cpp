#include "Boss2FinalHeadState.h"


Boss2FinalHeadState::Boss2FinalHeadState(EnermyData *pData)
	:
    FRAME_COUNT_SHUT(165), FRAME_COUNT_ATTACK(18)
{
    this->pData = pData;
    frameCountShut = FRAME_COUNT_SHUT;
    frameCountAttack = FRAME_COUNT_ATTACK;
    isStartAttack = false;
}


Boss2FinalHeadState::~Boss2FinalHeadState()
{
}

void Boss2FinalHeadState::onUpdate()
{
    if (isStartAttack)
    {
        if (frameCountAttack >= 0)
        {
            frameCountAttack--;
        }
        else
        {
            isStartAttack = false;
            pData->iCurrentArr = Boss2FinalData::ArrayIndex::SHUT;
        }
    }
    else
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
                for (size_t i = 0; i < 15; i++)
                {
                    this->pData->ppTextureArrays[pData->iCurrentArr]->update();
                }

                this->pData->bulletsVector.push_back(new Boss2FinalBullet(this->pData->x, this->pData->y + 50, 1.5f, D3DXToRadian(90)));
                this->pData->bulletsVector.push_back(new Boss2FinalBullet(this->pData->x, this->pData->y + 50, 1.5f, D3DXToRadian(60)));
                this->pData->bulletsVector.push_back(new Boss2FinalBullet(this->pData->x, this->pData->y + 50, 1.5f, D3DXToRadian(120)));

                isStartAttack = true;
                frameCountAttack = FRAME_COUNT_ATTACK;
                frameCountShut = FRAME_COUNT_SHUT;
            }
        }
    }
}


