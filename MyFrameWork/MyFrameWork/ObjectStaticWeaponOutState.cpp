#include "ObjectStaticWeaponOutState.h"


ObjectStaticWeaponOutState::ObjectStaticWeaponOutState(ObjectData *pData)
{
    this->pData = pData;
    this->pData->iCurrentArr = ObjectStaticWeaponData::OUTX;
    this->pData->isPlayerCollisionable = true;
    this->pData->isHittable = false;
    this->pData->vx = 0.95f;
    this->pData->vy = -3.9f;

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
        if (pData->y + 10 <= rect.rect.y)
        {
            this->pData->vy = 0;
            this->pData->vx = 0;
        }
    }
}

void ObjectStaticWeaponOutState::onCameraCollision(RectF rect)
{
    if ((rect.x + rect.width) - this->pData->x <= OBJECT_STATIC_WEAPON_RANGE_TURN)
    {
        this->pData->vx = -this->pData->vx;
    }
}