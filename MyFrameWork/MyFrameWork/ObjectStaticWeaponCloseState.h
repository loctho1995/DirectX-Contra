#pragma once
#include "ObjectData.h"
#include "ObjectState.h"
#include "ObjectStaticWeaponData.h"
#include "ObjectStaticWeaponPreparingState.h"
#include "UIComponents.h"

class ObjectStaticWeaponCloseState : public ObjectState
{
public:
    ObjectStaticWeaponCloseState(ObjectData *pData);
    ~ObjectStaticWeaponCloseState();
    void onUpdate();

private:
    int frameDelay;
    int currentFramecount;
};

