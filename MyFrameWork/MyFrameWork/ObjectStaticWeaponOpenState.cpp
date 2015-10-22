#include "ObjectStaticWeaponOpenState.h"


ObjectStaticWeaponOpenState::ObjectStaticWeaponOpenState(ObjectData *pData)
{
    this->pData = pData;
    this->pData->iCurrentArr = ObjectStaticWeaponData::OPENED;
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
        this->pData->pState = new ObjectStaticWeaponPreparingState(this->pData, false);
    }
    else
    {
        frameCurrentCount++;
    }
}
