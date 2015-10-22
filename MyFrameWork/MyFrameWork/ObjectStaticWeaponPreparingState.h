#pragma once
#include "ObjectStaticWeaponOpenState.h"
#include "ObjectStaticWeaponCloseState.h"
#include "ObjectStaticWeaponData.h"
#include "ObjectState.h"

class ObjectStaticWeaponPreparingState : public ObjectState
{
public:
    ObjectStaticWeaponPreparingState(ObjectData* pData, bool isNextOpen);
    ~ObjectStaticWeaponPreparingState();

    void onUpdate();

private:    
    bool isNextOpen; // = true thi state tiep theo la open con false thi next state la close
    int frameDelay, framCurrentCount;
};

