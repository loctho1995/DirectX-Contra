#pragma once
#include "EnermyState.h"
#include "EnermyData.h"
#include "EnermySoldierJumpingState.h"

const float SOLDIER_RANGE_TO_JUMP = 20.0f
;
class EnermySoldierRunningState : public EnermyState
{
public:
    EnermySoldierRunningState(EnermyData* pData);
    ~EnermySoldierRunningState();

    void onUpdate();
    void onCollision(RectF rect);
    void onCollision(CollisionRectF rect);
private:
    float acceleration;
};

