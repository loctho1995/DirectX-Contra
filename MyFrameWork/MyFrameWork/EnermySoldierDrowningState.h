#pragma once
#include "EnermyState.h"
#include "EnermySoldierData.h"

class EnemySoldierDrowningState : public EnermyState
{
public:
    EnemySoldierDrowningState(EnermyData *pData);
    ~EnemySoldierDrowningState();
    void onUpdate();
};

