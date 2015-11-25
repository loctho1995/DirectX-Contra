#pragma once
#include "Boss2FinalData.h"
#include "EnermySprite.h"
#include "Boss2FinalHeadState.h"
#include "BulletSprite.h"

class Boss2FinalHead : public EnermySprite
{
public:
    Boss2FinalHead(float x, float y, std::vector<BulletSprite*>& bulletSprite);
    ~Boss2FinalHead();

    void update();
    void draw(Camera *cam);
};

