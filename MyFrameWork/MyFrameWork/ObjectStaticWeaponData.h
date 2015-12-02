#pragma once
#include "ObjectData.h"
#include "Define.h"

float const OBJECT_STATIC_WEAPON_RANGE_OPEN = 120.0f; //chuyen state khi player lai gan
float const OBJECT_STATIC_WEAPON_RANGE_TURN = 15.0f; //bat lai khi cham vao camera

class ObjectStaticWeaponData : public ObjectData
{
public:
    ObjectStaticWeaponData();
    ~ObjectStaticWeaponData();

    enum StaticWeaponArrayIndex
    {
        CLOSED,
        PREAPRING,
        OPENED,
        OUTX,
        COUNT
    };

    BulletTypes bulletType;
};

