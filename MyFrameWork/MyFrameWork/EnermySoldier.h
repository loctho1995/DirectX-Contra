#pragma once
#include "EnermySprite.h"
#include "EnermySoldierData.h"
#include "EnermySoldierRunningState.h"
#include "EnermySoldierJumpingState.h"
#include "EnermySoldierDestroyState.h"
#include "EnermySoldierDieState.h"
#include "Camera.h"
#include "PlayerSprite.h"

class EnermySoldier : public EnermySprite
{
public:
    EnermySoldier(float x, float y);
    ~EnermySoldier();

    //void update();
    //void draw(Camera *cam);

};


