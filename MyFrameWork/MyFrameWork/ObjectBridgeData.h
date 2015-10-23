#pragma once
#include "ObjectData.h"

class ObjectBridgeData : public ObjectData
{
public:
    ObjectBridgeData();
    ~ObjectBridgeData();

    static const int EXPLOSION_FRAMES_TIME = 5; //so frame chuyen animation cua state explosion, su dung cho viec set delay explosion
    static const int EXPLOSION_TEXTURE_COUNT = 15; //so luong texture cua animation exlosion

    enum BridgeArrayIndex
    {
        ALIVE,
        EXPLOSION,
        COUNT
    };

    bool isAllowDestroy;
    bool isDestroying;
};

