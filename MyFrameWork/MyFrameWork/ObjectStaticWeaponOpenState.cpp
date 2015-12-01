#include "ObjectStaticWeaponOpenState.h"


ObjectStaticWeaponOpenState::ObjectStaticWeaponOpenState(ObjectData *pData)
{
    this->pData = pData;
    this->pData->iCurrentArr = ObjectStaticWeaponData::OPENED;
    this->pData->isHittable = true;
    this->pData->isPlayerCollisionable = false;
    frameCurrentCount = 0;
    frameDelay = 52;
}


ObjectStaticWeaponOpenState::~ObjectStaticWeaponOpenState()
{

}

void ObjectStaticWeaponOpenState::onUpdate()
{
    ObjectState::onUpdate();

    if (frameCurrentCount >= frameDelay)
    {
        transition(new ObjectStaticWeaponPreparingState(this->pData, false));
    }
    else
    {
        frameCurrentCount++;
    }
}
