#pragma once
#include "EnermyState.h"
#include "Boss2FinalData.h"
#include "Boss2FinalBullet.h"
#include "Boss2FinalHeadShuttingState.h"
#include "Boss2FinalHeadAttackingState.h"

class Boss2FinalHeadOpeningState : public EnermyState
{
public:
    Boss2FinalHeadOpeningState(EnermyData *pData);
    ~Boss2FinalHeadOpeningState();
    void onUpdate();

private:
    int frameChange;
};

