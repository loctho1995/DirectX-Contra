#pragma once
#include "BulletSprite.h"

class Boss2FinalBullet : public BulletSprite
{
public:
    Boss2FinalBullet(float x, float y, float vx, float vy, float speed = 5.0f);
    ~Boss2FinalBullet();

    void update();
    void draw(Camera *cam);
};

