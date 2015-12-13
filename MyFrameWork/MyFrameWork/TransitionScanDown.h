#pragma once
#include "Shader.h"
#include "TransitionEffect.h"

#define D3DFVF_CUSTOMVERTEX ( D3DFVF_XYZ | D3DFVF_TEX1 )


class TransitionScanDown : public TransitionEffect
{
public:
    //speed: percent / frame
    //width: 1.0f - height: 1.0f

    TransitionScanDown(float speed);
    void doAfterSetScene();
    void update();
    bool isFinish();

private:
    float speed, currentPos;
    IDirect3DTexture9 *texture0, *texture1;
};
