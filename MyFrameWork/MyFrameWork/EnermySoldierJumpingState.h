#pragma once
#include "EnermyState.h"
#include "EnermySoldier.h"
#include "EnermySoldierDrowningState.h"

class EnermySoldierJumpingState : public EnermyState
{
public:
    EnermySoldierJumpingState(EnermyData *pData);
    ~EnermySoldierJumpingState();

    void onUpdate();
    void onCollision(RectF rect);
    void onCollision(CollisionRectF rect);
    //void onCameraCollision(RectF camera);

private:
    float acceleration;
};

