#pragma once
#include "EnermyState.h"
#include "EnermyData.h"
#include "EnemySniperData.h"
#include "EnemySniperShowingState.h"

class EnemySniperHidingState : public EnermyState
{
public:
    EnemySniperHidingState(EnermyData* pData);
    ~EnemySniperHidingState();

    virtual void onUpdate();

private:
    float rangeChangeState;
    int frameChangeState;
};

