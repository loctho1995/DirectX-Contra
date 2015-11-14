#pragma once
#include "EnermyState.h"
#include "EnermySoldierRunningState.h"
#include "EnermyData.h"
#include "EnermySoldierDrowningState.h"

class EnermySoldierFallingState : public EnermyState
{
public:
    EnermySoldierFallingState(EnermyData *pData);
    ~EnermySoldierFallingState();

    void onUpdate();
    void onCollision(CollisionRectF rect);

private:
    float acceleration;
};

