#pragma once
#include "EnermyState.h"
#include "EnermyBridgeData.h"
#include "EnermyBridgeExplosionState.h"

class EnermyBridgeAliveState : public EnermyState
{
public:
    EnermyBridgeAliveState(EnermyData *pData);
    ~EnermyBridgeAliveState();

    void onUpdate();
    void destroy(int frameDelay);
    void onCollision(RectF rect);
    void onCollision(CollisionRectF rect);

private:
    int frameDelay;
    bool isAlloDestroy;
};

