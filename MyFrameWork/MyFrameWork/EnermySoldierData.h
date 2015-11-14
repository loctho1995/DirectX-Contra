#pragma once
#include "EnermyData.h"

const float SOLDIER_RANGE_TO_JUMP = 5.0f;
const float SOLDIER_RANGE_TO_TURN = 15.0f;

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
        FALL,
        DROWNING,
        COUNT
    };

};

