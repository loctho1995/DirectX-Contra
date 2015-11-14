#pragma once
#include "EnermySoldierJumpingState.h"
#include "EnermySoldierRunningState.h"
#include "EnermySoldier.h"

class EnermySoldierDieState : public EnermyState
{
public:
    EnermySoldierDieState(EnermyData *pData);
    ~EnermySoldierDieState();

    void onUpdate();

private:
    float acceleration;
};

