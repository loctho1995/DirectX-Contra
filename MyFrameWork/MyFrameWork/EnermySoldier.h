#pragma once
#include "EnermySprite.h"
#include "EnermySoldierData.h"
#include "EnermySoldierRunningState.h"
#include "Camera.h"
#include "PlayerSprite.h"

class EnermySoldier : public EnermySprite
{
public:
    EnermySoldier(int respawnX, int respawnY);
    ~EnermySoldier();

    //void update();
    //void draw(Camera *cam);
};


