#pragma once
#include "EnermyState.h"
#include "EnermyData.h"
#include "EnemySniperData.h"
#include "EnemySniperDeadState.h"
#include "EnemySniperShowingState.h"

class EnemySniperDyingState : public EnermyState
{
public:
    EnemySniperDyingState(EnermyData* pData);
    ~EnemySniperDyingState();

    virtual void onUpdate();

private:
    float acc;
};

