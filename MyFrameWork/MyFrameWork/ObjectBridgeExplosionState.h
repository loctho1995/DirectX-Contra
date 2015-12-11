#pragma once
#include "ObjectState.h"
#include "EnermyData.h"
#include "ObjectBridgeData.h"
#include "Sound.h"

class ObjectBridgeExplosionState : public ObjectState
{
public:
    void onUpdate();
    ObjectBridgeExplosionState(ObjectData *pData);
    ~ObjectBridgeExplosionState();
};

