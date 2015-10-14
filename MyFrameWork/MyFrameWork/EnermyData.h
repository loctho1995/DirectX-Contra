#pragma once

#include "SpriteData.h"

class EnermyData : public SpriteData
{
public :
	float playerX;
	float playerY;
    std::string botName; //add by Tho
    bool isDone; //enermy da chet cmn chua ?
    bool isHittable; //co hiep dc con enermy nay khong ?
};