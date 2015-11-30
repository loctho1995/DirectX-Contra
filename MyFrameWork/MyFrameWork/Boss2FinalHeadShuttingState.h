#pragma once
#include "EnermyState.h"
#include "Boss2FinalData.h"
#include "Boss2FinalBullet.h"
#include "Boss2FinalHeadOpeningState.h"

class Boss2FinalHeadShuttingState : public EnermyState
{
public:
    Boss2FinalHeadShuttingState(EnermyData *pData);
    ~Boss2FinalHeadShuttingState();

    void onUpdate();

private:
    int frameCountOpen;
    bool isStartChange;
};

