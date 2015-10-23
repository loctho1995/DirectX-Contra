#pragma once
#include "ObjectSprite.h"
#include "ObjectState.h"
#include "ObjectBridgeData.h"
#include "ObjectBridgeAliveState.h"
#include "ObjectBridgeExplosionState.h"

class ObjectBridgeTail : public ObjectSprite
{
public:
    ObjectBridgeTail(float x, float y);
    ~ObjectBridgeTail();
    bool isDestroying();
    void draw(Camera *cam);
};

