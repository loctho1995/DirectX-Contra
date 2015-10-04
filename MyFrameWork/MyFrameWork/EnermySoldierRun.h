#pragma once
#include "EnermySprite.h"
#include "EnermySoldierRunData.h"
#include "EnermySoldierRunRunningState.h"
#include "Camera.h"
#include "PlayerSprite.h"

class EnermySoldierRun : public EnermySprite
{
public:
    EnermySoldierRun(int respawnX, int respawnY);
    ~EnermySoldierRun();

    //void update();
    //void draw(Camera *cam);
};


