#pragma once
#include "EnermyData.h"

class EnermySoldierData : public EnermyData
{
public:
    EnermySoldierData();
    ~EnermySoldierData();

    enum SoldierArrayIndex
    {
        RUN,
        JUMP,
        SHOT,
        DIE,
        DESTROY,
        COUNT
    };
};

