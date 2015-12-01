#pragma once
#include "EnermyState.h"
#include "EnermyData.h"
#include "EnermySoldierJumpingState.h"
#include "EnermySoldierFallingState.h"
#include "EnermySoldierShootingState.h"

class EnermySoldierRunningState : public EnermyState
{
public:
    EnermySoldierRunningState(EnermyData* pData);
    ~EnermySoldierRunningState();

    void onUpdate();
    //void onCollision(RectF rect);
    void onCollision(CollisionRectF rect);
private:
    float acceleration;
    bool isFallDown;
    float frameShot;
};

