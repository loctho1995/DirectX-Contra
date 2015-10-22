#pragma once
#include "ObjectState.h"
#include "EnermyData.h"
#include "ObjectBridgeData.h"

class ObjectBridgeExplosionState : public ObjectState
{
public:
    void onUpdate();
    ObjectBridgeExplosionState(ObjectData *pData);
    ~ObjectBridgeExplosionState();
};

