#pragma once
#include "TransitionEffect.h"

class TransitionCircleOpen : public TransitionEffect
{
public:
    //speed = percent / frame
    TransitionCircleOpen(float speed = 0.005f);
    ~TransitionCircleOpen();

    void doAfterSetScene();
    void update();
    bool isFinish();

private:
    IDirect3DTexture9 *texture0, *texture1;
    float radius, speed;
};

