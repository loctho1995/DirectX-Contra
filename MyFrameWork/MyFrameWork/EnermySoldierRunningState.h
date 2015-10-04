#pragma once
#include "EnermyState.h"
#include "EnermyData.h"

class EnermySoldierRunningState : public EnermyState
{
public:
    EnermySoldierRunningState(EnermyData* pData);
    ~EnermySoldierRunningState();

    void onUpdate();
    void onCollision();
private:
    float acceleration;
};

