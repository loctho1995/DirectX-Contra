#include "ObjectStaticWeaponOutState.h"


ObjectStaticWeaponOutState::ObjectStaticWeaponOutState(ObjectData *pData)
{
    this->pData = pData;
    this->pData->iCurrentArr = ObjectStaticWeaponData::OUTX;
    this->pData->isPlayerCollisionable = true;
    this->pData->isAffectble = true;
    this->pData->isHittable = false;
    this->pData->vx = 0.8f;
    this->pData->vy = -3.8f;

    this->pData->body = RectF(0, 0, 24, 15);
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

void ObjectStaticWeaponOutState::onCollision(CollisionRectF rect)
{
    if (this->pData->vy > 0)
    {
        this->pData->vy = 0;
        this->pData->vx = 0;
    }
}