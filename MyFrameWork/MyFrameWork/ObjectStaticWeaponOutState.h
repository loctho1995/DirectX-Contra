#pragma once
#include "ObjectState.h"
#include "ObjectStaticWeaponData.h"

class ObjectStaticWeaponOutState : public ObjectState
{
public:
    ObjectStaticWeaponOutState(ObjectData *pData);
    ~ObjectStaticWeaponOutState();

    void onUpdate();
    void onCollision(CollisionRectF rect);
    void onCameraCollision(RectF rect);

private:
    float accelemeter;
};

