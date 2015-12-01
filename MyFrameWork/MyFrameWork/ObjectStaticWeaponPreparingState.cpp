#include "ObjectStaticWeaponPreparingState.h"


ObjectStaticWeaponPreparingState::ObjectStaticWeaponPreparingState(ObjectData *pData, bool isNextOpen)
{
    this->pData = pData;
    this->pData->iCurrentArr = ObjectStaticWeaponData::PREAPRING;
    this->isNextOpen = isNextOpen;
    this->pData->isHittable = false;
    this->pData->isPlayerCollisionable = false;
    framCurrentCount = 0;
    frameDelay = 0;
}


ObjectStaticWeaponPreparingState::~ObjectStaticWeaponPreparingState()
{
}

void ObjectStaticWeaponPreparingState::onUpdate()
{
    ObjectState::onUpdate();


    if (framCurrentCount >= frameDelay)
    {
        if (this->pData->ppTextureArrays[ObjectStaticWeaponData::PREAPRING]->isLastTexture())
        {
            if (this->isNextOpen)
            {
                transition(new ObjectStaticWeaponOpenState(this->pData));
                return;
            }
            else
            {
                transition(new ObjectStaticWeaponCloseState(this->pData));
                return;
            }
        }
    }
    else
    {
        framCurrentCount++;
    }
}