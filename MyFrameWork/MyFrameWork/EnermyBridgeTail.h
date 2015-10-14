#pragma once
#include "EnermySprite.h"
#include "EnermyState.h"
#include "EnermyBridgeData.h"
#include "EnermyBridgeAliveState.h"
#include "EnermyBridgeExplosionState.h"

class EnermyBridgeTail : public EnermySprite
{
public:
    EnermyBridgeTail(float x, float y);
    ~EnermyBridgeTail();
};

