#pragma once
#include "EnermyState.h"
#include "EnermySoldierRunningState.h"
#include "EnermyData.h"

class EnermySoldierFallingState : public EnermyState
{
public:
    EnermySoldierFallingState(EnermyData *pData);
    ~EnermySoldierFallingState();

    void onUpdate();
    void onCollision(CollisionRectF rect);
    void onCameraCollision(RectF camera);

private:
    float acceleration;
};

