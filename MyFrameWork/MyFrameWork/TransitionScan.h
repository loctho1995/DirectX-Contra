#pragma once
#include "Shader.h"
#include "TransitionEffect.h"

#define D3DFVF_CUSTOMVERTEX ( D3DFVF_XYZ | D3DFVF_TEX1 )


class TransitionScan : public TransitionEffect
{
public:
    enum TransitionFrom
    {
        LEFT, RIGHT, TOP, BOTTOM, RANDOM
    };

    //speed: percent / frame
    //width: 1.0f - height: 1.0f

    TransitionScan(float speed = 0.025, TransitionFrom from = TransitionFrom::RANDOM);
    void doAfterSetScene();
    void update();
    bool isFinish();

private:
    float speed, currentPos;
    IDirect3DTexture9 *texture0, *texture1;
    TransitionFrom from;
};
