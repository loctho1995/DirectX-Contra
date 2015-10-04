#pragma once
#include "EnermyData.h"

class EnermySoldierData : public EnermyData
{
public:
    EnermySoldierData();
    ~EnermySoldierData();

    enum SoldierRunArrayIndex
    {
        RUN,
        JUMP,
        SHOT,
        DIE,
        COUNT
    };
};

