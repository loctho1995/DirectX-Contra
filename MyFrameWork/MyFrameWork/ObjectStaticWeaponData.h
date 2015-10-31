#pragma once
#include "ObjectData.h"
#include "Define.h"

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

