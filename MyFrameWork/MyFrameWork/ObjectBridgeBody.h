#pragma once

#include "ObjectBridgeAliveState.h"
#include "ObjectBridgeExplosionState.h"
#include "ObjectState.h"
#include "ObjectSprite.h"

class ObjectBridgeBody : public ObjectSprite
{
public:
    ObjectBridgeBody(float x, float y);
    void draw(Camera *cam);
    bool isDestroying();
    ~ObjectBridgeBody();
};

