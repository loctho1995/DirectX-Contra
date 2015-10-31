#pragma once
#include "ObjectState.h"
#include "ObjectStaticWeaponData.h"
#include "ObjectStaticWeaponPreparingState.h"

class ObjectStaticWeaponOpenState : public ObjectState
{
public:
    ObjectStaticWeaponOpenState(ObjectData *pData);
    ~ObjectStaticWeaponOpenState();
    
    void onUpdate();

private:
    int frameDelay, frameCurrentCount;
};

