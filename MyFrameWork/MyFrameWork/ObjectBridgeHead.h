#pragma once
#include "ObjectSprite.h"
#include "ObjectBridgeData.h"
#include "ObjectBridgeAliveState.h"
#include "ObjectBridgeExplosionState.h"

class ObjectBridgeHead : public ObjectSprite
{
public:
    ObjectBridgeHead(float x, float y);
    ~ObjectBridgeHead();
    bool isDestroying();
    void draw(Camera *cam);

};

