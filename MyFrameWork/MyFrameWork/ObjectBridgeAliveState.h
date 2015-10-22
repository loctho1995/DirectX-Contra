#pragma once
#include "ObjectState.h"
#include "ObjectBridgeData.h"
#include "ObjectBridgeExplosionState.h"

class ObjectBridgeAliveState : public ObjectState
{
public:
    ObjectBridgeAliveState(ObjectData *pData);
    ~ObjectBridgeAliveState();

    void onUpdate();
    void destroy(int frameDelay);
    void onCollision(RectF rect);
    void onCollision(CollisionRectF rect);

private:
    int frameDelay;
    bool isAlloDestroy;
};

