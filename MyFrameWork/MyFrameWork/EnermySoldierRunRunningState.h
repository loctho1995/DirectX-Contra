#pragma once
#include "EnermyState.h"
#include "EnermyData.h"

class EnermySoldierRunRunningState : public EnermyState
{
public:
    EnermySoldierRunRunningState(EnermyData* pData);
    ~EnermySoldierRunRunningState();

    void onUpdate();
    void onCollision();
private:
    float acceleration;
};

