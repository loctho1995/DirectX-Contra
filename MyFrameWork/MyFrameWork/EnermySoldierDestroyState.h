#pragma once
#include "EnermyState.h"
#include "EnermyData.h"
#include "EnermySoldierData.h"

class EnermySoldierDestroyState : public EnermyState
{
public:
    EnermySoldierDestroyState(EnermyData *pData);
    ~EnermySoldierDestroyState();

    void onUpdate();
    void onCollision(RectF rect);
    void onCollision(CollisionRectF rect);
};

