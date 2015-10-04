#pragma once
#include "EnermyData.h"

class EnermySoldierRunData : public EnermyData
{
public:
    EnermySoldierRunData(std::string botName);
    ~EnermySoldierRunData();

    enum SoldierRunArrayIndex
    {
        RUN,
        JUMP,
        SHOT,
        DIE,
        COUNT
    };
};

