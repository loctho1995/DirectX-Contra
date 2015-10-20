#pragma once
#include "EnermyBridgeHead.h"
#include "EnermyBridgeBody.h"
#include "EnermyBridgeTail.h"
#include "EnermyBridgeAliveState.h"


class EnermyBridge : public EnermySprite
{
public:
    EnermyBridge(float x, float y, int numBody);
    void update();
    void draw(Camera *cam);
    void destroy();
    bool isDestroying();
    ~EnermyBridge();

private:
    EnermyBridgeHead *bridgeHead;
    EnermyBridgeBody **bridgeBodies;
    EnermyBridgeTail *bridgeTail;
    int numBody;
    bool isDestroy;
};

