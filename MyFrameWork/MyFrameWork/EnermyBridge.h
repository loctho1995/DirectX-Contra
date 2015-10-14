#pragma once
#include "EnermyBridgeHead.h"
#include "EnermyBridgeBody.h"
#include "EnermyBridgeTail.h"
#include "EnermyBridgeAliveState.h"


class EnermyBridge
{
public:
    EnermyBridge(float x, float y, int numBody);
    void update();
    void draw(Camera *cam);
    void destroy();
    bool isDestroying();
    void setPlayerPosition(float x,float y);
    ~EnermyBridge();

private:
    EnermyBridgeHead *bridgeHead;
    EnermyBridgeBody **bridgeBodies;
    EnermyBridgeTail *bridgeTail;
    int numBody;
    bool isDestroy;
    float playerX, playerY;
};

