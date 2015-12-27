#include "ObjectStaticWeaponCloseState.h"


ObjectStaticWeaponCloseState::ObjectStaticWeaponCloseState(ObjectData *pData)
{
    this->pData = pData;
    this->pData->iCurrentArr = ObjectStaticWeaponData::CLOSED;
    this->pData->isHittable = true;
    this->pData->isPlayerCollisionable = false;
    frameDelay = 85;
    currentFramecount = 0;
}


ObjectStaticWeaponCloseState::~ObjectStaticWeaponCloseState()
{
}

void ObjectStaticWeaponCloseState::onUpdate()
{
    ObjectState::onUpdate();

    if (currentFramecount >= frameDelay)
    {
        D3DXVECTOR2 playerPos(pData->playerX, pData->playerY);
        D3DXVECTOR2 selfPos(pData->x + 16, pData->y + 16);
        D3DXVECTOR2 directVector = playerPos - selfPos;
        float length1 = D3DXVec2Length(&directVector);
        float length = length1;

        if (UIComponents::getInstance()-> getNumberPlayer() == 2)
        {
            playerPos = D3DXVECTOR2(pData->player2X, pData->player2Y);
            directVector = playerPos - selfPos;
            float length2 = D3DXVec2Length(&directVector);
            length = length1 > length2 ? length1 : length2;
        }

        if (length <= OBJECT_STATIC_WEAPON_RANGE_OPEN)
        {
            transition(new ObjectStaticWeaponPreparingState(this->pData, true));
            return;
        }

        /*if (((ObjectStaticWeaponData*)pData)->isUp)
        {
            if (this->pData->playerX - this->pData->x >= -OBJECT_STATIC_WEAPON_RANGE_OPEN)
            {
                this->pData->pState = new ObjectStaticWeaponPreparingState(this->pData, true);
            }
        }
        else
        {
            if (this->pData->playerX - this->pData->x >= -OBJECT_STATIC_WEAPON_RANGE_OPEN)
            {
                this->pData->pState = new ObjectStaticWeaponPreparingState(this->pData, true);
            }
        }*/
    }
    else
    {
        currentFramecount++;
    }
}