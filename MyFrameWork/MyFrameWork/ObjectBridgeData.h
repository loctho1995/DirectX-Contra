#pragma once
#include "ObjectData.h"

const int EXPLOSION_FRAMES_TIME = 3; //so frame chuyen animation cua state explosion, su dung cho viec set delay explosion
const int EXPLOSION_TEXTURE_COUNT = 15; //so luong texture cua animation exlosion

class ObjectBridgeData : public ObjectData
{
public:
    ObjectBridgeData();
    ~ObjectBridgeData();

    enum BridgeArrayIndex
    {
        ALIVE,
        EXPLOSION,
        COUNT
    };

    bool isAllowDestroy;
    bool isDestroying;
};

