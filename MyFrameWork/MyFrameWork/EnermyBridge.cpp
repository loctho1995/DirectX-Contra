#include "EnermyBridge.h"


EnermyBridge::EnermyBridge(float x, float y, int numBody)
{
    //pData->pState = new EnermyBridgeAliveState(this->pData);

    bridgeBodies = new EnermyBridgeBody * [numBody];
    bridgeHead = new EnermyBridgeHead(x, y);
    this->numBody = numBody;
    isDestroy = false;

    for (size_t i = 0; i < numBody; i++)
    {
        bridgeBodies[i] = new EnermyBridgeBody(x + bridgeHead->getBody().width * (i + 1), y);
    }

    bridgeTail = new EnermyBridgeTail(bridgeBodies[numBody - 1]->getBody().x + 
                                        bridgeBodies[numBody - 1]->getBody().width, y);

    pData = new EnermyBridgeData();
    pData->x = x;
    pData->y = y;
    pData->vx = pData->vy = 0;
    pData->body = RectF(0, 0, bridgeHead->getBody().width + bridgeTail->getBody().width + 
                                bridgeBodies[0]->getBody().width * numBody, bridgeHead->getBody().height);
}

EnermyBridge::~EnermyBridge()
{

}

void EnermyBridge::update()
{
    //std::cout << "playerX: " << playerX;
    if (!isDestroy)
    {
        if (this->pData->playerX > bridgeHead->getBody().x)
        {
            destroy();
        }
    }

    if (bridgeHead != nullptr)
        bridgeHead->update();

    for (size_t i = 0; i < numBody; i++)
    {
        if (bridgeBodies[i] != nullptr)
            bridgeBodies[i]->update();
    }

    if (bridgeTail != nullptr)
        bridgeTail->update();
}

void EnermyBridge::draw(Camera *cam)
{
    if (bridgeHead != nullptr)
        bridgeHead->draw(cam);

    for (size_t i = 0; i < numBody; i++)
    {
        if (bridgeBodies[i] != nullptr)
            bridgeBodies[i]->draw(cam);
    }

    if (bridgeTail != nullptr)
        bridgeTail->draw(cam);
}

void EnermyBridge::destroy()
{
    isDestroy = true;

    ((EnermyBridgeAliveState*)(bridgeHead->getState()))->destroy(0);

    for (size_t i = 0; i < numBody; i++)
    {
        ((EnermyBridgeAliveState*)bridgeBodies[i]->getState())->destroy((i + 1) * EnermyBridgeData::EXPLOSION_FRAMES_TIME * EnermyBridgeData::EXPLOSION_TEXTURE_COUNT);
    }

    ((EnermyBridgeAliveState*)bridgeTail->getState())->destroy(EnermyBridgeData::EXPLOSION_FRAMES_TIME * (numBody + 1) * EnermyBridgeData::EXPLOSION_TEXTURE_COUNT);
}

bool EnermyBridge::isDestroying()
{
    return this->isDestroy;
}