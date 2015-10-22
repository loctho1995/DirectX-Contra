#pragma once
#include "ObjectData.h"

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
};

