#pragma once
#include "ObjectState.h"
#include "ObjectStaticWeaponData.h"

class ObjectStaticWeaponOutState : public ObjectState
{
public:
    ObjectStaticWeaponOutState(ObjectData *pData);
    ~ObjectStaticWeaponOutState();

    void onUpdate();

private:
    float accelemeter;
};

