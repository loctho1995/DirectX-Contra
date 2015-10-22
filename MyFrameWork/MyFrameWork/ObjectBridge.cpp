#include "ObjectBridge.h"


ObjectBridge::ObjectBridge(float x, float y, int numBody)
{
    //pData->pState = new ObjectBridgeAliveState(this->pData);

    bridgeBodies = new ObjectBridgeBody * [numBody];
    bridgeHead = new ObjectBridgeHead(x, y);
    this->numBody = numBody;
    isDestroy = false;

    for (size_t i = 0; i < numBody; i++)
    {
        bridgeBodies[i] = new ObjectBridgeBody(x + bridgeHead->getBody().width * (i + 1), y);
    }

    bridgeTail = new ObjectBridgeTail(bridgeBodies[numBody - 1]->getBody().x + 
                                        bridgeBodies[numBody - 1]->getBody().width, y);

    pData = new ObjectBridgeData();
    pData->x = x;
    pData->y = y;
    pData->vx = pData->vy = 0;
    pData->body = RectF(0, 0, bridgeHead->getBody().width + bridgeTail->getBody().width + 
                                bridgeBodies[0]->getBody().width * numBody, bridgeHead->getBody().height);

    pData->isAffectble = false;
    pData->isEnemyCollisionable = true;
    pData->isPlayerCollisionable = true;
    pData->isHittable = false;
}

ObjectBridge::~ObjectBridge()
{

}

void ObjectBridge::update()
{
    //std::cout << "playerX: " << playerX;
    if (!isDestroy)
    {
        if (this->pData->playerX > bridgeHead->getBody().x)
        {
            //destroy();
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

void ObjectBridge::draw(Camera *cam)
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

void ObjectBridge::destroy()
{
    isDestroy = true;

    ((ObjectBridgeAliveState*)(bridgeHead->getState()))->destroy(0);

    for (size_t i = 0; i < numBody; i++)
    {
        ((ObjectBridgeAliveState*)bridgeBodies[i]->getState())->destroy((i + 1) * ObjectBridgeData::EXPLOSION_FRAMES_TIME * ObjectBridgeData::EXPLOSION_TEXTURE_COUNT);
    }

    ((ObjectBridgeAliveState*)bridgeTail->getState())->destroy(ObjectBridgeData::EXPLOSION_FRAMES_TIME * (numBody + 1) * ObjectBridgeData::EXPLOSION_TEXTURE_COUNT);
}

bool ObjectBridge::isDestroying()
{
    return this->isDestroy;
}