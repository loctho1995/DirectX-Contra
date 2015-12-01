#include "EnermySoldierShootingState.h"

EnermySoldierShootingState::EnermySoldierShootingState(EnermyData *pData)
{
    this->pData = pData;
    this->pData->iCurrentArr = EnermySoldierData::SHOT;
    
    frameDelayTransition = 30;
}


EnermySoldierShootingState::~EnermySoldierShootingState()
{

}

void EnermySoldierShootingState::onUpdate()
{
    if (pData->ppTextureArrays[pData->iCurrentArr]->isLastTexture())
    {
        if (frameDelayTransition >= 0)
        {
            frameDelayTransition--;

            if (frameDelayTransition == 10 || frameDelayTransition == 25)
            {
                if (pData->dir.isLeft())
                {
                    pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x - 17.0 / 2, pData->y - 25, true, D3DXToRadian(180)));
                }
                else
                {
                    pData->bulletsVector.push_back(new EnermyWhiteBullet(pData->x + 17.0 / 2, pData->y - 25, true, 0));
                }
            }
        }
        else
        {
            transition(new EnermySoldierRunningState(this->pData));
            return;
        }
    }
    else
    {
        EnermyState::onUpdate();
    }
}
