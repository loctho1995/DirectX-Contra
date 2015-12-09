#pragma once
#include "Sprite.h"
class Boss2FinalExplosionSprite : public Sprite
{
public:
    Boss2FinalExplosionSprite(float x, float y);
    ~Boss2FinalExplosionSprite();

    virtual void update();
    virtual void draw(Camera *cam);
    void drawAtPosition(float x, float y,Camera *cam);

    void setPosition(float x, float y);
    void setPosition(D3DXVECTOR2 pos);
    bool isFinishAnimation();
};

