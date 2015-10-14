#pragma once
#include "EnermyState.h"
#include "EnermyData.h"
#include "EnermyBridgeData.h"

class EnermyBridgeExplosionState : public EnermyState
{
public:
    void onUpdate();
    EnermyBridgeExplosionState(EnermyData *pData);
    ~EnermyBridgeExplosionState();
};

