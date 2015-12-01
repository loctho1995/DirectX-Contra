#pragma once
#include "EnermyState.h"
#include "EnermySoldierData.h"
#include "EnermyWhiteBullet.h"
#include "EnermySoldierRunningState.h"

class EnermySoldierShootingState : public EnermyState
{
public:
    EnermySoldierShootingState(EnermyData *pData);
    ~EnermySoldierShootingState();
    void onUpdate();

private:
    int frameDelayTransition;
};

