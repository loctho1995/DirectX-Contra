#include "ObjectBridge.h"


ObjectBridge::ObjectBridge(float x, float y, int numBody)
{
    bridgeBodies = new ObjectBridgeBody * [numBody];
    bridgeHead = new ObjectBridgeHead(x, y);
    isCheck = false;

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
}

ObjectBridge::~ObjectBridge()
{
    delete bridgeHead;
    delete bridgeTail;
    delete[] bridgeBodies;

    bridgeHead = nullptr;
    bridgeTail = nullptr;
    bridgeBodies = nullptr;
}

void ObjectBridge::update()
{
	pData -> collisionRect  = CollisionRectF(pData ->getBody(), "throughable", pData -> vx, pData -> vy);
    if (!isDestroy)
    {
        if (this->pData->playerX > bridgeHead->getBody().x || this->pData->player2X > bridgeHead->getBody().x)
        {
            destroy();
        }
    }

    if (bridgeHead != nullptr)
    {
        bridgeHead->update();

        if (bridgeHead->isDestroying())
        {
            this->setBody(RectF(0, 0, this->getBody().width - bridgeHead->getBody().width, this->getBody().height));
            this->pData->x = bridgeHead->getBody().x + bridgeHead->getBody().width;
        }
    }        

    for (size_t i = 0; i < numBody; i++)
    {
        if (bridgeBodies[i] != nullptr)
        {
            bridgeBodies[i]->update();

            if (bridgeBodies[i]->isDestroying())
            {
                this->setBody(RectF(0, 0, this->getBody().width - bridgeBodies[i]->getBody().width, this->getBody().height));
                this->pData->x = bridgeBodies[i]->getBody().x + bridgeBodies[i]->getBody().width;
            }
        }            
    }

    if (bridgeTail != nullptr)
    {
        bridgeTail->update();

        if (bridgeTail->isDestroying())
        {
            this->setBody(RectF(0, 0, 0, 0));
            this->pData->x = bridgeTail->getBody().x + bridgeTail->getBody().width;
        }
    }
    
    if (bridgeTail->isDesTroyed())
    {
        this->pData->isDesTroyed = true;
    }        
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
        ((ObjectBridgeAliveState*)bridgeBodies[i]->getState())->destroy((i + 1) * EXPLOSION_FRAMES_TIME * EXPLOSION_TEXTURE_COUNT);
    }

    ((ObjectBridgeAliveState*)bridgeTail->getState())->destroy(EXPLOSION_FRAMES_TIME * (numBody + 1) * EXPLOSION_TEXTURE_COUNT);
}

bool ObjectBridge::isDestroying()
{
    return this->isDestroy;
}

bool ObjectBridge::isDesTroyed()
{
    return this->pData->isDesTroyed;
}

void ObjectBridge::loadResources()
{
    TextureArray* temp = new TextureArray("Resources\\Sprites", "bridge", "body", 3, 10);
    delete temp;

    temp = new TextureArray("Resources\\Sprites", "bridge", "head", 3, 10);
    delete temp;

    temp = new TextureArray("Resources\\Sprites", "bridge", "tail", 3, 10);
    delete temp;

    temp = new TextureArray("Resources\\Sprites", "bridge", "explosion", 3, 10);
    delete temp;
}