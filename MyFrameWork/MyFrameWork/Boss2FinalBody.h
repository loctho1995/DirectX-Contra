#pragma once
#include "Sprite.h"
#include "SpriteData.h"

class Boss2FinalBody : public Sprite
{
public:
    Boss2FinalBody(float x, float y);
    ~Boss2FinalBody();

    void draw(Camera* cam);
    void update();
};

