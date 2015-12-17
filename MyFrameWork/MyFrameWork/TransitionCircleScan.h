#pragma once
#include "TransitionEffect.h"

class TransitionCircleScan : public TransitionEffect
{
public:
    //degree/frame
    TransitionCircleScan(float speed = 5.0);
    ~TransitionCircleScan();

    void doAfterSetScene();
    void update();
    bool isFinish();

private:
    IDirect3DTexture9 *texture0, *texture1;
    float angle, speed;
};

