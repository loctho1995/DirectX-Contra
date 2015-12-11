#pragma once
#include "BulletSprite.h"
#include "EnermyData.h"
#include "BulletMovingState.h"
#include "Sound.h"

class Boss2FinalBullet : public BulletSprite
{
public:
    Boss2FinalBullet(float x, float y, float speed = 2.5f, float angle = 0);
    ~Boss2FinalBullet();

    void update();
    void draw(Camera *cam);
};

