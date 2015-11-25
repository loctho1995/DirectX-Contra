#pragma once
#include "ObjectBridgeHead.h"
#include "ObjectBridgeBody.h"
#include "ObjectBridgeTail.h"
#include "ObjectBridgeAliveState.h"


class ObjectBridge : public ObjectSprite
{
public:
    ObjectBridge(float x, float y, int numBody);
    void update();
    void draw(Camera *cam);
    void destroy();
    bool isDestroying();
    bool isDesTroyed();
    ~ObjectBridge();

    static void loadResources();

private:
    ObjectBridgeHead *bridgeHead;
    ObjectBridgeBody **bridgeBodies;
    ObjectBridgeTail *bridgeTail;
    int numBody;
    bool isDestroy;
    bool isCheck;
};

