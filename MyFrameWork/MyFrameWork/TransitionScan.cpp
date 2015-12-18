#include "TransitionScan.h"
#include <iostream>
using namespace std;

TransitionScan::TransitionScan(float speed, TransitionFrom from)
{
    currentPos = 0;
    this->speed = speed;
    this->from = from;

    srand(NULL);

    if (from == TransitionFrom::RANDOM)
    {
        switch (rand() % 4)
        {
            case 0:
                this->from = TransitionFrom::RIGHT;
                break;

            case 1:
                this->from = TransitionFrom::LEFT;
                break;

            case 2:
                this->from = TransitionFrom::TOP;
                break;

            default:
                this->from = TransitionFrom::BOTTOM;
                break;
        }
    }

    switch (this->from)
    {
        case TransitionFrom::TOP:
            //quet scene tu tren xuong duoi
            shader = new Shader("Resources\\Shader\\transitionscandown.fx");
            currentPos = 0;
        break;

        case TransitionFrom::BOTTOM:
            //quet anh tu duoi len tren
            shader = new Shader("Resources\\Shader\\transitionscanup.fx");
            currentPos = 1.0;
            break;

        case TransitionFrom::LEFT:
            //toa do x = -1 -> 1
            shader = new Shader("Resources\\Shader\\transitionscanright.fx");
            currentPos = -1.0;
            break;

        case TransitionFrom::RIGHT:
            shader = new Shader("Resources\\Shader\\transitionscanleft.fx");
            currentPos = 0;
            break;
    }   
}

void TransitionScan::update()
{
    Graphics::getInstance()->beginRender();

    switch (from)
    {
        case TransitionScan::LEFT:
            currentPos += speed;
            break;

        case TransitionScan::RIGHT:
            currentPos -= speed;
            break;

        case TransitionScan::TOP:            
            currentPos += speed;
            break;

        case TransitionScan::BOTTOM:
            currentPos -= speed;
            break;
        default:
            break;
    }

    unsigned int Passes = 0;
    shader->getEffect()->Begin(&Passes, 0);
    
    D3DXMATRIX mtxViewProj;
    D3DXMatrixIdentity(&mtxViewProj);
    mtxViewProj._11 = 2.0;
    mtxViewProj._22 = -2.0; //toa do loz texel no nguoc voi toa do hlsl nen phai cover
    mtxViewProj._41 = 1.0;
    mtxViewProj._42 = 1.0;

    shader->getEffect()->SetMatrix("WorldViewProj", &(mtxViewProj));
    shader->getEffect()->SetTexture("texture0", texture0);
    shader->getEffect()->SetTexture("texture1", texture1);
    shader->getEffect()->SetFloat("posMove", currentPos);

    for (int i = 0; i < Passes; ++i)
    {
        shader->getEffect()->BeginPass(i);

        Graphics::getInstance()->getDevice()->SetStreamSource(0, vertexBuffer, 0, sizeof(VertexData));
        Graphics::getInstance()->getDevice()->SetFVF(D3DFVF_CUSTOMVERTEX);
        Graphics::getInstance()->getDevice()->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);

        shader->getEffect()->EndPass();
    }

    shader->getEffect()->End();
    Graphics::getInstance()->endRender();
}

bool TransitionScan::isFinish()
{
    switch (from)
    {
        case TransitionScan::LEFT:
            return currentPos >= 0.0;

        case TransitionScan::RIGHT:
            return currentPos <= -1.0;
            break;

        case TransitionScan::TOP:
            return currentPos >= 1.0;

        case TransitionScan::BOTTOM:
            return currentPos <= 0;

        default:
            break;
    }
    return false;
}

void TransitionScan::doAfterSetScene()
{
    D3DXCreateTexture(Graphics::getInstance()->getDevice(), SCWIDTH, SCHEIGHT, D3DX_DEFAULT,
        D3DUSAGE_RENDERTARGET, D3DFMT_A8B8G8R8, D3DPOOL_DEFAULT, &texture0);

    D3DXCreateTexture(Graphics::getInstance()->getDevice(), SCWIDTH, SCHEIGHT, D3DX_DEFAULT,
        D3DUSAGE_RENDERTARGET, D3DFMT_A8B8G8R8, D3DPOOL_DEFAULT, &texture1);
    Graphics::getInstance()->isAllowPresent = false;

    IDirect3DSurface9 *surface, *backsurface;
    this->sceneDest->render();
    texture1->GetSurfaceLevel(0, &surface);
    Graphics::getInstance()->getDevice()->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &backsurface);

    D3DXLoadSurfaceFromSurface(surface, NULL, NULL, backsurface, NULL, NULL, D3DX_FILTER_NONE, 0);
    surface->Release();
    surface = nullptr;

    this->sceneSource->render();
    texture0->GetSurfaceLevel(0, &surface);
    D3DXLoadSurfaceFromSurface(surface, NULL, NULL, backsurface, NULL, NULL, D3DX_FILTER_NONE, 0);
    surface->Release();

    Graphics::getInstance()->isAllowPresent = true;
}