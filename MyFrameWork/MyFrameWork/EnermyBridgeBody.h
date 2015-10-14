#pragma once
#include "EnermyState.h"    
#include "EnermySprite.h"
#include "EnermyBridgeAliveState.h"
#include "EnermyBridgeExplosionState.h"

class EnermyBridgeBody : public EnermySprite
{
public:
    EnermyBridgeBody(float x, float y);
    ~EnermyBridgeBody();
};

