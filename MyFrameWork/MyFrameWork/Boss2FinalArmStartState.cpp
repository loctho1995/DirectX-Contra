#include "Boss2FinalArmStartState.h"


Boss2FinalArmStartState::Boss2FinalArmStartState(EnermyData *pData)
{
    this->pData = pData;
    delayFrame = 80;

    if (((Boss2FinalData*)this->pData)->armSide == Boss2FinalData::ArmSide::LEFT)
    {
        direction = D3DXVECTOR2(cos(D3DXToRadian(-110)), sin(D3DXToRadian(-110))); //huong di 
    }
    else
    {
        direction = D3DXVECTOR2(cos(D3DXToRadian(-70)), sin(D3DXToRadian(-70))); //huong di 
    }

    distance = 4 * 16; //quang duong di chuyen
    speedFrame = distance / D3DXVec2Length(&direction); //frame
    float t = 16 / D3DXVec2Length(&direction); // thoi gian di het 16pixel - de tinh thoi gian delay cua joint ke tiep

    for (size_t i = 4; i > 0 ; i--)
    {
        ((Boss2FinalData*)pData)->joints[i]->moveBy(direction.x, direction.y, speedFrame - (3 - i + 1) * t, (3 - i + 1) * t);
    }

    //((Boss2FinalData*)pData)->hand->moveBy(direction.x, direction.y, speedFrame + 2);
}


Boss2FinalArmStartState::~Boss2FinalArmStartState()
{
}

void Boss2FinalArmStartState::onUpdate()
{
    if (delayFrame > 0)
    {
        delayFrame--;
        return;
    }

    for (size_t i = 0; i < 5; i++)
    {
        ((Boss2FinalData*)pData)->joints[i]->update();
    }

    if (((Boss2FinalData*)pData)->joints[4]->isMoveBy == false)
    {
        this->pData->pState = new Boss2FinalArmWaveState(this->pData);
    }
}