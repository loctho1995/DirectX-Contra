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
    void onCollision(RectF rect);
    void onCollision(CollisionRectF rect);

private:
    float acceleration;
};

