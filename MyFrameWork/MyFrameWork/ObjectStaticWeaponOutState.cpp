#include "ObjectStaticWeaponOutState.h"


ObjectStaticWeaponOutState::ObjectStaticWeaponOutState(ObjectData *pData)
{
    this->pData = pData;
    this->pData->iCurrentArr = ObjectStaticWeaponData::OUTX;
    this->pData->isPlayerCollisionable = true;
    this->pData->vx = 0.8f;
    this->pData->vy = -3.1f;
    accelemeter = 0.1f;
}


ObjectStaticWeaponOutState::~ObjectStaticWeaponOutState()
{
}

void ObjectStaticWeaponOutState::onUpdate()
{
    ObjectState::onUpdate();

    this->pData->x = this->pData->x + this->pData->vx;
    this->pData->y = this->pData->y + this->pData->vy;
    this->pData->vy += accelemeter;
}
