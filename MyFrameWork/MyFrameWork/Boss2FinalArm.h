#pragma once
#include "EnermySprite.h"
#include "Boss2FinalData.h"
#include "Boss2FinalArmStartState.h"

class Boss2FinalArm : public EnermySprite
{
public:
    Boss2FinalArm(float x, float y,std::vector<BulletSprite*>& bulletSprites, Boss2FinalData::ArmSide armSide);
    ~Boss2FinalArm();

    void update();
    void draw(Camera *cam);
    RectF getBody();

private:
    Boss2FinalData::ArmSide armSide;
};

